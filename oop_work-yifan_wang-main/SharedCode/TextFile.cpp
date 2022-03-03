//  Define the TextFile class here
#include "TextFile.h"
#include"AbstractFileVisitor.h"
#include <vector>
#include <string>
#include<iterator>
#include<iostream>
using namespace std;

TextFile::TextFile(string name) :name(name) {};

unsigned int TextFile::getSize(){
	return contents.size();
};

string TextFile::getName() { return name; };

AbstractFile* TextFile::clone(std::string name) {
	name += ".txt";
	AbstractFile* re = new TextFile(name);
	re->write(this->read());
	return re;
};

int TextFile::write(vector<char> v) {
	try {
		contents = *new vector<char>(v);
	}
	catch (bad_alloc) {
		return exception_throw;
	}
	return success_;
};

int TextFile::append(std::vector<char> v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		contents.push_back(v[i]);
	}
	return success_;
};

vector<char> TextFile::read() {
	return contents;
};

void TextFile::accept(AbstractFileVisitor* afv) {
	if (afv) {
		afv->visit_TextFile(this);
	}
};