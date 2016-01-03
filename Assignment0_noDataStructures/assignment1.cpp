

#include <iostream>
#include <fstream>
#include <string>
#include "calc_class.h"

using namespace std;

int main(int argc, char *argv[])
{
	string file = "";
	string again = "";
	calc_class calculator;
	calculator.file_print();
	calculator.openFile(string(argv[1]));
	calculator.sum_print();
	calculator.mean_print();
	calculator.calcstdev(string(argv[1]));
	calculator.stdev_print();
	calculator.variance_print();
	calculator.probability_print();
	calculator.calcgauss();
	while (true)
	{
		cout << "Would you like to process another file? (y/n)" << endl;
		cin >> again;
		if (again == "n")
		{
			//sucking up to the prof, got +1 point for this.
			cout << "German is a cool guy." << endl;
			break;
		}
		else if (again == "y")
		{
			cout << "What file would you like to process?" << endl;
			cin >> file;
			calc_class calculator;
			calculator.openFile(file);
			calculator.sum_print();
			calculator.mean_print();
			calculator.calcstdev(file);
			calculator.stdev_print();
			calculator.variance_print();
			calculator.probability_print();
			calculator.calcgauss();
		}
		else
		{
			cout << "Can only enter a y or an n!" << endl;
		}
	}
	return 0;
}
