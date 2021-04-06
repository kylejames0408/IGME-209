// 5 - Create four classes that will all be derived from the Item struct. Yes, I said that the struct will be the parent of the class. For example, you could make a sword, shield, helmet,
//  and armor, or go with a different theme. Have the items fit a theme.
#include "Armor.h"
#include <iostream>
using namespace std;

/// <summary>
/// Default Armor constructor.
/// </summary>
Armor::Armor() : Item("Armor", 15, 10)
{
	// Initialize Fields
	threshold = 3;
}

/// <summary>
/// Paramaterized Armor constructor.
/// </summary>
/// <param name="_name">The name of the Armor.</param>
/// <param name="_value">The value of the Armor.</param>
/// <param name="_weight">The weight of the Armor.</param>
/// <param name="_threshold">The threshold of the Armor.</param>
Armor::Armor(std::string _name, int _value, float _weight, int _threshold) : Item(_name, _value, _weight)
{
	// Initialize Fields
	threshold = _threshold;
}

/// <summary>
/// Prints information about the Armor.
/// </summary>
void Armor::print()
{
	// Calls the base class print
	Item::print();

	// Adds it's unique print feature
	cout << " Threshold:  " << threshold << endl;
}
