// define methods of SimpleFileSystem class here
#include"SimpleFileSystem.h"
#include<iostream>


int SimpleFileSystem::addFile(string filename, AbstractFile* afile) {
	if (files[filename] != nullptr) {//check is the file already exist
		return invalid_input;
	}
	else if (afile == nullptr)//check is the pointer pointing to an file 
		return invalid_input;
	else {
		files.erase(filename);//to prevent the [] operator creating a pair that with empty value
		files.insert(pair<string, AbstractFile*>(filename, afile));
		//std::cout << "successful adding\n";
		return success_;
	}
};
/*
int SimpleFileSystem::createFile(string filename) {
	if (files[filename] == nullptr)	{
		files.erase(filename);
		string fileform = filename.substr(filename.size() - 3, 3);
		AbstractFile* afile;
		if (fileform == "txt") {
			afile = new TextFile(filename);
			files.insert(pair<string, AbstractFile*>(filename, afile));
			return success;
		}
		else if (fileform == "img") {
			afile = new ImageFile(filename);
			files.insert(pair<string, AbstractFile*>(filename, afile));
			return success;
		}
		return invalid_input;
	}
	else {
		return invalid_input;
	}
};
*/
AbstractFile* SimpleFileSystem::openFile(string filename) {
	
	if (files[filename] == nullptr) {
		files.erase(filename);
		return nullptr;
	}
	else {
		//cout << "YES!\n";
		AbstractFile* afile = files[filename];
		set<AbstractFile*>::iterator it;
		it = openFiles.find(afile);
		if (it == openFiles.end()) {
			openFiles.insert(afile);
			return afile;
		}
		return nullptr;
	}
};

int SimpleFileSystem::closeFile(AbstractFile* afile) {
	set<AbstractFile*>::iterator it;
	it = openFiles.find(afile);
	if (it == openFiles.end()) {
		return invalid_input;
	}
	else
		openFiles.erase(it);
		return success_;
};

int SimpleFileSystem::deleteFile(string filename) {
	if (files[filename] == nullptr) {
		files.erase(filename);
		return invalid_input;
	}
	else {
		AbstractFile* afile = files[filename];
		set<AbstractFile*>::iterator it;
		it = openFiles.find(afile);
		if (it != openFiles.end()) {
			return file_open;
		}
		else {
			files.erase(filename);
			delete afile;
			return success_;
		}
	}
}

set<std::string> SimpleFileSystem::getFileNames() {
	set<string> s;
	for (pair<string, AbstractFile*> temp : files) {
		s.insert(temp.first);
	}
	return s;
};