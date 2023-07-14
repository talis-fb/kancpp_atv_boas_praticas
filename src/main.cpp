#include <iostream>
#include <fstream>

#include "../include/TADS/DoublyLinkedList/DoublyLinkedList.hpp"
#include "../include/Board.h"
#include "../include/Column.h"
#include "../include/FeatureTask.h"
#include "../include/BugTask.h"
#include "../include/TestTask.h"
#include "../include/utils/Menu.hpp"

int main()
{
  system("clear||cls");

  Board board;

  std::fstream fileManager2("data/board.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::app);

  if (fileManager2.is_open() && fileManager2.peek() != std::ifstream::traits_type::eof())
  {
    board.deserialize(fileManager2);
    fileManager2.close();
  }
  else
  {
    string name, description;

    cout << "Insira as informacoes do seu Kanban\n";

    cout << "Nome do quadro: ";
    getline(cin, name);

    cout << "Descricao do quadro: ";
    getline(cin, description);

    Board board(name, description);

    cout << "Quadro criado com sucesso!\n\n";

    cout << "Vamos adicionar as primeiras colunas do quadro " << board.getName() << endl
         << endl;

    Menu::addNewColumns(&board);
  }

  int exitOption = 8;
  int selectedOption;

  do
  {
    selectedOption = Menu::show(exitOption);

    switch (selectedOption)
    {
    case 1:
      board.print();
      break;
    case 2:
      Menu::addNewColumns(&board);
      break;
    case 3:
      Menu::removeColumn(&board);
      break;
    case 4:
      Menu::addNewTask(&board);
      break;
    case 5:
      Menu::taskDetails(&board);
      break;
    case 6:
      /* code */
      break;
    case 7:
      Menu::saveBoard(&board);
      break;
    case 8:
      break;

    default:
      board.print();
      break;
    }

  } while (selectedOption != exitOption);

  return 0;
}