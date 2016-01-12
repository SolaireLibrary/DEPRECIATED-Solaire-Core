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
        virtual Pointer SOLAIRE_EXPORT_CALL getPtr(int32_t) throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL begin_() throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL end_() throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL rbegin_() throw() = 0;
        virtual SharedAllocation<Iterator<T>> SOLAIRE_EXPORT_CALL rend_() throw() = 0;
    public:
        virtual SOLAIRE_EXPORT_CALL ~StaticContainer() throw() {}

        virtual bool SOLAIRE_EXPORT_CALL isContiguous() const throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL size() const throw() = 0;
        virtual Allocator& SOLAIRE_EXPORT_CALL getAllocator() const throw() = 0;

        SOLAIRE_FORCE_INLINE Reference operator[](const int32_t aIndex) throw() {
            return *getPtr(aIndex);
        }

        SOLAIRE_FORCE_INLINE ConstReference operator[](const int32_t aIndex) const throw() {
            return *const_cast<StaticContainer<T>*>(this)->getPtr(aIndex);
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> begin() throw() {
            return STLIterator<T>(begin_());
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> end() throw() {
            return STLIterator<T>(end_());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> begin() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->begin_());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> end() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->end_());
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> rbegin() throw() {
            return STLIterator<T>(rbegin_());
        }

        SOLAIRE_FORCE_INLINE STLIterator<T> rend() throw() {
            return STLIterator<T>(rend_());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> rbegin() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->rbegin_());
        }

        SOLAIRE_FORCE_INLINE STLIterator<const T> rend() const throw() {
            return STLIterator<T>(const_cast<StaticContainer<T>*>(this)->rend_());
        }

        SOLAIRE_FORCE_INLINE operator StaticContainer<const T>&() throw() {
            return *reinterpret_cast<StaticContainer<const T>*>(this);
        }

        SOLAIRE_FORCE_INLINE operator const StaticContainer<const T>&() const throw() {
            return *reinterpret_cast<StaticContainer<const T>*>(this);
        }

        inline bool operator==(const StaticContainer<const T>& aOther) const throw() {
            const int32_t length = size();
            if(length != aOther.size()) return false;
            if(std::is_fundamental<T>::value && isContiguous() && aOther.isContiguous()) {
                return std::memcmp(getPtr(0), aOther.getPtr(0), sizeof(T) * length) == 0;
            }else {
                for(int32_t i = 0; i < length; ++i) {
                    if(getPtr(i) != aOther.getPtr(i)) return false;
                }
                return true;
            }
        }

        inline bool operator!=(const StaticContainer<const T>& aOther) const throw() {
            const int32_t length = size();
            if(length != aOther.size()) return true;
            if(std::is_fundamental<T>::value && isContiguous() && aOther.isContiguous()) {
                return std::memcmp(getPtr(0), aOther.getPtr(0), sizeof(T) * length) != 0;
            }else {
                for(int32_t i = 0; i < length; ++i) {
                    if(getPtr(i) != aOther.getPtr(i)) return true;
                }
                return false;
            }
        }

        SOLAIRE_FORCE_INLINE int32_t findFirstOf(const T& aValue) const throw() {
            return findNextOf(0, aValue);
        }

        inline int32_t findNextOf(const int32_t aIndex, const T& aValue) const throw() {
            const int32_t length = size();
            if(isContiguous()) {
                const T* const ptr = getPtr(0);
                for(int32_t i = aIndex; i < length; ++i) {
                    if(ptr[i] == aValue) return i;
                }
            }else {
                for(int32_t i = aIndex; i < length; ++i) {
                    if(*getPtr(i) == aValue) return i;
                }
            }

            return length;
        }

        inline int32_t findLastOf(const T& aValue) const throw() {
            const int32_t end = size();
            int32_t i = findFirstOf(aValue);
            int32_t j = i;

            while(i != end) {
                j = i;
                i = findNextOf(i + 1, aValue);
            }

            return j;
        }
	};

	template<class T>
	SOLAIRE_EXPORT_INTERFACE Stack : public StaticContainer<T> {
	public:
		virtual  SOLAIRE_EXPORT_CALL ~Stack() throw() {}
		virtual T& SOLAIRE_EXPORT_CALL pushBack(const T&) throw() = 0;
		virtual T SOLAIRE_EXPORT_CALL popBack() throw() = 0;
		virtual void SOLAIRE_EXPORT_CALL clear() throw() = 0;

		SOLAIRE_FORCE_INLINE T& SOLAIRE_DEFAULT_CALL back() throw() {
			return StaticContainer<T>::operator[](StaticContainer<T>::size() - 1);
		}

		SOLAIRE_FORCE_INLINE const T& SOLAIRE_DEFAULT_CALL back() const throw() {
			return StaticContainer<T>::operator[](StaticContainer<T>::size() - 1);
		}

        SOLAIRE_FORCE_INLINE operator Stack<const T>&() throw() {
            return *reinterpret_cast<Stack<const T>*>(this);
        }

        SOLAIRE_FORCE_INLINE operator const Stack<const T>&() const throw() {
            return *reinterpret_cast<Stack<const T>*>(this);
        }
	};

	template<class T>
	SOLAIRE_EXPORT_INTERFACE Deque : public Stack<T> {
	public:
		virtual SOLAIRE_EXPORT_CALL ~Deque() throw() {}

		virtual T& SOLAIRE_EXPORT_CALL pushFront(const T&) throw() = 0;
		virtual T SOLAIRE_EXPORT_CALL popFront() throw() = 0;

		SOLAIRE_FORCE_INLINE T& SOLAIRE_DEFAULT_CALL front() throw() {
			return StaticContainer<T>::operator[](0);
		}

		SOLAIRE_FORCE_INLINE const T& SOLAIRE_DEFAULT_CALL front() const throw() {
			return StaticContainer<T>::operator[](0);
		}

        SOLAIRE_FORCE_INLINE operator Deque<const T>&() throw() {
            return *reinterpret_cast<Deque<const T>*>(this);
        }

        SOLAIRE_FORCE_INLINE operator const Deque<const T>&() const throw() {
            return *reinterpret_cast<Deque<const T>*>(this);
        }
	};

	template<class T>
	SOLAIRE_EXPORT_INTERFACE List : public Deque<T> {
	public:
		virtual SOLAIRE_EXPORT_CALL ~List() throw() {}

		virtual T& SOLAIRE_EXPORT_CALL insertBefore(const int32_t, const T&) throw() = 0;
		virtual T& SOLAIRE_EXPORT_CALL insertAfter(const int32_t, const T&) throw() = 0;
		virtual bool SOLAIRE_EXPORT_CALL erase(const int32_t) throw() = 0;

        SOLAIRE_FORCE_INLINE operator List<const T>&() throw() {
            return *reinterpret_cast<List<const T>*>(this);
        }

        SOLAIRE_FORCE_INLINE operator const List<const T>&() const throw() {
            return *reinterpret_cast<List<const T>*>(this);
        }
	};

	typedef StaticContainer<const char> StringConstant;
	typedef List<char> String;

}


#endif
