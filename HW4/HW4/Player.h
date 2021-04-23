#pragma once
#include <string>
#include <ostream>

using namespace std;

class Player
{
private:
	string name;
	string characterClass;

public:
	/// <summary>
	/// Default Player constructor.
	/// </summary>
	Player();

	/// <summary>
	/// Parameterized Player constructor.
	/// </summary>
	/// <param name="_name">The Player's name.</param>
	/// <param name="_characterClass">The Player's character class.</param>
	Player(string _name, string _characterClass);

	/// <summary>
	/// Overloading << operator.
	/// </summary>
	/// <param name="os">The ostream to append to.</param>
	/// <param name="pl">The Player.</param>
	/// <returns>The ostream with appended information.</returns>
	friend ostream& operator<<(ostream& os, Player const& pl);
};

