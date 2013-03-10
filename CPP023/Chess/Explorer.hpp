// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef EXPLORER__INCLUDED
#define EXPLORER__INCLUDED

class Board;

class Explorer
{
public:
  Explorer(int _level);

  virtual void add(Board const & board, int x, int y, int i, int j);

protected:
  int level;
  int score;
};

#endif
