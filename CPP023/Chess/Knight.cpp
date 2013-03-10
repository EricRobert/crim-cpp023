// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Knight.hpp"

Knight::Knight(char c) : Piece(c) {
}

void Knight::explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const {
  exploreMove(explorer, board, i, j, i - 1, j + 2);
  exploreMove(explorer, board, i, j, i + 1, j + 2);
  exploreMove(explorer, board, i, j, i - 1, j - 2);
  exploreMove(explorer, board, i, j, i + 1, j - 2);
  exploreMove(explorer, board, i, j, i + 2, j - 1);
  exploreMove(explorer, board, i, j, i + 2, j + 1);
  exploreMove(explorer, board, i, j, i - 2, j - 1);
  exploreMove(explorer, board, i, j, i - 2, j + 1);
}
