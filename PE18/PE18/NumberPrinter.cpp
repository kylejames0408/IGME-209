// 1a.1 - Create a class named NumberPrinter. This class will hold the threaded code.
#include "NumberPrinter.h"

// 1a.3 - Add a parameterized constructor that accepts that number and saves it.
NumberPrinter::NumberPrinter(int _number)
{
	number = _number;
}

// 1a.4 - void Print();
void NumberPrinter::Print()
{
	// 1a.4a - Print the number 10 times in a row on the same line (with spaces) using cout without a endl
	for (int i = 0; i < 50; i++)
	{
		cout << number << " ";
	}
}