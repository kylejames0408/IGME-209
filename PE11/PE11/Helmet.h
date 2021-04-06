// 5 - Create four classes that will all be derived from the Item struct. Yes, I said that the struct will be the parent of the class. For example, you could make a sword, shield, helmet,
//  and armor, or go with a different theme. Have the items fit a theme.
#pragma once
#include "Item.h"

class Helmet :
    public Item
{
public:
    // Constructors
    Helmet();
    Helmet(std::string _name, int _value, float _weight, int _resistance);

    // Methods
    void print() override;

protected:
    // Fields
    int resistance;
};

