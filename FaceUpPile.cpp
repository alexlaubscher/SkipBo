#include <iostream>
#include "FaceUpPile.h"
#include "Card.h"

Card FaceUpPile::removeCard() {
  Card c = pile.back();
  pile.pop_back();
  return c;
}

// for live game play - must not change!
void FaceUpPile::display() const {
  if (size()) {
    pile[pile.size()-1].display();
  }
  else std::cout << "--";
  std::cout << "/" << size();
}

int FaceUpPile::getTopValue() {
  if (size() > 0) {
    return pile.back().getValue();
  }
  return -1;
}
