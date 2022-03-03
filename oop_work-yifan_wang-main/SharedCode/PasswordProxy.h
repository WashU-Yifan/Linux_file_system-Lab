#pragma once
#include"AbstractFile.h"
class PasswordProxy:public AbstractFile {
public:
	PasswordProxy(AbstractFile* af_, std::string password_);
	~PasswordProxy();
	virtual std::vector<char> read();
	virtual int write(std::vector<char> v);
	virtual int append(std::vector<char> v);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor * afv);
	virtual AbstractFile* clone(std::string name);
private:
	AbstractFile* af;
	std::string password;
protected:
	std::string passwordPrompt();
};