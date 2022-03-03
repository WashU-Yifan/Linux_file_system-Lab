#pragma once
#include"AbstractCommand.h"
#include"AbstractParsingStrategy.h"
#include"AbstractFileSystem.h"
#include<vector>
class MacroCommand :public AbstractCommand {
	std::vector<AbstractCommand*> v;
	AbstractParsingStrategy* aps;
	AbstractFileSystem* afs;
public:
	virtual int execute(std::string)override;
	virtual void displayInfo()override;
	MacroCommand(AbstractFileSystem* afs);
	void addCommand(AbstractCommand*) ;
	void setParseStrategy(AbstractParsingStrategy* aps_);
};