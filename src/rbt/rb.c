#include "rb.h"

TreeRBT *CreateTreeRBT()
{
  return NULL;
}

void insertFixUpRBT(TreeRBT **raiz, TreeRBT *child)
{
  TreeRBT *tio;

  while ((child != *raiz) && (child->pai->cor == false))
  {

    if (child->pai == child->pai->pai->esq)
    {

      tio = child->pai->pai->dir;

      // caso 1:
      if ((tio != NULL) && (tio->cor == false))
      {
        child->pai->cor = true;
        tio->cor = true;
        child->pai->pai->cor = false;
        child = child->pai->pai;
      }
      else
      {

        // caso 2
        if (child == child->pai->dir)
        {
          child = child->pai;
          rotacaoSimplesEsquerdaRBT(raiz, child);
        }

        // caso 3
        child->pai->cor = true;
        child->pai->pai->cor = false;
        rotacaoSimplesDireitaRBT(raiz, child->pai->pai);
      }
    }
    else
    {

      tio = child->pai->pai->esq;

      // caso 1
      if ((tio != NULL) && (tio->cor == false))
      {
        child->pai->cor = true;
        tio->cor = true;
        child->pai->pai->cor = false;
        child = child->pai->pai;
      }
      else
      {

        // caso 2
        if (child == child->pai->esq)
        {
          child = child->pai;
          rotacaoSimplesDireitaRBT(raiz, child);
        }

        // caso 3
        child->pai->cor = true;
        child->pai->pai->cor = false;
        rotacaoSimplesEsquerdaRBT(raiz, child->pai->pai);
      }
    }
  }

  (*raiz)->cor = true;
}

void insertTreeRBT(TreeRBT **t, TreeRBT **pai, TreeRBT **raiz, RecordRBT r)
{

  if (*t == NULL)
  {
    *t = (TreeRBT *)malloc(sizeof(TreeRBT));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->pai = pai != t ? *pai : NULL;
    (*t)->cor = false; // false: vermelho  true:preto
    (*t)->reg = r;
    insertFixUpRBT(raiz, *t);
  }
  else
  {

    if (r.key < (*t)->reg.key)
    {
      insertTreeRBT(&(*t)->esq, t, raiz, r);
      return;
    }

    if (r.key > (*t)->reg.key)
    {
      insertTreeRBT(&(*t)->dir, t, raiz, r);
      return;
    }
  }
}

void pesquisaRBT(TreeRBT **t, TreeRBT **aux, RecordRBT r)
{

  if (*t == NULL)
  {
    //printf("[ERROR]: Node not found!");
    return;
  }

  if ((*t)->reg.key > r.key)
  {
    pesquisaRBT(&(*t)->esq, aux, r);
    return;
  }
  if ((*t)->reg.key < r.key)
  {
    pesquisaRBT(&(*t)->dir, aux, r);
    return;
  }

  *aux = *t;
}

void rotacaoSimplesEsquerdaRBT(TreeRBT **raiz, TreeRBT *child)
{
  TreeRBT *x, *y;

  x = child;
  y = child->dir;
  x->dir = y->esq;

  if (y->esq != NULL)
    y->esq->pai = x;

  y->pai = x->pai;

  if (x->pai == NULL)
    *raiz = y;

  else
  {

    if (x == x->pai->esq)
      x->pai->esq = y;

    else
      x->pai->dir = y;
  }

  y->esq = x;
  x->pai = y;
}

void rotacaoSimplesDireitaRBT(TreeRBT **raiz, TreeRBT *child)
{
  TreeRBT *x, *y;

  x = child;
  y = child->esq;
  x->esq = y->dir;

  if (y->dir != NULL)
    y->dir->pai = x;

  y->pai = x->pai;

  if (x->pai == NULL)
  {
    *raiz = y;
  }

  else
  {

    if (x == x->pai->dir)
      x->pai->dir = y;

    else
      x->pai->esq = y;
  }

  y->dir = x;
  x->pai = y;
}

void preordemRBT(TreeRBT *t)
{
  if (!(t == NULL))
  {
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    preordemRBT(t->esq);
    preordemRBT(t->dir);
  }
}

void centralRBT(TreeRBT *t)
{
  if (!(t == NULL))
  {
    centralRBT(t->esq);
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    centralRBT(t->dir);
  }
}

void posordemRBT(TreeRBT *t)
{
  if (!(t == NULL))
  {
    posordemRBT(t->esq);
    posordemRBT(t->dir);
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
  }
}