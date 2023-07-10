#include <iostream>
#include "../include/Column.h"
#include "../include/FeatureTask.h"
#include "../include/storage/FileManager.hpp"

int main()
{
  Column *column = new Column("1", "name");

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

  readFile.~FileManager();

  return 0;
}