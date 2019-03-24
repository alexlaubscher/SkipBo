#ifndef _HAND_H
#define _HAND_H

#include "FaceUpPile.h"
#include <iostream>

class Hand : public FaceUpPile{
 public:
 Hand() : FaceUpPile() { }
  bool moveCard(Pile& dest);
  std::string type() const { return "Hand"; }
  void display() const;
  void prepHand(int index);
  int getSize(){ return pile.size(); }
  int getCardValue(int index) { return pile[index].getValue(); }
};

#endif
