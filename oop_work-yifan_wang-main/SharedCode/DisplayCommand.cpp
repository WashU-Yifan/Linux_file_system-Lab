#include"DisplayCommand.h"
#include"AbstractFile.h"
#include"BasicDisplayVisitor.h"
#include <iostream>
#include<sstream>
using namespace std;

int DisplayCommand::execute(std::string input) {
	string first, second;
	istringstream iss(input);
	AbstractFile* af;
	if (iss >> first) {

		af = afs->openFile(first);
		afs->closeFile(af);
		if (af == nullptr)
			return invalid_input;
		else {
			if (iss >> second) {
				if (second != "-d") {
					return invalid_input;
				}
				else {
					vector<char> v = af->read();
					for (unsigned int i = 0; i < v.size();i++) {
						cout << v[i];
					}
					cout << '\n';
					return success_;
				}
			}
			else {
				AbstractFileVisitor* afv = new BasicDisplayVisitor();
				af->accept(afv);
				delete afv;
				return success_;
			}
		
		}
	}
	return invalid_input;
};


void DisplayCommand::displayInfo() {
	
};
DisplayCommand::DisplayCommand(AbstractFileSystem* afs_) :afs(afs_){};
