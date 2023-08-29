# 📖 get_next_line #
** Reading a line on a fd is way too tedious **
![image](https://github.com/celiamateos/get_next_line/assets/127442472/e6acef71-d115-46b4-ba85-219cb8e80ba1)
![image](https://github.com/celiamateos/get_next_line/assets/127442472/0330442d-7906-4fc3-a20b-75378a039586)


💡 About the project
The aim of this project is to make you code a function that returns a line, read from a file descriptor.

You will understand how files are opened, read and closed in an OS,
and how they are interpreted by a programming language for further analysis.
This task is crucial to understand for a future programmer since much of the time is based
on manipulating files for data management and persistence.
This project consists of coding a function that returns one line at a time from a text file.
For more detailed information, look at the subject of this project.

🛠️ Usage
Requirements
The function is written in C language and thus needs the gcc compiler and some standard C libraries to run.

Instructions
1. Using it in your code

To use the function in your code, simply include its header:

#include "get_next_line.h"
and, when compiling your code, add the source files and the required flag:

get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
📋 Testing
You only have to edit the get_next_line.c file and uncomment the main function and headers inside it. You can edit test.txt files to put another text if you wish to test othe cases. Then simply run this command (change "xx" with desired buffer size) :

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
