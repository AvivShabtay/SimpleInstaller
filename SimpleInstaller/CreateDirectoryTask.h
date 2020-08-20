#ifndef __CREATE_DIRECTORY_TASK_H
#define __CREATE_DIRECTORY_TASK_H

//#pragma once
#include <windows.h>
#include "Task.h"
#include "CreateDirectoryException.h"
#include "Helper.h"

class CreateDirectoryTask : Task
{
private:
	std::string sourceDirectory;
public:
	CreateDirectoryTask(std::string sourceDirectory);
	bool SetSourceDirectory(std::string sourceDirectory);
	std::string GetSourceDirectory();
	virtual bool DoTask() throw (int, const char*);
	virtual bool UndoTask() throw (int, const char*);
};



#endif // !__CREATE_DIRECTORY_TASK_H


