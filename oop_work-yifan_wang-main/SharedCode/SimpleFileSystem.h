#pragma once
// declaration of SimpleFileSystem class goes here
#include"AbstractFileSystem.h"
#include "AbstractFile.h"
#include<map>
#include<set>
using namespace std;
class SimpleFileSystem :public AbstractFileSystem{

public:

	SimpleFileSystem() = default;
	virtual int addFile(string filename, AbstractFile* afile)override;
	//virtual int createFile(string filename) override;
	virtual int deleteFile(string filename) override;
	virtual AbstractFile* openFile(string filename) override;
	virtual int closeFile(AbstractFile* afile)override;
	virtual set<std::string> getFileNames()override;
private:
	std::map<string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
};