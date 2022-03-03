#include"MacroCommand.h"

#include<iostream>
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs_):afs(afs_) ,aps(nullptr){};

int MacroCommand::execute(std::string input) {
	vector<string> temp = aps->parse(input);
	for (unsigned int i = 0; i < v.size(); i++) {
		int j = v[i]->execute(temp[i]);
		if (j != 0)
			return j;
	}
	return success_;
};

void MacroCommand::addCommand(AbstractCommand* ac) {
	v.push_back(ac);
}


void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_) {
	this->aps = aps_;
};


void MacroCommand::displayInfo() {
	cout << "Macro command store multiple commands and excecute them by one command argument.\n";
};