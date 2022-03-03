#pragma once
#include"AbstractFile.h"
#include<vector>
#include<string>
// TextFile declaration goes here

class TextFile: public AbstractFile {
	std::vector<char> contents;
	std::string name;
	//std::vector<int> v;
public:
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char> v)override;
	virtual int append(std::vector<char> v)override;
	virtual unsigned int getSize()override;
	virtual std::string getName()override;
	TextFile(std::string name);
	virtual void accept(AbstractFileVisitor* afv);
	virtual AbstractFile* clone(std::string name);
};