#include <iostream>
#include "Stack.h"
#include "Player.h"

// Memory Leak Detection Inclusions
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

void wrapper()
{
	// Your Main.cpp MUST have the following:
	// Three stacks, each of a different data type. For each, do the following:
	cout << "|==========CREATING THREE STACKS==========|" << endl;
	cout << "TYPES: int, char, bool" << endl;
	Stack<int> intStack;
	Stack<char> charStack;
	Stack<bool> boolStack;

	// Add data to the stack with Push(), print it out using Print(), Pop() some elements from it, and then Print() again to prove that they have been “removed”.
	cout << endl << endl << endl << "|================INT STACK================|" << endl;
	cout << "Pushing numbers 1-6 to the Stack..." << endl;
	intStack.Push(new int(1));
	intStack.Push(new int(2));
	intStack.Push(new int(3));
	intStack.Push(new int(4));
	intStack.Push(new int(5));
	intStack.Push(new int(6));
	cout << "STACK ITEMS: ";
	intStack.Print();
	cout << "Popping two Stack items: ";
	cout << *intStack.Pop() << " ";
	cout << *intStack.Pop() << endl << "STACK ITEMS: ";
	intStack.Print();

	// Add data to the stack with Push(), print it out using Print(), Pop() some elements from it, and then Print() again to prove that they have been “removed”.
	cout << endl << endl << endl << "|================CHAR STACK================|" << endl;
	cout << "Pushing letters a-f to the Stack..." << endl;
	charStack.Push(new char('a'));
	charStack.Push(new char('b'));
	charStack.Push(new char('c'));
	charStack.Push(new char('d'));
	charStack.Push(new char('e'));
	charStack.Push(new char('f'));
	cout << "STACK ITEMS: ";
	charStack.Print();
	cout << "Popping three Stack items: ";
	cout << *charStack.Pop() << " ";
	cout << *charStack.Pop() << " ";
	cout << *charStack.Pop() << endl << "STACK ITEMS: ";
	charStack.Print();
	
	// Add data to the stack with Push(), print it out using Print(), Pop() some elements from it, and then Print() again to prove that they have been “removed”.
	cout << endl << endl << endl << "|================BOOL STACK================|" << endl;
	cout << "Pushing boolean values to the Stack..." << endl;
	boolStack.Push(new bool(true));
	boolStack.Push(new bool(false));
	boolStack.Push(new bool(false));
	boolStack.Push(new bool(true));
	boolStack.Push(new bool(true));
	boolStack.Push(new bool(false));
	cout << "STACK ITEMS: ";
	boolStack.Print();
	cout << "Popping two Stack items: ";
	cout << *boolStack.Pop() << " ";
	cout << *boolStack.Pop() << endl << "STACK ITEMS: ";
	boolStack.Print();
	
	// Prove that your copy constructor and copy assignment operators work.
	// Create a new stack using another with the same template type as the parameter for your copy constructor.Print() it out.
	cout << endl << endl << endl << "|==============COPY INT STACK==============|" << endl;
	cout << "Copying intStack to copyIntStack with the copy constructor..." << endl;
	Stack<int> copyIntStack = Stack<int>(intStack);
	cout << "STACK ITEMS: ";
	copyIntStack.Print();
	
	// Pop() some values from your new stack, Print() it again, and then set it equal to the original. Print() it a third time.
	cout << "Popping two Stack items: ";
	cout << *copyIntStack.Pop() << " ";
	cout << *copyIntStack.Pop() << endl << "STACK ITEMS: ";
	copyIntStack.Print();
	cout << "Copying intStack to copyIntStack with the copy assignment constructor..." << endl;
	copyIntStack = intStack;
	cout << "STACK ITEMS: ";
	copyIntStack.Print();
	
	// Extra Credit
	cout << endl << endl << endl << "|=======CREATING PLAYER CLASS STACK=======|" << endl;
	Stack<Player> playerStack;
	cout << "Pushing Player values to the Stack..." << endl;
	playerStack.Push(new Player());
	playerStack.Push(new Player("Sparrow", "Pirate"));
	playerStack.Push(new Player("Harry", "Wizard"));
	playerStack.Push(new Player("Mace", "Jedi"));
	playerStack.Push(new Player("Indy", "Archaeologist"));
	playerStack.Push(new Player("Apollo", "Boxer"));
	playerStack.Push(new Player("Quint", "Shark Hunter"));
	cout << "STACK ITEMS:\n ";
	playerStack.Print();
	cout << "Popping two Stack items:\n ";
	cout << *playerStack.Pop() << " ";
	cout << *playerStack.Pop() << "\nSTACK ITEMS:\n ";
	playerStack.Print();
	
	cout << endl << endl << endl << "|============COPY PLAYER STACK============|" << endl;
	cout << "Copying playerStack to copyPlayerStack with the copy constructor..." << endl;
	Stack<Player> copyPlayerStack = Stack<Player>(playerStack);
	cout << "STACK ITEMS:\n ";
	copyPlayerStack.Print();
	
	cout << "Popping two Stack items:\n ";
	cout << *copyPlayerStack.Pop() << " ";
	cout << *copyPlayerStack.Pop() << "\nSTACK ITEMS:\n ";
	copyPlayerStack.Print();
	cout << "Copying playerStack to copyPlayerStack with the copy assignment constructor..." << endl;
	copyPlayerStack = playerStack;
	cout << "STACK ITEMS:\n ";
	copyPlayerStack.Print();
}

int main()
{
	wrapper();

	// Check for memory leaks
	_CrtDumpMemoryLeaks();
}