#include"TouchCommand.h"
#include<sstream>
#include<iostream>
#include"PasswordProxy.h"
using namespace std;
TouchCommand::TouchCommand(AbstractFileSystem* afs_, AbstractFileFactory* aff_) :afs(afs_), aff(aff_) {};

int TouchCommand::execute(std::string input) {
	string name,second;
	istringstream iss(input);
	if (iss >> name)
	{
		AbstractFile* temp = aff->createFile(name);
		if (iss >> second) {
			if (second == "-p") {
				string password;
				cout << "What is your pssword?\n";
				cin >> password;
				AbstractFile* proxy = new PasswordProxy(temp, password);
				return afs->addFile(name, proxy);
			}
			return invalid_input;
		}
		else if (temp != nullptr) {
			return afs->addFile(name, temp);
		}
	}
	return invalid_input;
};


void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch canbe invoked with the command : touch <filename>\n";

};




 