#include "location.h"
using namespace std;

Location::Location(string id, string name, string description)
    :id {id}
{
    this->name=name;
    this->
}

Location changeLocation(Location currentLocation, Location newLocation) {
    //aaa

}


//current location is of type location, so it gets a copy of the location, so youre actually working
//with a duplicate of the current location
//solution is to use pointers!
//refrence cant be assigned, otherwise it just does a copy, make it a pointer instead, throw a star
//on it
