#include <iostream>
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

  int exitOption = 7;
  int selectedOption;

  do
  {
    selectedOption = Menu::show();

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

    default:
      board.print();
      break;
    }

  } while (selectedOption != exitOption);

  return 0;
}