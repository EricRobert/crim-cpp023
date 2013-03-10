// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Explorer.hpp"
#include "Board.hpp"
#include "Piece.hpp"

// dépendances
#include <algorithm>
#include <iostream>

Explorer::Explorer(int _level) : level(_level), score(0) {
}

void Explorer::add(Board const & board, int x, int y, int i, int j) {
  int result = 0;

  Piece const * self = board.getPieceAt(x, y);
  Piece const * item = board.getPieceAt(i, j);
  if(item) {
    result = item->getCost();
  }

  if(level) {
    Board next(board);
    next.movePiece(x, y, i, j);

    Explorer turn(level - 1);
    next.exploreMoveTree(self, turn);
    result -= turn.score;
  }

  score = std::max(score, result);
};
