// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Tree.hpp"
#include "Board.hpp"

Tree::Tree(int _limit) : Explorer(_limit), best(0) {
}

void Tree::add(Board const & board, int x, int y, int i, int j) {
  int last = score;
  score = 0;
  Explorer::add(board, x, y, i, j);

  if(moves.empty() || best <= score) {
    if(last != best) {
      moves.clear();
    }

    moves.push_back(Move(x, y, i, j));
    best = score;
  }
}

bool Tree::play(Board & board) const {
  int n = moves.size();
  if(n) {
    static int random;
    ++random;

    Move const & item = moves[random % n];
    board.movePiece(item.x, item.y, item.i, item.j);
  }

  return !!n;
}
