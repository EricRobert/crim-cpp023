// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef KING__INCLUDED
#define KING__INCLUDED

#include "Piece.hpp"

class King : public Piece
{
public:
  King(char c);

  void printPossibleMoves(Board const & board, int i, int j) const;
};

#endif
