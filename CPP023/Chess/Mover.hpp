#ifndef MOVER__INCLUDED
#define MOVER__INCLUDED

#include "Piece.hpp"

// classe intermédiaire commune aux pièces glissantes
class Mover : public Piece
{
public:
  Mover(char c);

protected:
  void slide(Board const & board, int x, int y, int dx, int dy) const;
};

#endif
