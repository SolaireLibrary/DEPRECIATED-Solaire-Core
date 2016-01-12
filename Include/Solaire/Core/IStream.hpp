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
        virtual uint8_t SOLAIRE_EXPORT_CALL ReadU8() throw() = 0;
        virtual uint16_t SOLAIRE_EXPORT_CALL ReadU16() throw() = 0;
        virtual uint32_t SOLAIRE_EXPORT_CALL ReadU32() throw() = 0;
        virtual uint64_t SOLAIRE_EXPORT_CALL ReadU64() throw() = 0;
        virtual int8_t SOLAIRE_EXPORT_CALL ReadI8() throw() = 0;
        virtual int16_t SOLAIRE_EXPORT_CALL ReadI16() throw() = 0;
        virtual int32_t SOLAIRE_EXPORT_CALL ReadI32() throw() = 0;
        virtual int64_t SOLAIRE_EXPORT_CALL ReadI64() throw() = 0;
        virtual float SOLAIRE_EXPORT_CALL ReadF() throw() = 0;
        virtual double SOLAIRE_EXPORT_CALL ReadD() throw() = 0;
        virtual char SOLAIRE_EXPORT_CALL ReadC() throw() = 0;
    public:
        virtual SOLAIRE_EXPORT_CALL ~IStream(){}

        virtual void SOLAIRE_EXPORT_CALL Read(void* const, const uint32_t) throw() = 0;

        SOLAIRE_FORCE_INLINE void operator>>(uint8_t& aValue) throw() {
            aValue = ReadU8();
        }

        SOLAIRE_FORCE_INLINE void operator>>(uint16_t& aValue) throw() {
            aValue = ReadU16();
        }

        SOLAIRE_FORCE_INLINE void operator>>(uint32_t& aValue) throw() {
            aValue = ReadU32();
        }

        SOLAIRE_FORCE_INLINE void operator>>(uint64_t& aValue) throw() {
            aValue = ReadU64();
        }

        SOLAIRE_FORCE_INLINE void operator>>(int8_t& aValue) throw() {
            aValue = ReadI8();
        }

        SOLAIRE_FORCE_INLINE void operator>>(int16_t& aValue) throw() {
            aValue = ReadI16();
        }

        SOLAIRE_FORCE_INLINE void operator>>(int32_t& aValue) throw() {
            aValue = ReadI32();
        }

        SOLAIRE_FORCE_INLINE void operator>>(int64_t& aValue) throw() {
            aValue = ReadI64();
        }

        SOLAIRE_FORCE_INLINE void operator>>(float& aValue) throw() {
            aValue = ReadF();
        }

        SOLAIRE_FORCE_INLINE void operator>>(double& aValue) throw() {
            aValue = ReadD();
        }

        SOLAIRE_FORCE_INLINE void operator>>(char& aValue) throw() {
            aValue = ReadC();
        }
    };

}

#endif
