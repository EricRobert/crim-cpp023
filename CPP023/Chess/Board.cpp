// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Board.hpp"
#include "Castle.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Pawn.hpp"

// dépendances
#include <iostream>

// constructeur par défaut qui initialise l'échiquier
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
  map['R'] = new Castle('R');
  map['r'] = new Castle('r');
  map['N'] = new Knight('N');
  map['n'] = new Knight('n');
  map['B'] = new Bishop('B');
  map['b'] = new Bishop('b');
  map['Q'] = new Queen('Q');
  map['q'] = new Queen('q');
  map['K'] = new King('K');
  map['k'] = new King('k');
  map['P'] = new Pawn('P');
  map['p'] = new Pawn('p');

  for(int i = 0; i != N * N; ++i) {
    squares[i] = map[board[i]];
  }
}

// affichage de l'échiquier sur la console
void Board::print() const {
  std::cout << " abcdefgh " << std::endl;

  // affiche les pièces noires puis les blanches
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

    // complète la ligne
    std::cout << j << std::endl;
  }

  std::cout << " abcdefgh " << std::endl << std::endl;
}

// affichage des déplacements possibles sur la console
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

// validation des coordonnées
bool Board::isValid(int i, int j) const {
  return i >= 0 && i < N && j >= 0 && j < N;
}

// déplacement d'une pièce
void Board::movePiece(int x, int y, int i, int j) {
  if(isValid(x, y) && isValid(i, j)) {
    squares[i + j * N] = squares[x + y * N];
    squares[x + y * N] = 0;
  }
}

// assignation d'une pièce
void Board::set(int i, int j, Piece * item) {
  squares[i + j * N] = item;
}

// accès aux pièces
Piece const * Board::getPieceAt(int i, int j) const {
  return squares[i + j * N];
}
