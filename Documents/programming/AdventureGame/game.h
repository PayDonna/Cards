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
};

#endif // GAME_H
