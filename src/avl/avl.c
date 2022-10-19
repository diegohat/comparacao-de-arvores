#include "avl.h"

TreeAVL *CreateTreeAVL()
{
	return NULL;
}

void insertTreeAVL(TreeAVL **t, RecordAVL r)
{

	if (*t == NULL)
	{
		*t = (TreeAVL *)malloc(sizeof(TreeAVL));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->weight = 0;
		(*t)->reg = r;
	}
	else
	{

		if (r.key < (*t)->reg.key)
		{
			insertTreeAVL(&(*t)->left, r);
			if ((getWeightAVL(&(*t)->left) - getWeightAVL(&(*t)->right)) == 2)
			{
				if (r.key < (*t)->left->reg.key)
					rotacaoSimplesDireitaAVL(t);
				else
					rotacaoDuplaDireitaAVL(t);
			}
		}

		if (r.key > (*t)->reg.key)
		{
			insertTreeAVL(&(*t)->right, r);
			if ((getWeightAVL(&(*t)->right) - getWeightAVL(&(*t)->left)) == 2)
			{
				if (r.key > (*t)->right->reg.key)
					rotacaoSimplesEsquerdaAVL(t);
				else
					rotacaoDuplaEsquerdaAVL(t);
			}
		}
	}

	(*t)->weight = getMaxWeightAVL(getWeightAVL(&(*t)->left), getWeightAVL(&(*t)->right)) + 1;
}

void pesquisaAVL(TreeAVL **t, TreeAVL **aux, RecordAVL r)
{

	if (*t == NULL)
	{
		//printf("[ERROR]: Node not found!");
		return;
	}

	if ((*t)->reg.key > r.key)
	{
		pesquisaAVL(&(*t)->left, aux, r);
		return;
	}
	if ((*t)->reg.key < r.key)
	{
		pesquisaAVL(&(*t)->right, aux, r);
		return;
	}

	*aux = *t;
}

int isInTreeAVL(TreeAVL *t, RecordAVL r)
{

	if (t == NULL)
	{
		return 0;
	}

	return t->reg.key == r.key || isInTreeAVL(t->left, r) || isInTreeAVL(t->right, r);
}

void antecessorAVL(TreeAVL **t, TreeAVL *aux)
{

	if ((*t)->right != NULL)
	{
		antecessorAVL(&(*t)->right, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->left;
	free(aux);
}

void rebalanceTreeAVL(TreeAVL **t)
{
	int balance;
	int left = 0;
	int right = 0;

	balance = getWeightAVL(&(*t)->left) - getWeightAVL(&(*t)->right);
	if ((*t)->left)
		left = getWeightAVL(&(*t)->left->left) - getWeightAVL(&(*t)->left->right);
	if ((*t)->right)
		right = getWeightAVL(&(*t)->right->left) - getWeightAVL(&(*t)->right->right);

	if (balance == 2 && left >= 0)
		rotacaoSimplesDireitaAVL(t);
	if (balance == 2 && left < 0)
		rotacaoDuplaDireitaAVL(t);

	if (balance == -2 && right <= 0)
		rotacaoSimplesEsquerdaAVL(t);
	if (balance == -2 && right > 0)
		rotacaoDuplaEsquerdaAVL(t);
}

void removeTreeAVL(TreeAVL **t, TreeAVL **f, RecordAVL r)
{
	TreeAVL *aux;

	if (*t == NULL)
	{
		//printf("[ERROR]: RecordAVL not found!!!\n");
		return;
	}

	if (r.key < (*t)->reg.key)
	{
		removeTreeAVL(&(*t)->left, t, r);
		return;
	}
	if (r.key > (*t)->reg.key)
	{
		removeTreeAVL(&(*t)->right, t, r);
		return;
	}

	if ((*t)->right == NULL)
	{
		aux = *t;
		*t = (*t)->left;
		free(aux);
		rebalanceTreeAVL(f);
		return;
	}

	if ((*t)->left != NULL)
	{
		antecessorAVL(&(*t)->left, *t);
		rebalanceTreeAVL(t);
		rebalanceTreeAVL(f);
		return;
	}

	aux = *t;
	*t = (*t)->right;
	free(aux);
	rebalanceTreeAVL(t);
	rebalanceTreeAVL(f);
}

void preordemAVL(TreeAVL *t)
{
	if (!(t == NULL))
	{
		printf("%f:%d\t", t->reg.key, t->weight);
		preordemAVL(t->left);
		preordemAVL(t->right);
	}
}

void centralAVL(TreeAVL *t)
{
	if (!(t == NULL))
	{
		centralAVL(t->left);
		printf("%f\t", t->reg.key);
		centralAVL(t->right);
	}
}

void posordemAVL(TreeAVL *t)
{
	if (!(t == NULL))
	{
		posordemAVL(t->left);
		posordemAVL(t->right);
		printf("%f\t", t->reg.key);
	}
}

int getWeightAVL(TreeAVL **t)
{
	if (*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeightAVL(int left, int right)
{
	if (left > right)
		return left;
	return right;
}

void rotacaoSimplesDireitaAVL(TreeAVL **t)
{
	TreeAVL *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeightAVL(getWeightAVL(&(*t)->left), getWeightAVL(&(*t)->right)) + 1;
	aux->weight = getMaxWeightAVL(getWeightAVL(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerdaAVL(TreeAVL **t)
{
	TreeAVL *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeightAVL(getWeightAVL(&(*t)->left), getWeightAVL(&(*t)->right)) + 1;
	aux->weight = getMaxWeightAVL(getWeightAVL(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireitaAVL(TreeAVL **t)
{
	rotacaoSimplesEsquerdaAVL(&(*t)->left);
	rotacaoSimplesDireitaAVL(t);
}

void rotacaoDuplaEsquerdaAVL(TreeAVL **t)
{
	rotacaoSimplesDireitaAVL(&(*t)->right);
	rotacaoSimplesEsquerdaAVL(t);
}
