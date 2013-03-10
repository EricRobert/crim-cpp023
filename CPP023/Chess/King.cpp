// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "King.hpp"

King::King(char c) : Piece(c) {
}

void King::explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const {
  exploreMove(explorer, board, i, j, i + 1, j + 1);
  exploreMove(explorer, board, i, j, i + 1, j);
  exploreMove(explorer, board, i, j, i + 1, j - 1);
  exploreMove(explorer, board, i, j, i, j + 1);
  exploreMove(explorer, board, i, j, i, j - 1);
  exploreMove(explorer, board, i, j, i - 1, j + 1);
  exploreMove(explorer, board, i, j, i - 1, j);
  exploreMove(explorer, board, i, j, i - 1, j - 1);
}
