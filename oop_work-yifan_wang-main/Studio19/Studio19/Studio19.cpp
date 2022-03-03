// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include"AbstractFile.h"
using namespace std;
#include<iostream>
//#include "../../SharedCode/TextFile.cpp"
#include"../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"



int main()
{
	
	vector<char>v = { 'a','v','b','n' };
	AbstractFile* af = new TextFile("A");
	af->append(v);
	std::vector<char> temp(af->read()); 
	//cout << af->read()[1];
	for (char a : temp) {
		cout << a << "\n";
	}
	for (char a : v) {
		cout << a << "\n";
	}
	return 0;
}
