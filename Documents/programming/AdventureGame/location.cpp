#include "location.h"
#include <stdexcept>
using namespace std;

Location::Location(string id, string name, string description)
    :id {id}
{
    this->name=name;
    this->id=id;
    this->description=description;
}

Location changeLocation(Location currentLocation, Location newLocation) {
    return currentLocation;
}

Location::Location() {

}

string directionName(Direction dir) {
    switch (dir) {
    case Direction::North:
        return "North";
    case Direction::South:
        return "South";
    case Direction::East:
        return "East";
    case Direction::West:
        return "West";
    }
    return "Bad direction, im confused";
}

void Location::addAdjLoc(Direction dir, Location loc) {
    adjacentLocations[dir] = loc.getId();
}

void Location::displayAdjacent() {
    //using current location, get to adjacent locations, display or return the direction.
    string pName;
    for(auto p : adjacentLocations){
        pName = directionName(p.first);
        cout << pName << endl;
    }
}

bool Location::doesHaveLocation(Direction dir){
    auto i = adjacentLocations.find(dir);
    if (i == adjacentLocations.end()) {
        return false;
    }
    else {
        return true;
    }
}

void Location::addItemToLocation(Item item) {
    locationItems.push_back(item);
}

void Location::removeItemFromLocation(Item item) {
    for (unsigned int i = 0; i < locationItems.size(); i++){
        if (locationItems[i].getId() == item.getId()) {
            locationItems.erase(locationItems.begin() + i);
            break;
        }
    }
}

void Location::displayItemsAtLocation() {
    //    string pName;
    //    for(auto p : adjacentLocations){
    //        pName = directionName(p.first);
    //        cout << pName << endl;
    //    }

    for (auto p : locationItems) {
        cout << p.getName() << endl;
    }
}

string Location::getAdjacentLocation(Direction dir) {
    string newLocId = adjacentLocations[dir];
    return newLocId;
}

bool Location::canHaveItem(string name) {
    for (auto item : locationItems) {
        if (item.getName() == name) {
            return true;
        }
    }
    return false;
}

Item Location::findItem(string name) {
    for (auto item : locationItems) {
        if (item.getName() == name) {
            return item;
        }
    }
    throw new invalid_argument("bad item!");
}

//current location is of type location, so it gets a copy of the location, so youre actually working
//with a duplicate of the current location
//solution is to use pointers!
//refrence cant be assigned, otherwise it just does a copy, make it a pointer instead, throw a star
//on it
