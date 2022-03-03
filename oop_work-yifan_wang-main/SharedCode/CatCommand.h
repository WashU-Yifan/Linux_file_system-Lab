#pragma once

#include"AbstractCommand.h"
#include"AbstractFileSystem.h"
class CatCommand :public AbstractCommand{
public:
	virtual int execute(std::string);
	virtual void displayInfo();
	CatCommand(AbstractFileSystem* afs_);

private:
	int executeHelper1(AbstractFile* af);
	int executeHelper2(AbstractFile* af);
	AbstractFileSystem* afs;
};