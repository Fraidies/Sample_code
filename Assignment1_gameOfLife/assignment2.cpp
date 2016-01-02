#include <iostream>
#include <fstream>
#include <string>
#include "game_class.h"

using namespace std;

int main()
{
	game_class GameOfLife;
	GameOfLife.inputdimensions();
	GameOfLife.play();
	return 0;
}