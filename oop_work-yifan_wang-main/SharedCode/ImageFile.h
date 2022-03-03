#pragma once
#include"AbstractFile.h"
// Image file class declaration here

class ImageFile :public AbstractFile {
	std::string name;
	std::vector<char> contents;
	char size;
	
public: 
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char> v)override;
	virtual int append(std::vector<char> v) override;
	virtual unsigned int getSize()override;
	char Csize();
	virtual std::string getName() override;
	ImageFile(std::string name_);
	virtual void accept(AbstractFileVisitor* afv);
	virtual AbstractFile* clone(std::string name);
};