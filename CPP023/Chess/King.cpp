// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "King.hpp"

King::King(char c) : Piece(c) {
}

void King::printPossibleMoves(Board const & board, int i, int j) const {
  printMove(board, i, j, i + 1, j + 1);
  printMove(board, i, j, i + 1, j);
  printMove(board, i, j, i + 1, j - 1);
  printMove(board, i, j, i, j + 1);
  printMove(board, i, j, i, j - 1);
  printMove(board, i, j, i - 1, j + 1);
  printMove(board, i, j, i - 1, j);
  printMove(board, i, j, i - 1, j - 1);
}
