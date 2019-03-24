#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <random>

#include "SkipBoGame.h"
#include "Player.h"

using std::vector;
using std::string;

SkipBoGame::SkipBoGame(bool shuffle,int players,int stock,vector<int>deck, int current) :
  draw(shuffle, deck), filledBuild(), isShuffle(shuffle),nump(players),
  stockSize(stock),winner(-1),curp(current){

  int rando = 0;
  
  if(shuffle){
    std::random_device rd;
    rando = rd() % nump + 1;
    if(rando < 0)
      rando *= -1;
  }
  
  //initialize players
  for(int i = 0; i < nump; i++){
    Player p = Player((rando + i) % nump);
    peep.push_back(p);
  }

  //fills each player's stockpiles
  for(int i = 0; i < stockSize; i++){
    for(vector<Player>::iterator it = peep.begin(); it != peep.end();it++){
      draw.moveCard(it->stock);
    }
  }
}

int SkipBoGame::nextPlayer(){
  curp++;
  if(curp >= nump)
    curp = 0;

  return curp;
}

void SkipBoGame::fillCurpHand(){
  while(peep[curp].hand.size() < 5)
    draw.moveCard(peep[curp].hand);   
}


/* for live game play - must not change format!

drawPile  build_a  build_b  build_c  build_d
playerName  stock_0  
discards: discard_1 discard_2 discard_3 discard_4
hand: card_5 card_6 card_7 card_8 card_9
 */
void SkipBoGame::display() const {
  std::cout << "Draw: ";
  draw.display();
  std::cout << "  Build Piles: ";
  for (int j = 0; j < 4; j++) {
    build[j].display();
    std::cout << " ";
  }
  std::cout << std::endl;
  peep[curp].display();
}

/* for saving state - must not change format!

shuffle numplayers currplayer
PlayerCurp [display]
PlayerCurp+1 [display]
[etc for all players]
Draw [display]
Build_a [display]
Build_b [display]
Build_c [display]
Build_d [display]
*/
std::string SkipBoGame::toString() const {
  std::stringstream result;
  int idx;
  result << draw.getRand() << " " << nump << " " << curp << "\n";
  for (int i = 0; i < nump; ++i) {
    idx = (curp+i) % nump;
    result << peep[idx].toString();
  }
  result << "Draw " << draw.toString(); 
  for (int j = 0; j < 4; j++) {
    result << "Build_" << char('a'+j) << " ";
    result << build[j].toString();  
  }
  return result.str();
}

void SkipBoGame::readIn(std::istream & is){
  for(int i = 0; i < nump; i++){
    peep[i].readIn(is);
  }
}
