#ifndef SOLAIRE_ISTREAM_HPP
#define SOLAIRE_ISTREAM_HPP

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
	\file IStream.hpp
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

	SOLAIRE_EXPORT_INTERFACE IStream {
    private:
        virtual uint8_t SOLAIRE_EXPORT_CALL readU8() throw() = 0;
        virtual uint16_t SOLAIRE_EXPORT_CALL readU16() throw() = 0;
        virtual uint32_t SOLAIRE_EXPORT_CALL readU32() throw() = 0;
        virtual uint64_t SOLAIRE_EXPORT_CALL readU64() throw() = 0;
        virtual int8_t SOLAIRE_EXPORT_CALL readI8() throw() = 0;
        virtual int16_t SOLAIRE_EXPORT_CALL readI16() throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL readI32() throw() = 0;
        virtual int64_t SOLAIRE_EXPORT_CALL readI64() throw() = 0;
        virtual float SOLAIRE_EXPORT_CALL readF() throw() = 0;
        virtual double SOLAIRE_EXPORT_CALL readD() throw() = 0;
        virtual char SOLAIRE_EXPORT_CALL readC() throw() = 0;
    public:
        virtual SOLAIRE_EXPORT_CALL ~IStream(){}

        virtual void SOLAIRE_EXPORT_CALL read(void* const, const uint32_t) throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL isOffsetable() const throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL getOffset() const throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL setOffset(const int32_t) throw() = 0;
        virtual bool SOLAIRE_EXPORT_CALL end() const throw() = 0;

        SOLAIRE_FORCE_INLINE IStream& operator>>(uint8_t& aValue) throw() {
            aValue = readU8();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(uint16_t& aValue) throw() {
            aValue = readU16();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(uint32_t& aValue) throw() {
            aValue = readU32();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(uint64_t& aValue) throw() {
            aValue = readU64();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(int8_t& aValue) throw() {
            aValue = readI8();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(int16_t& aValue) throw() {
            aValue = readI16();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(int32_t& aValue) throw() {
            aValue = readI32();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(int64_t& aValue) throw() {
            aValue = readI64();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(float& aValue) throw() {
            aValue = readF();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(double& aValue) throw() {
            aValue = readD();
            return *this;
        }

        SOLAIRE_FORCE_INLINE IStream& operator>>(char& aValue) throw() {
            aValue = readC();
            return *this;
        }
    };

}

#endif
