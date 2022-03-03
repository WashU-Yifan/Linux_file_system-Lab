// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>

using namespace std;


int main()
{
	vector<char> v={ 'a','b','c' };
	AbstractFile *temp=new TextFile("name");
	cout << temp->getSize() << endl;
	cout << temp->getName() << endl;
	temp->write(v);
	v.push_back('d');
	//temp->write(v);
	temp->append(v);
	temp->read();
	cout << temp->getSize();
}


