#ifndef SOLAIRE_FILE_HPP
#define SOLAIRE_FILE_HPP

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
	\file File.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\version 1.0
	\date
	Created			: 20th November 2015
	Last Modified	: 15th January 2016
*/

#include <cstdint>
#include "Solaire\Core\Maths.hpp"
#include "Solaire\Core\Container.hpp"
#include "Solaire\Core\STLString.hpp"

namespace Solaire {
    namespace FileImplementation {

        typedef uint8_t AttributeFlags;

        enum : AttributeFlags {
            FLAG_READ			= BIT_0,
            FLAG_WRITE			= BIT_1,
            FLAG_EXECUTABLE		= BIT_2,
            FLAG_HIDDEN			= BIT_3,
            FLAG_FILE			= BIT_4,
            FLAG_DIRECTORY		= BIT_5,
            FLAG_EXISTS			= BIT_6,

            FLAG_NONE			= 0,
            FLAG_READ_WRITE		= FLAG_READ | FLAG_WRITE
        };

        enum {
            MAX_PATH_LENGTH = 512
        };

        enum : char {
            #if SOLAIRE_OS == SOLAIRE_WINDOWS
                FILE_SEPERATOR = '\\'
            #else
                FILE_SEPERATOR = '/'
            #endif
        };

        static AttributeFlags SOLAIRE_EXPORT_CALL getAttributes(const StringConstant<char>&) throw();

        static bool SOLAIRE_EXPORT_CALL createFile(const StringConstant<char>&, const AttributeFlags) throw();
        static bool SOLAIRE_EXPORT_CALL createDirectory(const StringConstant<char>&) throw();
        static bool SOLAIRE_EXPORT_CALL deleteFile(const StringConstant<char>&) throw();
        static bool SOLAIRE_EXPORT_CALL deleteDirectory(const StringConstant<char>&) throw();

        static STLString SOLAIRE_EXPORT_CALL getParent(const StringConstant<char>&) throw();
        static STLString SOLAIRE_EXPORT_CALL getName(const StringConstant<char>&) throw();
        static STLString SOLAIRE_EXPORT_CALL getExtension(const StringConstant<char>&) throw();

        static int32_t SOLAIRE_EXPORT_CALL size(const StringConstant<char>&) throw();

        static bool SOLAIRE_EXPORT_CALL getFileList(const StringConstant<char>&, Stack<STLString>&) throw();
        static STLString SOLAIRE_EXPORT_CALL getCurrentDirectory() throw();
        static STLString SOLAIRE_EXPORT_CALL getTemporaryDirectory() throw();

        static bool SOLAIRE_EXPORT_CALL rename(const StringConstant<char>&, const StringConstant<char>&) throw();
        static bool SOLAIRE_EXPORT_CALL copy(const StringConstant<char>&, const StringConstant<char>&) throw();
        static bool SOLAIRE_EXPORT_CALL move(const StringConstant<char>&, const StringConstant<char>&) throw();
    }

}

#if SOLAIRE_OS == SOLAIRE_WINDOWS
    #include "Solaire/Core/FileWindows.inl"
#else
    #error SolaireCpp : File I/O only implemented for windows
#endif

#endif
