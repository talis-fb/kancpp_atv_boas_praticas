#ifndef MENU_CLASS
#define MENU_CLASS

#include <iostream>
#include "../Board.h"
#include "../Column.h"
#include "../FeatureTask.h"
#include "../BugTask.h"
#include "../TestTask.h"

using namespace std;

class Menu
{
public:
    static void addNewTask(Board *board)
    {
        int optionTask;

        board->print();

        cout << "+----------------------------------------+\n";
        cout << "|        Escolha o tipo da tarefa        |\n";
        cout << "+----------------------------------------+\n";
        cout << "|  1 - Bug                               |\n";
        cout << "|  2 - Feature                           |\n";
        cout << "|  3 - Teste                             |\n";
        cout << "+----------------------------------------+\n";

        cout << "Digite a opcao escolhida: ";
        cin >> optionTask;
        cin.ignore();

        string title, description, id;

        cout << "Digite o ID da coluna dessa tarefa: ";
        getline(cin, id);
        cout << endl;

        Column *selectedColumn = board->getColumnById(id);

        while (selectedColumn == nullptr)
        {
            cout << "Coluna nao encontrada. Tente novamente: ";
            cin >> id;
            cin.ignore();
            cout << endl;

            selectedColumn = board->getColumnById(id);
        }

        cout << "Nome da tarefa: ";
        getline(cin, title);
        cout << endl;

        cout << "Descricao da tarefa: ";
        getline(cin, description);
        cout << endl;

        switch (optionTask)
        {
        case 1:
        {
            cout << endl
                 << "+--------------------------------------------+\n";
            cout << "|        Qual a prioridade da tarefa?        |\n";
            cout << "+--------------------------------------------+\n";
            cout << "|  1 - Muito baixa                           |\n";
            cout << "|  2 - Baixa                                 |\n";
            cout << "|  3 - Media                                 |\n";
            cout << "|  4 - Alta                                  |\n";
            cout << "|  5 - Muito alta                            |\n";
            cout << "+--------------------------------------------+\n";
            cout << "Digite a opcao escolhida: ";

            int priority;

            cin >> priority;
            cin.ignore();
            cout << "-------------------------------" << endl;

            while (priority < 1 || priority > 5)
            {
                cout << "Opcao invalida. Tente novamente: ";
                cin >> priority;
                cin.ignore();
            }

            Task *bugTask = new BugTask(title, description, priority);
            selectedColumn->addTask(bugTask);

            break;
        }
        case 2:
        {
            string project;
            cout << "Qual o projeto dessa feature?: ";

            cin >> project;
            cin.ignore();

            Task *featureTask = new FeatureTask(title, description, project);
            selectedColumn->addTask(featureTask);

            break;
        }
        case 3:
        {
            char hasFeature;
            cout << "A tarefa possui feature? (S/N) ";
            cin >> hasFeature;
            cin.ignore();

            while (toupper(hasFeature) != 'S' && toupper(hasFeature) != 'N')
            {
                cout << "Opcao invalida. Tente novamente: ";
                cin >> hasFeature;
                cin.ignore();
            }

            Task *testTask;
            string feature;

            if (toupper(hasFeature) == 'S')
            {
                while (true)
                {
                    cout << "Id da feature: ";
                    cin >> feature;
                    cin.ignore();

                    Task *featureTask = board->searchTaskById(feature);

                    if (featureTask != nullptr && featureTask->getType() == "FEATURE")
                    {
                        testTask = new TestTask(title, description, static_cast<FeatureTask *>(featureTask));
                        break;
                    }
                    else
                    {
                        if (featureTask == nullptr)
                        {
                            cout << "Tarefa nao encontrada.";
                        }

                        if (featureTask->getType() != "FEATURE")
                        {
                            cout << "Tarefa encontrada nao e uma feature.";
                        }

                        cout << " Gostaria de criar sem feature? (S/N) ";
                        cin >> hasFeature;
                        cin.ignore();

                        while (toupper(hasFeature) != 'S' && toupper(hasFeature) != 'N')
                        {
                            cout << "Opcao invalida. Tente novamente: ";
                            cin >> hasFeature;
                            cin.ignore();
                        }

                        if (toupper(hasFeature) == 'N')
                        {
                            testTask = new TestTask(title, description);
                            break;
                        }
                    }
                }
            }
            else
            {
                testTask = new TestTask(title, description);
            }
            selectedColumn->addTask(testTask);

            break;
        }
        default:
            cout << "Opcao nao encontrada" << endl;
            break;
        }

        cout << "Tarefa adicionada com sucesso!" << endl;

        cout << "Pressione qualquer tecla para continuar...";

        cin.get();

        system("clear||cls");
    }

    static void taskDetails(Board *board)
    {
        // int option;
        // int minOption = 1;
        // int maxOption = 4;

        // board->print();

        // cout << "+-------------------------------------+\n";
        // cout << "|           MENU DE TAREFAS           |\n";
        // cout << "+-------------------------------------+\n";
        // cout << "|  1 - Exibir detalhes de uma tarefa  |\n";
        // cout << "|  2 - Editar tarefa                  |\n";
        // cout << "|  3 - Mover tarefa                   |\n";
        // cout << "|  4 - Remover tarefa                 |\n";
        // cout << "+-------------------------------------+\n\n";

        // cout << "Digite o numero da operacao desejada: ";

        // cin >> option;
        // cin.ignore();

        // while (option < minOption || option > maxOption)
        // {
        //     system("clear||cls");
        //     cout << "O numero digitado nao corresponde a nenhuma operacao. Tente novamente: ";
        //     cin >> option;
        //     cin.ignore();
        // }

        // string id;
        // Task *selectedTask;

        // cout << "Digite o ID da tarefa: ";
        // getline(cin, id);

        // selectedTask = board->searchTaskById(id);

        // while (selectedTask == nullptr)
        // {
        //     cout << "Tarefa nao encontrada. Tente novamente: ";
        //     cin >> id;
        //     cin.ignore();
        //     cout << endl;

        //     selectedTask = board->searchTaskById(id);
        // }

        // string columnId;

        // switch (option)
        // {
        // case 1:
        //     selectedTask->print();
        //     break;
        // case 2:
        //     // selectedTask->edit();
        //     break;
        // case 3:

        //     cout << "Digite o ID da coluna que deseja mover a tarefa: ";
        //     getline(cin, id);

        //     Column *selectedColumn = board->getColumnById(id);

        //     while (selectedColumn == nullptr)
        //     {
        //         cout << "Coluna nao encontrada. Tente novamente: ";
        //         cin >> id;
        //         cin.ignore();
        //         cout << endl;

        //         selectedColumn = board->getColumnById(id);
        //     }

        //     board->moveTask(selectedTask, *selectedColumn);

        //     break;
        // case 4:
        //     Column *selectedColumn = selectedTask->getColumn();
        //     selectedColumn->removeTask(selectedTask);
        //     cout << "Tarefa removida com sucesso!" << endl;
        //     cout << "Pressione qualquer tecla para continuar...";
        //     cin.get();

        //     delete selectedTask;

        //     system("clear||cls");

        //     break;
        // default:
        //     break;
        // }
    }

    static void addNewColumns(Board *board)
    {
        char addNewColumn = 'S';

        do
        {
            string name, description;
            char ordered;
            int order;
            Column *newColumn;

            cout << "Nome da coluna: ";
            getline(cin, name);

            cout << "Descricao da coluna: ";
            getline(cin, description);

            cout << "Deseja escolher uma ordem para a coluna? (S/N) ";

            cin >> ordered;

            while (toupper(ordered) != 'S' && toupper(ordered) != 'N')
            {
                cout << "Opcao invalida. Tente novamente: ";
                cin >> ordered;
            }

            if (toupper(ordered) == 'S')
            {
                cout << "Ordem da coluna (1 a " << board->getColumnCount() + 1 << "): ";

                cin >> order;

                while (order < 1 || order > board->getColumnCount() + 1)
                {
                    cout << "Ordem invalida. Tente novamente: ";
                    cin >> order;
                }

                cin.ignore();

                newColumn = new Column(name, description, order);
            }
            else
            {
                newColumn = new Column(name, description);
            }

            board->addColumn(newColumn);

            cout << "Deseja adicionar outra coluna? (S/N) ";
            cin >> addNewColumn;

            while (toupper(addNewColumn) != 'S' && toupper(addNewColumn) != 'N')
            {
                cout << "Opcao invalida. Tente novamente: ";
                cin >> addNewColumn;
            }

            cin.ignore();

            system("clear||cls");

        } while (toupper(addNewColumn) == 'S');
    }

    static void removeColumn(Board *board)
    {
        system("clear||cls");

        if (board->getColumnCount() == 0)
        {
            cout << "Nao ha colunas para remover." << endl
                 << endl;
            return;
        }

        board->print();

        string id;

        cout << "Digite o ID da coluna que deseja remover: ";
        getline(cin, id);

        Column *selectedColumn = board->getColumnById(id);

        while (selectedColumn == nullptr)
        {
            cout << "Coluna nao encontrada. Tente novamente: ";
            cin >> id;
            cin.ignore();
            cout << endl;

            selectedColumn = board->getColumnById(id);
        }

        if (selectedColumn->getTaskCount() > 0)
        {
            char confirm;

            cout << "A coluna possui tarefas. Deseja realmente remove-la? (S/N) ";
            cin >> confirm;

            while (toupper(confirm) != 'S' && toupper(confirm) != 'N')
            {
                cout << "Opcao invalida. Tente novamente: ";
                cin >> confirm;
            }

            if (toupper(confirm) == 'N')
            {
                return;
            }
        }

        board->removeColumn(selectedColumn);

        cout << "Coluna removida com sucesso!" << endl;

        cout << "Pressione qualquer tecla para continuar...";
        cin.get();

        system("clear||cls");
    }

    static int show()
    {
        int option;
        int minOption = 1;
        int maxOption = 7;

        cout << "+---------------------------------+\n";
        cout << "|        MENU DE OPERACOES        |\n";
        cout << "+---------------------------------+\n";
        cout << "|  1 - Exibir o quadro            |\n";
        cout << "|  2 - Adicionar nova coluna      |\n";
        cout << "|  3 - Remover coluna             |\n";
        cout << "|  4 - Adicionar nova tarefa      |\n";
        cout << "|  5 - Detalhar tarefa            |\n";
        cout << "|  6 - Opcoes de ordenacao        |\n";
        cout << "|  7 - Salvar o quadro            |\n";
        cout << "|  8 - Sair                       |\n";
        cout << "+---------------------------------+\n\n";

        cout << "Digite o numero da operacao desejada: ";

        cin >> option;
        cin.ignore();

        if (option < minOption || option > maxOption)
        {
            system("clear||cls");
            cout << "O numero digitado nao corresponde a nenhuma operacao. Tente novamente.\n";
            option = show();
        }

        return option;
    }
};

#endif