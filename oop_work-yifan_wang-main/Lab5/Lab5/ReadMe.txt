Lab 5 Readme
Group Member: Yifan Wang

I ususally prefer checking the correctness of  my code by commenting out the part of tests in UniTest and run tests on the methods that
I have written. So I don't usually check my code in main. But here are few:

    AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	CommandPrompt* cp = new CommandPrompt();
	string filename = "file.txt";
	AbstractFile* file = new TextFile(filename);
	sfs->addFile(filename, file);
	vector<char> origContents = { 'f','o','o' };
	file->append(origContents);
	CatCommand* cc = new CatCommand(sfs);
	cp->addCommand("cat", cc);
	cp->run();

	This is for testing whether the 'f','o','o' is still in the file.txt object after calling cat command on it.

	Most of the errors that I ran into are insignificant: missing space adding extra spaces.

	Here are some of the errors(but all are fixed) :

	 Message: 
    Assert failed. Unexpected equality:<0>
     Stack Trace: 
    renameCommand::renameInvalidNewFilename() line 1991
	
	Forget to check if the rename file already exist.
	add another logic gate in the execute() method in the CopyCommand file.