// 2 - Create a new class for a game level. In this class create multiple attributes to describe the level, such as level number, exit location, array of treasure or enemies. There are no
//	right or wrong attributes.
#include "GameLevel.h"
#include <iostream>
using namespace std;

// 2a - In the constructor and destructor, add a print statement to see when things get created and deleted.
GameLevel::GameLevel(int _level, int _enemies, std::string _exit, std::string item1, std::string item2, std::string item3)
{
	cout << "Game Level Constructor" << endl;

	level = _level;
	enemies = _enemies;
	exit = _exit;
	treasureSize = 3;
	treasure = new std::string[treasureSize]{ item1, item2, item3 };
}

GameLevel::~GameLevel()
{
	cout << "Game Level Destructor" << endl;

	delete[] treasure;
	treasure = nullptr;
	treasureSize = 0;
}

void GameLevel::PrintInfo()
{
	cout << "GAME LEVEL INFORMATION" << endl;
	cout << " Level:   " << level << endl;
	cout << " Enemies: " << enemies << endl;
	cout << " Exit:    " << exit << endl;
	cout << " Treasure:" << endl;
	
	for (int i = 0; i < treasureSize; i++)
	{
		cout << "	" << treasure[i] << endl;
	}
}
