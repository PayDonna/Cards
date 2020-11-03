#include "card.h"
#include <iostream>
using namespace std;

bool operator<(const Card&a, const Card& b) {
    return rankToInt(a.rank) < rankToInt(b.rank);
}

int rankToInt(Rank r) {
    return static_cast<int>(r);
}

Suit& operator++(Suit &c ) {
    c = static_cast<Suit>(static_cast<int>(c)+1);
    return c;
}

Rank& operator++(Rank &c ) {
    c = static_cast<Rank>(static_cast<int>(c)+1);
    return c;
}

string suitName(Suit a) {
    switch (a) {
    case Suit::Spade:
        return "Spades";
    case Suit::Heart:
        return "Hearts";
    case Suit::Club:
        return "Clubs";
    case Suit::Diamond:
        return "Diamonds";
    }
    return "Bad suit, im confused";
}

string rankName(Rank r) {
    switch (r) {
    case Rank::Ace:
        return "Ace";
    case Rank::Two:
        return "Two";
    case Rank::Three:
        return "Three";
    case Rank::Four:
        return "Four";
    case Rank::Five:
        return "Five";
    case Rank::Six:
        return "Six";
    case Rank::Seven:
        return "Seven";
    case Rank::Eight:
        return "Eight";
    case Rank::Nine:
        return "Nine";
    case Rank::Ten:
        return "Ten";
    case Rank::Jack:
        return "Jack";
    case Rank::Queen:
        return "Queen";
    case Rank::King:
        return "King";
    }
    return "Bad rank, im confused";
}

string Card::name() const {
    return rankName(rank) + " of " + suitName(suit);
}

Card::Card(Suit s, Rank r) {
    //set the fields!
    suit = s;
    rank = r;
}
