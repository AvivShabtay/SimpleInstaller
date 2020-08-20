#ifndef __CREATE_DIRECTORY_EXCEPTION_H
#define __CREATE_DIRECTORY_EXCEPTION_H

//#pragma once
#include "TaskException.h"

class CreateDirectoryException : public TaskException {
public:
	CreateDirectoryException(std::string* message) : TaskException(message) {}
};

#endif // !__CREATE_DIRECTORY_EXCEPTION_H