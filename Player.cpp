#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include "Player.h"
#include "Pile.h"
#include "StockPile.h"
#include "Hand.h"
#include "DiscardPile.h"

using std::ostream;

ostream& operator<<(ostream& os, Player p){
  os << p.name;
  return os;
}

Player::Player(int num):playerNumber(num),hand(),stock(),discard(),winner(false){
  std::stringstream ss;
  ss << "Player" << playerNumber;
  name = ss.str();
}

// for live game play - must not change!
void Player::display() const {
  std::cout << "Current ";
  std::cout << name << ":  Stock{0}: " ;
  stock.display();
  std::cout << std::endl;
  std::cout << "   Discards{1-4}: ";
  for (int i = 0; i < 4; ++i) {
    discard[i].display();
    std::cout << "  ";
  }
  std::cout << std::endl;
  std::cout << "   Hand{5-9}: ";
  hand.display();
  std::cout << std::endl;
}

/* saving state format - must not change!
PlayerName
Stock size
01 02 03  ...
...
Hand size
01 02 03 04 05
Discard1 size
01 02 03 04 ...
...
Discard2 size
...
Discard3 size
...
Discard4 size
...
*/
std::string Player::toString() const {
  std::stringstream result;
  result << name << "\n";
  result << "Stock " << stock.toString();
  result << "Hand " << hand.toString();
  for (int i = 0; i < 4; ++i) {
    result << "Discard" << i << " " << discard[i].toString();
  }
  return result.str();
}

void Player::readIn(std::istream & is){
  std::string name, word;
  is >> name;
  if(name.find("Player") != std::string::npos){
    std::cout << "this ain't it fam" << std::endl;
  }
  while(is >> word){
    if(word.compare("Stock")){
      hand.readIn(is); 
    }
    if(word.compare("Hand")){
      stock.readIn(is);
    }
    for(int i = 0; i < 4; i++){
      if(word.compare("Discard")){
	discard[i].readIn(is);
      }
    }
    break;
  }
}
