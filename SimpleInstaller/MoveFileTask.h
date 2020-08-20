#ifndef __MOVE_FILE_TASK_H
#define __MOVE_FILE_TASK_H

//#pragma once
#include <windows.h>
#include "Task.h"
#include "MoveFileException.h"
#include "Helper.h"

#define BUF_SIZE 256 // Can be changed if needed

class MoveFileTask : Task
{
private:
	std::string source;
	std::string destination;
	void ReportError();

public:
	MoveFileTask(std::string source, std::string destination);
	bool SetSource(std::string source);
	std::string GetSource();
	bool SetDestination(std::string destination);
	std::string GetDestination();
	virtual bool DoTask() throw (int, const char*);
	virtual bool UndoTask() throw (int, const char*);
};

#endif // !__MOVE_FILE_TASK_H
