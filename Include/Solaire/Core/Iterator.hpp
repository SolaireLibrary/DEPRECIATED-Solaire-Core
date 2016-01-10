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
        virtual SOLAIRE_EXPORT_CALL ~Iterator() throw() {}

        virtual Iterator<T>& SOLAIRE_EXPORT_CALL Increment(int32_t) throw() = 0;
        virtual Iterator<T>& SOLAIRE_EXPORT_CALL Decrement(int32_t) throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL Copy() const throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL GetOffset() const throw() = 0;
        virtual T* SOLAIRE_EXPORT_CALL GetPtr() throw() = 0;
    };

    template<class T>
    class STLIterator {
    public:
        typedef T Type;
        typedef T* Pointer;
        typedef T& Reference;
        typedef const T* ConstPointer;
        typedef const T& ConstReference;
    private:
        SharedAllocation<Iterator<T>> mIterator;
    public:
        STLIterator(SharedAllocation<Iterator<T>> aIterator) throw() :
            mIterator(aIterator)
        {}

        ~STLIterator() throw() {

        }

        // Input Iterator

        STLIterator<T>& operator++() throw() {
            mIterator->Increment(1);
            return *this;
        }

        SharedAllocation<Iterator<T>> operator++(int) throw() {
            SharedAllocation<Iterator<T>> tmp = mIterator->Copy();
            Increment(1);
            return STLIterator<T>(tmp);
        }

        bool operator==(const STLIterator<T> aOther) const throw() {
            return aOther.mIterator->GetOffset() == mIterator->GetOffset();
        }

        bool operator!=(const STLIterator<T> aOther) const throw() {
            return aOther.mIterator->GetOffset() != mIterator->GetOffset();
        }

        ConstReference operator*() const throw() {
            return *const_cast<STLIterator<T>*>(this)->mIterator->GetPtr();
        }

        ConstPointer operator->() const throw() {
            return const_cast<STLIterator<T>*>(this)->mIterator->GetPtr();
        }

        // Output Iterator

        Reference operator*() throw() {
            return mIterator->GetPtr();
        }

        Pointer operator->() throw() {
            return mIterator->GetPtr();
        }

        // Bidirectional Iterator

        STLIterator<T>& operator--() throw() {
            mIterator->Decrement(1);
            return *this;
        }

        STLIterator<T> operator--(int) throw() {
            SharedAllocation<Iterator<T>> tmp = mIterator->Copy();
            Decrement(1);
            return STLIterator<T>(tmp);
        }

        // Random Access Iterator

        STLIterator<T>& operator+=(const int32_t aCount) throw() {
            mIterator->Increment(aCount);
            return *this;
        }

        STLIterator<T> operator+(const int32_t aCount) throw() {
            SharedAllocation<Iterator<T>> tmp = mIterator->Copy();
            tmp.Increment(aCount);
            return STLIterator(tmp);
        }

        STLIterator<T>& operator-=(const int32_t aCount) throw() {
            mIterator->Decrement(aCount);
            return *this;
        }

        STLIterator<T> operator-(const int32_t aCount) throw() {
            SharedAllocation<Iterator<T>> tmp = mIterator->Copy();
            tmp.Decrement(aCount);
            return STLIterator(tmp);
        }

        int32_t operator-(const STLIterator<T>&aOther) const throw() {
            return mIterator->GetOffset() - aOther.mIterator->GetOffset();
        }

        Reference operator[](const int32_t aOffset) throw() {
            SharedAllocation<Iterator<T>> tmp = mIterator->Copy();
            tmp.Increment(aOffset);
            return **tmp;
        }

        ConstReference operator[](const int32_t aOffset) const throw() {
            SharedAllocation<Iterator<T>> tmp = mIterator->Copy();
            tmp.Increment(aOffset);
            return **tmp;
        }

        bool operator<(const STLIterator<T> aOther) const throw() {
            return aOther.mIterator->GetOffset() < mIterator->GetOffset();
        }

        bool operator>(const STLIterator<T> aOther) const throw() {
            return aOther.mIterator->GetOffset() > mIterator->GetOffset();
        }

        bool operator<=(const STLIterator<T> aOther) const throw() {
            return aOther.mIterator->GetOffset() <= mIterator->GetOffset();
        }

        bool operator>=(const STLIterator<T> aOther) const throw() {
            return aOther.mIterator->GetOffset() >= mIterator->GetOffset();
        }
    };
}


#endif
