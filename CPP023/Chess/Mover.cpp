#include "Mover.hpp"
#include "Board.hpp"

Mover::Mover(char c) : Piece(c) {
}

void Mover::slide(Board const & board, int x, int y, int dx, int dy) const {
  Piece const * self = board.getPieceAt(x, y);
  int i = x + dx;
  int j = y + dy;
  while(board.isValid(i, j)) {
    Piece const * item = board.getPieceAt(i, j);
    if(item) {
      // on termine le glissement dès qu'on rencontre une pièce
      if(!item->isSameTeam(self)) {
        printMove(board, x, y, i, j);
      }

      break;
    }
    else {
      printMove(board, x, y, i, j);
    }

    i += dx;
    j += dy;
  }
}
