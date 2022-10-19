#ifndef RB_H
#define RB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct RecordRBT RecordRBT;
typedef struct TreeRBT TreeRBT;

struct RecordRBT
{
	float key;
	int value;
};

struct TreeRBT
{
	RecordRBT reg;
	TreeRBT *esq, *dir;
	TreeRBT *pai; // específico para rubro negra
	bool cor;	  // específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};

TreeRBT *CreateTreeRBT();

void rotacaoSimplesEsquerdaRBT(TreeRBT **raiz, TreeRBT *child);
void rotacaoSimplesDireitaRBT(TreeRBT **raiz, TreeRBT *child);

void insertFixUpRBT(TreeRBT **raiz, TreeRBT *child);
void insertTreeRBT(TreeRBT **t, TreeRBT **pai, TreeRBT **raiz, RecordRBT r);
void pesquisaRBT(TreeRBT **t, TreeRBT **aux, RecordRBT r);

void preordemRBT(TreeRBT *t);
void centralRBT(TreeRBT *t);
void posordemRBT(TreeRBT *t);

#endif
