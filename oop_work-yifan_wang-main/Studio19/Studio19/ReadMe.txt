studio 19 answers here

2:
	vector<char>v = { 'a','v','b','n' };
	AbstractFile* af = new TextFile("A");
	af->write(v);
	std::vector<char> temp = af->read();
	for (char a : temp) {
		cout << a << "\n";
	}

	output is:
	a
	v
	b
	n

3:
	By calling the accept method in the derived object class with a visitor object passed in as argument,
	the visitor object passed in will call a specific type visit function on this derived object's memeber variable. In the visit funciton,
	the member variable(vector of char in this case) will be printed.

4:
	When adding a new file type, we only have to add another visit function to the visitor object to accommondate the change.

5:
	If we add a new file type to the system, then we have to renew all of our visitor classes. This is very inenfficient when we have 
	many visitors classes to update.