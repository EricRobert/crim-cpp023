// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef BOARD__INCLUDED
#define BOARD__INCLUDED

class Piece;

// représentation de l'échiquier
class Board
{
public:
  static const int N = 8;

  Board();

  void print() const;
  void printPossibleMoves() const;
  bool isValid(int i, int j) const;
  void movePiece(int x, int y, int i, int j);
  void set(int i, int j, Piece * item);

  Piece const * getPieceAt(int i, int j) const;

private:
  Piece * squares[N * N];
};

#endif
