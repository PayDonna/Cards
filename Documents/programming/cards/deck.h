#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck
{
    std::vector<Card> cards;
public:
    Deck();

    void displayAllCards () const;
    void shuffle();
};

#endif // DECK_H
