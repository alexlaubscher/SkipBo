#include "DiscardPile.h"
#include "PlayPile.h"
#include <string>

bool DiscardPile::moveCard(Pile& dest) {
  if (dest.type() == "BuildPile") {
    int cardval = pile.back().getValue();
    Card c = Card(cardval);
    dest.addCard(c);
    pile.pop_back();
    return true;
  }
  return false;
}

