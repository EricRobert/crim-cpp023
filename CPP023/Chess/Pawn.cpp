// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Pawn.hpp"
#include "Board.hpp"
#include "Explorer.hpp"

Pawn::Pawn(int type) : Piece(type ? 'p' : 'P') {
}

void Pawn::explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const {
  Piece const * self = board.getPieceAt(i, j);

  // on détermine la direction du mouvement selon la couleur
  int d = self->isWhite() ? 1 : -1;
  int y = j + d;

  // on teste les diagonales
  exploreCapture(explorer, board, i, j, i - 1, y);
  exploreCapture(explorer, board, i, j, i + 1, y);

  // et devant
  if(!board.getPieceAt(i, y)) {
    explorer.add(board, i, j, i, y);

    // et encore devant si la pièce se trouve sur la position initiale
    int w = self->isWhite() ? 1 : 6;
    if(j == w) {
      y += d;
      if(!board.getPieceAt(i, y)) {
        explorer.add(board, i, j, i, y);
      }
    }
  }
}

void Pawn::exploreCapture(Explorer & explorer, Board const & board, int x, int y, int i, int j) const {
  if(board.isValid(i, j)) {
    Piece const * self = board.getPieceAt(x, y);
    Piece const * item = board.getPieceAt(i, j);
    if(item && !item->isSameTeam(self)) {
      explorer.add(board, x, y, i, j);
    }
  }
}
