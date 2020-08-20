#ifndef __MOVE_FILE_EXCEPTION_H
#define __MOVE_FILE_EXCEPTION_H

//#pragma once
#include "TaskException.h"

class MoveFileException : public TaskException
{
public:
	MoveFileException(std::string* message) : TaskException(message) {}
};

#endif // !__MOVE_FILE_EXCEPTION_H


