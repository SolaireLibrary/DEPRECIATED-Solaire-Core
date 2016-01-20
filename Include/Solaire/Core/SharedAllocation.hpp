#ifndef SOLAIRE_SHARED_ALLOCATION_HPP
#define SOLAIRE_SHARED_ALLOCATION_HPP

//Copyright 2015 Adam Smith
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

// Contact :
// Email             : solairelibrary@mail.com
// GitHub repository : https://github.com/SolaireLibrary/SolaireCPP

/*!
	\file SharedAllocation.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\date
	Created			: 8th December 2015
	Last Modified	: 11th January 2016
*/

#include <algorithm>
#include "Solaire/Core/AllocatorI.hpp"

namespace Solaire {

    namespace Implementation {
        template<class T>
        static void SOLAIRE_EXPORT_CALL SharedObjectDestructor(void* const aObject) throw() {
            static_cast<T*>(aObject)->~T();
        }
    }



    class SharedObject {
    public:
        typedef void (SOLAIRE_EXPORT_CALL *Destructor)(void* const);
    private:
        AllocatorI& mAllocator;
        Destructor mDestructor;
        void* mObject;
        uint16_t mUsers;
    public:
        SharedObject(AllocatorI& aAllocator, void* const aObject, Destructor aDestructor) throw() :
            mAllocator(aAllocator),
            mDestructor(aDestructor),
            mObject(aObject),
            mUsers(0)
        {}

        ~SharedObject() throw() {
            if(mObject != nullptr) {
                mDestructor(mObject);
                mAllocator.deallocate(mObject);
            }
        }

        AllocatorI& getAllocator() const throw() {
            return mAllocator;
        }

        uint16_t getUsers() const throw() {
            return mUsers;
        }

        void* getPtr() throw() {
            return mObject;
        }

        const void* getPtr() const throw() {
            return mObject;
        }

        bool addUser() throw() {
            ++mUsers;
            return true;
        }

        bool removeUser() throw() {
            if(mUsers == 0) return false;
            if(mUsers == 1 && mObject != nullptr) {
                mDestructor(mObject);
                mAllocator.deallocate(mObject);
                mAllocator.deallocate(this);
            }
            return true;
        }
    };

	template<class T>
	class SharedAllocation {
	public:
		template<class T2>
		friend class SharedAllocation;
	private:
		SharedObject* mObject;
    private:
		SharedAllocation(SharedObject* const aObject) throw() :
			mObject(aObject)
		{
		    if(mObject) mObject->addUser();
		}
	public:
		SharedAllocation() throw() :
			mObject(nullptr)
		{}

		SharedAllocation(AllocatorI& aAllocator, T* const aObject) throw() :
			mObject(new(aAllocator.allocate(sizeof(SharedObject))) SharedObject(aAllocator, aObject, Implementation::SharedObjectDestructor<T>))
		{
		    mObject->addUser();
		}

		SharedAllocation(const SharedAllocation<T>& aOther) throw() :
			mObject(aOther.mObject)
		{
			if(mObject) mObject->addUser();
		}

		SharedAllocation(SharedAllocation<T>&& aOther) throw() :
			mObject(aOther.mObject)
		{
			aOther.mObject = nullptr;
		}

		~SharedAllocation() throw() {
			if(mObject) mObject->removeUser();
		}

		SharedAllocation<T>& operator=(const SharedAllocation<T>& aOther) throw() {
			if(mObject) mObject->removeUser();
			mObject = aOther.mObject;
			if(mObject) mObject->addUser();
			return *this;
		}

		SharedAllocation<T>& operator=(SharedAllocation<T>&& aOther) throw() {
			swap(aOther);
			return *this;
		}

		void swap(SharedAllocation<T>& aOther) throw() {
			std::swap(mObject, aOther.mObject);
		}

		AllocatorI& getAllocator() const throw() {
			return mObject->getAllocator();
		}

		uint32_t getUserCount() const throw() {
			return mObject ? mObject->getUsers() : 0;
		}

		operator bool() const throw() {
			return mObject != nullptr;
		}

		T& operator*() const throw() {
			return *operator->();
		}

		T* operator->() const throw() {
			return mObject ? static_cast<T*>(mObject->getPtr()) : nullptr;
		}

		template<class T2>
		bool operator==(const SharedAllocation<T2> aOther) const throw() {
		    return mObject == aOther.mObject;
		}

		template<class T2>
		bool operator!=(const SharedAllocation<T2> aOther) const throw() {
		    return mObject != aOther.mObject;
		}

		template<class T2, typename ENABLE = typename std::enable_if<
            std::is_base_of<T, T2>::value ||
            std::is_same<const T, T2>::value ||
            std::is_same<T2, void>::value
        >::type>
		explicit operator SharedAllocation<T2>() const throw() {
			return SharedAllocation<T2>(mObject);
		}
	};
}

#endif
