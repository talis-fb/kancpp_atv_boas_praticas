#include <iostream>
#include "../include/Board.h"

int main()
{
  Board *board = new Board("Initial board", "Default board for testing");

  std::cout << board->getName() << std::endl;
  std::cout << board->getDescription() << std::endl;

  return 0;
}