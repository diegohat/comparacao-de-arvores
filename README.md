# Comparação de Estruturas - Árvores

![C++](https://img.shields.io/badge/Linguagem-C++-green.svg)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![VSCode](https://img.shields.io/badge/IDE-VSCode-informational)

## Índice

__0.__ [Proposta] (#proposta)

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
    Este trabalho consiste no desenvolvimento de uma aplicação em terminal utilizando a linguagem C++. Através de estrutura de dados foi proposto a criação de um método de compressão de dados fazendo uso da codificação de Huffman. A codificação de Huffman é um método de compressão que usa as probabilidades de ocorrência dos símbolos no conjunto de dados a ser comprimido para determinar códigos de tamanho variável para cada símbolo.    
</p>

## Fundamento Teórico
<p align="justify">
    Para o uso da codificação, foram utilizadas estruturas em árvore, filas, listas e tabelas hash. Uma fila de prioridade foi criada para lidar com a reordenação da floresta de árvores que estava contida em uma lista de árvores. Abaixo segue as etapas do projeto e seus respectivos códigos.
</p>

### Metodologia

__1.__ [Contabilizar a recorrência de cada palavra no arquivo;](https://github.com/diegohat/huffman/blob/main/src/tree.cpp#L41)

__2.__ [Normalizar a contabilização;](https://github.com/diegohat/huffman/blob/main/src/tree.cpp#L49)

__3.__ [Montar a árvore com as regras apresentadas por Huffman;](https://github.com/diegohat/huffman/blob/main/src/tree.cpp#L95)

__4.__ [Trocar as palavras pela codificação binária;](https://github.com/diegohat/huffman/blob/main/src/tree.cpp#L62)

__5.__ [Salvar o arquivo em formato binário;](https://github.com/diegohat/huffman/blob/main/src/tree.cpp#L138)

__6.__ [Observar e discutir sobre o ganho ou perda de espaço.](#discussão-dos-resultados)

## Resultados e Análises

![Scrennshot](img/menuPrincipal.jpg)

- Ao executar o programa surgirão as seguintes opções:
    - `1` Imprime a lista de palavras do texto e suas frequências normalizadas.
    - `2` Imprime a árvore de huffman (em lista) com seus valores associados em binário.
    - `3` Cria o arquivo binário test.dat no diretório /src .
    - `9` Finaliza o programa.

- Resultados esperados pela execução das opções:

    - ### [1] Print word's frequencies.
        
        (Palavra, Frequencia Normalizada)

        ![Scrennshot](img/1.jpg)

    - ### [2] Print Huffman tree.

        (Palavra, Valor Binário)

        ![Scrennshot](img/2.jpg)

    - ### [3] Create binary file.

        ![Scrennshot](img/3.jpg)

    - ### [9] Exit.

        ![Scrennshot](img/4.jpg)


## Conclusão

<p align="justify">
    Através da análise do resultado da compressão foi possível identificar um aumento no tamanho do arquivo. Esse comportamento, contrário ao esperado, se deve devido ao código de Huffman verdadeiro (diferente do proposto) utilizar de caracteres como chaves para a construção da árvore e de seus respectivos valores binários. A quantidade de caracteres é muito inferior a quantidade de palavras possíveis dentro de um texto, fazendo com que os valores binários cresçam de tal maneira (devido a quantidade de palavras e o código não ter prefixos repetidos) que o tamanho do arquivo cresça.
</p>

![Scrennshot](img/huffman.jpg)

## Referências

abuewkodaw

## Compilação e Execução

| Comando    | Função                                                                                  |
| ---------- | --------------------------------------------------------------------------------------- |
| make clean | Apaga a última compilação realizada contida na pasta build                              |
| make       | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build |
| make run   | Executa o programa da pasta build após a realização da compilação                       |