#include"CatCommand.h"
#include<sstream>
#include<iostream>
#include<vector>
#include"BasicDisplayVisitor.h"
#include "AbstractFile.h"
using namespace std;
int CatCommand::execute(std::string input) {
	string first, second;
	istringstream iss(input);
	AbstractFile* af;
	if (iss >> first) {
		af = afs->openFile(first);
		afs->closeFile(af);
		if (af == nullptr)
			return invalid_input;
		if (iss >> second) {
			if (second == "-a" || second == "[-a]") {
				return executeHelper2(af);
			}
			return invalid_input;
		};
		return executeHelper1(af);

	}
	return invalid_input;
};

int CatCommand::executeHelper1(AbstractFile* af) {
	string read;
	vector<char> output;
	while (true) {
		cout << "Enter data you would like to write to the existing file. Enter :wq to save and file and exit, enter :q to exist without saving.\n";
		string temp;
		getline(cin, temp);
		if (temp == ":q") {
			
			return success_;
		}
		else if(temp == ":wq") {
			if (output[output.size() - 1] == '\n') output.pop_back();
			break;
		}
		else {
			temp += '\n';
			for (unsigned int i = 0; i < temp.size(); i++) {
				output.push_back(temp[i]);
			}
			
		}
	}
	
	return af->write(output);
}

int CatCommand::executeHelper2(AbstractFile* af) {
	string read;
	vector<char> output;
	AbstractFileVisitor* afv = new BasicDisplayVisitor();
	cout << '\n';
	af->accept(afv);
	cout << '\n';
	while (true) {
		cout << "Enter data you would like to append to the existing file. Enter :wq to save and file and exit, enter :q to exist without saving.\n";
		string temp;
		getline(cin, temp);
		if (temp == ":q") {
			delete afv;
			return success_;
		}
		else if (temp == ":wq") {
			if (output[output.size() - 1] == '\n') output.pop_back();
			break;
		}
		else {
			temp += '\n';
			for (unsigned int i = 0; i < temp.size(); i++) {
				output.push_back(temp[i]);
			}
		}
	}
	delete afv;
	return af->append(output);
}

void CatCommand::displayInfo() {
	cout << "CatCommand will concat the file with the input if -a is provided in the argument. Else this command will simple overwrite the file.\n";
	cout << "Invoke this command: cat <filename> -a(or[-a])\n";
};


CatCommand::CatCommand(AbstractFileSystem* afs_):afs(afs_) {
};
