//
// Created by hurdk on 4/12/2019.
//
#include "card.h"

Card::Card() {          // default, ace of spades
    myRank = 1;
    mySuit = spades;
}
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString()              const {  // return string version e.g. Ac 4h Js
    string suit = suitString(mySuit);
    string rank = rankString(myRank);
    return (rank+suit);
}
bool Card::sameSuitAs(const Card& c) const {  // true if suit same as c
    return (mySuit == c.mySuit);
}
int  Card::getRank()                 const {  // return rank, 1..13
    return myRank;
}
string Card::suitString(Suit s)      const {  // return "s", "h",...
    string suits[] = {"s", "h", "d", "c"};
    return suits[s];
}
string Card::rankString(int r)       const {  // return "A", "2", ..."Q"
    string ranks[] = {"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    return ranks[r];
}
void Card::swap(Card &c){
    Card temp = c;
    c = *this;
    *this = temp;
}

bool Card::operator == (const Card& rhs) const{
    return (myRank == rhs.myRank);
}
bool Card::operator != (const Card& rhs) const{
    return (myRank != rhs.myRank);
}