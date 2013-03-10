// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef KING__INCLUDED
#define KING__INCLUDED

#include "Piece.hpp"

class King : public Piece
{
public:
  King(char c);

  void explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const;

  int getCost() const {
    return 100;
  }
};

#endif
