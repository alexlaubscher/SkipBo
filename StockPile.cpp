#include "StockPile.h"
#include "PlayPile.h"
#include <string>
#include <iostream>
#include <vector>
#include <istream>

using std::string;
using std::vector;

bool StockPile::moveCard(Pile& dest) {
  if (dest.type() == "BuildPile") {
     int cardval = pile.back().getValue();
    Card c = Card(cardval);

    dest.addCard(c);
    pile.pop_back();
    return true;
  }
  return false;
}
