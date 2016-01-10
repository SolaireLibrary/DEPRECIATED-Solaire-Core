#ifndef SOLAIRE_CONTAINER_HPP
#define SOLAIRE_CONTAINER_HPP

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
	\file Container.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\date
	Created			: 3rd December 2015
	Last Modified	: 10th January 2016
*/

#include "Solaire/Core/Iterator.hpp"
#include "Solaire/Core/Allocator.hpp"

namespace Solaire {

	template<class T>
	SOLAIRE_EXPORT_INTERFACE StaticContainer {
    public:
        typedef T Type;
        typedef T* Pointer;
        typedef T& Reference;
        typedef const T* ConstPointer;
        typedef const T& ConstReference;
    protected:
        virtual Pointer SOLAIRE_EXPORT_CALL GetPtr(int32_t) throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL Begin() throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL End() throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL Rbegin() throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL Rend() throw() = 0;
    public:
        virtual SOLAIRE_EXPORT_CALL ~StaticContainer() throw() {}

        virtual bool SOLAIRE_EXPORT_CALL IsContiguous() const throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL Size() const throw() = 0;
        virtual Allocator& SOLAIRE_EXPORT_CALL GetAllocator() const throw() = 0;

        SOLAIRE_FORCE_INLINE Reference operator[](const int32_t aIndex) throw() {
            return *GetPtr(aIndex);
        }

        SOLAIRE_FORCE_INLINE ConstReference operator[](const int32_t aIndex) const throw() {
            return *const_cast<StaticContainer<T>*>(this)->GetPtr(aIndex);
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> begin() throw() {
            return STLIterator<T>(Begin());
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> end() throw() {
            return STLIterator<T>(End());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> begin() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->Begin());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> end() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->End());
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> rbegin() throw() {
            return STLIterator<T>(Rbegin());
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> rend() throw() {
            return STLIterator<T>(Rend());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> rbegin() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->Rbegin());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> rend() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->Rend());
        }
	};

	template<class T>
	SOLAIRE_EXPORT_INTERFACE Stack : public StaticContainer<T> {
	public:
		virtual  SOLAIRE_EXPORT_CALL ~Stack() throw() {}
		virtual T& SOLAIRE_EXPORT_CALL PushBack(const T&) throw() = 0;
		virtual T SOLAIRE_EXPORT_CALL PopBack() throw() = 0;
		virtual void SOLAIRE_EXPORT_CALL Clear() throw() = 0;

		SOLAIRE_FORCE_INLINE T& SOLAIRE_DEFAULT_CALL Back() throw() {
			return operator[](StaticContainer<T>::Size() - 1);
		}

		SOLAIRE_FORCE_INLINE const T& SOLAIRE_DEFAULT_CALL Back() const throw() {
			return operator[](StaticContainer<T>::Size() - 1);
		}
	};

	template<class T>
	SOLAIRE_EXPORT_INTERFACE Deque : public Stack<T> {
	public:
		virtual SOLAIRE_EXPORT_CALL ~Deque() throw() {}

		virtual T& SOLAIRE_EXPORT_CALL PushFront(const T&) throw() = 0;
		virtual T SOLAIRE_EXPORT_CALL PopFront() throw() = 0;

		SOLAIRE_FORCE_INLINE T& SOLAIRE_DEFAULT_CALL Front() throw() {
			return StaticContainer<T>::operator[](0);
		}

		SOLAIRE_FORCE_INLINE const T& SOLAIRE_DEFAULT_CALL Front() const throw() {
			return StaticContainer<T>::operator[](0);
		}
	};

	template<class T>
	SOLAIRE_EXPORT_INTERFACE List : public Deque<T> {
	public:
		virtual SOLAIRE_EXPORT_CALL ~List() throw() {}

		virtual T& SOLAIRE_EXPORT_CALL InsertBefore(const STLIterator<const T>, const T&) throw() = 0;
		virtual T& SOLAIRE_EXPORT_CALL InsertAfter(const STLIterator<const T>, const T&) throw() = 0;
		virtual bool SOLAIRE_EXPORT_CALL Erase(const STLIterator<const T>) throw() = 0;
	};

}


#endif
