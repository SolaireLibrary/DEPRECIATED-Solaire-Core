#ifndef SOLAIRE_STLSTRING_HPP
#define SOLAIRE_STLSTRING_HPP

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
	\file STLString.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\date
	Created			: 15th January 2016
	Last Modified	: 15th January 2016
*/

#include <string>
#include "Solaire/Core/NewAllocator.hpp"
#include "Solaire/Core/String.hpp"

namespace Solaire{

    class STLString : public String<char> {
	public:
		typedef char Type;
		typedef const char ConstType;
		typedef Type& Reference;
		typedef ConstType& ConstReference;
		typedef Type&& Move;
		typedef Type* Pointer;
		typedef ConstType* ConstPointer;
		typedef uint32_t Index;
		typedef STLString Self;
	private:
	    std::string mString;
    protected:
        // Inherited from StaticContainer

        Pointer SOLAIRE_EXPORT_CALL getPtr(int32_t aOffset) throw() override {
            return const_cast<Pointer>(mString.c_str() + aOffset);
        }

        SharedAllocation<Iterator<Type>> SOLAIRE_EXPORT_CALL begin_() throw() override {
            //! \todo Implement iterators for STLString
            return SharedAllocation<Iterator<Type>>();
        }

        SharedAllocation<Iterator<Type>> SOLAIRE_EXPORT_CALL end_() throw() override {
            //! \todo Implement iterators for STLString
            return SharedAllocation<Iterator<Type>>();
        }

        SharedAllocation<Iterator<Type>> SOLAIRE_EXPORT_CALL rbegin_() throw() override {
            //! \todo Implement iterators for STLString
            return SharedAllocation<Iterator<Type>>();
        }

        SharedAllocation<Iterator<Type>> SOLAIRE_EXPORT_CALL rend_() throw() override {
            //! \todo Implement iterators for STLString
            return SharedAllocation<Iterator<Type>>();
        }

    public:
        STLString() :
            mString()
        {}

        STLString(const Self& aOther) :
            mString(aOther.mString)
        {}

        STLString(Self&& aOther) :
            mString(std::move(aOther.mString))
        {}

        template<size_t LENGTH>
        STLString(const Type(&aString)[LENGTH]) :
            mString(aString)
        {}

        STLString(const std::string& aOther) :
            mString(aOther)
        {}

        SOLAIRE_EXPORT_CALL ~STLString() {

        }

        Self& operator=(const Self& aOther) {
            mString = aOther.mString;
            return *this;
        }

        Self& operator=(Self&& aOther) {
            mString = std::move(aOther.mString);
            return *this;
        }

        operator std::string&() throw() {
            return mString;
        }

        operator const std::string&() const throw() {
            return mString;
        }

        // Inherited from StaticContainer

        bool SOLAIRE_EXPORT_CALL isContiguous() const throw() override {
            return true;
        }

        int32_t SOLAIRE_EXPORT_CALL size() const throw() override {
            return mString.size();
        }

        Allocator& SOLAIRE_EXPORT_CALL getAllocator() const throw() override {
            return DEFAULT_ALLOCATOR;
        }

        // Inherited from Stack

		Type& SOLAIRE_EXPORT_CALL pushBack(const Type& aValue) throw() override {
		    mString += aValue;
            return mString.back();
        }

		Type SOLAIRE_EXPORT_CALL popBack() throw() {
		    Type tmp = mString.back();
		    mString.pop_back();
		    return tmp;
		}

		void SOLAIRE_EXPORT_CALL clear() throw() override {
            mString.clear();
        }

        // Inherited from Deque

		Type& SOLAIRE_EXPORT_CALL pushFront(const Type& aValue) throw() override {
		    mString = aValue + mString;
		    return mString.front();
		}

		Type SOLAIRE_EXPORT_CALL popFront() throw() override {
		    const char* const ptr = mString.c_str();
		    const char tmp = *ptr;
		    mString = ptr + 1;
		    return tmp;
		}

		// Inherited from List

		Type& SOLAIRE_EXPORT_CALL insertBefore(const int32_t aPos, const Type& aValue) throw() override {
            mString.insert(aPos, &aValue, 1);
		    return mString[aPos];
		}

		Type& SOLAIRE_EXPORT_CALL insertAfter(const int32_t aPos, const Type& aValue) throw() override {
            return insertBefore(aPos + 1, aValue);
		}

		bool SOLAIRE_EXPORT_CALL erase(const int32_t aPos) throw() override {
            mString.erase(aPos, 1);
            return true;
		}

	};
}

#endif
