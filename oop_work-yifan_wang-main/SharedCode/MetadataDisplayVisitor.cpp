// definitions of metadata visitor here
#include"MetadataDisplayVisitor.h"
#include<iostream>
using namespace std;
void MetadataDisplayVisitor::visit_TextFile(TextFile* t) {
	cout << t->getName();
	for (unsigned int i = t->getName().size(); i < 20; i++) cout << " ";
	cout <<"text" << "           "<<t->getSize()<<endl;
}; 

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* t) {
	cout << t->getName();
	for (unsigned int i = t->getName().size(); i < 20; i++) cout << " ";
	cout << "image" << "           " << t->getSize() << endl;
};