// Copyright (c) 2012 Eric Robert.
// All rights reserved.

// inclusions
#include <iostream>

// validation des coordonn�es
bool isValid(int i, int j) {
  return i >= 0 && i < 8 && j >= 0 && j < 8;
}

// repr�sentation de l'�chiquier
class Board
{
public:
  Board();

  void print() const;
  void movePiece(int x, int y, int i, int j);

private:
  char squares[64];
};

// constructeur par d�faut
Board::Board() {
  char const * board =
    "RNBQKBNR"
    "PPPPPPPP"
    "        "
    "        "
    "        "
    "        "
    "pppppppp"
    "rnbqkbnr";

  for(int i = 0; i != 64; ++i) {
    squares[i] = board[i];
  }
}

// affichage de l'�chiquier
void Board::print() const {
  std::cout << " abcdefgh " << std::endl;

  // affiche les pi�ces noires puis les blanches
  for(int j = 8; j != 0; --j) {
    std::cout << j;
    for(int i = 0; i != 8; ++i) {
      std::cout << squares[i + (j - 1) * 8];
    }

    // compl�te la ligne
    std::cout << j << std::endl;
  }

  std::cout << " abcdefgh " << std::endl;
}

// d�placement d'une pi�ce
void Board::movePiece(int x, int y, int i, int j) {
  if(isValid(x, y) && isValid(i, j)) {
    squares[i + j * 8] = squares[x + y * 8];
    squares[x + y * 8] = ' ';
  }
}

int main() {
  // allocation de l'�chiquier
  Board a;

  a.print();
  a.movePiece(1, 0, 2, 2); // bouge le chevalier blanc
  a.print();

  // duplique l'�chiquier
  Board b(a);
  b.movePiece(1, 7, 2, 5); // bouge le chevalier noir
  b.print();
}
