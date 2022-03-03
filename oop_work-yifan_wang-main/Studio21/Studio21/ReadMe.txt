Studio 21 ReadMe.txt 

2:
	Since concrete command object might contain pointers to commands. We need to define a virtual destructor
 and let compiler to decide which version of the destructor we are going to use.

 3:
	Since the CommandPrompt object is merely an invoker to command objects. How those file systtem and file factory
interact after calling a command will in the scope of those concrete command objects. The invoker is just a container for 
those command object and it doesn't have to know implementation of those commands.

4:
    SimpleFileSystem* sfs = new SimpleFileSystem();
	SimpleFileFactory* sff = new SimpleFileFactory();
	AbstractCommand* ac = new TouchCommand(sfs,sff);
	CommandPrompt cp;
	cp.addCommand("touch", ac);
	cp.run();
	sfs->openFile("text.txt");

	Also I modify the openFile method so that it prints out a message if the file is in the files[] container. Here is the output message:

	Enter a command, q to quit, help for a list of commands,
	or help followed by a command name for more information about that command.
	$   touch text.txt
	touchsuccessful adding
	Enter a command, q to quit, help for a list of commands,
	or help followed by a command name for more information about that command.
	$   q
	YES!
