#ifndef CARD_H
#define CARD_H
#include <iostream>

//this is a header file

enum class Suit {
    Spade,
    Heart,
    Club,
    Diamond
};

enum class Rank {
    Ace = 1,
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

class Card {
public: //methods and fields are members of the class
    Rank rank; //these are fields, instance varaibles
    Suit suit;
//    static int blah; //this is a class varaible or static varaible
public:
    //constructor
    Card(Suit suit, Rank rank); //declaration of the constructor
    //methods
    std::string name() const;
};

//constructor is a special method used to intiialize an instance of a class, by setting
//the field values

//implementation of the constuctor

bool operator<(const Card a, const Card b);

Suit& operator++(Suit &c);
Rank& operator++(Rank &c);
int rankToInt(Rank r);
std::string suitName(Suit a);
std::string rankName(Rank r);

#endif // CARD_H
