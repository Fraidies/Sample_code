#include "calc_class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define _USE_MATH_DEFINES
using namespace std;

calc_class::calc_class(){
	cout << "Created instance of cc" << endl;
	counter = 0;
	bigramcounter = 0;
	linecounter = 1;
	counterA=0;
	counterT=0;
	counterC=0;
	counterG=0;
	counterAA=0;
	counterTA=0;
	counterCA=0;
	counterGA=0;
	counterAT=0;
	counterTT=0;
	counterCT=0;
	counterGT=0;
	counterAC=0;
	counterTC=0;
	counterCC=0;
	counterGC=0;
	counterAG=0;
	counterTG=0;
	counterCG=0;
	counterGG=0;
	mean = 0.0;
	stdev = 0.0; 
}

void calc_class::openFile(string fileName){

	ifstream infile;
	infile.open(fileName.c_str());
	if(infile.fail()) //if file exists / is corrupted...
	{
		cout << "Error opening file." << endl;
	}
	char x, y, z;
	int count = 0;
	while (infile.get(x)) //read a file untill end (eof)
	{
		x= toupper(x);
		if (x=='A')
		{
			counterA++;
		}
		if (x=='T')
		{
			counterT++;
		}	
		if (x=='C')
		{
			counterC++;
		}		
		if (x=='G')
		{
			counterG++;
		}
		if ((x=='A') || (x=='T') || (x=='C') || (x=='G'))
		{
			counter++;
			count++;
		}
		if (x=='\n')
		{   
			linecounter++;
		}
		if (counter == 1)
		{
			y = x;
		}
		if (counter >= 2)
		{
			z = x;
			if (y == 'A' && z=='A')
			{
				counterAA++;
			}
			if (y == 'A' && z=='T')
			{
				counterAT++;
			}
			if (y == 'A' && z=='C')
			{
				counterAC++;
			}
			if (y == 'A' && z=='G')
			{
				counterAG++;
			}
			if (y == 'T' && z=='A')
			{
				counterTA++;
			}
			if (y == 'T' && z=='T')
			{
				counterTT++;
			}
			if (y == 'T' && z=='C')
			{
				counterTC++;
			}
			if (y == 'T' && z=='G')
			{
				counterTG++;
			}
			if (y == 'C' && z=='A')
			{
				counterCA++;
			}
			if (y == 'C' && z=='T')
			{
				counterCT++;
			}
			if (y == 'C' && z=='C')
			{
				counterCC++;
			}
			if (y == 'C' && z=='G')
			{
				counterCG++;
			}
			if (y == 'G' && z=='A')
			{
				counterGA++;
			}
			if (y == 'G' && z=='T')
			{
				counterGT++;
			}
			if (y == 'G' && z=='C')
			{
				counterGC++;
			}
			if (y == 'G' && z=='G')
			{
				counterGG++;
			}
			bigramcounter++;
			y = z;
		}
	}

}

void calc_class::file_print()
{

	ofstream myfile ("kevinhewitt.out");
	if (myfile.is_open())
	 {
		myfile << "Student name: Kevin Hewitt" << '\n' << "Student ID: 1809993" << '\n';
	    myfile.close();
	}	
}

void calc_class::sum_print()
{
	ofstream myfile ("kevinhewitt.out",ios::app);
	if (myfile.is_open())
 	{
		myfile << "There were a total of " << counter << " nucleotides!" << '\n';
    	myfile.close();
	}	
}

void calc_class::mean_print()
{
	mean = counter / linecounter;
	ofstream myfile ("kevinhewitt.out",ios::app);
	if (myfile.is_open())
	{
		myfile << "The mean in " << mean << "." << '\n'; 
//		myfile << "counter is at " << linecounter << '\n';
		myfile.close();
	}
}

void calc_class::stdev_print()
{
	ofstream myfile ("kevinhewitt.out",ios::app);
	if (myfile.is_open())
	{
		myfile << "The standard deviation is " << stdev << "!" << '\n';
		myfile.close();
	}
}

void calc_class::variance_print()
{	
	ofstream myfile ("kevinhewitt.out",ios::app);
	if (myfile.is_open())
	{
		myfile << "The variance is " << stdev*stdev << "!" << '\n';
		myfile.close();
	}
}

void calc_class::probability_print()
{
	ofstream myfile ("kevinhewitt.out",ios::app);
	if (myfile.is_open())
	{
		myfile << "The probability of adenine is " << (((double)counterA / (double)counter)*100) << "%\n";
			myfile << "The probability of thymine is " << (((double)counterT / (double)counter)*100) << "%" <<"\n";
				myfile << "The probability of cytosine is " << (((double)counterC / (double)counter)*100) << "%" <<'\n';
			myfile << "The probability of guanine is " << (((double)counterG / (double)counter)*100) << "%" <<'\n';
		myfile << "The probability of an AA bigram is " << (((double)counterAA / (double)bigramcounter)*100) << "%" <<'\n';
			myfile << "The probability of an AT bigram is " << (((double)counterAT / (double)bigramcounter)*100) << "%" <<'\n'; 
				myfile << "The probability of an AC bigram is " << (((double)counterAC / (double)bigramcounter)*100) << "%" <<'\n'; 
					myfile << "The probability of an AG bigram is " << (((double)counterAG / (double)bigramcounter)*100) << "%" <<'\n'; 
						myfile << "The probability of an TA bigram is " << (((double)counterTA / (double)bigramcounter)*100) << "%" <<'\n'; 
					myfile << "The probability of an TT bigram is " << (((double)counterTT / (double)bigramcounter)*100) << "%" <<'\n'; 
				myfile << "The probability of an TC bigram is " << (((double)counterTC / (double)bigramcounter)*100) << "%" <<'\n'; 
			myfile << "The probability of an TG bigram is " << (((double)counterTG / (double)bigramcounter)*100) << "%" <<'\n'; 
		myfile << "The probability of an CA bigram is " << (((double)counterCA / (double)bigramcounter)*100) << "%" <<'\n'; 
			myfile << "The probability of an CT bigram is " << (((double)counterCT / (double)bigramcounter)*100) << "%" <<'\n'; 
				myfile << "The probability of an CC bigram is " << (((double)counterCC / (double)bigramcounter)*100) << "%" <<'\n'; 
					myfile << "The probability of an CG bigram is " << (((double)counterCG / (double)bigramcounter)*100) << "%" <<'\n'; 
				myfile << "The probability of an GA bigram is " << (((double)counterGA / (double)bigramcounter)*100) << "%" <<'\n'; 
			myfile << "The probability of an GT bigram is " << (((double)counterGT / (double)bigramcounter)*100) << "%" <<'\n'; 
		myfile << "The probability of an GC bigram is " << (((double)counterGC / (double)bigramcounter)*100) << "%" <<'\n'; 
	myfile << "The probability of an GG bigram is " << (((double)counterGG / (double)bigramcounter)*100) << "%" <<'\n'; 
	myfile.close();
	}
}

void calc_class::calcstdev(string fileName)
{
	ifstream infile;
	infile.open(fileName.c_str());
	string line;
	double deltadouble;
	while (infile.good())
	{
		getline(infile,line);
		int linelength = line.size()-1;
		int c = infile.peek();
		if (!infile.good())
		{
			linelength += 1;
		}
		double delta = (linelength - mean)*(linelength - mean);
		deltadouble += delta;
	}
	double deltacounter = deltadouble / linecounter;
	stdev = sqrt(deltacounter);
}

void calc_class::calcgauss()
//C = sqrt(-2 ln (a)) * cos(2πb)
//D = stdevC + mean
{		
	srand (time(NULL));
	ofstream myfile ("kevinhewitt.out",ios::app);
	for (int i=0; i<1000; ++i)
	{
		
		int tempA = rand() % 100+1;
		int tempB = rand() % 100+1;
		double a = ((double)(tempA)/(double)100);
		double b = ((double)(tempB)/(double)100);
	//	cout << "TempA is " << tempA << endl;
	//	cout << "TempB is " << tempB << endl;
	//	cout << "A is " << a << endl;
	//	cout << "B is " << b << endl;
		double C = sqrt(-2*log(a))*cos(2*M_PI*b);
	//	cout << "C is " << C << endl;
		double D = stdev*C + mean;
	//	cout << "D is " << D << endl;

		string DNA = "";
		char nucleotide = 'p';
		if (D >= 0)
		{
			for (int i=0; i<(int)D; ++i)
			{
				int temp = rand() % 100;
		//		cout << "temp is " << temp << endl;
		//		cout << "(((double)counterA / (double)counter)*100) is " << (((double)counterA / (double)counter)*100) << endl;
				double nucleoA = (((double)counterA / (double)counter)*100);
				double nucleoT = (((double)counterT / (double)counter)*100);
				double nucleoC = (((double)counterC / (double)counter)*100); 
				if (temp <= nucleoA)
				{
					nucleotide = 'A';
				}
				else if (temp <=nucleoA+ nucleoT)
				{
					nucleotide = 'T';
				}
				else if (temp <=nucleoA+ nucleoT+ nucleoC)
				{
					nucleotide = 'C';
				}
				else
				{
					nucleotide = 'G';
				}
				
				DNA += nucleotide;
			}


			if (myfile.is_open())
			{
				myfile << DNA << endl;
//				cout << "DNA string is " << DNA << endl;
			}
		}
		else 
		{
			--i;
		}
	}
	myfile.close();
}
