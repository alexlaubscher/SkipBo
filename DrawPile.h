#ifndef _DRAWPILE_H
#define _DRAWPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Pile.h"

class DrawPile : public Pile{
 public:
  DrawPile(bool shuffle, std::vector<int> deck);

  bool moveCard(Pile& dest);

  std::string type() const { return "DrawPile"; }
  
  void shuffle_deck();
  virtual void display() const;
  bool getRand() const { return random; }
  
 private:
  bool random;
};

#endif
