#include "tictactoe.h"

using namespace std;

Tictactoe :: Tictactoe(int size) 
{
  if (size >= 3 && size < 75){ // if other board size is given, sets a limit
	bdSize = size;             // and assures that the other methods
  }                            // will run with the correct size
  
  board = new char *[bdSize];
  assert(board != nullptr); 

  for (int i = 0; i < bdSize; i++){
	board[i] = new char[bdSize];
	assert(board[i] != nullptr); 
  }

  for (int r = 0; r < bdSize; r ++){
	for (int c = 0; c < bdSize; c++){
	  board[r][c] = BLANK;
	}
  }
}

Tictactoe :: Tictactoe(const Tictactoe& t)
{
  bdSize = t.bdSize;

  board = new char *[bdSize];

  for (int i = 0; i < bdSize; i++){
	board[i] = new char[bdSize];
  }

  for (int r = 0; r < bdSize; r ++){
	for (int c = 0; c < bdSize; c++){
	  board[r][c] = t.board[r][c];
	}
  }
  
}
Tictactoe& Tictactoe :: operator=(const Tictactoe& rhs)
{
  if (this != &rhs){
	for (int d = 0; d < bdSize; d++){
	  delete [] board[d];
	}
	delete [] board;
  
	for (int r = 0; r < bdSize; r ++){
	  for (int c = 0; c < bdSize; c++){
		board[r][c] = rhs.board[r][c];
	  }
	}
  }
  
  return *this;
  
}
Tictactoe :: ~Tictactoe()
{
  // deallocates memory for each element within the array
  for (int d = 0; d < bdSize; d++){
	delete []board[d];
  }

  // dellocates memory for array itself
  delete []board; 
}

void Tictactoe :: displayBoard()
{
  cout << endl << endl << endl;

  for(int r = 0; r < bdSize; r++){
	if (r == 0){
	  for(int c = 0; c < bdSize; c++){
		cout << BLANK << BLANK << c << BLANK;
	  }
	cout << endl;
	}
	cout << r << " ";
	for (int c = 0; c < bdSize; c++){
	  cout << board[r][c];
	  if (c < bdSize - 1)
		cout << COL;
	}
	cout << endl;
	cout << BLANK << BLANK;
	if (r < bdSize - 1){
	  for (int i = 0; i < bdSize; i++)
		cout << ROW;
	}
	cout << endl; 
  }
}
bool Tictactoe :: placePiece(char piece, int row, int col)
{
  if (board[row][col] != BLANK || row > SIZE - 1 || col > SIZE - 1 ||
	  row < 0 || col < 0)
	return false;
  else{
	board[row][col] = piece;
	return true; 
  }
}

char Tictactoe :: checkWinner()
{
  int countX = 0;  // counts number of x's in board array
  int countO = 0;  // counts number of o's in board array
  char detWin = BLANK; // determines who won or if game still continues
  bool stillSpaces = false; // flag for if there are still spaces available
  
  // checks for row win

  for (int r = 0; r < bdSize; r++){
	countX = 0;
	countO = 0;
	for (int c = 0; c < bdSize; c++){
	  if(board[r][c] == X)
		countX++;
	  else if (board[r][c] == O)
		countO++;
	}
	if (countX == bdSize)
	  detWin = X;
	else if (countO == bdSize)
	  detWin = O;
  }
  
  // checks for column win

  for (int c = 0; c < bdSize; c++){
	countX = 0;
	countO = 0;
	for (int r = 0; r < bdSize; r++){
	  if (board[r][c] == X)
		countX++;
	  else if (board[r][c] == O)
		countO++;
	}
	if (countX == bdSize)
	detWin = X;
	else if (countO == bdSize)
	  detWin = O;
  }

  // checks for left to right diagonal win

  countX = 0;
  countO = 0; 
  for (int r = 0; r < bdSize; r++){
	
	if (board[r][r] == X)
	  countX++;
	else if (board[r][r] == O)
	  countO++;
 
	if (countX == bdSize)
	  detWin = X;
	else if (countO == bdSize)
	  detWin = O;
	
  }

  // checks for right to left diagonal win

  countX = 0;
  countO = 0;
  
  for (int r = bdSize - 1; r >= 0; r--){	
	  if (board[r][bdSize - (r+1)] == X)
		countX++;
	  else if (board[r][bdSize - (r+1)] == O)
		countO++;
	
	  if (countX == bdSize)
		detWin = X;
	  else if (countO == bdSize)
		detWin = O;
  }
  
  for (int r = 0; r < bdSize; r++){
	for (int c = 0; c < bdSize; c++){
	  if (board[r][c] == BLANK)
		stillSpaces = true;
	}
  }
  
  if (!stillSpaces)
	detWin = TIE;
  
  return detWin;
}

void Tictactoe :: reset()
{
   for (int r = 0; r < bdSize; r ++){
	for (int c = 0; c < bdSize; c++){
	  board[r][c] = BLANK;
	}
   }
}
