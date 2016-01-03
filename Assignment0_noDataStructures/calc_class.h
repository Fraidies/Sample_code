#ifndef CALC_CLASS_H
#define CALC_CLASS_H

#include <string>
class calc_class
{
	//the lack of private variables is due to haste in turning in on time. Current code of mine is legitimately not horrid. Promise. 
	public:
		calc_class();
		void openFile(std::string fileName);
		int calcSum();
		void calcstdev(std::string fileName);
		void calcgauss();
		int linecounter;
		int counter;
		int bigramcounter;
		int counterA;
		int counterT;
		int counterC;
		int counterG;
		int counterAA;
		int counterTA;
		int counterCA;
		int counterGA;
		int counterAT;
		int counterTT;
		int counterCT;
		int counterGT;
		int counterAC;
		int counterTC;
		int counterCC;
		int counterGC;
		int counterAG;
		int counterTG;
		int counterCG;
		int counterGG;
		void file_print();
		void sum_print();
		void mean_print();
		void stdev_print();
		void variance_print();
		void probability_print();
		double mean;
		double stdev;
};
#endif