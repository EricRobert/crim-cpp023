// Copyright (c) 2012 Eric Robert.
// All rights reserved.

#ifndef GAME__INCLUDED
#define GAME__INCLUDED

// inclusions
#include "Board.hpp"
#include "Piece.hpp"

// d�pendances
#include <vector>

// logique de jeu
class Game : public Board
{
public:
  Game();

  // routine principale de jeu
  void play();

private:
  bool playBestMove(Piece const * kind);

  template<typename T>
    T * create(int color) {
      T * item = new T(color);
      pieces.push_back(ListType::value_type(item));
      return item;
  }

  // profondeur de r�cursion maximale
  static const int DEPTH = 3;

private:
  // gestion des pi�ces
  typedef std::vector<std::unique_ptr<Piece>> ListType;
  ListType pieces;

  Piece * kings[2];
};

#endif
