#pragma once
#include"AbstractCommand.h"
#include"AbstractFileSystem.h"
class CopyCommand :public AbstractCommand {
public:
	virtual int execute(std::string);
	virtual void displayInfo();
	CopyCommand(AbstractFileSystem* afs_);
private:
	AbstractFileSystem* afs;
};