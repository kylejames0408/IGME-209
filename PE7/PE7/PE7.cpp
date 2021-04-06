// PE7_Pointers_Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster* boss = new Monster();
	//Player* pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster* fakeMonster = (Monster*)pOne;

	// add code here
	// 3 - print out the addresses of the boss, player, and fake monster
	cout << "Boss Address:		" << boss << endl;
	cout << "Player Address:		" << pOne << endl;
	cout << "Fake Monster Address:	" << fakeMonster << endl;

	// 4 - set the positions of the boss, player, and fake monster
	boss->xPos = 5; boss->yPos = 5;					// (5, 5)
	pOne->xPos = 10; pOne->yPos = 10;				// (10, 10)
	fakeMonster->xPos = 15; fakeMonster->yPos = 15; // (15, 15)

	// 5 - print the positions of the boss, player, and fake monster using the PrintPos() method from the MovableObject class
	cout << "Boss Position:		"; boss->PrintPos();
	cout << "Player Position:	"; pOne->PrintPos();
	cout << "Fake Monster Position:	"; fakeMonster->PrintPos();

	// 6 -
	//	When deleting the pOne Player Class, it calls it's delete method.
	//	When deleting the pOne MovableObject Class, it doesn't call the Player delete method because it is a MovableObject.
	//	They both call the Player() method as MovableObject is instantiated as a Player class.

	delete boss;
	delete pOne;
	//delete fakeMonster;
	// 2 - crashing due to trying to delete something that was already deleted (pointing to the same data as pOne)

	// Instead, it should set to nullptr since we are no longer using it, as well as the other two classes
	boss = nullptr;
	pOne = nullptr;
	fakeMonster = nullptr;

	return 0;
}

