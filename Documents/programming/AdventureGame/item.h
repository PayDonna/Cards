#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <map>
#include <vector>
#include "location.h"

//ITEMS HAVE
//names
//properties??? like what they would do if you used it, like for potions
//an amount?? like how many of an item you have

class Item
{
private:
    std::string name;
    int amount;
public:
    Item();

    void addItem(Item item);
    void removeItem(vector<Item>::const_iterator item);

    void displayItem();
};

#endif // ITEM_H
