// 2 - Create a new class called Player. This requires you to create both a Player.cpp and Player.h file. You can do this manually, but the easiest way is to right click on your project and
//	choose “Add > Class...”
#pragma once
class Player
{
	// 3 - Once you have the basics set up, add the following declarations in Player.h:
	// 3a - Add several private member variables. There should be a character pointer – a char* – for the player’s name, and at least three integer stats (strength, dexterity, etc.).
private:
	char* name;
	int strength;
	int dexterity;
	int intelligence;

public:
	// Default constructor
	Player();

	// 3b - Declare a parameterized constructor that takes a name and the three stats.
	Player(const char* _name, int _strength, int _dexterity, int _intelligence);

	// Deconstructor
	~Player();

	// 3c - Declare a public void method called printPlayer( ), with no parameters.
	void printPlayer();
};

