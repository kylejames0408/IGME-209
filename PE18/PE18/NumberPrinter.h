// 1a.1 - Create a class named NumberPrinter. This class will hold the threaded code.
#pragma once
#include <iostream>

using namespace std;

class NumberPrinter
{
public:
	// 1a.3 - Add a parameterized constructor that accepts that number and saves it.
	NumberPrinter(int _number);
	// 1a.4 - void Print();
	void Print();

private:
	// 1a.2 - Declare an int field called “number”
	int number;
};