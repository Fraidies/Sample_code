#ifndef GAME_CLASS_H
#define GAME_CLASS_H
#include <string>

using namespace std;

class game_class
{
	public:
		game_class();
		bool nextgen;
		char **board;
		char **newboard;
		char **backgen1;
		char **backgen2;
		char boundrymode;
		string outputfilename;
		void inputdimensions();
		void sustainedlife();
		void updateboard();
		void classiclife();
		void mirrorlife();
		void play();
		void createboard();
		void life();
		void doughnutlife();
		void writeboard();
		void pause();
		int lifecounter;
		int pausechoice;
		int generationcounter;
		char answer;
		int height;
		int width;
		double population;
		double percentage;
};
#endif