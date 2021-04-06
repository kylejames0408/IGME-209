// 1 - Create a new Windows Console Application C++ project. In the main cpp, set it up the usual way: include iostream, using namespace std.
#include <iostream>
#include "Item.h"
#include "Sword.h"
#include "Shield.h"
#include "Helmet.h"
#include "Armor.h"
#include <vector>

using namespace std;

int main()
{
	// 6 - In your main( ) function, create pointers to each of the items that you created above. To do this you will need to make sure to include all the headers. Make sure to delete all
	//	of the items at the end of the main when you are done.
	Item* item = new Item();
	Sword* sword = new Sword();
	Shield* shield = new Shield();
	Helmet* helmet = new Helmet();
	Armor* armor = new Armor();

	// 7 - Create a vector<Item*> inventory variable in the main function. Add each of the items created using the push_back function on the inventory. You will need to include <vector>.
	//	Vector is essentially ‘list’ from C#. Under the hood, Vector is a dynamically sized array (that does most of the heavy lifting for us).
	vector<Item*> inventory = vector<Item*>();
	inventory.push_back(item);
	inventory.push_back(sword);
	inventory.push_back(shield);
	inventory.push_back(helmet);
	inventory.push_back(armor);

	// 8 - Loop through the inventory vector and call the print method on each object.
	for (int i = 0; i < inventory.size(); i++)
	{
		inventory[i]->print();
		cout << endl;

		delete inventory[i];
		inventory[i] = nullptr;
	}
}