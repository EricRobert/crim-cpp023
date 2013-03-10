// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Board.hpp"
#include "Tree.hpp"

int main() {
  // jeu initial
  Board board;
  board.print();

  // explore l'arbre de possibilités
  Tree white(2);
  board.exploreMoveTree(board.getPieceAt(4, 7), white);
  white.play(board);
  board.print();

  Tree black(2);
  board.exploreMoveTree(board.getPieceAt(4, 0), black);
  black.play(board);
  board.print();
}
