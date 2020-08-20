#include "TaskException.h"

TaskException::TaskException(std::string* message) :
	type(type), message(message) { }

TaskException::~TaskException()
{
	delete this->message;
}

std::string* TaskException::GetErrorMessage() {
	return this->message;
}

TaskException::ExceptionType TaskException::GetErrorType()
{
	return ExceptionType();
}
