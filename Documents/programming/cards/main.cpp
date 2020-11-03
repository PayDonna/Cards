#include <iostream>
#include "card.h"
#include "cardList.h"
#include <set>
using namespace std;

int blackJackValueCard(Card c){
    int x = rankToInt(c.rank);
    if (x >= 10) {
        x = 10;
    }
    if (x == 1) {
        x = 11;
    }
    return x;
}

int blackJackValueHand(CardList hand){
    //so you could basically write another blackjackvalue that takes a whole hand
    int sum = 0;
    for(int i = 0; i < hand.numCards(); i++) {
        Card c = hand.getCard(i);
        int v = blackJackValueCard(c);
        sum = sum + v;
        cout << "sum = " << sum << endl;
    }
    //THE ACE PROBLEM GOES HERE
    for(int i = 0; i < hand.numCards(); i++) {
        Card c = hand.getCard(i);
        if (c.rank == Rank::Ace) {
            if (sum > 21) {
                sum = sum - 10;
                cout << "HANDLING ACE WARNING,,, sum = " << sum << endl;
            }
        }
    }
    return sum;
}

void stand(CardList& deck, CardList& dHand, CardList& pHand) {
    //so basically you do like "if its less than the players hand, hit"
    //and "if its over 21, RIP"
    int pValue = blackJackValueHand(pHand);
    int dValue = blackJackValueHand(dHand);
    bool keepHitting = true;
    while (keepHitting == true) {
        if (dValue < pValue) {
            hit(deck, dHand);
        }
        if (dValue == pValue) {
            keepHitting = false;
            cout << "PUSH" << endl;
        }
        if (dValue > pValue && dValue < 21) {
            keepHitting = false;
        }
    }


}

//bool isGreater(CardList hand1, CardList hand2) {
//    //return true if hand1 beats hand2 (standard 5 card poker rules)
//}

//bool isFlush(vector<Card> hand) {
//    int numSpades = 0;
//    int numHearts = 0;
//    int numDiamonds = 0;
//    int numClubs = 0;

//    for (Card c : hand) {
//        switch (c.suit) {
//        case Suit::Spade:
//            numSpades++;
//            break;
//        case Suit::Heart:
//            numHearts++;
//            break;
//        case Suit::Diamond:
//            numDiamonds++;
//            break;
//        case Suit::Club:
//            numClubs++;
//            break;
//        }
//    }

//    return (numSpades == 5 || numHearts == 5 || numDiamonds == 5 || numClubs == 5);
//}

////if there is at least one pair of any rank
//bool isOnePair(vector<Card> hand) {
//    for (int i = 0; i < hand.size(); i++) {
//        for (int j = 1; j < hand.size(); j++) {
//            if (hand[i].rank == hand[j].rank) {
//                return true;
//            }
//        }
//    }

//    return false;
//}

//bool hasOnePair(vector<Card> hand) {
//    set<Rank> ranks;

//    for (int i = 0; i < hand.size(); i++) {
//        ranks.insert(hand[i].rank);
//    }

//    return ranks.size() < hand.size();
//}

//bool isThreeOfAKind(vector<Card> hand) {
//    for (Rank r = Rank::Ace; r <= Rank::King; ++r) {
//        int count = 0;
//        for (Card c : hand) {
//            if (c.rank == r) {
//                count++;
//            }
//            if (count >= 3) {
//                return true;
//            }
//        }
//    }
//    return false;
//}

//bool hasTwoPairs(vector<Card> hand) {
//    set<Rank> ranks;

//    for (int i = 0; i < hand.size(); i++) {
//        ranks.insert(hand[i].rank);
//    }

//    return (ranks.size() < hand.size()-1) && (isThreeOfAKind(hand) == false);
//}

//bool isStraight(vector<Card> hand) {
//    sort(hand.begin(), hand.end());

//    int counter = 0;

//    for (int i = 1; i < hand.size(); i++) {
//        int r1 = rankToInt(hand[i-1].rank);
//        int r2 = rankToInt(hand[i].rank);
//        if (r1+1 == r2) {
//            counter++;
//        }
//        else if (r1 != r2) {
//            counter = 0;
//        }
//        else {
//            //ignore duplicate
//        }
//    }

//    return counter >= 4;
//}

//bool isFullHouse(vector<Card> cards) {
//    //a
//}

//bool isStraightFlush(vector<Card> cards) {
//    return isThreeOfAKind(cards);
//}

int main()
{
    while (true) {
        CardList deck(true);
        CardList hand(false);
        CardList dealer(false);

        cout << endl;
        cout << "////" << endl;
        cout << "Welcome to blackjack. To hit, enter 'H'. To stand, enter 'S'." << endl;

        deck.shuffle();
        deal(deck, hand, 2);
        deal(deck, dealer, 2);
        cout << "Your hand:" << endl;
        hand.displayAllCards();
        cout << endl;
        dealer.displayDealerCard();
        int pValue = blackJackValueHand(hand);

        char response;
        bool askAgain = true;

        while (askAgain == true) {
            cin >> response;
            if (response == 'H' || response == 'h') {
                hit(deck, hand);
                pValue = blackJackValueHand(hand);
                cout << "Your hand:" << endl;
                hand.displayAllCards();
                cout << "Your hands value:" << pValue << endl;
                cout << endl;
                dealer.displayDealerCard();
                if (pValue >= 21) {
                    askAgain = false;
                }
            }
            else if (response == 'S' || response == 's') {
                askAgain = false;
            }
            else {
                cout << "bad response." <<endl;
            }
        }

        //STAND FUNCTION
        //continutiously hitting with the dealer
        //until its either 17 or above the players hand in value
        int dValue = blackJackValueHand(dealer);
        bool hitAgain = true;
        while (hitAgain == true) {
            if (dValue < 17 && dValue < pValue) {
                hit(deck, dealer);
                dValue = blackJackValueHand(dealer);
                cout << "Dealers hand:" << endl;
                dealer.displayAllCards();
                cout << "Dealers hands value:" << dValue << endl;
            }
            else {
                hitAgain = false;
            }
        }

        cout << "Dealer value: " << dValue << endl;
        cout << "Player value: " << pValue << endl;
        if (pValue > 21 && dValue > 21) {
            cout << "Draw." << endl;
        }
        else if (dValue > pValue || pValue > 21) {
            if (dValue <= 21) {
                cout << "Dealer wins." << endl;
            }
        }
        else if (pValue > dValue && pValue <= 21) {
            cout << "You win!" << endl;
        }
        else if (pValue == dValue) {
            cout << "Draw." << endl;
        }
    }
    return 0;
}
