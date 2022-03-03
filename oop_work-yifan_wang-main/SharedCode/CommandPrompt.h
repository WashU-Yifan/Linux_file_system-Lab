#pragma once
#include"AbstractCommand.h"
#include"ImageFile.h"
#include"TextFile.h"
#include"AbstractFileFactory.h"
#include"AbstractFileSystem.h"
#include<map>
#include<string>
class CommandPrompt {
 private:
	std::map<std::string, AbstractCommand*> m;
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
 public:
	CommandPrompt() = default;
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem* afs_);
	void setFileFactory(AbstractFileFactory* aff_);
	int addCommand(std::string s, AbstractCommand* ac);
    int run();
protected:
	virtual void listCommands();
	virtual std::string prompt();
};