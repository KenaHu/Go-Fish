//
// Created by hurdk on 4/12/2019.
//
#include <ctime>
#include "deck.h"

Deck::Deck() {           // pristine, sorted deck
    myIndex=0;
    for (Card::Suit s = Card::spades; s <= Card::clubs;s = Card::Suit(s+1)){
        for (int r = 1; r<=13; r++) {
            myCards[myIndex] = Card(r, s);
            myIndex++;
        }
    }

    myIndex=0;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

void Deck::shuffle() {   // shuffle the deck, all 52 cards present
    for(int i=0; i<SIZE; i++){
        int random = (rand() %SIZE);
        swap(myCards[i],myCards[random]);
    }
}
Card Deck::dealCard() {   // get a card, after 52 are dealt, fail
    if (size() > 0){
        myIndex++;
        return myCards[myIndex-1];
    }
    return (Card(0,Card::hearts));
}

int  Deck::size() const { // # cards left in the deck
    return (SIZE-myIndex);
}
