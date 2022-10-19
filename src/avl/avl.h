#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct RecordAVL RecordAVL;
typedef struct TreeAVL TreeAVL;

struct RecordAVL
{
	float key;
	int value;
};

struct TreeAVL
{
	RecordAVL reg;
	TreeAVL *left, *right;
	int weight;
};

TreeAVL *CreateTreeAVL();
void insertTreeAVL(TreeAVL **t, RecordAVL r);
void pesquisaAVL(TreeAVL **t, TreeAVL **aux, RecordAVL r);
int isInTreeAVL(TreeAVL *t, RecordAVL r);

// muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTreeAVL(TreeAVL **t, TreeAVL **f, RecordAVL r);
void antecessorAVL(TreeAVL **t, TreeAVL *aux);
void rebalanceTreeAVL(TreeAVL **t);

void preordemAVL(TreeAVL *t);
void centralAVL(TreeAVL *t);
void posordemAVL(TreeAVL *t);

int getWeightAVL(TreeAVL **t);
int getMaxWeightAVL(int left, int right);

void rotacaoSimplesDireitaAVL(TreeAVL **t);
void rotacaoSimplesEsquerdaAVL(TreeAVL **t);
void rotacaoDuplaDireitaAVL(TreeAVL **t);
void rotacaoDuplaEsquerdaAVL(TreeAVL **t);

#endif
