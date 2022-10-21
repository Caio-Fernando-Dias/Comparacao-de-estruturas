#ifndef tree_HPP
#define tree_HPP

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <fstream>
#include <string>

using namespace std;

typedef struct Record_binary Record_binary;
typedef struct Tree_binary Tree_binary;

struct Record_binary{
	string key;
	string value;
	int cont = 0;
};

struct Tree_binary{
	Record_binary reg;
	Tree_binary *left, *right;
};

Tree_binary* CreateTree_binary();
bool TVazia_binary(Tree_binary **t);
void insertTree_binary(Tree_binary **t, Record_binary r);
int pesquisa_binary(Tree_binary **t, Tree_binary **aux, Record_binary r);
int isInTree_binary(Tree_binary *t, Record_binary r);

void removeTree_binary(Tree_binary **t, Record_binary r);
void antecessor(Tree_binary **t, Tree_binary *aux);

#endif