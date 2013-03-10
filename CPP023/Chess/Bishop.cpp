// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Bishop.hpp"

Bishop::Bishop(int type) : Mover(type ? 'b' : 'B') {
}

void Bishop::explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const {
  slide(explorer, board, i, j, 1, 1);
  slide(explorer, board, i, j, 1, -1);
  slide(explorer, board, i, j, -1, 1);
  slide(explorer, board, i, j, -1, -1);
}
