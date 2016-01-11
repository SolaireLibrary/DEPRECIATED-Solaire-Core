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

#include "Solaire/Core/AllocatorI.hpp"

namespace Solaire {

	template<class T>
	struct SharedObject {
        AllocatorI& Allocator_;
        T* Object;
        uint16_t Count;

        SharedObject(AllocatorI& aAllocator, T* const aObject) :
            Allocator_(aAllocator),
            Object(aObject),
            Count(0)
        {}

        ~SharedObject() {
            if(Object) {
                Object->~T();
                Allocator_.Deallocate(Object);
            }
        }
	};

	template<class T>
	class SharedAllocation {
	public:
		template<class T2>
		friend class SharedAllocation;
	private:
		SharedObject<T>* mObject;
	private:
		bool DeleteObject() throw() {
		    if(mObject == nullptr) return false;
		    --mObject->Count;
		    if(mObject->Count == 0) {
                mObject->~SharedObject();
                mObject->Allocator_.Deallocate(mObject);
		    }
		    mObject = nullptr;
		    return true;
		}

	public:
		SharedAllocation() throw() :
			mObject(nullptr)
		{}

		SharedAllocation(AllocatorI& aAllocator, T* const aObject) throw() :
			mObject(new(aAllocator.Allocate(sizeof(SharedObject<T>))) SharedObject<T>(aAllocator, aObject))
		{
		    ++mObject->Count;
		}

		SharedAllocation(const SharedAllocation<T>& aOther) throw() :
			mObject(aOther.mObject)
		{
			if(mObject) ++mObject->Count;
		}

		SharedAllocation(SharedAllocation<T>&& aOther) throw() :
			mObject(aOther.mObject)
		{
			aOther.mObject = nullptr;
		}

		/*template<class T2>
		SharedAllocation(const SharedAllocation<T2>& aOther) throw() :
			mObject(aOther.mObject)
		{
			++mObject->Count;
		}

		template<class T2>
		SharedAllocation(SharedAllocation<T2>&& aOther) throw() :
			mObject(aOther.mObject)
		{
			aOther.mObject = nullptr;
		}*/

		~SharedAllocation() throw() {
			DeleteObject();
		}

		SharedAllocation& operator=(const SharedAllocation<T>& aOther) throw() {
			DeleteObject();
			mObject = aOther.mObject;
			++mObject->Count;
			return *this;
		}

		SharedAllocation& operator=(SharedAllocation<T>&& aOther) throw() {
			Swap(aOther);
			return *this;
		}

		template<class T2>
		SharedAllocation& operator=(const SharedAllocation<T2>& aOther) throw() {
			DeleteObject();
			mObject = aOther.mObject;
			++mObject->Count;
			return *this;
		}

		void Swap(SharedAllocation<T>& aOther) throw() {
			std::swap(mObject, aOther.mObject);
		}

		T* ReleaseOwnership() throw() {
			if(mObject == nullptr) return nullptr;
			if(mObject->Count != 1) return nullptr;

			T* const tmp = mObject->Object;
			DeleteObject();
			return tmp;
		}

		AllocatorI& GetAllocator() const throw() {
			return mObject->Allocator_;
		}

		uint32_t GetUserCount() const throw() {
			return mObject == nullptr ? 0 : mObject->Count;
		}

		operator bool() const throw() {
			return mObject != nullptr;
		}

		T& operator*() const throw() {
			return *(mObject->Object);
		}

		T* operator->() const throw() {
			return mObject == nullptr ? nullptr : mObject->Object;
		}
	};
}

#endif
