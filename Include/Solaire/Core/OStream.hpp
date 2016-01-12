#ifndef SOLAIRE_OSTREAM_HPP
#define SOLAIRE_OSTREAM_HPP

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
	\file OStream.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\date
	Created			: 20th November 2015
	Last Modified	: 12th January 2016
*/

#include <cstdint>
#include "Solaire/Core/ModuleHeader.hpp"

namespace Solaire {

	SOLAIRE_EXPORT_INTERFACE OStream {
    private:
        virtual void SOLAIRE_EXPORT_CALL WriteU8(const uint8_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteU16(const uint16_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteU32(const uint32_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteU64(const uint64_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteI8(const int8_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteI16(const int16_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteI32(const int32_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteI64(const int64_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteF(const float) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteD(const double) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL WriteC(const char) throw() = 0;
    public:
        virtual SOLAIRE_EXPORT_CALL ~OStream(){}

        virtual void SOLAIRE_EXPORT_CALL Write(const void* const, const uint32_t) throw() = 0;

        SOLAIRE_FORCE_INLINE void operator<<(const uint8_t aValue) throw() {
            WriteU8(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const uint16_t aValue) throw() {
            WriteU16(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const uint32_t aValue) throw() {
            WriteU32(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const uint64_t aValue) throw() {
            WriteU64(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const int8_t aValue) throw() {
            WriteI8(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const int16_t aValue) throw() {
            WriteI16(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const int32_t aValue) throw() {
            WriteI32(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const int64_t aValue) throw() {
            WriteI64(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const float aValue) throw() {
            WriteF(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const double aValue) throw() {
            WriteD(aValue);
        }

        SOLAIRE_FORCE_INLINE void operator<<(const char aValue) throw() {
            WriteC(aValue);
        }
    };

}

#endif
