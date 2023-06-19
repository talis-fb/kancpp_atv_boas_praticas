# Kan++

## Sobre

- Um sistema de gerenciamento de tarefas utilizando o Método Kanban. É possível criar um quadro de tarefas, adicionar colunas e tarefas, mover as tarefas entre as colunas e deletar as tarefas e colunas. O sistema também possui um sistema de login e cadastro de usuários. Os dados são salvos em arquivos de texto e são carregados ao iniciar o programa.

- O programa é dividido em 3 classes principais: `Board`, `Column` e `Task`. A classe `Board` é responsável por gerenciar as colunas e tarefas. A classe `Column` é responsável por gerenciar as tarefas de uma coluna. A classe `Task` é responsável por gerenciar os dados de uma tarefa.

- Há também as classes `Admin` e `Member`, ambas herdam da classe `User`. A classe `Member` é responsável por mover as tarefas entre as colunas e atualizar suas labels. A classe `Admin` também possui essas funções, mas também é responsável por criar e deletar colunas e tarefas. Além disso, a classe `Admin` pode promover um `Member` para `Admin`.
