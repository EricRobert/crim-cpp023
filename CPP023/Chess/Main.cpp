// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Board.hpp"
#include "Explorer.hpp"

int main() {
  // jeu initial
  Board board;
  board.print();

  // explore l'arbre de possibilités
  Explorer root(2);
  board.exploreMoveTree(board.getPieceAt(4, 7), root);
}
