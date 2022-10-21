#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

typedef struct Record_AVL Record_AVL;
typedef struct Tree_AVL Tree_AVL;

struct Record_AVL{
	string key;
	string value;
};

struct Tree_AVL{
	Record_AVL reg;
	Tree_AVL *left, *right;
	int weight;
};

Tree_AVL* CreateTree_AVL();
void insertTree_AVL(Tree_AVL **t, Record_AVL r);
int pesquisa_AVL(Tree_AVL **t, Tree_AVL **aux, Record_AVL r);
int isInTree_AVL(Tree_AVL *t, Record_AVL r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTree_AVL(Tree_AVL **t, Tree_AVL **f, Record_AVL r);
void antecessor_AVL(Tree_AVL **t, Tree_AVL *aux);
void rebalanceTree_AVL(Tree_AVL **t);

int getWeight_AVL(Tree_AVL **t);
int getMaxWeight_AVL(int left, int right);


void rotacaoSimplesDireita_AVL(Tree_AVL **t);
void rotacaoSimplesEsquerda_AVL(Tree_AVL **t);
void rotacaoDuplaDireita_AVL(Tree_AVL **t);
void rotacaoDuplaEsquerda_AVL(Tree_AVL **t);


#endif
