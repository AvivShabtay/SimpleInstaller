#include "CreateDirectoryTask.h"

CreateDirectoryTask::CreateDirectoryTask(std::string sourceDirectory) {
	this->SetSourceDirectory(sourceDirectory);
}

/* Set the directory path. */
bool CreateDirectoryTask::SetSourceDirectory(std::string sourceDirectory) {
	if (sourceDirectory.empty()) {
		return false;
	}
	this->sourceDirectory = sourceDirectory;
	return true;
}

/* Return the directory path. */
std::string CreateDirectoryTask::GetSourceDirectory() {
	return this->sourceDirectory;
}

/* Create directory. */
bool CreateDirectoryTask::DoTask() throw(int, const char*) {
	BOOL result;

	result = CreateDirectoryA(sourceDirectory.c_str(), nullptr);
	if (!result) {
		std::string* errorMessage = new std::string(Helper::GetLastErrorAsString());
		throw CreateDirectoryException(errorMessage);
	}
	return true;
}

/* Remove directory. */
bool CreateDirectoryTask::UndoTask() throw(int, const char*) {
	BOOL result;

	result = RemoveDirectoryA(sourceDirectory.c_str());
	return result;
}
