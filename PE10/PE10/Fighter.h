// 10.2 - Create a new class called Fighter. Right click, go to Add > Class… to use Visual Studio’s Class Wizard.
// 10.2a - After you enter the name of the class, also enter the base class name Player (the class you made last time). The access should be “public”.
#pragma once
#include "Player.h"
class Fighter :
    public Player
{
    // 10.3 - Once you have the basics set up, add the following declarations to Fighter.h:
private:
    // 10.3a - Add another member variable for the fighter’s weapon skill.
    char* weaponSkill;

public:
    // Default Constructor
    Fighter();

    // 10.3b - Declare a parameterized constructor that takes a name, a weapon skill and the three other stats from player.
    Fighter(const char* _name, const char* _weaponSkill, int _strength, int _dexterity, int _intelligence);

    // Deconstructor
    ~Fighter();

    // 10.3c - Declare a public void method called printFighter( ), with no parameters.
    void printFighter();
};

