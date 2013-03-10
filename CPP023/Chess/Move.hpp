// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef MOVE__INCLUDED
#define MOVE__INCLUDED

struct Move
{
  int x;
  int y;
  int i;
  int j;

  Move(int _x, int _y, int _i, int _j) : x(_x), y(_y), i(_i), j(_j) {
  }
};

#endif
