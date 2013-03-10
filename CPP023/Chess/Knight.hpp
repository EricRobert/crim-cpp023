// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef KNIGHT__INCLUDED
#define KNIGHT__INCLUDED

#include "Piece.hpp"

class Knight : public Piece
{
public:
  Knight(char c);

  void explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const;

  int getCost() const {
    return 3;
  }
};

#endif
