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

        void operator+=(const StringConstant<T>& aString) throw() {
            const int32_t length = aString.size();
            for(int32_t i = 0; i < length; ++i) this->pushBack(aString[i]);
            return *this;
        };

	};


}


#endif
