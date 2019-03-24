//StockPile.h
#ifndef _STOCKPILE_H
#define _STOCKPILE_H

#include "PlayPile.h"
#include <string>
#include <iostream>

class StockPile : public PlayPile{
 public:
  bool moveCard(Pile& dest);
  std::string type() const { return "StockPile"; }
 StockPile() : PlayPile() {}
 
};

#endif
