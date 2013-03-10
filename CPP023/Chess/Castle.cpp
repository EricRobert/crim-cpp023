// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Castle.hpp"

Castle::Castle(char c) : Mover(c) {
}

void Castle::printPossibleMoves(Board const & board, int i, int j) const {
  slide(board, i, j, 1, 0);
  slide(board, i, j, -1, 0);
  slide(board, i, j, 0, 1);
  slide(board, i, j, 0, -1);
}
