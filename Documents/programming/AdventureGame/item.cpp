#include "item.h"
#include <stdexcept>
using namespace std;

Item::Item(string id, string name, int amount)
    :id {id}
{
    this->name=name;
    this->id=id;
    this->amount=amount;
}

Item::Item() {

}
