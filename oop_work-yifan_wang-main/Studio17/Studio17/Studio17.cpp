// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include"..\..\\SharedCode\ImageFile.h"
#include<iostream>
#include"..\..\\SharedCode\SimpleFileSystem.h"
using namespace std;
int main()
{
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	AbstractFile *temp = new ImageFile("name");
	//cout << temp->getSize() << endl;
	//cout << temp->getName() << endl;
	cout<<temp->write(v);
	temp->read();
	//cout << temp->getSize();
	return 0;
}

