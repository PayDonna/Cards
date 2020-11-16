#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <map>
#include <vector>

//ITEMS HAVE
//names
//properties??? like what they would do if you used it, like for potions
//an amount?? like how many of an item you have

class Item
{
private:
    std::string id;
    std::string name;
    int amount;
public:
    Item(std::string id, std::string name, int amount);
    Item();

    std::string getId() const {return id;}
    std::string getName() const{return name;}
    int getAmount() const{return amount;}

    //void removeItem(vector<Item>::const_iterator item);
};

#endif // ITEM_H
