#include <iostream>
#include "../include/Column.h"
#include "../include/FeatureTask.h"
#include "../include/storage/FileManager.hpp"

int main()
{
  Column *column = new Column("1", "name");
  FeatureTask *featureTask = new FeatureTask(*column, "title", "description", "project");

  std::cout << featureTask->getProject() << std::endl;

  FileManager *file = new FileManager("task.bin");

  if (file->isOpen())
  {
    file->write(featureTask);
    delete file;
    cout << "Objeto da classe FeatureTask foi persistido com sucesso no arquivo feature_tasks.bin." << endl;
  }
  else
  {
    cout << "Erro ao abrir o arquivo." << endl;
  }

  // Ler o objeto da classe FeatureTask do arquivo

  FileManager *file2 = new FileManager("task.bin");

  if (file2->isOpen())
  {
    cout << "Arquivo aberto com sucesso." << endl;
    FeatureTask *featureTask2 = file2->read<FeatureTask>();
    featureTask2->print();
    delete file2;

    // if (!file2->isEOF())
    // {
    //   // O objeto da classe FeatureTask foi lido com sucesso do arquivo
    //   // Agora você pode trabalhar com o objeto recuperado

    //   // Lembre-se de liberar a memória alocada para o objeto featureTask
    //   delete featureTask2;
    // }
    // else
    // {
    //   cout << "Erro ao ler o objeto da classe FeatureTask do arquivo->" << endl;
    // }
  }
  else
  {
    cout << "Erro ao abrir o arquivo." << endl;
  }

  return 0;
}