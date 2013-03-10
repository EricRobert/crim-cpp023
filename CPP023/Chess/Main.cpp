// Copyright (c) 2012 Eric Robert.
// All rights reserved.

// inclusions
#include <iostream>

// �chiquier 8x8
char board[] = "RNBQKBNR"
               "PPPPPPPP"
               "        "
               "        "
               "        "
               "        "
               "pppppppp"
               "rnbqkbnr";

// affichage de l'�chiquier
void print() {
  std::cout << " abcdefgh " << std::endl;

  // affiche les pi�ces noires puis les blanches
  for(int j = 8; j != 0; --j) {
    std::cout << j;
    for(int i = 0; i != 8; ++i) {
      std::cout << board[i + (j - 1) * 8];
    }

    // compl�te la ligne
    std::cout << j << std::endl;
  }

  std::cout << " abcdefgh " << std::endl;
}

// validation des coordonn�es
bool isValid(int i, int j) {
  return i >= 0 && i < 8 && j >= 0 && j < 8;
}

// d�placement d'une pi�ce
void movePiece(int x, int y, int i, int j) {
  if(isValid(x, y) && isValid(i, j)) {
    board[i + j * 8] = board[x + y * 8];
    board[x + y * 8] = ' ';
  }
}

int main() {
  print();
  movePiece(1, 0, 2, 2); // bouge le chevalier blanc
  print();
}
