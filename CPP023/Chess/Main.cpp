// Copyright (c) 2012 Eric Robert.
// All rights reserved.

// inclusions
#include <iostream>

// repr�sentation de l'�chiquier
class Board
{
public:
  static const int N = 8;

  Board();

  void print() const;
  void printPossibleMoves(char type) const;

  void movePiece(int x, int y, int i, int j);

  // validation des coordonn�es
  bool isValid(int i, int j) const {
    return i >= 0 && i < N && j >= 0 && j < N;
  }

  // acc�s aux pi�ces
  char getPieceAt(int i, int j) const {
    return squares[i + j * N];
  }

private:
  char squares[N * N];
};

// groupe les fonctions li�es au chevalier
class Knight
{
public:
  // v�rifie les 8 cas possibles du chevalier
  static void printPossibleMoves(Board const & board, int i, int j) {
    printMove(board, i, j, i - 1, j + 2);
    printMove(board, i, j, i + 1, j + 2);
    printMove(board, i, j, i - 1, j - 2);
    printMove(board, i, j, i + 1, j - 2);
    printMove(board, i, j, i + 2, j - 1);
    printMove(board, i, j, i + 2, j + 1);
    printMove(board, i, j, i - 2, j - 1);
    printMove(board, i, j, i - 2, j + 1);
  }

  static void printMove(Board const & board, int x, int y, int i, int j);
};

// constructeur par d�faut
Board::Board() {
  const char * board =
    "RNBQKBNR"
    "PPPPPPPP"
    "        "
    "        "
    "        "
    "        "
    "pppppppp"
    "rnbqkbnr";

  for(int i = 0; i != N * N; ++i) {
    squares[i] = board[i];
  }
}

// affichage de l'�chiquier
void Board::print() const {
  std::cout << " abcdefgh " << std::endl;

  // affiche les pi�ces noires puis les blanches
  for(int j = N; j != 0; --j) {
    std::cout << j;
    for(int i = 0; i != N; ++i) {
      std::cout << getPieceAt(i, j - 1);
    }

    // compl�te la ligne
    std::cout << j << std::endl;
  }

  std::cout << " abcdefgh " << std::endl << std::endl;
}

// recherche les d�placements possibles
void Board::printPossibleMoves(char type) const {
  for(int j = 0; j != N; ++j) {
    for(int i = 0; i != N; ++i) {
      char c = getPieceAt(i, j);
      if(c == type) {
        switch(c) {
        case 'n': case 'N':
          Knight::printPossibleMoves(*this, i, j);
          break;
        case 'r': case 'R':
        case 'b': case 'B':
        case 'k': case 'K':
        case 'q': case 'Q':
        case 'p': case 'P':
          break;
        }
      }
    }
  }
}

// d�placement d'une pi�ce
void Board::movePiece(int x, int y, int i, int j) {
  if(isValid(x, y) && isValid(i, j)) {
    squares[i + j * N] = squares[x + y * N];
    squares[x + y * N] = ' ';
  }
}

// d�termine si 2 pi�ces sont de la m�me couleur
bool isSameTeam(char a, char b) {
  return (a >= 'a' && b >= 'a') || (a <= 'Z' && b <= 'Z');
}

// effectue et imprime le d�placement
void Knight::printMove(Board const & board, int x, int y, int i, int j) {
  if(board.isValid(i, j)) {
    char self = board.getPieceAt(x, y);
    char item = board.getPieceAt(i, j);
    if(item == ' ' || !isSameTeam(item, self)) {
      Board copy(board);
      copy.movePiece(x, y, i, j);
      copy.print();
    }
  }
}

int main() {
  // jeu initial
  Board board;
  board.print();

  // ouvertures
  board.printPossibleMoves('n');

  // bouge le chevalier noir
  board.movePiece(1, 7, 2, 5);
  board.print();

  // encore...
  board.printPossibleMoves('n');
}
