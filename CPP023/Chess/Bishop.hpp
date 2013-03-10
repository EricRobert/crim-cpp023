// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef BISHOP__INCLUDED
#define BISHOP__INCLUDED

#include "Mover.hpp"

class Bishop : public virtual Mover
{
public:
  Bishop(char c);

  void printPossibleMoves(Board const & board, int i, int j) const;
};

#endif
