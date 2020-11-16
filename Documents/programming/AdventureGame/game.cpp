#include "game.h"
using namespace std;

Game::Game()
{

}

void Game::addLocation(Location loc){
    locations[loc.getId()] = loc;
}

void Game::updateLocation(string locId){
    currentLocation = &locations.at(locId);
}

Location* Game::getCurrentLoc() const {
    return currentLocation;
}

bool isValidDirection(string name) {
    for (string::iterator i = name.begin(); i < name.end(); i++){
            *i = tolower(*i);
    }
    if (name == "north") {
        return true;
    }
    else if (name == "south") {
        return true;
    }
    else if (name == "east") {
        return true;
    }
    else if (name == "west") {
        return true;
    }
    else {
        return false;
    }

}

Direction stringToDirection(string name) {
    for (string::iterator i = name.begin(); i < name.end(); i++){
            *i = tolower(*i);
    }
    if (name == "north") {
        return Direction::North;
    }
    else if (name == "south") {
        return Direction::South;
    }
    else if (name == "east") {
        return Direction::East;
    }
    else if (name == "west") {
        return Direction::West;
    }
    throw new invalid_argument("bad direction!");
}

void Game::checkAndMoveDirection(string name) {
    bool aDirection = isValidDirection(name);
    if (aDirection == true) {
        cout << "trying to move!" << endl;
        Direction dir = stringToDirection(name);
        if (currentLocation->doesHaveLocation(dir)) {
            string newLocId = currentLocation->getAdjacentLocation(dir);
            updateLocation(newLocId);
        }
        else {
            cout << "No location there!" << endl;
        }
    }
    else {
        cout << "Not a valid direction!" << endl;
    }
    //time to look in adjacent locations for that direction
    //so,,,, you use current location to get to adjacent locations


            //adjacentLocations[dir] = loc.getId();

}

void Game::addItemToInventory(Item item) {
    inventory.push_back(item);
}

void Game::removeItemFromInventory(Item item) {
    for (unsigned int i = 0; i < inventory.size(); i++){
        if (inventory[i].getId() == item.getId()) {
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}

void Game::displayItemsInInventory() {
    for (auto p : inventory) {
        cout << p.getName() << endl;
    }
}

bool Game::canHaveItemInventory(string name) {
    for (auto item : inventory) {
        if (item.getName() == name) {
            return true;
        }
    }
    return false;
}

Item Game::findItemInventory(string name) {
    for (auto item : inventory) {
        if (item.getName() == name) {
            return item;
        }
    }
    throw new invalid_argument("bad item!");
}
