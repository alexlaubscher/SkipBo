#include "gamefunc.h"
#include <string>
#include <cctype>
#include <iostream>

using std::string;
using std::cerr;
using std::endl;

string to_lower(string s){
  for(char &c: s){
    c = tolower(c);
  }
  return s;
}

bool is_num(string s){
  int num_stat;
  int index = 0;
  for(char &c: s){
    num_stat = isdigit(c);
    if(num_stat == 0){
      if(index == 0 && c == '-'){
	index++;
	break;
      }
      return false;
    }
  }
  return true;
}

bool valid_move(string s){
  if(s.compare("p") != 0 || s.compare("s") != 0 || s.compare("q")){
    return false;
  }
  else{
    return true;
  }
}

bool get_bool(string s){
  if(s.compare("true") == 0){
    return true;
  }
  else{
    return false;
  }
}

bool valid_players(int players){
  if(players <= 6 && players >= 2){
    return true;
  }
  else{
    cerr << "invalid program usage: num players must be 2-6" << endl;
    return false;
  }
}

bool valid_stock(int players, int stock){
  //CHANGE 5 BACK TO 10 LATER
  if(stock >= 5 && stock <= 30){
    if(players == 6 && stock >= 20){
      cerr << "invalid program usage: bad stock size" << endl;
      return false;
    }
    return true;
  }
  else{
    cerr << "invalid program usage: bad stock size" << endl;
    return false;
  }
}

bool valid_move(char move, char from, char to){
  string err =  "invalid move: try again";
  if(move == 'm'){
    if('0' <= from && from <= '9'){
      if(('a' <= to && 'd' >= to) || ('1' <= to && '4' >= to)){
	return true;
      }
      else{
	//cerr << err << endl;
	return false;
      }
    }
    else{
      cerr << err << endl;
      return false;
    }
  } 
  else{
    cerr << err <<  endl;
    return false;
  }
}

bool first_check(string s){
  if(s.compare("true") != 0 && s.compare("false") != 0){
    cerr << "invalid program usage: invalid first argument" << endl;
    return false;
  }
  return true;
}

void illegalCommand(){
  cerr << "illegal command, try again" << endl;
}
