#ifndef SOLAIRE_STRING_HPP
#define SOLAIRE_STRING_HPP

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
	\file String.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\date
	Created			: 10th December 2015
	Last Modified	: 15th January 2016
*/

#include "Solaire/Core/Container.hpp"

namespace Solaire {

    template<class T>
	using StringConstant = StaticContainer<T>;

    template<class T>
	SOLAIRE_EXPORT_INTERFACE String : public List<T> {
    public:
        SOLAIRE_EXPORT_CALL ~String() throw() {}

        template<size_t LENGTH>
        String<T>& operator+=(const T(&aString)[LENGTH]) throw() {
            for(int32_t i = 0; i < LENGTH; ++i) this->pushBack(aString[i]);
            return *this;
        };

        String<T>& operator+=(const T aValue) throw() {
            this->pushBack(aValue);
            return *this;
        };

        String<T>& operator+=(const StringConstant<T>& aString) throw() {
            const int32_t length = aString.size();
            for(int32_t i = 0; i < length; ++i) this->pushBack(aString[i]);
            return *this;
        };

        String<T>& operator+=(int8_t aValue) throw() {
            return operator+=(static_cast<int32_t>(aValue));
        };

        String<T>& operator+=(int16_t aValue) throw() {
            return operator+=(static_cast<int32_t>(aValue));
        };

        String<T>& operator+=(int32_t aValue) throw() {
            char buf[32];
            int i = 30;
            for(i; aValue && i ; --i, aValue /= 10) buf[i] = "0123456789abcdef"[aValue % 10];
            for(i; i < 30; ++i) this->pushBack(buf[i]);
            return *this;
        };

        String<T>& operator+=(int64_t aValue) throw() {
            //! \bug Values outside range of int32_t are lost
            return operator+=(static_cast<int32_t>(aValue));
        };

        String<T>& operator+=(uint8_t aValue) throw() {
            return operator+=(static_cast<int32_t>(aValue));
        };

        String<T>& operator+=(uint16_t aValue) throw() {
            return operator+=(static_cast<int32_t>(aValue));
        };

        String<T>& operator+=(uint32_t aValue) throw() {
            //! \bug Values outside range of int32_t are lost
            return operator+=(static_cast<int32_t>(aValue));
        };

        String<T>& operator+=(uint64_t aValue) throw() {
            //! \bug Values outside range of int32_t are lost
            return operator+=(static_cast<int32_t>(aValue));
        };

	};


}


#endif
