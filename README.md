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
## Proposta
Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2) Qual o tempo necessário para montar a estrutura em memória. 

3) Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4) Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?

Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise. 
## Objetivos
<p align="justify">
    Aplicar os conhecimentos adquiridos na disciplina de Algoritmos e Estrutura de Dados II para realizar uma comparação de tempo de execução da inserção, pesquisa e remoção de diferentes estruturas e através dos resultados avaliar suas aplicações.
</p>

## Fundamento Teórico
### Estrutura de Dados

<p align="justify">

Estrutura de dados é o ramo da computação que estuda os diversos mecanismos de organização de dados para atender aos diferentes requisitos de processamento. Utiliza-se de conjuntos dinâmicos que podem crescer, encolher ou sofrer mudanças ao longo do tempo. Através de algumas técnicas básicas podemos representar esses conjuntos e manipulá-los em um computador. Os algoritmos utilizam desses conjuntos e exigem vários tipos diferentes de operações. A melhor maneira de implementar um conjunto dinâmico depende das operações que devem ser suportadas.
    
Para saber mais sobre Estruturas de dados, acesse:   

<https://www.geeksforgeeks.org/data-structures/>

<https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/>
</p>

Visualizador de estruturas online:

<https://www.cs.usfca.edu/~galles/visualization/Algorithms.html>

### Árvores

<p align="justify">

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

</p>

## Metodologia
<p align="justify">



</p>

## Resultados e Análises

![Tabela 500](/img/500.png)

![Gráfico Insert 500](/img/ins500.png)

![Gráfico Search 500](/img/pesq500.png)

![Gráfico Remove 500](/img/rem500.png)

![Tabela 5000](/img/5000.png)

![Gráfico Insert 5000](/img/inse5000.png)

![Gráfico Search 5000](/img/pesq5000.png)

![Gráfico Remove 5000](/img/rem5000.png)

![Tabela 50000](/img/50000.png)

![Gráfico Insert 50000](/img/ins50000.png)

![Gráfico Search 50000](/img/pesq50000.png)

![Gráfico Remove 50000](/img/rem50000.png)

![Tabela 500000](/img/500000.png)

![Gráfico Insert 500000](/img/inse500000.png)

![Gráfico Search 500000](/img/pesq500000.png)

![Gráfico Remove 500000](/img/rem500000.png)


## Conclusão

<p align="justify">

</p>

## Referências
<p align="justify">

</p>

## Compilação e Execução

| Comando    | Função                                                                                  |
| ---------- | --------------------------------------------------------------------------------------- |
| make clean | Apaga a última compilação realizada contida na pasta build                              |
| make       | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build |
| make run   | Executa o programa da pasta build após a realização da compilação                       |