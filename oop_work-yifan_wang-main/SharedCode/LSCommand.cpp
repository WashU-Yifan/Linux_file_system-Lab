#include"LSCommand.h"
#include"MetadataDisplayVisitor.h"
//#include"AbstractFile.h"
#include<iostream>
using namespace std;


LSCommand::LSCommand(AbstractFileSystem* afs_) : afs(afs_){};


int LSCommand::execute(std::string input) {
	set<string>s = afs->getFileNames();
	if (s.empty()) {
		cout << "The list is empty\n";
		return commonfail;
	}
	if (input == "") {
		int count = 0;
		for (string temp : s) {
			cout << temp;
			for (int i = temp.size(); i < 20; i++) {
				cout << " ";
			}
			if (count % 2 == 1)
				cout << "\n";
			count++;
		}
		return success_;
	}
	else if (input == "-m") {
		AbstractFileVisitor* afv = new MetadataDisplayVisitor();
		AbstractFile* af;
		for (string temp : s) {
			af = afs->openFile(temp);
			af->accept(afv);
			afs->closeFile(af);
		}
		delete afv;//delete dynamically allocated object to avoid memory leak.
		return success_;
	}
	return invalid_input;
};
void LSCommand::displayInfo() {
	cout << "ls prints all file name and its metadate if you add '-m' as addition argument.\n Invoke this command:ls -m(optional)\n";
};