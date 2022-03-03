#pragma once
#include"AbstractCommand.h"
#include"AbstractFileSystem.h"

class DisplayCommand :public AbstractCommand {
	AbstractFileSystem* afs;
public:
	virtual int execute(std::string);
	virtual void displayInfo();
	DisplayCommand(AbstractFileSystem* afs_);

};