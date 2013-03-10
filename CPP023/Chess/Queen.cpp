// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Queen.hpp"

Queen::Queen(char c) : Mover(c), Bishop(c), Castle(c) {
}

void Queen::printPossibleMoves(Board const & board, int i, int j) const {
  Bishop::printPossibleMoves(board, i, j);
  Castle::printPossibleMoves(board, i, j);
}
