#ifndef __TASK_H
#define __TASK_H
#pragma once
#include <iostream>

class Task
{
protected:
	std::string m_Description;
public:
	virtual bool DoTask() = 0;
	virtual bool UndoTask() = 0;
	bool SetDescription(std::string description);
	std::string GetDescription() const;
};

#endif // __TASK_H


