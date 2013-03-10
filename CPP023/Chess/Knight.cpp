// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Knight.hpp"

Knight::Knight(char c) : Piece(c) {
}

void Knight::printPossibleMoves(Board const & board, int i, int j) const {
  printMove(board, i, j, i - 1, j + 2);
  printMove(board, i, j, i + 1, j + 2);
  printMove(board, i, j, i - 1, j - 2);
  printMove(board, i, j, i + 1, j - 2);
  printMove(board, i, j, i + 2, j - 1);
  printMove(board, i, j, i + 2, j + 1);
  printMove(board, i, j, i - 2, j - 1);
  printMove(board, i, j, i - 2, j + 1);
}
