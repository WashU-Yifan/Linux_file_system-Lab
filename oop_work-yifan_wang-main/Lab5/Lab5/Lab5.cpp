// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/CommandTest.h"
#include "../../SharedCode\LSCommand.h"
#include "../../SharedCode\RemoveCommand.h"
#include "../../SharedCode\CatCommand.h"
#include "../../SharedCode\CopyCommand.h"
#include "../../SharedCode\MacroCommand.h"
#include "../../SharedCode\DisplayCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include"EditDisplayParsingStrategy.h"
using namespace std;
int main()
{
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	CommandPrompt* cp = new CommandPrompt();
	string filename = "file.txt";
	AbstractFile* file = new TextFile(filename);
	sfs->addFile(filename, file);
	vector<char> origContents = { 'f','o','o' };
	file->append(origContents);
	CatCommand* cc = new CatCommand(sfs);
	AbstractCommand* dp = new DisplayCommand(sfs);
	//cp->addCommand("cat", cc);
	AbstractCommand* copy = new CopyCommand(sfs);
	AbstractCommand* rm = new RemoveCommand(sfs);
	AbstractParsingStrategy* aps = new RenameParsingStrategy();
	AbstractParsingStrategy* aps2 = new EditDisplayParsingStrategy();
	MacroCommand* mc2 = new MacroCommand(sfs);
	MacroCommand* mc = new MacroCommand(sfs);
	mc->setParseStrategy(aps);
	mc->addCommand(copy);
	mc->addCommand(rm);
	mc2->addCommand(cc);
	mc2->addCommand(dp);
	cp->addCommand("cc&dp", mc2);//setup the Edit and Display macrocommand
	cp->addCommand("rn", mc);//setup the rename macrocommand
	//cp->addCommand("cp", copy);
	cp->run();
	AbstractFile* af= sfs->openFile("text.txt");
	for (int i = 0; i < 3; i++) {
		cout << af->read()[i];
	}
	return 0;
}


