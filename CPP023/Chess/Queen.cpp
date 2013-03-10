// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Queen.hpp"

Queen::Queen(char c) : Mover(c), Bishop(c), Castle(c) {
}

void Queen::explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const {
  Bishop::explorePossibleMoves(explorer, board, i, j);
  Castle::explorePossibleMoves(explorer, board, i, j);
}
