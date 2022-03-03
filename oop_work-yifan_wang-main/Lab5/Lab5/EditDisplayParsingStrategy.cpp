#include"EditDisplayParsingStrategy.h"
#include<sstream>
using namespace std;
std::vector<std::string> EditDisplayParsingStrategy::parse(std::string input) {
	istringstream iss(input);
	string name1,extension1,name2,extension2;
	vector<string > temp;
	iss >> name1;
	iss >> extension1;
	
	if (name1 == extension1) {//if only 2 file names are provided
		temp.push_back(name1);
		temp.push_back(extension1);
		return temp;
	}
	else if(extension1=="-a"){// if the cat command has -a
		if (iss >> name2 && name1._Equal(name2)) {//2 files' names have to be the same
			name1 = name1 + " " + extension1;
			temp.push_back(name1);

			if (iss >> extension2) {
				name2 = name2 + " " + extension2;
			}
			temp.push_back(name2);
		}
	}
	return temp;
};