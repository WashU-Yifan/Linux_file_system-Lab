// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/PasswordProxy.h"
#include<string>
#include<iostream>
using namespace std;
int main()
{
	std::string a(5,'x');
	AbstractFile* af = new TextFile(a);
	AbstractFile *proxy = new PasswordProxy(af, "123456");
	vector<char> temp = { 'a','b','c','d' };
	proxy->append(temp);
	for (char temp : proxy->read()) {
		cout << temp << " ";
	}
	return 0;
}

