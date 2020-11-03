#include <iostream>
#include <map>
#include "location.h"
#include "item.h"
#include "game.h"

using namespace std;

int main()
{
    //this is mainly just gonna be a loop of like asking what the player wants to do
    //loop that is just displaying where the player is and asking what they wanna do

    bool play = true;

    //OKAY YOUD HAVE TO LIKE PUT THE CURRENT LOCATION IN SOMETHING
    Location livingRoom("lr", "Living Room", "the living room, which is dimly lit by the fireplace.");
    Location currentLocation = livingRoom;
    //OKAY SO YOUD NEED TO HAVE A FUNCTION OR SOMETHING FOR CHANGING LOCATIONS
    cout << "You are in " << currentLocation.getDesc() << endl;


//    map<int,string> stuff;

//    stuff[7] = "Hello";
//    stuff[10] = "hello10";
//    stuff[50] = "hello18";

//    cout << stuff.size() << endl;

//    int idx = 10;
//    auto x = 5.4;

//    for (auto pair : stuff) {
//        if (pair.first == idx) {
//            cout << "i found:" << pair.second << endl;
//        }
//    }

//    auto i = stuff.find(10);

//    if (i != stuff.end()) {
//        cout << "I found:" << i->second << endl;
//        cout << "I found:" << (*i).second << endl;
//    }

//    if (stuff[13].size() > 0) {
//        cout << "I found:" << stuff[10] << endl;
//    }


    return 0;
}
