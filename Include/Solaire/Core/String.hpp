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

	namespace Implementation {
        static constexpr char STRING_NUMERIC_CHARS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        static constexpr uint64_t constexprPower(const uint64_t aValue, const uint64_t aExponent) {
            return aExponent == 0 ? 1 : aExponent == 1 ? aValue : aValue * constexprPower(aValue, aExponent - 1);
        }

        static constexpr uint16_t POWERS_OF_10[] = {
            constexprPower(10, 0),
            constexprPower(10, 1),
            constexprPower(10, 2),
            constexprPower(10, 3),
            constexprPower(10, 4),
            constexprPower(10, 5),
            constexprPower(10, 6),
            constexprPower(10, 7),
            constexprPower(10, 8),
            constexprPower(10, 9),
            constexprPower(10, 10),
            constexprPower(10, 11),
            constexprPower(10, 12),
            constexprPower(10, 13),
            constexprPower(10, 14)
        };
	}

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
            return operator+=(static_cast<int64_t>(aValue));
        };

        String<T>& operator+=(int16_t aValue) throw() {
            return operator+=(static_cast<int64_t>(aValue));
        };

        String<T>& operator+=(int32_t aValue) throw() {
            return operator+=(static_cast<int64_t>(aValue));
        };

        String<T>& operator+=(int64_t aValue) throw() {
            if(aValue < 0) {
                this->pushBack('-');
                return operator+=(static_cast<uint64_t>(aValue * -1));
            }else {
                return operator+=(static_cast<uint64_t>(aValue));
            }
        };

        String<T>& operator+=(uint8_t aValue) throw() {
            return operator+=(static_cast<uint64_t>(aValue));
        };

        String<T>& operator+=(uint16_t aValue) throw() {
            return operator+=(static_cast<uint64_t>(aValue));
        };

        String<T>& operator+=(uint32_t aValue) throw() {
            return operator+=(static_cast<uint64_t>(aValue));
        }

        template<const uint32_t BASE = 10, const char* CHARACTERS = Implementation::STRING_NUMERIC_CHARS>
        String<T>& operator+=(uint64_t aValue) throw() {
            if(aValue == 0){
                this->pushBack(CHARACTERS[0]);
            }else{
                char buf[130];
                uint32_t i = 128;
                for(i; aValue && i ; --i, aValue /= BASE) buf[i] = CHARACTERS[aValue % BASE];
                ++i;
                for(i; i <= 128; ++i) this->pushBack(buf[i]);
            }
            return *this;
        };

        explicit operator uint64_t() const throw() {
            //! \todo Support different bases
            int32_t begin = 0;
            const int32_t end = this->size();
            while(begin < end && this->operator[](begin) == '0') {
                ++begin;
            }

            uint64_t value = 0;
            uint8_t col = 0;
            for(uint32_t i = begin; i < end; ++i, ++col) {
                const char c = this->operator[](end - (i + 1));
                if(c < '0' || c > '9') break;
                value += static_cast<uint64_t>(c - '0') * Implementation::POWERS_OF_10[col];
            }

            return value;
        }

        explicit operator uint32_t() const throw() {
            return static_cast<uint32_t>(static_cast<uint64_t>(*this));
        }

        explicit operator uint16_t() const throw() {
            return static_cast<uint16_t>(static_cast<uint64_t>(*this));
        }

        explicit operator uint8_t() const throw() {
            return static_cast<uint8_t>(static_cast<uint64_t>(*this));
        }

        explicit operator int64_t() const throw() {
            //! \bug Does not parse last column
            //! \todo Support different bases
            bool sign = false;
            int32_t begin = 0;
            const int32_t end = this->size();
            if(begin < end && this->operator[](begin) == '-'){
                sign = true;
                ++begin;
            }
            while(begin < end && this->operator[](begin) == '0') {
                ++begin;
            }

            int64_t value = 0;
            uint8_t col = 0;
            for(uint32_t i = begin; i < end; ++i, ++col) {
                const char c = this->operator[](end - (i + 1));
                if(c < '0' || c > '9') break;
                value += static_cast<int64_t>(c - '0') * Implementation::POWERS_OF_10[col];
            }

            return sign ? value * -1 : value;
        }

        explicit operator int32_t() const throw() {
            return static_cast<int32_t>(static_cast<int64_t>(*this));
        }

        explicit operator int16_t() const throw() {
            return static_cast<int16_t>(static_cast<int64_t>(*this));
        }

        explicit operator int8_t() const throw() {
            return static_cast<int8_t>(static_cast<int64_t>(*this));
        }

	};


}


#endif
