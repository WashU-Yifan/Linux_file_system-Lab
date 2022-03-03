// studio 18 - simple file factory definitions
#include"SimpleFileFactory.h"
#include"ImageFile.h"
#include"TextFile.h"
AbstractFile* SimpleFileFactory::createFile(std::string filename) {
	AbstractFile* afile=nullptr;
	std::string fileform = filename.substr(filename.size() - 3, 3);
	if (fileform == "txt") {
		afile = new TextFile(filename);
	}
	else if (fileform == "img") {
		afile = new ImageFile(filename);
	}
	return afile;

};