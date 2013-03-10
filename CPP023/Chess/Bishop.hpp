// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef BISHOP__INCLUDED
#define BISHOP__INCLUDED

#include "Mover.hpp"

class Bishop : public virtual Mover
{
public:
  Bishop(int type);

  void explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const;

  int getCost() const {
    return 3;
  }
};

#endif
