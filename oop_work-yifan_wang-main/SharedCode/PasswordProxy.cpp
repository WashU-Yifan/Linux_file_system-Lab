#include"PasswordProxy.h"
#include<sstream>
#include<iostream>
PasswordProxy::PasswordProxy(AbstractFile* af_, std::string password_):af(af_),password(password_) {
};

PasswordProxy::~PasswordProxy() {
	delete af;
};
AbstractFile* PasswordProxy::clone(std::string name) {
	AbstractFile* in = af->clone(name);
	AbstractFile* out = new PasswordProxy(in,this->password);
	return out;

};

std::string PasswordProxy::passwordPrompt() {
	std::string input;
	std::cin >> input;
	return input;
};

std::vector<char> PasswordProxy::read() {
	if (passwordPrompt() == password) {
		return af->read();
	}
	std::vector<char> temp;
	return temp;
};
int PasswordProxy::write(std::vector<char> v) {
	if (passwordPrompt() == password) {
		return af->write(v);
	}
	return Incorrect_password_Write;
};
int  PasswordProxy::append(std::vector<char> v) {
	if (passwordPrompt() == password) {
		return af->append(v);
	}
	return Incorrect_password_Append;
};
unsigned int  PasswordProxy::getSize() {
	return af->getSize();
};
std::string  PasswordProxy::getName() {
	return af->getName();
};
void PasswordProxy::accept(AbstractFileVisitor* afv) {
	if (passwordPrompt() == password) {
		af->accept(afv);
	}
	return;
};