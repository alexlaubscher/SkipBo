#ifndef _FACEUPPILE_H
#define _FACEUPPILE_H


#include "Card.h"
#include "Pile.h"
#include <vector>
#include <iostream>

class FaceUpPile : public Pile{
 public:
 FaceUpPile() : Pile(){ }
  Card removeCard();
  void display() const;
  int getTopValue(); 
};



#endif
