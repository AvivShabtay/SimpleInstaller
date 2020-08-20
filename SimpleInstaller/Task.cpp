#include "Task.h"

/* Used to set task desription. */
bool Task::SetDescription(std::string description)
{
	this->m_Description = description;
	return true;
}

/* Used to get task desription. */
std::string Task::GetDescription() const
{
	return this->m_Description;
}
