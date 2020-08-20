#include "MoveFileTask.h"

MoveFileTask::MoveFileTask(std::string source, std::string destination) {
	this->SetSource(source);
	this->SetDestination(destination);
}

/* Set the source path of the file. */
bool MoveFileTask::SetSource(std::string source) {
	if (source.empty())
		return false;

	this->source = source;
	return true;
}

/* Get the source path of the file. */
std::string MoveFileTask::GetSource() {
	return this->source;
}

/* Set the destination path of the file. */
bool MoveFileTask::SetDestination(std::string destination) {
	if (destination.empty())
		return false;

	this->destination = destination;
	return true;
}

/* Get the destination path of the file. */
std::string MoveFileTask::GetDestination() {
	return this->destination;
}

/* Read the file in chunks and copy it to new location. */
bool MoveFileTask::DoTask() {

	CHAR buffer[BUF_SIZE];
	DWORD dwRead;
	DWORD dwWrite;

	// TODO: Change work with TCHAR
	SafeHandle hSource(CreateFileA(source.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr));

	if (hSource.Get() == INVALID_HANDLE_VALUE) {
		ReportError();
	}

	// TODO: Change work with TCHAR
	SafeHandle hDestination(CreateFileA(destination.c_str(), GENERIC_WRITE, 0, nullptr,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr));

	if (hDestination.Get() == INVALID_HANDLE_VALUE) {
		ReportError();
	}

	while (ReadFile(hSource.Get(), buffer, BUF_SIZE, &dwRead, nullptr) && dwRead > 0) {
		WriteFile(hDestination.Get(), buffer, dwRead, &dwWrite, nullptr);
		if (dwRead != dwWrite) {
			ReportError();
		}
	}
	return true;
	// Automatically close handles thanks to SafeHandler (RAII)
}

/* Used to delete the file. */
bool MoveFileTask::UndoTask() {
	BOOL result;

	result = DeleteFileA(destination.c_str());
	return result;
}

/* Used to report exception to caller. */
void MoveFileTask::ReportError() {
	std::string* errorMessage = new std::string(Helper::GetLastErrorAsString());
	throw MoveFileException(errorMessage);
}