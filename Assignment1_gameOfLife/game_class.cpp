#include "game_class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

game_class::game_class()
{
	srand (time(NULL));
	cout << "Created instance of gc" << endl;
	boundrymode = ' ';
	outputfilename = "";
	nextgen = true;
	answer = ' ';
	generationcounter = 0;
	lifecounter = 0;
	height = 0;
	width = 0;
	pausechoice = 0;
	population = 0.0;
	percentage = 0.0;
}

void game_class::inputdimensions()
{	
	
	cout << "Would you like a custom environment, or provide a map file? (C / M)" << endl;
	cin >> answer;
	if (answer == 'C')
	{
		createboard();
	}
	if (answer == 'M')
	{
		writeboard();
	}
}

void game_class::writeboard()
{
	int linecounter = 0;
	string filename = "";
	cout << "What is the name of your provided map file? (including the .txt)" << endl;
	cin >> filename;
	ifstream infile(filename.c_str());
	string line;
	while (getline(infile, line))
	{
		if (linecounter == 0)
		{
			int value = atoi(line.c_str());
			height = value;
		}
		if (linecounter == 1)
		{
			int value = atoi(line.c_str());
			width = value;	
			board = new char*[height];
			for(int i = 0; i < height; ++i)
			{
				board[i] = new char[width];
			}
			newboard = new char*[height];
			backgen1 = new char*[height];
			backgen2 = new char*[height];

			for(int i = 0; i < height; ++i)
			{
				newboard[i] = new char[width];
				backgen1[i] = new char[width];
				backgen2[i] = new char[width];
			}
	
		}
		if (linecounter >= 2)
		{
			for(int j = 0; j < width; ++j)
			{
				board[linecounter-2][j] = line.at(j);
			}
		}
		linecounter++;
	} 
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			cout << board[i][j]  << "  ";
		}
		cout << endl;
	}
	infile.close();
	cout << "Would you like to increment generations slowly, by hitting enter, or have all generations written to a file? Please type 1, 2, or 3 accordingly." << endl;
	cin >> pausechoice;
	if (pausechoice == 3)
	{
		cout << "Please provide a file name to output to!" << endl;
		cin >> outputfilename;
		ofstream myfile (outputfilename.c_str());
		if (myfile.is_open())
		 {
			myfile << "Let there be life!" << endl;
		    myfile.close();
		}
	}
	cout << "And now, what sort of boundry mode would you like? C for classic, M for mirror, or D for doughnut?" << endl;
	cin >> boundrymode;
}

void game_class::createboard()
{
	cout << "Enter the width of the board now please!" << endl;
	cin >> width;
	cout << "And now the height." << endl;
	cin >> height;
	cout << "Now input a decimal value to determine the initial population density! (Between 0 and 1)" << endl;
	cin >> population;
	cout << "And now, what sort of boundry mode would you like? C for classic, M for mirror, or D for doughnut?" << endl;
	cin >> boundrymode;
	cout << "Would you like to increment generations slowly, by hitting enter, or have all generations written to a file? Please type 1, 2, or 3 accordingly." << endl;
	cin >> pausechoice;
	if (pausechoice == 3)
	{
		cout << "Please provide a file name to output to!" << endl;
		cin >> outputfilename;
		ofstream myfile (outputfilename.c_str());
		if (myfile.is_open())
		 {
			myfile << "Let there be life!" << endl;
		    myfile.close();
		}	
	}
	percentage = ((height*width)*(population*100))/100;
	board = new char*[height];
	for(int i = 0; i < height; ++i)
	{
		board[i] = new char[width];
	}
	newboard = new char*[height];
	backgen1 = new char*[height];
	backgen2 = new char*[height];
	for(int i = 0; i < height; ++i)
	{
		newboard[i] = new char[width];
		backgen1[i] = new char[width];
		backgen2[i] = new char[width];
	}
//generate the board
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			board[i][j] = '-'; //generate the board
		}
	}
//randomly places X based on percentage given by user. If there already exists an X (to prevent overlapping,) go again.
	for (int i=0; i<percentage; ++i)
	{
		int x = rand()%height;
		int y = rand()%width;
		if (board[x][y] = '-')
		{
			board[x][y] = 'X';
		}
		else
//circumventing overlapping by resetting the index by 1
		{
			i -= 1;
		}
	}
//print the board
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			cout << board[i][j]  << "  ";
		}
		cout << endl;
//		cout << "height is " << height << " and width is " << width <<endl;
	}
}

void game_class::updateboard()
{
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			board[i][j] = newboard[i][j];
			newboard[i][j] = '-';
			cout << board[i][j]  << "  ";
		}
		cout << endl;
	}
	generationcounter++;
	cout << "Generation " << generationcounter << endl;
	cout << endl;
}

void game_class::classiclife()
{
for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			newboard[i][j] = board[i][j];
		}
	}
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			lifecounter = 0;
			if (i!=height-1)
			{
				if (board[i+1][j] == 'X')
				{
					lifecounter++;
				}
			}
			if (j!=width-1)
			{
				if (board[i][j+1] == 'X')
				{
					lifecounter++;
				}
			}	
			if (i!=height-1 && j!=width-1)
			{
				if (board[i+1][j+1] == 'X')
				{
					lifecounter++;
				}
			}
			if (i!=0)
			{
				if (board[i-1][j] == 'X')
				{
					lifecounter++;
				}
			}
			if (j!=0)
			{
				if (board[i][j-1] == 'X')
				{
					lifecounter++;
				}
			}
			if (i!=0 && j!=0)
			{
				if (board[i-1][j-1] == 'X')
				{
					lifecounter++;
				}
			}
			if (i!=height-1 && j != 0)
			{
				if (board[i+1][j-1] == 'X')
				{
					lifecounter++;
				}
			}
			if (i!=0 && j!=width-1)
			{
				if (board[i-1][j+1] == 'X')
				{
					lifecounter++;
				}
			}
			// calculate the results of the next generation
			if (lifecounter <= 1)
			{
				newboard[i][j] = '-';
			}
			if (lifecounter == 2)
			{
				newboard[i][j] = board[i][j];
			}
			if (lifecounter == 3)
			{
				newboard[i][j] = 'X';
			}
			if (lifecounter >= 4)
			{
				newboard[i][j] = '-';
			}
		}
	}
	updateboard();
}

void game_class::mirrorlife()
{
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			newboard[i][j] = board[i][j];
		}
	}
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			lifecounter = 0;
//j=width	
//top row
			if (i!=height-1)
			{
				if (board[i+1][j] == 'X')
				{
					lifecounter++;
				}
			}
			if (i==height-1)
			{
				if (board[i][j] == 'X')
					lifecounter++;
			}
//bottom row
			if (i!=0)
			{
				if (board[i-1][j]=='X')
					lifecounter++;
			}
			if (i==0)
			{
				if (board[i][j] == 'X')
					lifecounter++;
			}
//left column
			if (j!=0)
			{
				if (board[i][j-1] == 'X')
				{
					lifecounter++;
				}
			}
			if (j==0)
			{
				if (board[i][j] == 'X')
				{
					lifecounter++;
				}
			}
//right column
			if (j!=width-1)
			{
				if (board[i][j+1] == 'X')
				{
					lifecounter++;
				}
			}
			if (j==width-1)
			{
				if (board[i][j] == 'X')
				{
					lifecounter++;
				}
			}
//top-left
			if (i!=height-1 && j!=0)
			{
				if (board[i+1][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=0 && i==height-1)
			{
				if (board[i][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==0 && i!= height-1)
			{
				if (board[i+1][j] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==height-1 && j== 0)
			{
				if (board[i][j] == 'X')
				{
					lifecounter++;	
				}
			}
//top right
			if (i!=height-1 && j!=width-1)
			{
				if (board[i+1][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=width-1 && i==height-1)
			{
				if (board[i][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==width-1 && i!= height-1)
			{
				if (board[i+1][j] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==height-1 && j== width-1)
			{
				if (board[i][j] == 'X')
				{
					lifecounter++;	
				}
			}
//bottom left
			if (i!=0 && j!=0)
			{
				if (board[i-1][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=0 && i==0)
			{
				if (board[i][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==0 && i!= 0)
			{
				if (board[i-1][j] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==0 && j== 0)
			{
				if (board[i][j] == 'X')
				{
					lifecounter++;	
				}
			}
//bottom right
			if (i!=0 && j!=width-1)
			{
				if (board[i-1][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=width-1 && i==0)
			{
				if (board[i][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==width-1 && i!= 0)
			{
				if (board[i-1][j] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==0 && j== width-1)
			{
				if (board[i][j] == 'X')
				{
					lifecounter++;	
				}
			}
// calculate the results of the next generation
			if (lifecounter <= 1)
			{
				newboard[i][j] = '-';
			}
			if (lifecounter == 2)
			{
				newboard[i][j] = board[i][j];
			}
			if (lifecounter == 3)
			{
				newboard[i][j] = 'X';
			}
			if (lifecounter >= 4)
			{
				newboard[i][j] = '-';
			}
		}
	}
	updateboard();
}

void game_class::doughnutlife()
{
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			newboard[i][j] = board[i][j];
		}
	}
	for(int i=0; i<height; i++)    //This loops on the height.
	{
		for(int j=0; j<width; j++) //This loops on the width
		{
			lifecounter = 0;
//j=width	
//top row
			if (i!=height-1)
			{
				if (board[i+1][j] == 'X')
				{
					lifecounter++;
				}
			}
			if (i==height-1)
			{
				if (board[0][j] == 'X')
					lifecounter++;
			}
//bottom row
			if (i!=0)
			{
				if (board[i-1][j]=='X')
					lifecounter++;
			}
			if (i==0)
			{
				if (board[height-1][j] == 'X')
					lifecounter++;
			}
//left column
			if (j!=0)
			{
				if (board[i][j-1] == 'X')
				{
					lifecounter++;
				}
			}
			if (j==0)
			{
				if (board[i][width-1] == 'X')
				{
					lifecounter++;
				}
			}
//right column
			if (j!=width-1)
			{
				if (board[i][j+1] == 'X')
				{
					lifecounter++;
				}
			}
			if (j==width-1)
			{
				if (board[i][0] == 'X')
				{
					lifecounter++;
				}
			}
//top-left
			if (i!=height-1 && j!=0)
			{
				if (board[i+1][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=0 && i==height-1)
			{
				if (board[0][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==0 && i!= height-1)
			{
				if (board[i+1][width-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==height-1 && j== 0)
			{
				if (board[0][width-1] == 'X')
				{
					lifecounter++;	
				}
			}
//top right
			if (i!=height-1 && j!=width-1)
			{
				if (board[i+1][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=width-1 && i==height-1)
			{
				if (board[0][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==width-1 && i!= height-1)
			{
				if (board[i+1][0] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==height-1 && j== width-1)
			{
				if (board[0][0] == 'X')
				{
					lifecounter++;	
				}
			}
//bottom left
			if (i!=0 && j!=0)
			{
				if (board[i-1][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=0 && i==0)
			{
				if (board[height-1][j-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==0 && i!= 0)
			{
				if (board[i-1][width-1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==0 && j== 0)
			{
				if (board[height-1][width-1] == 'X')
				{
					lifecounter++;	
				}
			}
//bottom right
			if (i!=0 && j!=width-1)
			{
				if (board[i-1][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j!=width-1 && i==0)
			{
				if (board[height-1][j+1] == 'X')
				{
					lifecounter++;	
				}
			}
			if (j==width-1 && i!= 0)
			{
				if (board[i-1][0] == 'X')
				{
					lifecounter++;	
				}
			}
			if (i==0 && j== width-1)
			{
				if (board[height-1][0] == 'X')
				{
					lifecounter++;	
				}
			}
// calculate the results of the next generation
			if (lifecounter <= 1)
			{
				newboard[i][j] = '-';
			}
			if (lifecounter == 2)
			{
				newboard[i][j] = board[i][j];
			}
			if (lifecounter == 3)
			{
				newboard[i][j] = 'X';
			}
			if (lifecounter >= 4)
			{
				newboard[i][j] = '-';
			}
		}
	}
	updateboard();
}

void game_class::pause()
{
	switch(pausechoice)
	{
		case 1:
		{
			usleep(200000);
			break;
		}
		case 2:
		{
			if(cin.get()=='\n')
			{

			}
			break;
		}
		case 3:
		{
			ofstream myfile (outputfilename.c_str(),ios::app);
			if (myfile.is_open())
		 	{
				for(int i=0; i<height; i++)    //This loops on the height.
				{
					for(int j=0; j<width; j++) //This loops on the width
					{
						myfile << board[i][j]  << " ";
					}
					myfile << endl;
				}
				myfile << endl;
				myfile << generationcounter << endl;
			    myfile.close();
			}	
		break;
		}
	}
}

void game_class::sustainedlife()
{
	if (generationcounter == 2)
	{
		for(int i=0; i<height; i++)    //This loops on the height.
		{
			for(int j=0; j<width; j++) //This loops on the width
				{
					backgen1[i][j] = board[i][j];
				}
		}
	}
	else if (generationcounter == 3)
	{
		for(int i=0; i<height; i++)    //This loops on the height.
		{
			for(int j=0; j<width; j++) //This loops on the width
				{
					backgen2[i][j] = backgen1[i][j];
				}
		}
		for(int i=0; i<height; i++)    //This loops on the height.
		{
			for(int j=0; j<width; j++) //This loops on the width
				{
					backgen1[i][j] = board[i][j];
				}
		}
	}
	else 
	{
		bool matches1 = true;
		bool matches2 = true;
		for(int i=0; i<height; i++)    //This loops on the height.
		{
			for(int j=0; j<width; j++) //This loops on the width
				{
					if (backgen1[i][j] != board[i][j])
					{
						matches1 = false;
					}
				}
		}
		for(int i=0; i<height; i++)    //This loops on the height.
		{
			for(int j=0; j<width; j++) //This loops on the width
			{
				if (backgen2[i][j] != board[i][j])
				{
					matches2 = false;
				}
			}
		}
		if(matches2 || matches1)
		{
			nextgen = false;
			cout << "Life has stabalized!" << endl;
			cout << "Hit 'enter' to exit!" <<endl;
			if(cin.get()=='\n')
			{
				exit(0);
			}
		}
		else
		{
			for(int i=0; i<height; i++)    //This loops on the height.
		{
			for(int j=0; j<width; j++) //This loops on the width
				{
					backgen2[i][j] = backgen1[i][j];
				}
		}
		for(int i=0; i<height; i++)    //This loops on the height.
		{
			for(int j=0; j<width; j++) //This loops on the width
				{
					backgen1[i][j] = board[i][j];
				}
			}
		}
	}

}

void game_class::play()
{

	if (boundrymode == 'C')
	{
		while (nextgen == true)
		{	
			sustainedlife();
			classiclife();
			pause();
		}
	}
	if (boundrymode == 'M')
	{
		while (nextgen == true)
		{
			int counter = 0;
			counter++;
			sustainedlife();
			mirrorlife();
			pause();
		}
	}
	if (boundrymode == 'D')
	{
		while (nextgen == true)
		{
			int counter = 0;
			counter++;
			sustainedlife();
			doughnutlife();
			pause();
		}
	}
}