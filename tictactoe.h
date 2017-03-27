// Purpose: Allows two users to play multiple games of TicTacToe in which
// each player tries to place their piece (an X or an O) on the board
// either three in a row, three in a column or three in a perfect diagonal.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cassert>

#ifndef TICTACTOE_H
#define TICTACTOE_H

using namespace std;

class Tictactoe
{
 public:
  explicit Tictactoe(int size = 3);
  // constructor which initializes all variables and allocated memory
  // for the board array
  // IN: can take in a size parameter
  Tictactoe(const Tictactoe& t);
  // copy constructor which allows to copy currently existing objects
  Tictactoe& operator=(const Tictactoe& rhs);
  // Overloaded Assignment operator which allows assignment
  // of one currently existing object to another
  ~Tictactoe();
  //deconstructor which deallocates memory for the board array

  void displayBoard();
  // displays the board with the proper pieces in the correct row
  // and column (rows and columns are to be numbered)
  bool placePiece(char piece, int row, int col);
  // IN: the current player's piece and their placement choice
  // processes the placement of a piece on the board, updating
  // the board array. returns false if there is already a piece placed
  // there.
  char checkWinner(); 
  // checks to see if the current player has won, returns the
  // piece of the player if someone has won, returns a blank if the game
  // should continue, or returns a T to represent a tie in the case that
  // no blank spaces are left on the board
  
  void reset();
  // resets the board to blank after a game has finished


 private:

  char **board; //pointer of type pointer to "pointer to char" to allow
  // memory allocation for

  // all constants below are purely for board formatting
  static const int SIZE = 3;
  static const char X = 'X';
  static const char O = 'O';
  static const char BLANK = ' ';
  static const char TIE = 'T';
  const string ROW = "---";
  const string COL = " |";
  int bdSize; // allows for different board sizes
};
#endif 
