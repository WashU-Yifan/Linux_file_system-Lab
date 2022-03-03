#include"RenameParsingStrategy.h"
#include<sstream>
using namespace std;
vector<string> RenameParsingStrategy::parse(string input) {
	istringstream iss(input);
	string newName;
	iss >> newName;
	vector<string> temp;
	temp.push_back(input);
	temp.push_back(newName);
	return temp;
};