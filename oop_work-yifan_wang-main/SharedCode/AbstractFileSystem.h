#pragma once
// declaration of the interface all file systems provide goes here
#include "AbstractFile.h"
#include<set>
class AbstractFileSystem {
public:
	int maxS;
	virtual int addFile(std::string filename, AbstractFile* afile) = 0;
	//virtual int createFile(std::string filename) = 0;
	virtual int deleteFile(std::string filename) = 0;
	virtual AbstractFile* openFile(std::string filename) = 0;
	virtual int closeFile(AbstractFile* afile) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};