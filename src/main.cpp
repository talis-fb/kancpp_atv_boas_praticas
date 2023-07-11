#include <iostream>
#include "../include/TADS/DoublyLinkedList/DoublyLinkedList.hpp"
#include "../include/Board.h"
#include "../include/Column.h"
#include "../include/FeatureTask.h"
#include "../include/storage/FileManager.hpp"

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

  // DoublyLinkedList* teste = new DoublyLinkedList<int>();


  cout << "Insira as informacoes do seu Kanban\n";
  
  // cout << "Nome: ";
  string nameKanban = "teste";
  // cin >> nameKanban;
  
  // cout << "Descricao: ";
  string descriptionKanban = "teste descricao";
  // cin >> descriptionKanban;

  Board boardKanban(nameKanban, descriptionKanban);
  
  cout << "Vamos adicionar as primeiras colunas do seu quadro kanban\n";

  char addNewColumn = 'S';
  

  do{
    string id, name, description;
    int order;

    cout << "Digite as informacoes da coluna" << endl;

    cout << "Id: ";
    // id = "1";
    getline(cin, id);
    cout << "-------------------------------" << endl;;

    cout << "Nome: ";
    // name = "A fazer";
    getline(cin, name);
    cout << "-------------------------------" << endl;;
    
    cout << "Descricao: ";
    // description = "Tarefas a fazer";
    getline(cin, description);
    cout << "-------------------------------" << endl;;

    cout << "Ordem: ";
    // order = 1;
    cin >> order;
    cout << "-------------------------------" << endl;;

    Column* newColumn = new Column(id, name, description, order);

    cout << newColumn->getId() << endl;
    cout << newColumn->getName() << endl;
    cout << newColumn->getDescription() << endl;
    cout << newColumn->getOrder() << endl;

    boardKanban.addColumn(newColumn);

    cout << "Deseja adicionar outra coluna?(S/N) ";
    cin.ignore();
    cin >> addNewColumn;
    cin.ignore();

  }while(toupper(addNewColumn) == 'S');



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
      /* code */
      break;
    case 3:
      /* code */
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