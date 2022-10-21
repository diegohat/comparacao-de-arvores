# Comparação de Estruturas - Árvores
![C++](https://img.shields.io/badge/Linguagem-C++-green.svg)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![VSCode](https://img.shields.io/badge/IDE-VSCode-informational)

## Índice
__0.__ [Proposta](#proposta)

__1.__ [Objetivos](#objetivos)

__2.__ [Fundamento Teórico](#fundamento-teórico)

__3.__ [Metodologia](#metodologia)

__4.__ [Resultados e Análises](#resultados-e-análises)

__5.__ [Conclusão](#discussão-dos-resultados)

__6.__ [Referências](#referências)

__7.__ [Compilação e Execução](#compilação-e-execução)

***
## Proposta
Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2) Qual o tempo necessário para montar a estrutura em memória. 

3) Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4) Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?

Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise. 

***
## Objetivos
Aplicar os conhecimentos adquiridos na disciplina de Algoritmos e Estrutura de Dados II para realizar uma comparação de tempo de execução da inserção, pesquisa e remoção de diferentes estruturas e através dos resultados avaliar suas aplicações.

***
## Fundamento Teórico
### Estrutura de Dados


Estrutura de dados é o ramo da computação que estuda os diversos mecanismos de organização de dados para atender aos diferentes requisitos de processamento. Utiliza-se de conjuntos dinâmicos que podem crescer, encolher ou sofrer mudanças ao longo do tempo. Através de algumas técnicas básicas podemos representar esses conjuntos e manipulá-los em um computador. Os algoritmos utilizam desses conjuntos e exigem vários tipos diferentes de operações. A melhor maneira de implementar um conjunto dinâmico depende das operações que devem ser suportadas.
    
Para saber mais sobre Estruturas de dados, acesse:   

<https://www.geeksforgeeks.org/data-structures/>

<https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/>

Visualizador de estruturas online:

<https://www.cs.usfca.edu/~galles/visualization/Algorithms.html>

### Árvores

Uma estrutura de dados Árvore é um conjunto finito de elementos em que cada elemento é chamado nó e o primeiro elemento é chamado de raiz da árvore.

Esse tipo de estrutura organiza seus elementos de forma hierárquica, onde existe um elemento que fica no topo da árvore, chamado de raiz e existem os elementos subordinados a ele, que são chamados de nós filhos. Cada nó filho pode conter zero, um ou mais de um nó filho. Os nós filhos que não contém outros nós filhos são chamados de nós folhas.

Para mais detalhes: 

<https://www.freecodecamp.org/news/the-codeless-guide-to-tree-data-structures/>

Tipos de Árvore:

- Árvore Binária

    <https://www.freecodecamp.org/news/binary-search-tree-what-is-it/>

- Árvore AVL

    <https://www.freecodecamp.org/news/avl-tree-insertion-rotation-and-balance-factor/>

- Árvore Rubro-Negra

    <https://www.freecodecamp.org/news/red-black-trees/>


Mais sobre árvores: 

<https://sites.google.com/site/proffdesiqueiraed/aulas/aula-10---arvores>

***
## Metodologia

Foi realizado um estudo prévio das estruturas para compreensão de suas implementações. Em seguida, foram reutilizados códigos de repositórios públicos para o desenvolvimento de uma aplicação que, através da biblioteca [chrono::](https://en.cppreference.com/w/cpp/header/chrono) contabiliza o tempo de execução de cada uma de suas requisições. Após a criação das estruturas básicas, foram adicionados dois arquivos com números gerados aleatóriamente. O arquivo data.txt possui os valores utilizados para gerar as estruturas com 500, 5.000, 50.000, 500.000 dados. Em seguida, foi criado o arquivo input.txt com as entradas para busca. Ao final da coleta, é imprimido no console os tempos de execução. Os tempos foram coletados três vezes e inseridos em uma planilha para o cálculo da média, sua normalização e a criação de um gráfico para representação visual.

### Estruturas

- [Árvore Binária de Busca](https://github.com/diegohat/Comparacao-de-Arvores/blob/main/src/bst/tree.c)
- [Árvore AVL](https://github.com/diegohat/Comparacao-de-Arvores/blob/main/src/avl/avl.c)
- [Árvore Rubro-Negra](https://github.com/diegohat/Comparacao-de-Arvores/blob/main/src/rbt/rb.c)
- [Vetores](https://github.com/diegohat/Comparacao-de-Arvores/blob/main/src/chronos.cpp#239)
- [Map](https://github.com/diegohat/Comparacao-de-Arvores/blob/main/src/chronos.cpp#315)
- [Unordered Map](https://github.com/diegohat/Comparacao-de-Arvores/blob/main/src/chronos.cpp#379)

### Requisições

- Inserção
- Busca
- Remoção

***
## Resultados e Análises

A diferença no tempo de execução das estruturas, principalmente entre árvore e vetor, é bem vísivel através dos dados coletados. Os vetores possuem valores de inserção muito rápidos devido a não necessidade de percorrer a estrutura para inserir valores. Porém para utilizarmos uma busca no mesmo é necessário aplicar um método de ordenação para que seja possível realizarmos uma pesquisa binária. A remoção, devido a sua necessidade de utilizar o método de pesquisa cai no mesmo critério.

Para entradas pequenas (500) o vetor tem comportamento próximo das outras estruturas. Já após 50.000 entradas, ele se demonstra uma estrutura custosa.

Entre as árvores foi possível perceber tempos bem próximos destacando-se a rubro-negra que possui tempos menores.

Os ganhos das estruturas map e unordered map são baixos comparados com as outras árvores. Unordered Map possui um tempo melhor em comparação a todas as estruturas para altas quantidades de dados.


***
### 500 Entradas

![Tabela 500](/img/500.png)

![Gráfico Insert 500](/img/ins500.png)

![Gráfico Search 500](/img/pesq500.png)

![Gráfico Remove 500](/img/rem500.png)

***

### 5.000 Entradas

![Tabela 5000](/img/5000.png)

![Gráfico Insert 5000](/img/inse5000.png)

![Gráfico Search 5000](/img/pesq5000.png)

![Gráfico Remove 5000](/img/rem5000.png)

***

### 50.000 Entradas

![Tabela 50000](/img/50000.png)

![Gráfico Insert 50000](/img/ins50000.png)

![Gráfico Search 50000](/img/pesq50000.png)

![Gráfico Remove 50000](/img/rem50000.png)

***

### 500.000 Entradas

![Tabela 500000](/img/500000.png)

![Gráfico Insert 500000](/img/inse500000.png)

![Gráfico Search 500000](/img/pesq500000.png)

![Gráfico Remove 500000](/img/rem500000.png)

***
## Conclusão

Foi possível concluir que as árvores são estruturas dinâmicas muito bem otimizadas que podem ser utilizadas principalmente em programas com muitas entradas e saídas de valores. Os vetores são usados em estruturas que possuem pouca fluidez (entrada / saída) pois os métodos de ordenação possuem um custo muito alto comparado com as árvores.

***
## Referências

CORMEN, Thomas H. et al. Introduction to algorithms. MIT press, 2022.

FREE CODE CAMP. Free Code Camp: Learn to code — for free, c2022. Disponível em: <https://www.freecodecamp.org>. Acesso em: 14 de out. de 2022.

PROGRAMAÇÃO DESCOMPLICADA. Programação Descomplicada: Linguagem C Descomplicada, c2022. Disponível em: <https://programacaodescomplicada.wordpress.com/>. Acesso em: 08 de out. de 2022.

CPPREFERENCE. CPP Reference, c2022. Disponível em: <https://en.cppreference.com/w/>. Acesso em: 17 de out. de 2020.

***
## Compilação e Execução

| Comando    | Função                                                                                  |
| ---------- | --------------------------------------------------------------------------------------- |
| make clean | Apaga a última compilação realizada contida na pasta build                              |
| make       | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build |
| make run   | Executa o programa da pasta build após a realização da compilação                       |