#ifndef SOLAIRE_ITERATOR_HPP
#define SOLAIRE_ITERATOR_HPP

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
	\file Iterator.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\date
	Created			: 3rd December 2015
	Last Modified	: 10th January 2016
*/

#include <cstdint>
#include "Solaire/Core/ModuleHeader.hpp"
#include "Solaire/Core/SharedAllocation.hpp"

namespace Solaire {

	template<class T>
    SOLAIRE_EXPORT_INTERFACE Iterator {
    public:
        typedef T Type;
        typedef T* Pointer;
        typedef T& Reference;
        typedef const T* ConstPointer;
        typedef const T& ConstReference;
    protected:
        virtual Iterator<T>& SOLAIRE_EXPORT_CALL Increment(int32_t) throw() = 0;
        virtual Iterator<T>& SOLAIRE_EXPORT_CALL Decrement(int32_t) throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL Copy() const throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL GetOffset() const throw() = 0;
        virtual Pointer SOLAIRE_EXPORT_CALL GetPtr() throw() = 0;
    public:
        virtual SOLAIRE_EXPORT_CALL ~Iterator(){}

        // Iterator Type
        virtual bool SOLAIRE_EXPORT_CALL IsInputIterator() const throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL IsOutputIterator() const throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL IsForwardIterator() const throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL IsIterator() const throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL IsRandomAccessIterator() const throw() = 0;

        // Input Iterator

        SOLAIRE_FORCE_INLINE Iterator<T>& operator++() throw() {
            return Increment(1);
        }

        SOLAIRE_FORCE_INLINE SharedAllocation<Iterator<T>> operator++(int) throw() {
            SharedAllocation<Iterator<T>> tmp = Copy();
            tmp.Increment(1);
            return tmp;
        }

        SOLAIRE_FORCE_INLINE bool operator==(const Iterator<T>& aOther) const throw() {
            return aOther.GetOffset() == GetOffset();
        }

        SOLAIRE_FORCE_INLINE bool operator!=(const Iterator<T>& aOther) const throw() {
            return aOther.GetOffset() != GetOffset();
        }

        SOLAIRE_FORCE_INLINE ConstReference operator*() const throw() {
            return *const_cast<Iterator<T>*>(this)->GetPtr();
        }

        SOLAIRE_FORCE_INLINE ConstPointer operator->() const throw() {
            return const_cast<Iterator<T>*>(this)->GetPtr();
        }

        // Output Iterator

        SOLAIRE_FORCE_INLINE Reference operator*() throw() {
            return GetPtr();
        }

        SOLAIRE_FORCE_INLINE Pointer operator->() throw() {
            return GetPtr();
        }

        // Bidirectional Iterator

        SOLAIRE_FORCE_INLINE Iterator<T>& operator--() throw() {
            return Decrement(1);
        }

        SOLAIRE_FORCE_INLINE SharedAllocation<Iterator<T>> operator--(int) throw() {
            SharedAllocation<Iterator<T>> tmp = Copy();
            tmp.Decrement(1);
            return tmp;
        }

        // Random Access Iterator

        SOLAIRE_FORCE_INLINE Iterator<T>& operator+=(const int32_t aCount) throw() {
            return Increment(aCount);
        }

        SOLAIRE_FORCE_INLINE SharedAllocation<Iterator<T>> operator+(const int32_t aCount) throw() {
            SharedAllocation<Iterator<T>> tmp = Copy();
            tmp.Increment(aCount);
            return tmp;
        }

        SOLAIRE_FORCE_INLINE SharedAllocation<const Iterator<T>> operator+(const int32_t aCount) const throw() {
            SharedAllocation<Iterator<T>> tmp = Copy();
            tmp.Increment(aCount);
            return tmp;
        }

        SOLAIRE_FORCE_INLINE Iterator<T>& operator-=(const int32_t aCount) throw() {
            return Decrement(aCount);
        }

        SOLAIRE_FORCE_INLINE SharedAllocation<Iterator<T>> operator-(const int32_t aCount) throw() {
            SharedAllocation<Iterator<T>> tmp = Copy();
            tmp.Decrement(aCount);
            return tmp;
        }

        SOLAIRE_FORCE_INLINE SharedAllocation<const Iterator<T>> operator-(const int32_t aCount) const throw() {
            SharedAllocation<Iterator<T>> tmp = Copy();
            tmp.Decrement(aCount);
            return tmp;
        }

        SOLAIRE_FORCE_INLINE int32_t operator-(const Iterator<T>& aOther) const throw() {
            return GetOffset() - aOther.GetOffset();
        }

        SOLAIRE_FORCE_INLINE bool operator<(const Iterator<T>& aOther) const throw() {
            return aOther.GetOffset() < GetOffset();
        }

        SOLAIRE_FORCE_INLINE bool operator>(const Iterator<T>& aOther) const throw() {
            return aOther.GetOffset() > GetOffset();
        }

        SOLAIRE_FORCE_INLINE bool operator<=(const Iterator<T>& aOther) const throw() {
            return aOther.GetOffset() <= GetOffset();
        }

        SOLAIRE_FORCE_INLINE bool operator>=(const Iterator<T>& aOther) const throw() {
            return aOther.GetOffset() >= GetOffset();
        }
    };
}


#endif
