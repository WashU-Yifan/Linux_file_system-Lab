// definition of ImageFile class here
#include"ImageFile.h"
#include"AbstractFileVisitor.h"
#include<iostream>
using namespace std;
ImageFile::ImageFile(string name_):name(name_),size(0) {
};

unsigned int ImageFile::getSize() {
	return contents.size();
};

string ImageFile::getName() {
	return name;
};

 AbstractFile* ImageFile::clone(string name) {
	 name += ".img";
	 AbstractFile* re = new ImageFile(name);
	 re->write(this->read());
	 return re;
};
int ImageFile::write(vector<char> v) {
	int imageSize = v[v.size()-1]-48;
	if (v.size() != (imageSize *imageSize + 1)) {
		return commonfail;
	}
	else {
		char a = 'X';
		char b = ' ';
		for (unsigned int i = 0; i < v.size()-1; i++) {
			if (v[i] != a && v[i] != b) {
				return commonfail;
			}
		}
		try {
			size = v[v.size() - 1];
			vector<char>*temp = &contents;
			contents = *new vector<char>();
			for (unsigned int i = 0; i < v.size()-1; i++) {
				contents.push_back(v[i]);
			}
		}
		catch(bad_alloc){
			return exception_throw;
		}
		
		for (unsigned int i = 0; i < contents.size(); i++) {
			if (contents[i] != a && contents[i] != b) {
				return commonfail;
			}
		}
		return success_;
	}
};

int ImageFile::append(vector<char> v) {
	return no_implementation;
};

vector<char> ImageFile::read() {
	//cout << contents[1];
	return contents;
};

char ImageFile::Csize() { return size; };

void ImageFile::accept(AbstractFileVisitor* afv) {
	if (afv) {
		afv->visit_ImageFile(this);
	}
};
