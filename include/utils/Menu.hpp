#ifndef MENU_CLASS
#define MENU_CLASS

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "../Board.h"
#include "../Column.h"
#include "../FeatureTask.h"
#include "../BugTask.h"
#include "../TestTask.h"

using namespace std;

class Menu
{
public:
    static void printTaskTypeMenu()
    {
        cout << "\n+----------------------------------------+\n";
        cout << "|        Escolha o tipo da tarefa        |\n";
        cout << "+----------------------------------------+\n";
        cout << "|  1 - Bug                               |\n";
        cout << "|  2 - Feature                           |\n";
        cout << "|  3 - Teste                             |\n";
        cout << "+----------------------------------------+\n";
    }

    static void printBugTaskPiorityMenu()
    {
        cout << "\n+--------------------------------------------+\n";
        cout << "|        Qual a prioridade da tarefa?        |\n";
        cout << "+--------------------------------------------+\n";
        cout << "|  1 - Muito baixa                           |\n";
        cout << "|  2 - Baixa                                 |\n";
        cout << "|  3 - Media                                 |\n";
        cout << "|  4 - Alta                                  |\n";
        cout << "|  5 - Muito alta                            |\n";
        cout << "+--------------------------------------------+\n";
    }

    static void printTaskMenu()
    {
        cout << "\n+-------------------------------------+\n";
        cout << "|           MENU DE TAREFAS           |\n";
        cout << "+-------------------------------------+\n";
        cout << "|  1 - Exibir detalhes de uma tarefa  |\n";
        cout << "|  2 - Editar tarefa                  |\n";
        cout << "|  3 - Mover tarefa                   |\n";
        cout << "|  4 - Remover tarefa                 |\n";
        cout << "+-------------------------------------+\n\n";
    }

    static void printTaskActions()
    {
        cout << "\n+-------------------------------------+\n";
        cout << "|            EDITAR TAREFA            |\n";
        cout << "+-------------------------------------+\n";
        cout << "|  1 - Editar titulo                  |\n";
        cout << "|  2 - Editar descricao               |\n";
        cout << "|  3 - Editar ordem                   |\n";
        cout << "|  4 - Editar prazo                   |\n";
        cout << "|  5 - Remover tarefa                 |\n";
        cout << "+-------------------------------------+\n\n";
    }

    static void printMenuActions()
    {
        cout << "\n+---------------------------------+\n";
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
    }

    static void printSortActions()
    {
        cout << "+-----------------------------------+\n";
        cout << "|       OPCOES DE ORDENACAO         |\n";
        cout << "+-----------------------------------+\n";
        cout << "|  1 - Ordenar tarefa por titulo    |\n";
        cout << "|  2 - Ordenar tarefa por descricao |\n";
        cout << "|  3 - Ordenar tarefa por Id        |\n";
        cout << "+-----------------------------------+\n\n";
    }

    static void addBugTask(Board *board, Column *selectedColumn)
    {
        string title, description;
        int priority;

        cout << "Nome da tarefa: ";
        getline(cin, title);

        cout << "Descricao da tarefa: ";
        getline(cin, description);

        printBugTaskPiorityMenu();

        cout
            << "Digite a opcao escolhida: ";
        cin >> priority;
        cin.ignore();

        while (priority < 1 || priority > 5)
        {
            cout << "Opcao invalida. Tente novamente: ";
            cin >> priority;
            cin.ignore();
        }

        Task *bugTask = new BugTask(title, description, priority);
        selectedColumn->addTask(bugTask);
    }

    static void addFeatureTask(Board *board, Column *selectedColumn)
    {
        string title, description, project;
        cout << "Nome da tarefa: ";
        getline(cin, title);

        cout << "Descricao da tarefa: ";
        getline(cin, description);

        cout << "Qual o projeto dessa feature?: ";
        getline(cin, project);

        Task *featureTask = new FeatureTask(title, description, project);

        selectedColumn->addTask(featureTask);
    }

    static void addTestTask(Board *board, Column *selectedColumn)
    {
        string title, description;

        cout << "Nome da tarefa: ";
        getline(cin, title);

        cout << "Descricao da tarefa: ";
        getline(cin, description);

        char hasFeature;

        cout << "Esse teste esta associado a uma feature? (S/N) ";
        cin >> hasFeature;
        cin.ignore();

        Task *testTask;

        if (toupper(hasFeature) == 'S')
        {
            string feature;
            bool isValidFeature = false;

            do
            {
                cout << "Id da feature: ";
                cin >> feature;
                cin.ignore();

                Task *featureTask = board->searchTaskById(feature);

                if (featureTask != nullptr && featureTask->getType() == "FEATURE")
                {
                    testTask = new TestTask(title, description, static_cast<FeatureTask *>(featureTask));
                    isValidFeature = true;
                }
                else
                {
                    cout << "Tarefa invalida. Gostaria de criar sem uma feature associada? (S/N) ";
                    cin >> hasFeature;
                    cin.ignore();

                    if (toupper(hasFeature) == 'N')
                    {
                        isValidFeature = true;
                        testTask = new TestTask(title, description);
                    }
                }
            } while (!isValidFeature);
        }
        else
        {
            testTask = new TestTask(title, description);
        }
        selectedColumn->addTask(testTask);
    }

    static void editTask(Board *board, Column *selectedColumn, Task *selectedTask)
    {
        string title, description, dateStr;
        int option, order;
        tm deadline;
        bool isValidDate = false;

        printTaskActions();
        cout << "Digite o numero da operacao desejada: ";

        cin >> option;
        cin.ignore();

        while (option < 1 || option > 5)
        {
            system("clear||cls");
            cout << "O numero digitado nao corresponde a nenhuma operacao. Tente novamente: ";
            cin >> option;
            cin.ignore();
        }

        switch (option)
        {
        case 1:
            cout << "Digite o novo titulo: ";
            getline(cin, title);

            selectedTask->setTitle(title);

            break;
        case 2:
            cout << "Digite a nova descricao: ";
            getline(cin, description);

            selectedTask->setDescription(description);

            break;
        case 3:
            cout << "Digite a nova ordem: ";
            cin >> order;
            cin.ignore();

            selectedTask->setOrder(order);

            break;

        case 4:

            do
            {
                std::cout << "Digite o prazo da atividade (formato dd/mm/yyyy): ";
                std::cin >> dateStr;

                std::istringstream iss(dateStr);
                char delimiter;
                iss >> deadline.tm_mday >> delimiter >> deadline.tm_mon >> delimiter >> deadline.tm_year;

                if (!iss.fail() && delimiter == '/' && deadline.tm_mday >= 1 && deadline.tm_mday <= 31 &&
                    deadline.tm_mon >= 1 && deadline.tm_mon <= 12 && deadline.tm_year >= 1900)
                {
                    deadline.tm_mon -= 1;
                    deadline.tm_year -= 1900;
                    isValidDate = true;
                }
                else
                {
                    std::cout << "Data inválida. Por favor, digite novamente." << std::endl;
                }
            } while (!isValidDate);

            selectedTask->setDeadline(deadline);

            break;
        case 5:
            selectedColumn = board->getColumnByTask(selectedTask);
            selectedColumn->removeTask(selectedTask);

            break;
        default:
            break;
        }
    }

    static void deleteTask(Board *board, Column *selectedColumn, Task *selectedTask)
    {
        string id;
        cout << "Digite o ID da coluna que deseja mover a tarefa: ";
        getline(cin, id);

        selectedColumn = board->getColumnById(id);

        while (selectedColumn == nullptr)
        {
            cout << "Coluna nao encontrada. Tente novamente: ";
            cin >> id;
            cin.ignore();
            cout << endl;

            selectedColumn = board->getColumnById(id);
        }

        board->moveTask(selectedTask, *selectedColumn);
    }

    static void addNewTask(Board *board)
    {
        system("clear||cls");
        board->print();

        char addNewTask = 'S';
        do
        {
            int optionTask;

            printTaskTypeMenu();

            cout << "Digite a opcao escolhida: ";
            cin >> optionTask;
            cin.ignore();

            string id;
            Column *selectedColumn = nullptr;

            do
            {
                cout << "Digite o ID da coluna dessa tarefa: ";
                getline(cin, id);

                selectedColumn = board->getColumnById(id);

                if (selectedColumn == nullptr)
                    cout << "Coluna nao encontrada. Tente novamente." << endl;

            } while (selectedColumn == nullptr);

            switch (optionTask)
            {
            case 1:
            {
                addBugTask(board, selectedColumn);
                break;
            }
            case 2:
            {
                addFeatureTask(board, selectedColumn);
                break;
            }
            case 3:
            {
                addTestTask(board, selectedColumn);
                break;
            }
            default:
                cout << "Opcao nao encontrada" << endl;
                break;
            }

            cout << "Tarefa adicionada com sucesso!" << endl;

            cout << "Deseja adicionar outra tarefa? (S/N) ";
            cin >> addNewTask;

            cin.ignore();

            system("clear||cls");

        } while (toupper(addNewTask) == 'S');
    }

    static void taskDetails(Board *board)
    {
        system("clear||cls");
        board->print();

        int option;
        int minOption = 1;
        int maxOption = 4;

        printTaskMenu();

        cout << "Digite o numero da operacao desejada: ";

        cin >> option;
        cin.ignore();

        while (option < minOption || option > maxOption)
        {
            system("clear||cls");
            printTaskMenu();

            cout << "O numero digitado nao corresponde a nenhuma operacao. Tente novamente: ";
            cin >> option;
            cin.ignore();
        }

        string id;
        Task *selectedTask = nullptr;

        cout << "Digite o ID da tarefa: ";
        getline(cin, id);

        selectedTask = board->searchTaskById(id);

        while (selectedTask == nullptr)
        {
            cout << "Tarefa nao encontrada. Tente novamente: ";
            cin >> id;
            cin.ignore();
            cout << endl;

            selectedTask = board->searchTaskById(id);
        }

        Column *selectedColumn = nullptr;

        switch (option)
        {
        case 1:
            selectedTask->print();
            break;
        case 2:
            editTask(board, selectedColumn, selectedTask);
            break;
        case 3:
            deleteTask(board, selectedColumn, selectedTask);
            break;
        case 4:
            selectedColumn = board->getColumnByTask(selectedTask);
            selectedColumn->removeTask(selectedTask);
            break;
        default:
            break;
        }

        cout << "Pressione qualquer tecla para continuar...";
        cin.get();

        system("clear||cls");
    }

    static void addNewColumns(Board *board)
    {
        system("clear||cls");
        board->print();

        char addNewColumn = 'S';

        do
        {
            string name, description;
            char ordered;
            int order;
            Column *newColumn = nullptr;

            cout << "Nome da coluna: ";
            getline(cin, name);

            cout << "Descricao da coluna: ";
            getline(cin, description);

            cout << "Deseja escolher uma ordem para a coluna? (S/N) ";

            cin >> ordered;

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

            cin.ignore();

            system("clear||cls");

        } while (toupper(addNewColumn) == 'S');

        system("clear||cls");
    }

    static void removeColumn(Board *board)
    {
        system("clear||cls");
        board->print();

        if (board->getColumnCount() == 0)
        {
            cout << "Nao ha colunas para remover." << endl
                 << endl;

            cout << "Pressione qualquer tecla para continuar...";
            cin.get();

            system("clear||cls");
            return;
        }

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

    static void saveBoard(Board *board)
    {
        try
        {
            std::fstream fileManager("./data/board.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

            board->serialize(fileManager);

            fileManager.close();

            cout << "Quadro salvo com sucesso!" << endl;
        }
        catch (const std::exception &e)
        {
            cout << "Erro ao salvar o quadro." << endl;
        }

        cout << "Pressione qualquer tecla para continuar...";
        cin.get();

        system("clear||cls");
    }

    static int show(int maxOption)
    {
        int option;
        int minOption = 1;

        printMenuActions();

        cout << "Digite o numero da operacao desejada: ";

        cin >> option;
        cin.ignore();

        if (option < minOption || option > maxOption)
        {
            system("clear||cls");
            cout << "O numero digitado nao corresponde a nenhuma operacao. Tente novamente.\n";
            option = show(maxOption);
        }

        return option;
    }

    static void sortOptions(Board *board)
    {
        system("clear||cls");
        board->print();

        int option;

        printSortActions();

        cout << "Escolha o criterio de ordenacao: ";
        cin >> option;
        cin.ignore();

        while (option < 1 && option > 3)
        {
            cout << "O numero digitado nao corresponde a nenhuma opcao. Tente novamente.\n";
            cout << "Escolha um criterio de ordenacao: ";
            cin >> option;
            cin.ignore();
        }

        switch (option)
        {
        case 1:
            board->sortTask("title");
            break;
        case 2:
            board->sortTask("description");
            break;
        case 3:
            board->sortTask("id");
            break;
        default:
            break;
        }
    }
};

#endif