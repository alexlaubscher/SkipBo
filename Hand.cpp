#include <iostream>
#include <vector>
#include "Hand.h"
#include "FaceUpPile.h"

/*************************************
For SkipBo - Fall 2018 - EN.601.220
Instructor provided code
*************************************/

// for live game play - must not change!
void Hand::display() const {
  int i;
  for (i = 0; i < size(); i++) {
    pile[i].display();
    std::cout << "  ";
  }
  for ( ; i < 5; i++)
    std::cout << "--  ";
}

bool Hand::moveCard (Pile& dest) {
  int cardval = pile.back().getValue();
  Card c = Card(cardval);

  dest.addCard(c);
  pile.pop_back();
  return true;
}

void Hand::prepHand(int index) {
  int cardval = pile.at(index).getValue();
  Card c = Card(cardval);
  pile.push_back(c);
  pile.erase(pile.begin()+index);
}
