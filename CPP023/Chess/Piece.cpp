// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Piece.hpp"
#include "Board.hpp"

Piece::Piece(char value) : c(value) {
}

// d�termine si 2 pi�ces sont de la m�me couleur
bool Piece::isSameTeam(Piece const * item) const {
  return (c >= 'a' && item->c >= 'a') || (c <= 'Z' && item->c <= 'Z');
}

bool Piece::isWhite() const {
  return c >= 'A' && c <= 'Z';
}

bool Piece::isBlack() const {
  return c >= 'a' && c <= 'z';
}

char Piece::getNotation() const {
  return c;
}

void Piece::printPossibleMoves(Board const & board, int i, int j) const {
}

void Piece::printMove(Board const & board, int x, int y, int i, int j) const {
  if(board.isValid(i, j)) {
    Piece const * self = board.getPieceAt(x, y);
    Piece const * item = board.getPieceAt(i, j);
    if(!item || !item->isSameTeam(self)) {
      Board copy(board);
      copy.movePiece(x, y, i, j);
      copy.print();
    }
  }
}
