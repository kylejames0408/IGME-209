// 5 - Create four classes that will all be derived from the Item struct. Yes, I said that the struct will be the parent of the class. For example, you could make a sword, shield, helmet,
//  and armor, or go with a different theme. Have the items fit a theme.
#include "Shield.h"
#include <iostream>
using namespace std;

/// <summary>
/// Default Shield constructor.
/// </summary>
Shield::Shield() : Item("Shield", 7, 2)
{
	// Initialize Fields
	defense = 2;
}

/// <summary>
/// Paramaterized Shield constructor.
/// </summary>
/// <param name="_name">The name of the Shield.</param>
/// <param name="_value">The value of the Shield.</param>
/// <param name="_weight">The weight of the Shield.</param>
/// <param name="_defense">The defense of the Shield.</param>
Shield::Shield(std::string _name, int _value, float _weight, int _defense) : Item(_name, _value, _weight)
{
	// Initialize Fields
	defense = _defense;
}

/// <summary>
/// Prints information about the Shield.
/// </summary>
void Shield::print()
{
	// Calls the base class print
	Item::print();

	// Adds it's unique print feature
	cout << " Defense:    " << defense << endl;
}
