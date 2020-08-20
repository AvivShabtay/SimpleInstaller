#ifndef __MANAGER_H
#define __MANAGER_H

//#pragma once
#include <vector>
#include "Task.h"
#include "MoveFileException.h"
#include "InvalidPathException.h"

class Manager
{
private:
	std::vector<Task*> tasks;
	int currentTask;
	bool RunInstallation();
	bool AbortInstallation();

public:
	Manager();
	~Manager();
	bool AddTask(Task* task);
	bool Install();
};

#endif // !__MANAGER_H


