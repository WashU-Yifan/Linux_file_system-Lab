studio 18 answers here
Team member: Yifan Wang

2:
	We have to re-define the createFile method in the new file system, which costs extra time.
Also, if we add a new type of file type. Then we have to go to every file system to modify our code to accommondate the new file type.

3:
	Advantage of using a factory pattern is that we can save a lot space and time when adding a new file type 
to the system. The diadvantage is that we may want to declare and define a helper function since factory does not have
access to the containers of file system.

	The only thing we have to modify is to add several new lines of code to the createFile in factory.

	The same factory implementation can be used for both situation since the factory can handle all defined file types.

4:
`bstractFileSystem* abs = new SimpleFileSystem();
	AbstractFileFactory* abf = new SimpleFileFactory();
	AbstractFile* a = abf->createFile("a.txt");
	AbstractFile* b = abf->createFile("b.img");
	AbstractFile* c = abf->createFile("c.txt");
	AbstractFile* d = abf->createFile("d.img");
	abs->addFile("a.txt",a);
	abs->addFile("b.img", a);
	abs->addFile("c.txt", a);
	abs->addFile("d.img", a);

Modified the addFile function so that it will print "successful adding\n" if adding was successful:

int SimpleFileSystem::addFile(string filename, AbstractFile* afile) {
	if (files[filename] != nullptr) {//check is the file already exist
		return invalid_input;
	}
	else if (afile == nullptr)//check is the pointer pointing to an file 
		return invalid_input;
	else {
		files.erase(filename);//to prevent the [] operator creating a pair that with empty value
		files.insert(pair<string, AbstractFile*>(filename, afile));
		std::cout << "successful adding\n";
		return success;
	}
};

Here is the output:

successful adding
successful adding
successful adding
successful adding

5:
	The SimpleFileSystem now only depends on the AbstractFile.h file