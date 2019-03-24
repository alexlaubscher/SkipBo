//Player.h

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Hand.h"
#include "StockPile.h"
#include "DiscardPile.h"
#include <string>
#include <iostream>

class Player{
 public:
  friend class SkipBoGame;
  friend std::ostream& operator<<(std::ostream& s, Player p);

 Player(int num);
 
  void display() const;
  std::string toString() const;

  std::string getName() { return name; }
  int getPlayerNum() { return playerNumber; }
  
  bool isWinner() { return stock.size() == 0; }

  StockPile getStock() { return stock; }
  void readIn(std::istream & is);
 private:
  int playerNumber;
  std::string name;
  
  Hand hand;
  StockPile stock;
  DiscardPile discard[4];

  bool winner;
};

#endif
