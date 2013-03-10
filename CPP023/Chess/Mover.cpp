// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Mover.hpp"
#include "Board.hpp"
#include "Explorer.hpp"

Mover::Mover(char c) : Piece(c) {
}

void Mover::slide(Explorer & explorer, Board const & board, int x, int y, int dx, int dy) const {
  Piece const * self = board.getPieceAt(x, y);
  int i = x + dx;
  int j = y + dy;
  while(board.isValid(i, j)) {
    Piece const * item = board.getPieceAt(i, j);
    if(item) {
      // on termine le glissement dès qu'on rencontre une pièce
      if(!item->isSameTeam(self)) {
        explorer.add(board, x, y, i, j);
      }

      break;
    }
    else {
      explorer.add(board, x, y, i, j);
    }

    i += dx;
    j += dy;
  }
}
