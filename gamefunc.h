#ifndef _GAMEFUNC_H
#define _GAMEFUNC_H

#include <string>
#include <iostream>
//essentially everything we don't want to shove in main for readability
//mostly validity checking :D

//case insensitive input
std::string to_lower(std::string s);
//check if input is an int
bool is_num(std::string s);
//check if the move is valid
bool valid_move(char move, char from, char to);
//get the boolean idk
bool get_bool(std::string s);
//number checking
bool valid_players(int shuffle);
bool valid_stock(int players, int stock);
bool first_check(std::string s);

void illegalCommand();

#endif
