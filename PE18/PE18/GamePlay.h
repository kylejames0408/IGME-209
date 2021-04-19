// 2a - Create a class named GamePlay. This class will hold the threaded code.
#pragma once
#include <string>
#include <iostream>

using namespace std;

class GamePlay
{
public:
	// 2a.2 - Create a parameterized constructor that accepts and saves the name.
	GamePlay(string _control);
	// 2a.3 - Within the class create a method named Update. This method will be public, will return nothing, and will have no parameters. The method should loop 10 times, printing the
	//	name and a percent completed message, each on a single line, like so:
	//		Physics: 10% Complete
	//		Physics: 20 % Complete
	//		Physics: 30 % Complete
	void Update();

private:
	// 2a.1 - Create a field to hold a name. This will be the name of the portion of game play this object controls, such as “Physics” or “Pathfinding”.
	string control;
};

