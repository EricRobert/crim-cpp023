// Copyright (c) 2012 Eric Robert.
// All rights reserved.

// inclusions
#include <iostream>

// représentation de l'échiquier
class Board
{
public:
  static const int N = 8;

  Board();

  void print() const;
  void printPossibleMoves(char type) const;

  void movePiece(int x, int y, int i, int j);

  // validation des coordonnées
  bool isValid(int i, int j) const {
    return i >= 0 && i < N && j >= 0 && j < N;
  }

  // accès aux pièces
  char getPieceAt(int i, int j) const {
    return squares[i + j * N];
  }

private:
  char squares[N * N];
};

// groupe les fonctions liées au chevalier
class Knight
{
public:
  // vérifie les 8 cas possibles du chevalier
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

// constructeur par défaut
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

// affichage de l'échiquier
void Board::print() const {
  std::cout << " abcdefgh " << std::endl;

  // affiche les pièces noires puis les blanches
  for(int j = N; j != 0; --j) {
    std::cout << j;
    for(int i = 0; i != N; ++i) {
      std::cout << getPieceAt(i, j - 1);
    }

    // complète la ligne
    std::cout << j << std::endl;
  }

  std::cout << " abcdefgh " << std::endl << std::endl;
}

// recherche les déplacements possibles
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

// déplacement d'une pièce
void Board::movePiece(int x, int y, int i, int j) {
  if(isValid(x, y) && isValid(i, j)) {
    squares[i + j * N] = squares[x + y * N];
    squares[x + y * N] = ' ';
  }
}

// détermine si 2 pièces sont de la même couleur
bool isSameTeam(char a, char b) {
  return (a >= 'a' && b >= 'a') || (a <= 'Z' && b <= 'Z');
}

// effectue et imprime le déplacement
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
