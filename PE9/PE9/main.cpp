// 1 - Set up your C++ project. Add a single source file called main.cpp. Set it up the usual way: include iostream, using namespace std and main().
#include <iostream>
using namespace std;

#include "Player.h"

int main()
{
	// 5 - In your main() function, create at least 4 characters:
	// 5a - Create one as a local variable (on the stack) using the default constructor.
	Player defaultStackPlayer = Player();

	// 5b - Create another one on the stack using the parameterized constructor.
	Player paramStackPlayer = Player("Param Stack Player", 5, 5, 5);

	// 5c - Create the third using new (on the heap) with the default constructor. Remember: using new will return a pointer.
	Player* defaultHeapPlayer = new Player();

	// 5d - The last should be on the heap using the parameterized constructor.
	Player* paramHeapPlayer = new Player("Param Heap Player", 3, 3, 3);

	// 6 - One at a time, print them all out. Remember that calling methods of objects referred to by pointers requires the use of the arrow operator.
	defaultStackPlayer.printPlayer();
	paramStackPlayer.printPlayer();
	defaultHeapPlayer->printPlayer();
	paramHeapPlayer->printPlayer();

	// 6a - Delete any objects that were created with new before leaving main.
	delete defaultHeapPlayer;
	defaultHeapPlayer = nullptr;
	delete paramHeapPlayer;
	paramHeapPlayer = nullptr;
}