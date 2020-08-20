#ifndef __TASK_EXCEPTION_H
#define __TASK_EXCEPTION_H

//#pragma once
#include <iostream>

class TaskException {
public:
	enum ExceptionType { MoveFileException, InvalidPathException }; // TODO: Remove ?
	TaskException(std::string* message);
	~TaskException();
	std::string* GetErrorMessage();
	ExceptionType GetErrorType();

protected:
	ExceptionType type;
	std::string* message;
};

#endif // !__TASK_EXCEPTION_H

