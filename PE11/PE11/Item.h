// 2 - Create a new struct called Item. This requires you to create both an Item.cpp and Item.h file. You can do this manually, but the easiest way is to right click on your project and
//	choose “Add > Class…” and then change the class in the header file to struct.
#pragma once
#include <string>

struct Item
{
	// 3 - Once you have the basics set up, add the following declarations in Item.h:
	// 3a - Add several protected member variables. There should be a std::string for the item’s name, and at least two integer/float stats (damage, weight, etc.). You will need to include
	//	<string>. Strings are essentially the same as you remember them from C#, and have most of the functionality you are familiar with.
protected:
	std::string name;
	int value;
	float weight;

	// Although structs are default public, this is to explicitly show the contrast between public and protected.
public:
	// Default Constructor
	Item();

	// Paramaterized constructor
	Item(std::string _name, int _value, float _weight);

	// 3b - Declare a public void method called print( ), with no parameters.
	virtual void print();
};

