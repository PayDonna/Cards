#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <map>
#include <vector>
#include "item.h"

//oh god okay how to implement items
//items would obvs be in certain locations
//specific rooms or areas
//


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
    // items
    std::map<Direction, std::string> adjacentLocation;
    std::vector<Item> itemsAtLocation;
public:
    Location(std::string id, std::string name, std::string description);
    Location changeLocation(Location newLocation);
    std::string getId() const {return id;}
    std::string getName() const{return name;}
    std::string getDesc() const{return description;}
    std::map<Direction, std::string> getAdj() const {return adjacentLocation;}
    const std::vector<Item>& getItems() const {return itemsAtLocation;}
    void addAdjLoc(Direction dir, Location loc);
    void displayAdjacent();

};

#endif // LOCATION_H
