#include "Player.h"

/// <summary>
/// Default Player constructor.
/// </summary>
Player::Player()
{
    name = "Unknown";
    characterClass = "Human";
}

/// <summary>
/// Parameterized Player constructor.
/// </summary>
/// <param name="_name">The Player's name.</param>
/// <param name="_characterClass">The Player's character class.</param>
Player::Player(string _name, string _characterClass)
{
    name = _name;
    characterClass = _characterClass;
}

/// <summary>
/// Overloading << operator.
/// </summary>
/// <param name="os">The ostream to append to.</param>
/// <param name="pl">The Player.</param>
/// <returns>The ostream with appended information.</returns>
ostream& operator<<(ostream& os, Player const& pl)
{
    os << "NAME: " << pl.name << "\t\tCLASS: " << pl.characterClass << endl;
    return os;
}
