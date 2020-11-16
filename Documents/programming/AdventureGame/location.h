#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <map>
#include <vector>
#include "item.h"


enum class Direction {
    North,
    South,
    East,
    West
};

class Location
{
    std::string id;
    std::string name;
    std::string description;
    std::map<Direction, std::string> adjacentLocations;
    std::vector<Item> locationItems;
public:
    Location(std::string id, std::string name, std::string description);
    Location();
    std::string getId() const {return id;}
    std::string getName() const{return name;}
    std::string getDesc() const{return description;}
    //const std::vector<Item>& getItems();
    void addAdjLoc(Direction dir, Location loc);
    void displayAdjacent();
    bool doesHaveLocation(Direction dir);
    std::string getAdjacentLocation(Direction dir);
    void addItemToLocation(Item item);
    void removeItemFromLocation(Item item);
    void displayItemsAtLocation();
    bool canHaveItem(std::string name);
    Item findItem(std::string name);

};

#endif // LOCATION_H
