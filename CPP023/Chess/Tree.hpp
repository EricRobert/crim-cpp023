// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef TREE__INCLUDED
#define TREE__INCLUDED

#include <vector>

#include "Explorer.hpp"
#include "Move.hpp"

class Tree : public Explorer
{
public:
  Tree(int _limit);

  void add(Board const & board, int x, int y, int i, int j);
  bool play(Board & board) const;

private:
  std::vector<Move> moves;
  int best;
};

#endif
