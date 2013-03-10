// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef PIECE__INCLUDED
#define PIECE__INCLUDED

class Board;

// classe de base pour tous les types de pi�ces
class Piece
{
public:
  Piece(char value);

  bool isSameTeam(Piece const * item) const;
  bool isWhite() const;
  bool isBlack() const;
  char getNotation() const;

  virtual void printPossibleMoves(Board const & board, int i, int j) const;

protected:
  void printMove(Board const & board, int x, int y, int i, int j) const;

private:
  char c;
};

#endif