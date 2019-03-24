#ifndef SKIPBOGAME_H_
#define SKIPBOGAME_H_

#include <iostream>
#include <sstream>
#include <vector>

#include "Player.h"
#include "StockPile.h"
#include "BuildPile.h"
#include "DrawPile.h"

class SkipBoGame{
 public:
  SkipBoGame(bool shuffle, int players, int stock, std::vector<int> deck, int current=0);
  //SkipBoGame(bool shuffle, int players, int curp, int stock, std::vector<int> deck);
  int nextPlayer();
  void fillCurpHand();

  void setWinner(int winnerNum) { winner = winnerNum; }
  
  int getNump() { return nump; }
  int getCurp() { return curp; }
  std::string getCurpName() { return peep[curp].getName(); }
  int getStock() { return stockSize; }
  int getWinner() { return winner; }
  
  BuildPile& getBuild(int index) { return build[index]; }
  
  StockPile& getCurpStock() { return peep[curp].stock; }
  DiscardPile& getCurpDiscard(int index) { return peep[curp].discard[index]; }
  Hand& getCurpHand() { return peep[curp].hand; }

  void display() const;
  void readIn(std::istream & is);
  std::string toString() const;
  
  std::vector<Player> peep;
  
 private:  
  DrawPile draw;
  BuildPile build[4];
  
  std::vector<BuildPile> filledBuild;

  bool isShuffle;
  
  int nump;
  
  int stockSize;

  int winner;
  int curp;
};

#endif
