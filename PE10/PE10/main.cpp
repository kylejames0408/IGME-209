// 9.1 - Set up your C++ project. Add a single source file called main.cpp. Set it up the usual way: include iostream, using namespace std and main().
#include <iostream>
using namespace std;

#include "Player.h"
#include "Fighter.h"

int main()
{
	// Inform the user of the split between practice exercises
	cout << "===PRACTICE EXERCISE 9===" << endl;

	// 9.5 - In your main() function, create at least 4 characters:
	// 9.5a - Create one as a local variable (on the stack) using the default constructor.
	Player defaultStackPlayer = Player();

	// 9.5b - Create another one on the stack using the parameterized constructor.
	Player paramStackPlayer = Player("Param Stack Player", 5, 5, 5);

	// 9.5c - Create the third using new (on the heap) with the default constructor. Remember: using new will return a pointer.
	Player* defaultHeapPlayer = new Player();

	// 9.5d - The last should be on the heap using the parameterized constructor.
	Player* paramHeapPlayer = new Player("Param Heap Player", 3, 3, 3);

	// 9.6 - One at a time, print them all out. Remember that calling methods of objects referred to by pointers requires the use of the arrow operator.
	defaultStackPlayer.printPlayer();
	paramStackPlayer.printPlayer();
	defaultHeapPlayer->printPlayer();
	paramHeapPlayer->printPlayer();

	// 9.6a - Delete any objects that were created with new before leaving main.
	delete defaultHeapPlayer;
	defaultHeapPlayer = nullptr;
	delete paramHeapPlayer;
	paramHeapPlayer = nullptr;

	// Inform the user of the split between practice exercises
	cout << "\n===PRACTICE EXERCISE 10===" << endl;

	// 10.5 - In your main( ) function, create at least 2 fighters:
	// 10.5a - Create one using the default constructor.
	Fighter defaultStackFighter = Fighter();

	// 10.5b - Create the other using the parameterized constructor.
	Fighter paramStackFighter = Fighter("Param Stack Fighter", "Stack Punch", 7, 7, 7);

	// Extra Heap Fighters
	Fighter* defaultHeapFighter = new Fighter();
	Fighter* paramHeapFighter = new Fighter("Param Heap Fighter", "Heap Kick", 11, 11, 11);

	// 10.6 - One at a time, print them all out. Remember that calling methods of objects referred to by pointers requires the use of the arrow operator.
	defaultStackFighter.printFighter();
	paramStackFighter.printFighter();
	defaultHeapFighter->printFighter();
	paramHeapFighter->printFighter();

	// 10.6a - Delete any objects that were created with new before leaving main.
	delete defaultHeapFighter;
	defaultHeapFighter = nullptr;
	delete paramHeapFighter;
	paramHeapFighter = nullptr;
}