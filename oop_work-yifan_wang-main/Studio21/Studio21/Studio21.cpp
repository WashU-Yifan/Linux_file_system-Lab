// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<string>
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include<iostream>
int main()
{
	SimpleFileSystem* sfs = new SimpleFileSystem();
	SimpleFileFactory* sff = new SimpleFileFactory();
	AbstractCommand* ac = new TouchCommand(sfs,sff);
	CommandPrompt cp;
	cp.addCommand("touch", ac);
	cp.run();
	sfs->openFile("text.txt");
	return 0;
}

