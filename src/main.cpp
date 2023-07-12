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

  /*Column *column = new Column("1", "name");

  FeatureTask featureTask1(*column, "project1");
  FeatureTask featureTask2(*column, "project2");

  FileManager file(Filename::TASK);

  if (file.isReady())
  {
    file.write(featureTask1, featureTask2);
    cout << "Objetos da classe FeatureTask foram persistidos com sucesso no arquivo tasks.bin." << endl;
  }
  else
  {
    cout << "Erro ao abrir o arquivo." << endl;
  }

  file.~FileManager();

  FileManager readFile(Filename::TASK);

  vector<FeatureTask> tasks = readFile.read<FeatureTask>();
  cout << "Objetos lidos do arquivo:" << endl;
  for (const FeatureTask &task : tasks)
  {
    task.print();
  }

  readFile.~FileManager();*/

  cout << "Insira as informacoes do seu Kanban\n";

  // cout << "Nome: ";
  string nameKanban = "teste";
  // cin >> nameKanban;

  // cout << "Descricao: ";
  string descriptionKanban = "teste descricao";
  // cin >> descriptionKanban;

  Board boardKanban(nameKanban, descriptionKanban);

  cout << "Vamos adicionar as primeiras colunas do seu quadro kanban\n";

  Menu::addNewColumns(&boardKanban);

  int exitOption = 7;
  int chosenOption;

  do
  {
    chosenOption = Menu::show();

    switch (chosenOption)
    {
    case 1:
      boardKanban.print();
      break;
    case 2:
      Menu::addNewColumns(&boardKanban);
      break;
    case 3:
      Menu::addNewTask(&boardKanban);
      break;
    case 4:
      /* code */
      break;
    case 5:
      /* code */
      break;
    case 6:
      /* code */
      break;

    default:
      boardKanban.print();
      break;
    }

  } while (chosenOption != exitOption);

  return 0;
}