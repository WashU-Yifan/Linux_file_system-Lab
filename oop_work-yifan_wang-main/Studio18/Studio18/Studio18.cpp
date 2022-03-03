// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include"../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"

using namespace std;

int main()
{
	AbstractFileSystem* abs = new SimpleFileSystem();
	AbstractFileFactory* abf = new SimpleFileFactory();
	AbstractFile* a = abf->createFile("a.txt");
	AbstractFile* b = abf->createFile("b.img");
	AbstractFile* c = abf->createFile("c.txt");
	AbstractFile* d = abf->createFile("d.img");
	abs->addFile("a.txt",a);
	abs->addFile("b.img", a);
	abs->addFile("c.txt", a);
	abs->addFile("d.img", a);

	return 0;
}
