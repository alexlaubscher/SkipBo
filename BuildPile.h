#ifndef _BUILDPILE_H
#define _BUILDPILE_H

#include "FaceUpPile.h"
#include <vector>

class BuildPile : public FaceUpPile{
 public:
 BuildPile() : FaceUpPile() {} 
  bool moveCard(Pile& dest);
  Card addCard(const Card c){ pile.push_back(c); return c; }
  std::string type() const { return "BuildPile"; }
  bool isFilled() { return pile.size() == 12; }
  void display() const;
};

#endif
