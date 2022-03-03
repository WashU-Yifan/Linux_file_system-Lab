#pragma once
// declaration of the file visitor interface here
#include"ImageFile.h"
#include"TextFile.h"

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* t) = 0;
	virtual void visit_ImageFile(ImageFile * t) = 0;

};