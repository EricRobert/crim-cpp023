// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#include "Pawn.hpp"
#include "Board.hpp"

Pawn::Pawn(char c) : Piece(c) {
}

void Pawn::printPossibleMoves(Board const & board, int i, int j) const {
  Piece const * self = board.getPieceAt(i, j);

  // on d�termine la direction du mouvement selon la couleur
  int d = self->isWhite() ? 1 : -1;
  int y = j + d;

  // on teste les diagonales
  printCapture(board, i, j, i - 1, y);
  printCapture(board, i, j, i + 1, y);

  // et devant
  if(!board.getPieceAt(i, y)) {
    printMove(board, i, j, i, y);

    // et encore devant si la pi�ce se trouve sur la position initiale
    int w = self->isWhite() ? 1 : 6;
    if(j == w) {
      y += d;
      if(!board.getPieceAt(i, y)) {
        printMove(board, i, j, i, y);
      }
    }
  }
}

void Pawn::printCapture(Board const & board, int x, int y, int i, int j) const {
  if(board.isValid(i, j)) {
    Piece const * self = board.getPieceAt(x, y);
    Piece const * item = board.getPieceAt(i, j);
    if(item && !item->isSameTeam(self)) {
      Board copy(board);
      copy.movePiece(x, y, i, j);
      copy.print();
    }
  }
}