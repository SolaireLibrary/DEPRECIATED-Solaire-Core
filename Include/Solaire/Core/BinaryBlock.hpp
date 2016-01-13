#ifndef SOLAIRE_BINARY_BLOCK_HPP
#define SOLAIRE_BINARY_BLOCK_HPP

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
	\file BinaryBlock.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\date
	Created			: 13th January 2016
	Last Modified	: 13th January 2016
*/

#include <cstdint>

namespace Solaire {

    static constexpr bool binaryBlockFn(const int8_t aBytes, const int8_t aMin, const int8_t aMax) throw() {
        return aBytes >= aMin && aBytes < aMax;
    }

    template<const uint32_t BYTES>
    struct ByteArray {
    private:
        uint8_t mBytes[BYTES];
    };

    template<const uint32_t BYTES, const bool SIGN, typename ENABLE = void>
    struct BinaryBlockStruct {
        typedef ByteArray<BYTES> Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 33, 65) && ! SIGN>::type> {
        typedef uint64_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 17, 33) && ! SIGN>::type> {
        typedef uint32_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 9, 17) && ! SIGN>::type> {
        typedef uint16_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 0, 9) && ! SIGN>::type> {
        typedef uint8_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 33, 65) && SIGN>::type> {
        typedef int64_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 17, 33) && SIGN>::type> {
        typedef int32_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 9, 17) && SIGN>::type> {
        typedef int16_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    struct BinaryBlockStruct<BYTES, SIGN, typename std::enable_if<binaryBlockFn(BYTES, 0, 9) && SIGN>::type> {
        typedef int8_t Type;
    };

    template<const uint32_t BYTES, const bool SIGN>
    using BinaryBlock = typename BinaryBlockStruct<BYTES, SIGN>::Type;
}


#endif
