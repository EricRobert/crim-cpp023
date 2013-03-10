// Copyright (c) 2012 Eric Robert.
// All rights reserved.

// inclusions
#include <iostream>

// d�claration anticip�es
class Board;

// classe de base pour tous les types de pi�ces
class Piece
{
public:
  Piece(char value);

  bool isSameTeam(Piece const * item) const;
  char getNotation() const;

  // d�termine les mouvements possibles d'une pi�ce
  virtual void printPossibleMoves(Board const & board, int i, int j) const {
  }

private:
  char c;
};

// construit une pi�ce
Piece::Piece(char value) : c(value) {
}

// d�termine si 2 pi�ces sont de la m�me couleur
bool Piece::isSameTeam(Piece const * item) const {
  return (c >= 'a' && item->c >= 'a') || (c <= 'Z' && item->c <= 'Z');
}

// d�termine le caract�re � afficher
char Piece::getNotation() const {
  return c;
}

// repr�sentation de l'�chiquier
class Board
{
public:
  static const int N = 8;

  Board();

  void print() const;
  void printPossibleMoves() const;

  void movePiece(int x, int y, int i, int j);

  // validation des coordonn�es
  bool isValid(int i, int j) const {
    return i >= 0 && i < N && j >= 0 && j < N;
  }

  // acc�s aux pi�ces
  Piece const * getPieceAt(int i, int j) const {
    return squares[i + j * N];
  }

  void set(int i, int j, Piece * item);
  void set(int i, int j, Piece * white, Piece * black);

private:
  Piece * squares[N * N];
};

// place une pi�ce
void Board::set(int i, int j, Piece * item) {
  squares[i + j * N] = item;
}

// place une pi�ce en mirror et de chaque c�t�s
void Board::set(int i, int j, Piece * white, Piece * black) {
  set(i, j, white);
  set(N - i - 1, j, white);
  set(i, N - j - 1, black);
  set(N - i - 1, N - j - 1, black);
}

// groupe les fonctions li�es au chevalier
class Knight : public Piece
{
public:
  Knight(char c) : Piece(c) {
  }

  // v�rifie les 8 cas possibles du chevalier
  void printPossibleMoves(Board const & board, int i, int j) {
    printMove(board, i, j, i - 1, j + 2);
    printMove(board, i, j, i + 1, j + 2);
    printMove(board, i, j, i - 1, j - 2);
    printMove(board, i, j, i + 1, j - 2);
    printMove(board, i, j, i + 2, j - 1);
    printMove(board, i, j, i + 2, j + 1);
    printMove(board, i, j, i - 2, j - 1);
    printMove(board, i, j, i - 2, j + 1);
  }

  void printMove(Board const & board, int x, int y, int i, int j);
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

  Piece * map[128] = {};
  map['R'] = new Piece('R');
  map['r'] = new Piece('r');
  map['N'] = new Knight('N');
  map['n'] = new Knight('n');
  map['B'] = new Piece('B');
  map['b'] = new Piece('b');
  map['Q'] = new Piece('Q');
  map['q'] = new Piece('q');
  map['K'] = new Piece('K');
  map['k'] = new Piece('k');
  map['P'] = new Piece('P');
  map['p'] = new Piece('p');

  for(int i = 0; i != N * N; ++i) {
    squares[i] = map[board[i]];
  }
}

// affichage de l'�chiquier
void Board::print() const {
  std::cout << " abcdefgh " << std::endl;

  // affiche les pi�ces noires puis les blanches
  for(int j = N; j != 0; --j) {
    std::cout << j;

    for(int i = 0; i != N; ++i) {
      Piece const * item = getPieceAt(i, j - 1);
      if(item) {
        std::cout << item->getNotation();
      }
      else {
        std::cout << ' ';
      }
    }

    // compl�te la ligne
    std::cout << j << std::endl;
  }

  std::cout << " abcdefgh " << std::endl << std::endl;
}

// recherche les d�placements possibles
void Board::printPossibleMoves() const {
  for(int j = 0; j != N; ++j) {
    for(int i = 0; i != N; ++i) {
      Piece const * item = getPieceAt(i, j);
      if(item) {
        item->printPossibleMoves(*this, i, j);
      }
    }
  }
}

// d�placement d'une pi�ce
void Board::movePiece(int x, int y, int i, int j) {
  if(isValid(x, y) && isValid(i, j)) {
    squares[i + j * N] = squares[x + y * N];
    squares[x + y * N] = 0;
  }
}

// effectue et imprime le d�placement
void Knight::printMove(Board const & board, int x, int y, int i, int j) {
  if(board.isValid(i, j)) {
    Piece const * self = board.getPieceAt(x, y);
    Piece const * item = board.getPieceAt(i, j);
    if(!item || !item->isSameTeam(self)) {
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
  board.printPossibleMoves();

  // bouge le chevalier noir
  board.movePiece(1, 7, 2, 5);
  board.print();

  // encore...
  board.printPossibleMoves();
}
