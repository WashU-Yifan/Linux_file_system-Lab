#pragma once
#include"AbstractFileSystem.h"
#include"AbstractCommand.h"
class LSCommand :public AbstractCommand{
public:
	LSCommand(AbstractFileSystem* afs);
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* afs;
};