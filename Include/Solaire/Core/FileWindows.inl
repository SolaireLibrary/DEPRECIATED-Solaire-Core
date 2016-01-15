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
	\file FileWindows.inl
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\version 1.0
	\date
	Created			: 20th November 2015
	Last Modified	: 15th January 2016
*/

namespace Solaire { namespace File {

    namespace Implementation {

        const char* const makeCString(const StringConstant<char>& aString, char* aPath) {
            const int32_t size = aString.size();
            aPath[size] = '\0';
            if(aString.isContiguous()) {
                std::memcpy(aPath, &aString[0], size);
            }else {
                for(int32_t i = 0; i < size; ++i) aPath[i] = aString[i];
            }
            return aPath;
        }

         bool openFile(const StringConstant<char>& aFilename, HANDLE& aHandle, const int32_t aFlags) {
            char filename[MAX_PATH_LENGTH + 1];
            Implementation::makeCString(aFilename, filename);
            const HANDLE handle = CreateFileA(
                filename,
                aFlags,
                0,
                nullptr,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                nullptr
            );

            return handle != INVALID_HANDLE_VALUE;
        }

         bool openRFile(const StringConstant<char>& aFilename, HANDLE& aHandle) {
            return openFile(aFilename, aHandle, GENERIC_READ);
        }

         bool openWFile(const StringConstant<char>& aFilename, HANDLE& aHandle) {
            return openFile(aFilename, aHandle, GENERIC_WRITE);
        }

         bool openRWFile(const StringConstant<char>& aFilename, HANDLE& aHandle) {
            return openFile(aFilename, aHandle, GENERIC_READ | GENERIC_WRITE);
        }

        bool closeFile(HANDLE& aHandle) {
            return CloseHandle(aHandle);
        }
    }

    AttributeFlags SOLAIRE_EXPORT_CALL getAttributes(const StringConstant<char>& aFilename) throw() {
        char buffer[MAX_PATH_LENGTH + 1];
        const char* const filename = Implementation::makeCString(aFilename, buffer);

        const DWORD attributes = GetFileAttributesA(filename);
        DWORD binaryType;
        const BOOL executable = GetBinaryTypeA(filename, &binaryType);

        AttributeFlags tmp = FLAG_NONE;
        if(attributes & FILE_ATTRIBUTE_HIDDEN) tmp |= FLAG_HIDDEN;
        if(attributes & FILE_ATTRIBUTE_DIRECTORY) tmp |= FLAG_DIRECTORY;
        else tmp |= FLAG_FILE;
        if(attributes & FILE_ATTRIBUTE_READONLY) tmp |= FLAG_READ;
        else tmp |= FLAG_READ | FLAG_WRITE;
        if(executable) tmp |= FLAG_EXECUTABLE;
        if(tmp != FLAG_NONE) tmp |= FLAG_EXISTS;

        return tmp;
    }

    bool SOLAIRE_EXPORT_CALL createFile(const StringConstant<char>& aFilename, const AttributeFlags aAttributes) throw() {
        char buffer[MAX_PATH_LENGTH + 1];
        const char* const filename = Implementation::makeCString(aFilename, buffer);

        DWORD access = 0;
        if(aAttributes & FLAG_READ) access |= GENERIC_READ;
        if(aAttributes & FLAG_WRITE) access |= GENERIC_WRITE;

        DWORD flags = 0;
        if(aAttributes & FLAG_HIDDEN) flags |= FILE_ATTRIBUTE_HIDDEN;
        if((aAttributes & FLAG_READ) != 0 && (aAttributes & FLAG_WRITE) == 0) flags |= FILE_ATTRIBUTE_READONLY;
        if(flags == 0) flags = FILE_ATTRIBUTE_NORMAL;

        const HANDLE handle = CreateFileA(
            filename,
            access,
            0,
            nullptr,
            CREATE_NEW,
            flags,
            nullptr
        );

        if(handle != INVALID_HANDLE_VALUE) {
            CloseHandle(handle);
            return true;
        }else {
            return false;
        }
    }

    bool SOLAIRE_EXPORT_CALL createDirectory(const StringConstant<char>& aFilename) throw() {
        char buffer[MAX_PATH_LENGTH + 1];
        return CreateDirectoryA(Implementation::makeCString(aFilename, buffer), nullptr) > 0;
    }

    bool SOLAIRE_EXPORT_CALL deleteFile(const StringConstant<char>& aFilename) throw() {
        char buffer[MAX_PATH_LENGTH + 1];
        return DeleteFileA(Implementation::makeCString(aFilename, buffer)) > 0;
    }

    bool SOLAIRE_EXPORT_CALL deleteDirectory(const StringConstant<char>& aFilename) throw() {
        char buffer[MAX_PATH_LENGTH + 1];
        return DeleteFileA(Implementation::makeCString(aFilename, buffer)) > 0;
    }

    STLString SOLAIRE_EXPORT_CALL getParent(const StringConstant<char>& aFilename) throw() {
        const int32_t length = aFilename.size();
        const int32_t seperator = aFilename.findLastOf(FILE_SEPERATOR);

        STLString path;
        if(seperator != length) for(int32_t i = 0; i <= seperator; ++i) path.pushBack(aFilename[i]);
        return path;
    }

    STLString SOLAIRE_EXPORT_CALL getName(const StringConstant<char>& aFilename) throw() {
        const int32_t length = aFilename.size();
        const int32_t seperator = aFilename.findLastOf(FILE_SEPERATOR);
        const int32_t end = aFilename.findLastOf('.');

        if(seperator == length) {
            return STLString();
        }else {
            STLString tmp;
            for(int32_t i = seperator + 1; i < end; ++i) tmp.pushBack(aFilename[i]);
            return tmp;
        }
    }

    STLString SOLAIRE_EXPORT_CALL getExtension(const StringConstant<char>& aFilename) throw() {
        const int32_t length = aFilename.size();
        const int32_t seperator = aFilename.findLastOf('.');

        if(seperator == length) {
            return STLString();
        }else {
            STLString tmp;
            for(int32_t i = 0; i <= seperator; ++i) tmp.pushBack(aFilename[i]);
            return tmp;
        }
    }

    int32_t SOLAIRE_EXPORT_CALL size(const StringConstant<char>& aFilename) throw() {
        HANDLE handle;
        if(! Implementation::openRFile(aFilename, handle)) return 0;
        const int32_t size = GetFileSize(handle, nullptr);
        Implementation::closeFile(handle);
        return size;
    }

    bool SOLAIRE_EXPORT_CALL getFileList(const StringConstant<char>& aDirectory, Stack<STLString>& aFiles) throw() {
        WIN32_FIND_DATAA findData;
        HANDLE handle = INVALID_HANDLE_VALUE;

        char directory[MAX_PATH_LENGTH + 1];
        Implementation::makeCString(aDirectory, directory);

        uint32_t fileCount = 0;

        handle = FindFirstFileA(directory, &findData);
        if (handle == INVALID_HANDLE_VALUE) return 0;
        do{
            aFiles.pushBack(STLString(findData.cFileName));
        } while(FindNextFileA(handle, &findData) != 0);

        FindClose(handle);

        return fileCount;
    }

    STLString SOLAIRE_EXPORT_CALL getCurrentDirectory() throw() {
        char buffer[MAX_PATH_LENGTH + 1];
        const bool tmp = GetCurrentDirectoryA(MAX_PATH_LENGTH, buffer);
        return tmp ? STLString(buffer) : STLString();
    }

    STLString SOLAIRE_EXPORT_CALL getTemporaryDirectory() throw() {
        char buffer[MAX_PATH_LENGTH + 1];
        const bool tmp = GetTempPathA(MAX_PATH_LENGTH, buffer);
        return tmp ? STLString(buffer) : STLString();
    }

    bool SOLAIRE_EXPORT_CALL rename(const StringConstant<char>& aOldName, const StringConstant<char>& aNewName) throw() {
        //! \todo Optimise Rename
        if(! copy(aOldName, aNewName)) return false;
        if(! deleteFile(aOldName)){
            return deleteFile(aNewName);
        }
        return true;
    }

    bool SOLAIRE_EXPORT_CALL copy(const StringConstant<char>& aSrc, const StringConstant<char>& aDst) throw() {
        char bufferA[MAX_PATH_LENGTH + 1];
        char bufferB[MAX_PATH_LENGTH + 1];
        return CopyFileA(Implementation::makeCString(aSrc, bufferA), Implementation::makeCString(aDst, bufferB), FALSE) > 0;
    }

    bool SOLAIRE_EXPORT_CALL move(const StringConstant<char>& aFilename, const StringConstant<char>& aTarget) throw() {
        char bufferA[MAX_PATH_LENGTH + 1];
        char bufferB[MAX_PATH_LENGTH + 1];
        return MoveFileA(Implementation::makeCString(aFilename, bufferA), Implementation::makeCString(aTarget, bufferB)) > 0;
    }
}}
