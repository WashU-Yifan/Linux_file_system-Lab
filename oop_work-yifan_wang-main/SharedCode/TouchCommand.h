#pragma once
#include"AbstractCommand.h"
#include"AbstractFileSystem.h"
#include"AbstractFileFactory.h"
#include<string>
class TouchCommand :public AbstractCommand{
public:
	virtual int execute(std::string);
	virtual void displayInfo();
	TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff);
	~TouchCommand() = default;
private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;

};