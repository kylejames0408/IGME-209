// 5 - Create four classes that will all be derived from the Item struct. Yes, I said that the struct will be the parent of the class. For example, you could make a sword, shield, helmet,
//  and armor, or go with a different theme. Have the items fit a theme.
#include "Sword.h"
#include <iostream>
using namespace std;

/// <summary>
/// Default Sword constructor.
/// </summary>
Sword::Sword() : Item("Sword", 10, 5)
{
	// Initialize Fields
	damage = 5;
}

/// <summary>
/// Paramaterized Sword constructor.
/// </summary>
/// <param name="_name">The name of the Sword.</param>
/// <param name="_value">The value of the Sword.</param>
/// <param name="_weight">The weight of the Sword.</param>
/// <param name="_damage">The damage of the Sword.</param>
Sword::Sword(std::string _name, int _value, float _weight, int _damage) : Item(_name, _value, _weight)
{
	// Initialize Fields
	damage = _damage;
}

/// <summary>
/// Prints information about the Sword.
/// </summary>
void Sword::print()
{
	// Calls the base class print
	Item::print();

	// Adds it's unique print feature
	cout << " Damage:     " << damage << endl;
}
