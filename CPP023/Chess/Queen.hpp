// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef QUEEN__INCLUDED
#define QUEEN__INCLUDED

#include "Bishop.hpp"
#include "Castle.hpp"

class Queen : public Bishop, public Castle
{
public:
  Queen(char c);

  void printPossibleMoves(Board const & board, int i, int j) const;
};

#endif
