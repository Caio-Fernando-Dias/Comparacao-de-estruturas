#include "tree.hpp"
#include"fila.hpp"

Tree_binary* CreateTree_binary(){
  return NULL;
}

bool TVazia_binary(Tree_binary **t){
  return *t == NULL;
}

void insertTree_binary(Tree_binary **t, Record_binary r){

  if(TVazia_binary(t)){
    *t = new Tree_binary;
    (*t)->left = NULL; 
    (*t)->right = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree_binary(&(*t)->left, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_binary(&(*t)->right, r);
    }
  
  }
}

int pesquisa_binary(Tree_binary **t, Tree_binary **aux, Record_binary r){

  if(*t == NULL){
    return 0;
  }

  if((*t)->reg.key > r.key){ pesquisa_binary(&(*t)->left, aux, r); return 1;}
  if((*t)->reg.key < r.key){ pesquisa_binary(&(*t)->right, aux, r); return 1;}

  *aux = *t;
  return 1;
}


int isInTree_binary(Tree_binary *t, Record_binary r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree_binary(t->left, r) || isInTree_binary(t->right, r);
}


void antecessor(Tree_binary **t, Tree_binary *aux){ 

  if ((*t)->right != NULL){ 
    antecessor(&(*t)->right, aux);
    return;
  }
    
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->left;
  delete aux;
} 


void removeTree_binary(Tree_binary **t, Record_binary r){
  Tree_binary *aux;
    
    if (*t == NULL){ 
      return;
    }

    if (r.key < (*t)->reg.key){ removeTree_binary(&(*t)->left, r); return; }
    if (r.key > (*t)->reg.key){ removeTree_binary(&(*t)->right, r); return; }

    if ((*t)->right == NULL){ 
      aux = *t;  
      *t = (*t)->left;
      delete aux;
      return;
    }

    if ((*t)->left != NULL){ antecessor(&(*t)->left, *t); return; }

    aux = *t;  
    *t = (*t)->right;
    delete aux;
}