#ifndef __INVALID_PATH_EXCEPTION_H
#define __INVALID_PATH_EXCEPTION_H

//#pragma once
#include "TaskException.h"

class InvalidPathException : public TaskException {
public:
	InvalidPathException(std::string* message) : TaskException(message) {}
};

#endif // !__INVALID_PATH_EXCEPTION_H


