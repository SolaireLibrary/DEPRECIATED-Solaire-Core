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
        virtual void SOLAIRE_EXPORT_CALL writeU8(const uint8_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeU16(const uint16_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeU32(const uint32_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeU64(const uint64_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeI8(const int8_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeI16(const int16_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeI32(const int32_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeI64(const int64_t) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeF(const float) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeD(const double) throw() = 0;
        virtual void SOLAIRE_EXPORT_CALL writeC(const char) throw() = 0;
    public:
        virtual SOLAIRE_EXPORT_CALL ~OStream(){}

        virtual void SOLAIRE_EXPORT_CALL write(const void* const, const uint32_t) throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL isOffsetable() const throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL getOffset() const throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL setOffset(const int32_t) throw() = 0;

        SOLAIRE_FORCE_INLINE OStream& operator<<(const uint8_t aValue) throw() {
            writeU8(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const uint16_t aValue) throw() {
            writeU16(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const uint32_t aValue) throw() {
            writeU32(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const uint64_t aValue) throw() {
            writeU64(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const int8_t aValue) throw() {
            writeI8(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const int16_t aValue) throw() {
            writeI16(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const int32_t aValue) throw() {
            writeI32(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const int64_t aValue) throw() {
            writeI64(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const float aValue) throw() {
            writeF(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const double aValue) throw() {
            writeD(aValue);
            return *this;
        }

        SOLAIRE_FORCE_INLINE OStream& operator<<(const char aValue) throw() {
            writeC(aValue);
            return *this;
        }
    };

}

#endif
