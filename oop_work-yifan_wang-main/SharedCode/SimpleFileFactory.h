#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include"AbstractFileFactory.h"
class TextFile;
class ImageFile;
class SimpleFileFactory :public AbstractFileFactory{
public:
	virtual AbstractFile* createFile(std::string FileName);
};