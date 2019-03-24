#ifndef DISCARDPILE_H_
#define DISCARDPILE_H_

#include "PlayPile.h"

class DiscardPile : public PlayPile{
 public:
 DiscardPile() : PlayPile() {}
  bool moveCard(Pile& dest);
  std::string type() const { return "DiscardPile"; }
};

#endif
