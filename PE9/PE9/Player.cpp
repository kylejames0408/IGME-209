// 2 - Create a new class called Player. This requires you to create both a Player.cpp and Player.h file. You can do this manually, but the easiest way is to right click on your project and
//	choose “Add > Class...”
#include "Player.h"
#include <cstring>
#include <iostream>
using namespace std;

// 4 - Over in Player.cpp, do the following:
// 4a - Update the default constructor to set the three stats to 10 each. Use the string “Unknown” for the name.
Player::Player()
{
	strength = 10;
	dexterity = 10;
	intelligence = 10;
	name = new char[8]{ "Unknown" };
}

// 4b - Create the parameterized constructor, which should receive in all of the data through parameters and store it in the appropriate variables.
Player::Player(const char* _name, int _strength, int _dexterity, int _intelligence)
{
	strength = _strength;
	dexterity = _dexterity;
	intelligence = _intelligence;

	int nameSize = strlen(_name) + 1;
	name = new char[nameSize];
	strcpy_s(name, nameSize, _name);
}

/// <summary>
/// Deconstructor to prevent memory leaks.
/// </summary>
Player::~Player()
{
	strength = 0;
	dexterity = 0;
	intelligence = 0;

	delete[] name;
	name = nullptr;
}

// 4c - Create the printPlayer() method. It should print out the player’s name and stats, one per line. To use cout here, you’ll need to #include <iostream> and set up your using statement in this file.
void Player::printPlayer()
{
	cout << "Name: " << name << endl;
	cout << " Strength:     " << strength << endl;
	cout << " Dexterity:    " << dexterity << endl;
	cout << " Intelligence: " << intelligence << endl;
}
