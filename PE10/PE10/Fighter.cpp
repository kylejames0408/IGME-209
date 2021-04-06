// 10.2 - Create a new class called Fighter. Right click, go to Add > Class… to use Visual Studio’s Class Wizard.
// 10.2a - After you enter the name of the class, also enter the base class name Player (the class you made last time). The access should be “public”.
#include "Fighter.h"
#include <cstring>
#include <iostream>
using namespace std;

// 10.4 Over in Fighter.cpp, do the following:
// 10.4a - Update the default constructor to set a default value for the fighter’s weapon skill. Player’s default constructor will be called automatically.
Fighter::Fighter() : Player()
{
	weaponSkill = new char[8]{ "Default" };
}

// 10.4b - Create the parameterized constructor, which should receive in all of the data through parameters. Call Player’s parameterized constructor, passing in the 4 necessary pieces of
//	data. Save the weapon skill here as well.
Fighter::Fighter(const char* _name, const char* _weaponSkill, int _strength, int _dexterity, int _intelligence) : Player(_name, _strength, _dexterity, _intelligence)
{
	int skillSize = strlen(_weaponSkill) + 1;
	weaponSkill = new char[skillSize];
	strcpy_s(weaponSkill, skillSize, _weaponSkill);
}

/// <summary>
/// Deconstructor to prevent memory leaks for the Fighter class.
/// </summary>
Fighter::~Fighter()
{
	delete[] weaponSkill;
	weaponSkill = nullptr;
}

// 10.4c - Create the printFighter( ) method. It should call the base class’s printPlayer( ) method, and also print out this fighter’s weapon skill. Reminder: To use cout here, you’ll need
//	to #include <iostream> and set up your using statement in this file.
void Fighter::printFighter()
{
	printPlayer();

	cout << " Weapon Skill: " << weaponSkill << endl;
}