Answer studio 16 questions here 
Yifan Wang

2:
Declaring an interface in C++ is to create an abstract class that only contains pure virtual functions that have not been
implemented yet.

3:
a: interface inheritance
b: it should be protected since there might be classes that will inherit from this class.

4:
The TextFile variable temp behaves correctly when calling member function of TextFile on it.

cout << temp->getSize()<< endl;;
	cout << temp->getName()<< endl;;
	temp->write(v);
	v.push_back('d');
	temp->append(v);
	temp->read();
	cout << temp->getSize();

	The output is:
	0
	name
	a b c a b c d
	7

5:
By changing the variable from TextFile type to AbstractFile type.
The output remains the same:

0
name
a b c a b c d
7

6: