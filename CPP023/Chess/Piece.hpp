// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef PIECE__INCLUDED
#define PIECE__INCLUDED

class Board;
class Explorer;

// classe de base pour tous les types de pièces
class Piece
{
public:
  Piece(char value);

  virtual ~Piece() {
  }

  bool isSameTeam(Piece const * item) const;
  bool isWhite() const;
  bool isBlack() const;
  char getNotation() const;

  virtual void explorePossibleMoves(Explorer & explorer, Board const & board, int i, int j) const;

  virtual int getCost() const;

protected:
  void exploreMove(Explorer & explorer, Board const & board, int x, int y, int i, int j) const;

private:
  char c;
};

#endif
