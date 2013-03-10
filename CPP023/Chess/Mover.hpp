// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef MOVER__INCLUDED
#define MOVER__INCLUDED

#include "Piece.hpp"

// classe interm�diaire commune aux pi�ces glissantes
class Mover : public Piece
{
public:
  Mover(char c);

protected:
  void slide(Explorer & explorer, Board const & board, int x, int y, int dx, int dy) const;
};

#endif
