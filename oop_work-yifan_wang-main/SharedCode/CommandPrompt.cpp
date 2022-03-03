#include"CommandPrompt.h"
#include<iostream>
#include<sstream>
using namespace std;
void CommandPrompt::setFileSystem(AbstractFileSystem* afs_) {
	afs = afs_;
};
void CommandPrompt::setFileFactory(AbstractFileFactory* aff_) {
	aff = aff_;
};
int CommandPrompt::addCommand(std::string temp, AbstractCommand* ac) {
	if (ac == nullptr|| m.find(temp) != m.end()||temp.empty())
		return invalid_input;
	
	m.insert(std::pair<std::string, AbstractCommand*>(temp,ac));
	return success_;

};

void CommandPrompt::listCommands() {
	for (pair<string, AbstractCommand*> temp : m) {
		cout << temp.first << " \n";
	}
};

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, \nor help followed by a command name for more information about that command.\n";
	cout << "$   ";
	string temp;
	char s[20];
	cin.getline(s,20);
	temp = s;
	return temp;
};

int CommandPrompt::run() {
	while (true) {
		string temp = prompt();
		if (temp == "q")
			return no_implementation;
		else if(temp=="help") {
			listCommands();
		}
		else {
			if (temp.find(' ') == string::npos) {
				for (pair<string, AbstractCommand*> p : m) {
					if (temp == p.first) {
						if (p.second->execute("") != 0) {
							cout << "The command: " << p.first << " has failed.\n";
						}
					}
				}
				if (m.find(temp) == m.end()) {
					cout << "The command you typed does not exist.\n";
				}
			}
			else {
				istringstream iss(temp);
				string first;
				iss >> first;
				if ( first == "help") {
					string name;
					iss >> name;/*
					for (pair<string, AbstractCommand*> p : m) {
						if (name == p.first) {
							p.second->displayInfo();
						}
					}
					*/
					if (m.find(name) == m.end()) {
						cout << "The command you typed does not exist.\n";
					}
					else {
						m.find(name)->second->displayInfo();
					}
				}
				else {
					cout << first;
					int loc = temp.find_first_of(' ');
					temp = temp.substr(loc + 1, temp.length() - loc);
					/*for (pair<string, AbstractCommand*> p : m) {
						if (first == p.first) {
							if (p.second->execute(temp) != 0) {
								cout << "The command: " << p.first << " has failed.\n";
							}
						}
					}
					*/
					if (m.find(first) == m.end()) {
						cout << "The command you typed does not exist.\n";
					}
					else {
						 int i = m.find(first)->second->execute(temp);
						 if(i!=0)
							 cout << "The command: " << first << " has failed.\n";
					}
				}
			}
		}
	}
};
