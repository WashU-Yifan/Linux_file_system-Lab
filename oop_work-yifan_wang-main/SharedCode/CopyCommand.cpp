#include"CopyCommand.h"
#include<sstream>
#include<iostream>
using namespace std;


int CopyCommand::execute(std::string input) {
	istringstream iss(input);
	string first, second;
	if (iss >> first && iss >> second) {
		if (first.substr(0, first.size() - 4) == second) {
			cout << "they can't have same name.\n";
			return invalid_input;
		}
		AbstractFile* af = afs->openFile(first);
		afs->closeFile(af);
		if (af == nullptr) {
			return invalid_input;
		}
		else {
			string name = second + first.substr(first.size() - 4, 4);
			AbstractFile* af2 = afs->openFile(name);
			if (af2 != nullptr) {
				afs->closeFile(af2);
				return invalid_input;
			}
			AbstractFile* temp = af->clone(second);
			if (temp != nullptr) {
				afs->addFile(name, temp);
				return success_;
			}
		}
	
	}
	return invalid_input;
};
void CopyCommand::displayInfo() {
	cout << "cp command takes the first argument as the file to be copied, and takes the second argument as the name of the copy file.\n";
	cout << "Invoke this command: cp <file_to_Copy> <new_name_with_no_extension>\n";
};
CopyCommand::CopyCommand(AbstractFileSystem* afs_):afs(afs_) {
};