// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Castle.hpp"

Castle::Castle(char c) : Mover(c) {
}

void Castle::explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const {
  slide(explorer, board, i, j, 1, 0);
  slide(explorer, board, i, j, -1, 0);
  slide(explorer, board, i, j, 0, 1);
  slide(explorer, board, i, j, 0, -1);
}
