Studio 20 ReadMe.txt


2:
 We have to destroy the abstractFile pointer by calling delete or memory leaks might happen.

4:
    std::string a(5,'x');
	AbstractFile* af = new TextFile(a);
	AbstractFile *proxy = new PasswordProxy(af, "123456");
	vector<char> temp = { 'a','b','c','d' };
	proxy->append(temp);
	for (char temp : proxy->read()) {
		cout << temp << " ";
	}
	return 0;

	The code above will require the user to type password twice.
	The vector will only be printed out only if both password are typed correctly.