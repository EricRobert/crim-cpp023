// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef PAWN__INCLUDED
#define PAWN__INCLUDED

#include "Piece.hpp"

class Pawn : public Piece
{
public:
  Pawn(int type);

  void explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const;

  int getCost() const {
    return 1;
  }

private:
  void exploreCapture(Explorer & explorer, Board const & board, int x, int y, int i, int j) const;
};

#endif
