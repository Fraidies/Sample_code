#include <string>
#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void readfile();

int main(int argc, char *argv[])
{
	readfile();
}

void error(int lines, char delim);

void readfile()
{
	string name;
	string line;
	char tempPop;
	GenStack<char> delimStack(12);
	delimStack.push('#');
	int linecounter = 1;

	cout << "What's the name of your file?" << endl;
	getline(cin, name);
	ifstream inFile(name.c_str());
	if(!inFile)
	{
		cout << "Something went wrong with the file" << endl;
		exit(0);
	}
	while(!inFile.eof()){
		getline(inFile, line);
		for (int i=0; i<line.length(); ++i)
		{
			char ch = line[i];
			if (ch == '\n')
			{
				linecounter++;
			}
			switch(ch)
			{
				case '{':
				delimStack.push(ch);
				break;
				case '[':
				delimStack.push(ch);
				break;
				case '(':
				delimStack.push(ch);
				break;
			}
			if (line[i] == ')' && delimStack.top() != '(')
			{
				char delim = delimStack.top();
				error(linecounter, delim);
			}
			if (line[i] == ']' && delimStack.top() != '[')
			{
				char delim = delimStack.top();
				error(linecounter, delim);
			}
			if (line[i] == '}' && delimStack.top() != '{')
			{
				char delim = delimStack.top();
				error(linecounter, delim);
			}
			if (line[i] == ')' && delimStack.top() == '(')
			{
				delimStack.pop(tempPop);
			}
			if (line[i] == ']' && delimStack.top() == '[')
			{
				delimStack.pop(tempPop);
			}
			if (line[i] == '}' && delimStack.top() == '{')
			{
				delimStack.pop(tempPop);
			}
		}
	}
	if(!delimStack.empty()){
		char delim = delimStack.top();
		error(linecounter, delim);
	}
}

void error(int lines, char delim)
{
	cout << "Error! Need to close " << delim << " at line " << lines << endl;
}
