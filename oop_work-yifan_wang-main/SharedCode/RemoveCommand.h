#pragma once
#include"AbstractFileSystem.h"
#include"AbstractCommand.h"

class RemoveCommand: public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem* afs_);
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* afs;
};
