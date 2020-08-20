#include "MoveFileTask.h"
#include "CreateDirectoryTask.h"
#include "Manager.h"
#include <vector>

std::vector<MoveFileTask> GenerateTasks(std::string destFolder);
void SetupInstallation(Manager& manager);

int main(int argc, char** argv) {

	// Create installation manager:
	Manager manager;

	// Setup the installation according to the application files:
	SetupInstallation(manager);

	// Running the installation:
	manager.Install();
}

/* Helper function to setup installation manager. */
void SetupInstallation(Manager& manager) {
	bool isDestFolder;

	// Check if destination folder exist:
	isDestFolder = Helper::IsDirectoryExist("C:\\temp\\InstallationFolder");

	// Add destination file of needed:
	if (!isDestFolder) {
		CreateDirectoryTask* t1 = new CreateDirectoryTask("C:\\temp\\InstallationFolder");
		manager.AddTask((Task*)t1);
	}

	// Add few tasks to move files:
	MoveFileTask* t2 = new MoveFileTask("C:\\temp\\PackageFolder\\configuration.txt",
		"C:\\temp\\InstallationFolder\\configuration.txt");
	MoveFileTask* t3 = new MoveFileTask("C:\\temp\\PackageFolder\\logFile.txt",
		"C:\\temp\\InstallationFolder\\logFile.txt");

	manager.AddTask((Task*)t2);
	manager.AddTask((Task*)t3);

	// Add tasks to create inner directory:
	CreateDirectoryTask* t4 = new CreateDirectoryTask("C:\\temp\\InstallationFolder\\InnerFolder");
	manager.AddTask((Task*)t4);

	// Add more task to move files to the new directory:
	MoveFileTask* t5 = new MoveFileTask("C:\\temp\\PackageFolder\\logFile.txt",
		"C:\\temp\\InstallationFolder\\InnerFolder\\logFile.txt");

	manager.AddTask((Task*)t5);
}

/* Helper function used for testing. */
std::vector<MoveFileTask> GenerateTasks(std::string destFolder) {
	std::string sources[] = {
		"C:\\temp\\PackageFolder\\configuration.txt",
		"C:\\temp\\PackageFolder\\logFile.txt",
		"C:\\temp\\PackageFolder\\img.txt",
	};

	std::vector<MoveFileTask> tasks;
	tasks.reserve(sources->size());

	for (auto& source : sources) {
		std::string fileName = source.substr(source.find_last_of("\\/"), source.length());

		std::string temp = source.substr(0, source.find_last_of("\\/"));

		std::string destination = temp.substr(0, temp.find_last_of("\\/"));

		destination += "\\" + destFolder + fileName;

		tasks.push_back(MoveFileTask(source, destination));
	}

	return tasks;
}


