#include "Helper.h"
#include "InvalidPathException.h"

/*
 * Helper function to convert from system error returned by
 * GetLastError to string message.
 */
std::string Helper::GetLastErrorAsString()
{
	//Get the error message, if any.
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0)
		return std::string(); //No error message has been recorded

	LPSTR messageBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	std::string message(messageBuffer, size);

	//Free the buffer.
	LocalFree(messageBuffer);

	return message;
}

/*
 * Using FileAttributes to figure if the directory exist.
*/
bool Helper::IsDirectoryExist(const std::string& dirName) {

	DWORD dwError;
	DWORD dwFileType;

	dwFileType = GetFileAttributesA(dirName.c_str());
	dwError = GetLastError();

	/*
	if (dwError == ERROR_INVALID_NAME || dwError == ERROR_BAD_NETPATH) {
		return false;
	}
	*/

	if (dwFileType == INVALID_FILE_ATTRIBUTES) {
		//std::string* errorMessage = new std::string(Helper::GetLastErrorAsString());
		//throw InvalidPathException(errorMessage);
		return false;
	}


	if (dwFileType & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}
