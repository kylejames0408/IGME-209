// 5 - Create four classes that will all be derived from the Item struct. Yes, I said that the struct will be the parent of the class. For example, you could make a sword, shield, helmet,
//  and armor, or go with a different theme. Have the items fit a theme.
#include "Helmet.h"
#include <iostream>
using namespace std;

/// <summary>
/// Default Helmet constructor.
/// </summary>
Helmet::Helmet() : Item("Helmet", 2, 1)
{
	// Initialize Fields
	resistance = 1;
}

/// <summary>
/// Paramaterized Helmet constructor.
/// </summary>
/// <param name="_name">The name of the Helmet.</param>
/// <param name="_value">The value of the Helmet.</param>
/// <param name="_weight">The weight of the Helmet.</param>
/// <param name="_resistance">The resistance of the Helmet.</param>
Helmet::Helmet(std::string _name, int _value, float _weight, int _resistance) : Item(_name, _value, _weight)
{
	// Initialize Fields
	resistance = _resistance;
}

/// <summary>
/// Prints information about the Helmet.
/// </summary>
void Helmet::print()
{
	// Calls the base class print
	Item::print();

	// Adds it's unique print feature
	cout << " Resistance: " << resistance << endl;
}
