//
// Created by hurdk on 4/12/2019.
//
#include "player.h"

Player::Player(){
    myName = "";
}

void Player::addCard(Card c) {  //adds a card to the hand
    myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    for (vector<Card>::iterator i=myHand.begin(); i != myHand.end()-1; i++){
        c1 = *i;
        for (vector<Card>::iterator j=i+1; j != myHand.end(); j++) {
            c2 = *j;
            if (c1 == c2)
                return true;
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//bool Player::rankInHand(Card c) const{}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    int random = myHand.size();
    if (random != 0){
        random = (rand() % random);
        return myHand[random];
    }
    else
        return Card(0,Card::Suit::hearts);
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    if (myHand.empty())
        return false;
    for (auto i=myHand.begin();i!=myHand.end(); i++){
            if (*i == c)
                return true;
        }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    auto i=myHand.begin();
    while((i != myHand.end()) && (*i!=c)){
        i++;
    }
    if(*i == c)
        myHand.erase(i);
    return c;
}

string Player::showHand() const{
    string temp;
    for (auto i = myHand.begin(); i != myHand.end(); i++){
        temp +=i->toString() + " ";
    }
    return temp;
}
string Player::showBooks() const{
    string temp;
    for (auto i = myBook.begin(); i != myBook.end(); i++){
        temp +=i->rankString(i->getRank()) + " ";
    }
    return temp;
}

int Player::getHandSize() const{
    return(myHand.size());
}
int Player::getBookSize() const{
    return (myBook.size());
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//bool Player::checkHandForPair(Card &c1, Card &c2){}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

//bool Player::sameRankInHand(Card c) const{}

