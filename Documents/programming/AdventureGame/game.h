#ifndef GAME_H
#define GAME_H
#include "location.h"
#include <map>
#include "item.h"


class Game
{
    std::map<std::string, Location> locations;

    Location* currentLocation;

    std::vector <Item> inventory;

public:
    void updateLocation(std::string locId);
    Game();
    void addLocation(Location loc);
    Location* getCurrentLoc() const;
    void checkAndMoveDirection(std::string name);
    void addItemToInventory(Item item);
    void removeItemFromInventory(Item item);
    void displayItemsInInventory();
    bool canHaveItemInventory(std::string name);
    Item findItemInventory(std::string name);
};

#endif // GAME_H
