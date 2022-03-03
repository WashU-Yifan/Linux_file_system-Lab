#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include<vector>
#include<string>
//#include"AbstractFileVisitor.h"
enum returntype { 
	success_ = 0, commonfail = 1, exception_throw=2, no_implementation=3, invalid_input=4, file_open=5,Incorrect_password_Write=6, Incorrect_password_Append = 6
};
class AbstractFileVisitor;
class AbstractFile {
public:
	virtual std::vector<char> read()= 0;
	virtual int write(std::vector<char> v) = 0;
	virtual int append(std::vector<char> v) = 0;
	virtual unsigned int getSize()= 0;
	virtual std::string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor* afv) = 0;
	virtual AbstractFile* clone(std::string name) = 0;
};