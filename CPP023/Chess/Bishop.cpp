// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Bishop.hpp"

Bishop::Bishop(char c) : Mover(c) {
}

void Bishop::printPossibleMoves(Board const & board, int i, int j) const {
  slide(board, i, j, 1, 1);
  slide(board, i, j, 1, -1);
  slide(board, i, j, -1, 1);
  slide(board, i, j, -1, -1);
}
