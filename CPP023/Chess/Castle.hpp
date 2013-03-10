// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef CASTLE__INCLUDED
#define CASTLE__INCLUDED

#include "Mover.hpp"

class Castle : public virtual Mover
{
public:
  Castle(char c);

  void explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const;

  int getCost() const {
    return 5;
  }
};

#endif
