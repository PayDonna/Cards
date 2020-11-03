#ifndef CARDLIST_H
#define CARDLIST_H

#include <vector>
#include "card.h"

class CardList {
private:
    std::vector<Card> cards;
public:
    CardList(bool makeDeck);

    //pick a card
    void displayAllCards() const;
    void displayDealerCard() const;
    void shuffle();

    Card drawCard(); //take out a card
    void addCard(Card c); //put the card at the end of the vector
    //with their powers combined, they can take a card out of the deck and add it to a hand

    Card getCard(int index) const; //ok, heres a copy of like, the 5th card
    int numCards() const; //how many cards are in the card list

    std::vector <Card> allCards() const;
};

void deal(CardList& deck, CardList& hand, int i);
void hit(CardList& deck, CardList& hand);

#endif // CARDLIST_H
