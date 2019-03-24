#include "Card.h"
#include "Pile.h"
#include "SkipBoGame.h"
#include "gamefunc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::cerr;
using std::string;
using std::ifstream;
using std::vector;

int main(int argc, char* argv[]){
  string input;
  bool shuffle;
  int players, stock, curp;
  string s;

  vector<int> deck;

  //check number of inputs
  if(argc != 3 && argc != 5){
    cerr << "invalid program usage: invalid number of arguments" << endl;
    return 1;
  }

  //check if it's "true" or "false"
  string shuff = to_lower(argv[1]);
  if(!first_check(shuff)){
    return 1;
  }
  
  //starting a new game
  if(argc == 5){ //full 5 commandline inputs
    //t/f, int, file checking
    if(!is_num(argv[2]) || !is_num(argv[3])){
      cerr << "not a num D:" << endl;
      return 1;
    }

    //check if you can open the file
    std::ifstream file(argv[4]);
    if(!file.is_open()){
      cerr << "invalid program usage: can't open input game file" << endl;
      return 1;
    }

    int cardval;
    while(file >> cardval){
      deck.push_back(cardval);
    }

    shuffle = get_bool(shuff);
    players = atoi(argv[2]);
    stock = atoi(argv[3]);

    if(!valid_players(players)){ //check if valid # of players
      return 1;
    }
    
    if(!valid_stock(players, stock)) // check validity of stock value
      return 1;
  }
  
  //loading a saved game
  else if(argc == 3){
    //t/f, file checking
    ifstream file;
    file.open(argv[2], ifstream::in);
    string shuff = to_lower(argv[1]);
    if(!first_check(shuff)){
      return 1;
    }
    if(!file.is_open()){
      cerr << "invalid program usage: can't open input game file" << endl;
      return 1;
    }
    file >> shuffle >> players >> curp;
    while(file >> s){
      if(s.compare("Draw")){
	int draw_size;
	int num;
	cout << "num";
	file >> draw_size;
	for(int i = 0; i < draw_size; i++){
	  file >> num;
	  deck.push_back(num);
	}
      }
    }
    SkipBoGame sb = SkipBoGame(shuffle, players, curp, deck);
    sb.readIn(file);
    //make a new sb game
    //shuffle = get_bool(shuff);
    //s just holds the random shuffle string
    //file >> get curp from this
    //file >> "Stock"
    //file >> stocksize
    /*
      for(int i = 0; i < sizesize; i++){
      int cardval;
      file >> cardval;
      deck.push_back(cardval);

      //all the readins.
}
     */
  }
  
  //make new skipbo game
  //file.open(argv[4], ifstream::in);
  SkipBoGame sb = SkipBoGame(shuffle, players, stock, deck);
  cout << "num players is " << sb.getNump() << endl;
  cout << "stock size is " << sb.getStock() << endl << endl;

  char move, from, to;
  do{
    //start player turn
    cout << ">> " << sb.getCurpName() << " turn next" << endl;
    cout << "(p)lay, (s)ave, or (q)uit ? ";
    
    cin >> input;
    input = to_lower(input);

    sb.fillCurpHand();
    
    //quit game
    if(input.compare("q") == 0){
      cout << "thanks for playing" << endl;
      return 0;
    }
    //save the game and leaaave
    else if(input.compare("s") == 0){
      cout << "save filename: ";
      string savename;
      cin >> savename;
      std::ofstream savefile(savename);
      string game = sb.toString();
      savefile << game;
      savefile.close();
      return 0;
    }
      //play the game
    else if(input.compare("p") == 0){
      while (true) {
	sb.display();
	cout << "(m)ove [start] [end] or (d)raw ? ";
	cin >> move;
	
	if (move == 'm') {
	  cin >> from;
	  cin >> to;
	  if (valid_move(move, from, to)) {
	    if (from == '0') {
	      if ('a' <= to && 'd' >= to) {
		int index = to - 'a';
		int moveval = sb.getCurpStock().getTopValue();
		int destval = sb.getBuild(index).size();
		if (destval == 0) {
		  if (moveval == 0 || moveval == 1) {
		    sb.getCurpStock().moveCard(sb.getBuild(index));
		  }
		} else if (moveval == 0 || moveval == destval + 1) {
		  sb.getCurpStock().moveCard(sb.getBuild(index));
		}
		else{
		  illegalCommand();
		}
	      }
	      // starts at discard(1-4) goes to build (a-d)  
	    } else if (from >= '1' && from <= '4') {
	      if ('a' <= to && 'd' >= to) {
		int dest_index = to - 'a';
		int start_index = from - '1';
		int moveval = sb.getCurpDiscard(start_index).getTopValue();
		int destval = sb.getBuild(dest_index).size();
		if (destval == 0) {
                  if (moveval == 0 || moveval == 1) {
                    sb.getCurpDiscard(start_index).moveCard(sb.getBuild(dest_index));
                  }
                }
		else if (moveval == 0 || moveval == destval + 1) {
                  sb.getCurpDiscard(start_index).moveCard(sb.getBuild(dest_index));
                }
		else
		  illegalCommand();
	      }
	    }
	    
	    //FROM HAND (5-9)
	    else if (from >= '5' && from <= '9') {

	      int start_index = from - '5';
	      int moveval = sb.getCurpHand().getCardValue(start_index);
	      
	      if(sb.getCurpHand().size() < start_index + 1){
		illegalCommand();
	      }
	      //TO BUILD (a-d)
	      else if ('a' <= to && 'd' >= to) {
		int dest_index = to - 'a';
		int destval = sb.getBuild(dest_index).size();
		if (destval == 0) {
                  if (moveval == 0 || moveval == 1) {
		    sb.getCurpHand().prepHand(start_index);
                    sb.getCurpHand().moveCard(sb.getBuild(dest_index));
                  }
                }
		else if (moveval == 0 || moveval == destval + 1) {
		  
		  sb.getCurpHand().prepHand(start_index);
                  sb.getCurpHand().moveCard(sb.getBuild(dest_index));
                }
		else{
		  illegalCommand();
		}
	      }
	      //TO DISCARD (1-4)
	      else if ('1' <= to && '4' >= to) {
		int dest_index = to - '1';

		sb.getCurpHand().prepHand(start_index);
		sb.getCurpHand().moveCard(sb.getCurpDiscard(dest_index));

		cout << endl;
		sb.display();
		cout << endl;

		break;
	      }
	      else{
		illegalCommand();
	      }
	    }
	    else{
	      illegalCommand();
	    }
	  }
	}
		
	//DRAW CARDS
	else if (move == 'd') {
	  if (sb.getCurpHand().getSize() == 0)
	    sb.fillCurpHand();
	  else
	    illegalCommand();
	} // Add the end and draw later
	
	cout << endl;
	
	//if we have a winner, declare it and end the game
	if(sb.peep[sb.getCurp()].isWinner()){
	  sb.setWinner(sb.getCurp());
	  break;
	}
      }
      sb.nextPlayer();
    }
  } while(sb.getWinner() == -1);

  cout << "Player" << sb.getWinner() << " is the winner" << endl;
    
  return 0;
}
