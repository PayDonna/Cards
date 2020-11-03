#include "cardList.h"
#include <ctime>
#include <cstdlib>

using namespace std;

CardList::CardList(bool makeDeck) {
    if (makeDeck == true) {
        for (Suit s = Suit::Spade; s <=  Suit::Diamond; ++s) {
            for (Rank r = Rank::Ace; r <= Rank::King; ++r) {
                Card c {s, r};
                cards.push_back(c);
            }
        }
    }
}

void CardList::shuffle(){
    srand (time(nullptr));

    vector<Card> newCards;

    while (cards.size() > 0) {
        int num = rand() % cards.size ();
        newCards.push_back(cards[num]);
        cards.erase(cards.begin()+num);
    }

    cards = newCards;
}

void CardList::displayAllCards() const{
    for(int i = 0; i < cards.size(); ++i){
        cout << cards[i].name() << endl;
    }
}

void CardList::displayDealerCard() const{
    cout << "Dealers hand:" << endl;
    int i = 0;
    cout << cards[i].name() << endl;
}

Card CardList::drawCard() {
    Card c = cards[cards.size()-1];
    //couldve been just cards.back()
    cards.erase(cards.begin()+cards.size()-1);
    //couldve been just cards.pop_back()
    return c;
}

void CardList::addCard(Card c) {
    cards.push_back(c);
}

Card CardList::getCard(int index) const {
    Card c = cards[index];
    return c;
}

int CardList::numCards() const {
   int num = cards.size();
   return num;
}

void deal(CardList& deck, CardList& hand, int t){
    for(int i = 0; i < t; i++) {
        Card c = deck.drawCard();
        hand.addCard(c);
    }
}

std::vector <Card> CardList::allCards() const {
    return cards;
}

//HIT FUNCTION
//ok so hitting is basically just adding a card from the deck
void hit(CardList& deck, CardList& hand) {
    Card c = deck.drawCard();
    hand.addCard(c);
}
