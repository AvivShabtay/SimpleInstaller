#include "Manager.h"

Manager::Manager() : currentTask(0) {}

Manager::~Manager() {
	// Remove all the dynamically allocated objects:
	for (auto it : tasks) {
		delete it;
	}
}

/* Run all the task for the installation. */
bool Manager::RunInstallation() {
	for (; currentTask < tasks.size(); currentTask++) {
		Task* t = tasks.at(currentTask);
		if (!t->DoTask())
			return false;
	}
	return true;
}

/* Undo all the task that have been made during the installation. */
bool Manager::AbortInstallation() {
	for (--currentTask; 0 <= currentTask; currentTask--) {
		Task* t = tasks.at(currentTask);
		if (!t->UndoTask())
			return false;
	}
	return true;
}

/* Add task to be preformed during the installation. */
bool Manager::AddTask(Task* task) {
	if (task == nullptr)
		return false;

	this->tasks.push_back(task);
	return true;
}

/* Running all the installation tasks. */
bool Manager::Install() {
	// Using outer block to provide re-thrown mechanism
	// for code reuse.
	try {
		// Provide custom message for every exception that have
		// been thrown during the installation.
		try {

			std::cout << "[+] Starting installation..." << std::endl;

			if (!RunInstallation()) {
				throw "Something went wrong";
			}

			std::cout << "[+] Installation success !" << std::endl;
			return true;
		}
		catch (MoveFileException& e) {
			std::string* message = e.GetErrorMessage();
			std::cout << "[-] Something went wrong while copying files, error: " << message->c_str() << std::endl;
			throw;
		}
		catch (InvalidPathException& e) {
			std::string* message = e.GetErrorMessage();
			std::cout << "[-] Something went wrong while copying files, error: " << message->c_str() << std::endl;
			throw;
		}
	}
	// Generic exception handling, abort all the last operation
	// that have been made.
	catch (...) {
		std::cout << "[-] Abort installation..." << std::endl;
		AbortInstallation();
		return false;
	}
}
