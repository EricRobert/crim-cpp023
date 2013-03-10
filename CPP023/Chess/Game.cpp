// Copyright (c) 2012 Eric Robert.
// All rights reserved.

// inclusion des dépendances
#include <iostream>

// inclusions
#include "Game.hpp"
#include "Tree.hpp"

// inclusion des types de pièces
#include "Pawn.hpp"
#include "Castle.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Queen.hpp"

Game::Game() {
  const char * board =
    "RNBQKBNR"
    "PPPPPPPP"
    "        "
    "        "
    "        "
    "        "
    "pppppppp"
    "rnbqkbnr";

  Piece * map[128] = {};
  map['R'] = create<Castle>(0);
  map['r'] = create<Castle>(1);
  map['N'] = create<Knight>(0);
  map['n'] = create<Knight>(1);
  map['B'] = create<Bishop>(0);
  map['b'] = create<Bishop>(1);
  map['Q'] = create<Queen>(0);
  map['q'] = create<Queen>(1);
  map['K'] = kings[0] = create<King>(0);
  map['k'] = kings[1] = create<King>(1);
  map['P'] = create<Pawn>(0);
  map['p'] = create<Pawn>(1);

  for(int i = 0; i != N * N; ++i) {
    set(i % N, i / N, map[board[i]]);
  }
}

void Game::play() {
  char const * names[] = { "white", "black" };

  int rounds = 0;
  int player = 0;

  // boucle de jeu
  for(;;) {
    Piece const * opponent = kings[player ^ 1];
    if(!playBestMove(opponent)) {
      std::cout << "\n" << names[player] << " is stalemate" << std::endl;
      break;
    }

    std::cout << "\n" << names[player] << " is playing at round #" << ++rounds << "\n\n";
    print();

    player ^= 1;
    if(isCheckmate(opponent)) {
      std::cout << "\n" << names[player] << " is checkmate" << std::endl;
      break;
    }
  }

  std::cout << "game ended in " << rounds << " rounds" << std::endl;
}

bool Game::playBestMove(Piece const * kind) {
  Tree tree(DEPTH);
  exploreMoveTree(kind, tree);
  return tree.play(*this);
}
