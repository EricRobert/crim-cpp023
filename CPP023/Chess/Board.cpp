// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Board.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Explorer.hpp"

// dépendances
#include <iostream>

// constructeur par défaut qui initialise l'échiquier
Board::Board() {
  for(int i = 0; i != N * N; ++i) {
    squares[i] = 0;
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

// explore les déplacements possibles
void Board::exploreMoveTree(Piece const * opponent, Explorer & explorer) const {
  for(int j = 0; j != N; ++j) {
    for(int i = 0; i != N; ++i) {
      Piece const * item = getPieceAt(i, j);
      if(item && !item->isSameTeam(opponent)) {
        item->explorePossibleMoves(explorer, *this, i, j);
      }
    }
  }
}

bool Board::isCheckmate(Piece const * king) {
  for(int i = 0; i != N * N; ++i) {
    if(squares[i] == king) {
      return false;
    }
  }

  return true;
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
