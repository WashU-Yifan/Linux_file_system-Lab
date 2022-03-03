// definitions of basic display visitor here
#include"BasicDisplayVisitor.h"
#include<vector>
#include <iostream>
 void BasicDisplayVisitor::visit_TextFile(TextFile* t) {
	for (unsigned int i = 0;i<t->read().size(); i++) {
		std::cout << t->read()[i];;
	}
 };
 void BasicDisplayVisitor::visit_ImageFile(ImageFile* t) {
	 int realSize = t->Csize() - 48;
	 for (int h = realSize; h > 0; h--) {
		 for (int w = 0; w < realSize; w++) {
			 std::cout << t->read()[(h - 1) * realSize + w] << "";
		 }
		 std::cout << "\n";
	 }
 };

