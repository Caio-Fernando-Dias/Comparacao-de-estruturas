#ifndef RB_HPP 
#define RB_HPP

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;

typedef struct Record_RB Record_RB;
typedef struct Tree_RB Tree_RB;

struct Record_RB{
	string key;
	string value;
};

struct Tree_RB{
	Record_RB reg;
	Tree_RB *left, *right;
	Tree_RB *pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};


Tree_RB* CreateTree_RB();

void rotacaoSimplesEsquerda_RB(Tree_RB **raiz, Tree_RB *child);
void rotacaoSimplesDireita_RB(Tree_RB **raiz, Tree_RB *child);

void insertFixUp_RB(Tree_RB **raiz, Tree_RB *child);
void insertTree_RB(Tree_RB **t, Tree_RB **pai, Tree_RB **raiz, Record_RB r);
int pesquisa_RB(Tree_RB **t, Tree_RB **aux, Record_RB r);

void delete_RB(Tree_RB **t, Tree_RB *value);
void RBTransplant(Tree_RB **t, Tree_RB *value, Tree_RB *sucessor);
void removeRB(Tree_RB **raiz, Tree_RB **t, Record_RB r);
void RBDeleteFixup(Tree_RB **t, Tree_RB *x);
Tree_RB *TreeMinimun(Tree_RB **t);


#endif