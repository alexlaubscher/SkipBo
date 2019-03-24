#include <iostream>
#include <algorithm>
#include <cctype>
#include "DrawPile.h"

using std::string;
using std::vector;

//check the specifics later, the idea is there
DrawPile::DrawPile(bool shuffle, vector<int> deck): Pile(), random(shuffle) {
  for(vector<int>::iterator it = deck.begin(); it != deck.end(); it++){
    Card c = Card(*it);
    pile.push_back(c);
  }
  
  if(random){
    shuffle_deck();
  }
}

// for live game play - must not change!
void DrawPile::display() const {
  std::cout << "[XX]/" << size();
}

void DrawPile::shuffle_deck(){
  std::random_shuffle(pile.begin(), pile.end());
}
bool DrawPile::moveCard(Pile& dest) {
  //std::cout << "MOVING CARD FROM DRAWPILE" << std::endl;
  if (dest.type() == "Hand" || dest.type() == "StockPile") {
    //std::cout << "were in boys" << std::endl;
    int cardval = pile.back().getValue();
    Card c = Card(cardval);
    
    dest.addCard(c);
    pile.pop_back();
    
    return true;
  }
  return false;
}
