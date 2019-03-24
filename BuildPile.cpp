#include "FaceUpPile.h"
#include "BuildPile.h"
#include <vector>
#include <iostream>

using std::cout;

bool BuildPile::moveCard(Pile& dest) {
  return false;
}

void BuildPile::display() const{
  if(pile.size() == 0)
    cout << "--/0";

  else if(pile.back().getValue() == 0)
    cout << "[SB]/" << pile.size();
  
  else
    cout << "[" << pile.back().getValue() << "]/" << pile.size();
}
