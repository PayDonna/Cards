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
    Game game;

    Location livingRoom("lr", "Living Room", "the living room, which is dimly lit by the fireplace.");
    Location kitchen("kit", "Kitchen", "the kitchen. It's... It's a kitchen.");
    Location bedroom("br", "Bedroom", "the bedroom. It's a bedroom homie. Idk it's comfy I guess.");
    livingRoom.addAdjLoc(Direction::West, kitchen);
    livingRoom.addAdjLoc(Direction::East, bedroom);
    bedroom.addAdjLoc(Direction::West, livingRoom);
    kitchen.addAdjLoc(Direction::East, livingRoom);

    Item toaster("tstr", "toaster", 1);
    Item pencil("pncl", "pencil", 1);

    livingRoom.addItemToLocation(toaster);
    livingRoom.addItemToLocation(pencil);

    game.addLocation(livingRoom);
    game.addLocation(kitchen);
    game.addLocation(bedroom);
    game.updateLocation("lr");

    bool play = true;
    string command;
    string commandAfter;

    while(play == true) {
        cout << "You are in " << game.getCurrentLoc()->getDesc() << endl;
        cout << "You can go: " << endl;
        game.getCurrentLoc()->displayAdjacent();
        //"you can go west."
        cout << "These items are here:" << endl;
        game.getCurrentLoc()->displayItemsAtLocation();
        cin >> command;
        for (string::iterator i = command.begin(); i < command.end(); i++){
            *i = tolower(*i);
        }

        //look for the direction in the adjactentLocations of the current location

        if (command == "go") {

            cin >> commandAfter;
            if (commandAfter == "west") {
                game.checkAndMoveDirection(commandAfter);
            }
            else if (commandAfter == "east") {
                game.checkAndMoveDirection(commandAfter);
            }
            else {
                cout << "Bad word after command:" << commandAfter << endl;
            }
        }
        if (command == "get") {
            cin >> commandAfter;
            bool isViableItem = game.getCurrentLoc()->canHaveItem(commandAfter);
            if(isViableItem) {
                Item item = game.getCurrentLoc()->findItem(commandAfter);
                game.getCurrentLoc()->removeItemFromLocation(item);
                game.addItemToInventory(item);
                cout << "You now have these items in your inventory:" << endl;
                game.displayItemsInInventory();
            }
            else {
                cout << "Invalid item." << endl;
            }
        }
        if (command == "drop") {
            cin >> commandAfter;
            bool isViableItem = game.canHaveItemInventory(commandAfter);
            if (isViableItem) {
                Item item = game.findItemInventory(commandAfter);
                game.removeItemFromInventory(item);
                game.getCurrentLoc()->addItemToLocation(item);
                cout << "You dropped your " << commandAfter << ". You now have these items in your inventory:" << endl;
                game.displayItemsInInventory();
            }
        }
        else {
            cout << "Bad command: " << command << endl;
        }
    }

    return 0;
}




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
