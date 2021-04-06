// 2 - Create a new class for a game level. In this class create multiple attributes to describe the level, such as level number, exit location, array of treasure or enemies. There are no
//	right or wrong attributes.
#pragma once
#include <string>

class GameLevel
{
public:
	GameLevel(int _level = 1, int _enemies = 0, std::string _exit = "NONE", std::string item1 = "DUST", std::string item2 = "DIRT", std::string item3 = "POCKET LINT");

	~GameLevel();

	void PrintInfo();

private:
	int level;
	int enemies;
	int treasureSize;
	std::string* treasure;
	std::string exit;
};

