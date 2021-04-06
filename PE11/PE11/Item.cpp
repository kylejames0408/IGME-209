// 2 - Create a new struct called Item. This requires you to create both an Item.cpp and Item.h file. You can do this manually, but the easiest way is to right click on your project and
//	choose “Add > Class…” and then change the class in the header file to struct.
#include "Item.h"
#include <iostream>
using namespace std;

// 4 - Over in Item.cpp, do the following:
// 4a - Instantiate your variables in the default constructor. | I elected to do so through calling the paramaterized constructor for conciseness.
Item::Item() : Item("Default Item", 0, 0)
{
}

/// <summary>
/// Paramaterized Item constructor.
/// </summary>
/// <param name="_name">The name of the Item</param>
/// <param name="_value">The value of the Item</param>
/// <param name="_weight">the weight of the Item</param>
Item::Item(std::string _name, int _value, float _weight)
{
	name = _name;
	value = _value;
	weight = _weight;
}

// 4b - Create the print( ) method. It should print out the item’s name and stats, one per line. To use cout here, you’ll need to #include <iostream> and set up your using statement in this
//	file.
void Item::print()
{
	cout << "Item Name:   " << name << endl;
	cout << " Value:      " << value << endl;
	cout << " Weight:     " << weight << endl;
}
