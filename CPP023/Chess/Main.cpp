// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Board.hpp"

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
