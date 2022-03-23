# filesystem

This is a C++ project I am currently working on. It emulates a filesystem as seen in the terminal. 

Users can create a hierarchical structure of dictionaries and move up and down between them.

Currently available commands are:
mkdir *dir* - creates a dictionary (in the current dictionary) with name *dir*
cd *dir* - moves to directory with name *dir*. Must be a subdirectory of the current directory.
cd .. - moves up a directory
dir - prints items in current directory
bye - ends the program

Planned for the future: 
-creating files with text content and writing to/reading from them
-deleting directories
-optional save current state of the filesystem to a file, optional read from file when starting the program
-GUI
