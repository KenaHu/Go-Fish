// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"


using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main(){
    ofstream myfile ("gofish_results.txt");
    if(myfile.is_open()){}
    else
        return 0;
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    Card temp1;
    Card temp2;

    myfile << p1.getName() << " has : " << p1.showHand() << endl;
    myfile << p2.getName() << " has : " << p2.showHand() << endl;

    while (p1.checkHandForBook(temp1,temp2)) {
        p1.bookCards(temp1, temp2);
        myfile << p1.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
    }
    while (p2.checkHandForBook(temp1,temp2)) {
        p2.bookCards(temp1, temp2);
        myfile << p2.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
    }

    while(d.size()>0){
        int flag=0;
        if (p1.checkHandForBook(temp1,temp2)) {
            p1.bookCards(temp1, temp2);
            myfile << p1.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
        }
        if (p2.checkHandForBook(temp1,temp2)) {
            p2.bookCards(temp1, temp2);
            myfile << p2.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
        }

	myfile << p1.getName() << " has : " << p1.showHand() << endl;
	myfile << p2.getName() << " has : " << p2.showHand() << endl;

if(p2.getHandSize() == 0)
            dealHand(d,p2,3);
        if(p1.getHandSize() == 0)
            dealHand(d,p1,3);
        Card choice = p1.chooseCardFromHand();
        myfile << p1.getName() << ": Do you have a " << choice.rankString(choice.getRank()) << endl;
        while (p2.cardInHand(choice)) {
            myfile << p2.getName() << ": Yes. I have a " << choice.rankString(choice.getRank()) << endl;
            p2.removeCardFromHand(choice);
            p1.addCard(choice);
            p1.checkHandForBook(temp1, temp2);
            p1.bookCards(temp1, temp2);
            myfile << p1.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
            if (p1.getHandSize() > 0) {
                choice = p1.chooseCardFromHand();
                    myfile << p1.getName() << ": Do you have a " << choice.rankString(choice.getRank()) << endl;
            }
            else {
                flag=1;
                dealHand(d,p1,3);
            }
        }
        if (flag == 0) {
            myfile << p2.getName() << ": Go Fish!" << endl;
            dealHand(d, p1, 1);
        }

        flag=0;
        if (p1.checkHandForBook(temp1, temp2)) {
            p1.bookCards(temp1, temp2);
            myfile << p1.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
        }
        myfile << p1.getName() << " has : " << p1.showHand() << endl;
        myfile << p2.getName() << " has : " << p2.showHand() << endl;

        if(p2.getHandSize() == 0)
            dealHand(d,p2,3);
        if(p1.getHandSize() == 0)
            dealHand(d,p1,3);
        choice = p2.chooseCardFromHand();
        myfile << p2.getName() << ": Do you have a " << choice.rankString(choice.getRank()) << endl;
        while (p1.cardInHand(choice)) {
            myfile << p1.getName() << ": Yes. I have a " << choice.rankString(choice.getRank()) << endl;
            p1.removeCardFromHand(choice);
            p2.addCard(choice);
            p2.checkHandForBook(temp1, temp2);
            p2.bookCards(temp1, temp2);
            myfile << p2.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
            if (p2.getHandSize() > 0) {
                choice = p2.chooseCardFromHand();
                myfile << p2.getName() << ": Do you have a " << choice.rankString(choice.getRank()) << endl;
            }
            else {
                flag=1;
                dealHand(d,p2,3);
            }
        }
        if (flag==0) {
            myfile << p1.getName() << ": Go Fish!" << endl;
            dealHand(d,p2,1);
        }
        if (p2.checkHandForBook(temp1, temp2)) {
            p2.bookCards(temp1, temp2);
            myfile << p2.getName() << " books the " << temp1.rankString(temp1.getRank()) << endl;
        }
    }
    myfile << p1.getName() << " " << p1.getBookSize()/2 << " - " << p1.showBooks() << endl;
    myfile << p2.getName() << " " << p2.getBookSize()/2 << " - " << p2.showBooks() << endl;
    if (p1.getBookSize() > p2.getBookSize())
        myfile << p1.getName() << " WINS" << endl;
    if (p1.getBookSize() < p2.getBookSize())
        myfile << p2.getName() << " WINS" << endl;
    if (p1.getBookSize() == p2.getBookSize())
            myfile << "IT'S A TIE" << endl;

    myfile.close();
    return EXIT_SUCCESS;
}


void dealHand(Deck &d, Player &p, int numCards){
    while((numCards > 0) && d.size() > 0) {
     //   Card c = d.dealCard();
        p.addCard(d.dealCard());
     //   myfile << p.getName() << " draws " << c.toString() << endl;
        numCards-=1;
    }
}
