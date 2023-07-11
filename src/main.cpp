#include <iostream>
#include "../include/TADS/DoublyLinkedList/DoublyLinkedList.hpp"
#include "../include/Board.h"
#include "../include/Column.h"
#include "../include/FeatureTask.h"
#include "../include/BugTask.h"
#include "../include/TestTask.h"
#include "../include/storage/FileManager.hpp"

void addNewTask(Board* board){
  int optionTask;
  board->printBoard();

  cout << "Escolha o tipo da tarefa" << endl;

  cout << "1. Bug Task" << endl; 
  cout << "2. Feature Task" << endl; 
  cout << "3. Test Task" << endl;

  cout << "Digite a opcao escolhida: ";
  cin >> optionTask;
  cin.ignore();

  string title, description, id;

  cout << "Digite as informacoes da coluna" << endl;
  cout << "Id da coluna: ";
  getline(cin, id);
  cout << "-------------------------------" << endl;

  cout << "Nome: ";
  getline(cin, title);
  cout << "-------------------------------" << endl;
  
  cout << "Descricao: ";
  getline(cin, description);
  cout << "-------------------------------" << endl;

  tm deadline;
  // cout << "Ordem: ";
  // cin >> order;
  // cout << "-------------------------------" << endl;

  Column chosenColumn = board->getColumnById(id);
  switch (optionTask)
  {
  case 1:
  {
    int priority;
    cout << "Prioridade: ";
    cin >> priority;
    cin.ignore();
    cout << "-------------------------------" << endl;
    Task* bugTask = new BugTask(&chosenColumn, title, description, deadline, priority);
    chosenColumn.addTask(bugTask);
  }
    break;
  
  default:
    cout << "Opcao nao encontrada" << endl;
  }
}

void addNewColumns(Board* board){
  char addNewColumn = 'S';
  
  do{
    string id, name, description;
    int order;

    cout << "Digite as informacoes da coluna" << endl;
    cout << "Id: ";
    getline(cin, id);
    cout << "-------------------------------" << endl;

    cout << "Nome: ";
    getline(cin, name);
    cout << "-------------------------------" << endl;
    
    cout << "Descricao: ";
    getline(cin, description);
    cout << "-------------------------------" << endl;

    cout << "Ordem: ";
    cin >> order;
    cout << "-------------------------------" << endl;

    Column* newColumn = new Column(id, name, description, order);

    board->addColumn(newColumn);

    cout << "Deseja adicionar outra coluna?(S/N) ";
    cin.ignore();
    cin >> addNewColumn;
    cin.ignore();

  }while(toupper(addNewColumn) == 'S');
}

int showMenu(){
  int option;
  int minOption = 1;
  int maxOption = 7;

  // system("clear||cls");

  cout << "+---------------------------------+\n";
  cout << "|        MENU DE OPERACOES        |\n";
  cout << "+---------------------------------+\n";
  cout << "|  1 - Exibir o quadro            |\n";
  cout << "|  2 - Adicionar nova coluna      |\n";
  cout << "|  3 - Adicionar nova tarefa      |\n";
  cout << "|  4 - Detalhar tarefa            |\n";
  cout << "|  5 - Opcoes de ordenacao        |\n";
  cout << "|  6 - Salvar o quadro            |\n";
  cout << "|  7 - Sair                       |\n";
  cout << "+---------------------------------+\n";
  cout << "Digite o numero da operacao desejada: ";
  cin >> option;
  cin.ignore();

  if(option < minOption || option > maxOption){
    system("clear||cls");
    cout << "O numero digitado nao corresponde a nenhuma operacao. Tente novamente.\n";
    option = showMenu();
  }

  return option;
}

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

  addNewColumns(&boardKanban);

  int exitOption = 7;
  int chosenOption;

  do{
    chosenOption = showMenu();

    switch (chosenOption)
    {
    case 1:
      boardKanban.printBoard();
      break;
    case 2:
      addNewColumns(&boardKanban);
      break;
    case 3:
      addNewTask(&boardKanban);
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
      boardKanban.printBoard();
      break;
    }

  }while(chosenOption != exitOption);


  return 0;
}