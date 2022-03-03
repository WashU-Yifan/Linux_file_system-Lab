#include"RemoveCommand.h"
#include<iostream>
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* afs_):afs(afs_) {};


int RemoveCommand::execute(std::string temp) {
	if (temp == "")
		return invalid_input;
	else{
		return afs->deleteFile(temp);
	}
};
void RemoveCommand::displayInfo() {
	cout << "rm command removes the file with the name of the additional argument.\n ";
	cout << "Invoke this command: rm <filename>\n";
};