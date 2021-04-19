// 2a - Create a class named GamePlay. This class will hold the threaded code.
#include "GamePlay.h"

// 2a.2 - Create a parameterized constructor that accepts and saves the name.
GamePlay::GamePlay(string _control)
{
	control = _control;
}

// 2a.3 - Within the class create a method named Update. This method will be public, will return nothing, and will have no parameters. The method should loop 10 times, printing the name
//	and a percent completed message, each on a single line, like so:
//		Physics: 10% Complete
//		Physics: 20 % Complete
//		Physics: 30 % Complete
void GamePlay::Update()
{
	for (int i = 0; i < 10; i++)
	{
		cout << control << ": " << (i + 1) * 10 << "% Complete" << endl;
	}
}
