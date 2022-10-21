#include "avl.hpp"

Tree_AVL* CreateTree_AVL(){
	return NULL;
}

void insertTree_AVL(Tree_AVL **t, Record_AVL r){

  if(*t == NULL){
    //*t = (Tree_AVL*)malloc(sizeof(Tree_AVL));
    *t = new Tree_AVL;
    (*t)->left   = NULL; 
    (*t)->right  = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree_AVL(&(*t)->left, r);
      if ((getWeight_AVL(&(*t)->left) - getWeight_AVL(&(*t)->right)) == 2){
      	if(r.key < (*t)->left->reg.key)
      		rotacaoSimplesDireita_AVL(t);
      	else
      		rotacaoDuplaDireita_AVL(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_AVL(&(*t)->right, r);
      if ((getWeight_AVL(&(*t)->right) - getWeight_AVL(&(*t)->left)) == 2){
      	if(r.key > (*t)->right->reg.key)
      		rotacaoSimplesEsquerda_AVL(t);
      	else
      		rotacaoDuplaEsquerda_AVL(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight_AVL(getWeight_AVL(&(*t)->left), getWeight_AVL(&(*t)->right)) + 1;
}


int pesquisa_AVL(Tree_AVL **t, Tree_AVL **aux, Record_AVL r){

	if(*t == NULL){
		return 0;
	}

	if((*t)->reg.key > r.key){ pesquisa_AVL(&(*t)->left, aux, r); return 1;}
	if((*t)->reg.key < r.key){ pesquisa_AVL(&(*t)->right, aux, r); return 1;}

	*aux = *t;
	return 1;
}

int isInTree_AVL(Tree_AVL *t, Record_AVL r){
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree_AVL(t->left, r) || isInTree_AVL(t->right, r);
}


void antecessor_AVL(Tree_AVL **t, Tree_AVL *aux){ 

	if ((*t)->right != NULL){ 
		antecessor_AVL(&(*t)->right, aux);
		return;
  	}
  	
  	aux->reg = (*t)->reg;
  	aux = *t; 
  	*t = (*t)->left;
  	delete aux;
} 

void rebalanceTree_AVL(Tree_AVL **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight_AVL(&(*t)->left) - getWeight_AVL(&(*t)->right);
	if((*t)->left)
		left = getWeight_AVL(&(*t)->left->left) - getWeight_AVL(&(*t)->left->right);
	if((*t)->right)
		right = getWeight_AVL(&(*t)->right->left) - getWeight_AVL(&(*t)->right->right);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita_AVL(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita_AVL(t);

	if(balance == -2 && right <= 0)
		rotacaoSimplesEsquerda_AVL(t);
	if(balance == -2 && right > 0)
		rotacaoDuplaEsquerda_AVL(t); 	

}

void removeTree_AVL(Tree_AVL **t, Tree_AVL **f, Record_AVL r){
	Tree_AVL *aux;
  	
  	if (*t == NULL){ 
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree_AVL(&(*t)->left, t, r); return;}
  	if (r.key > (*t)->reg.key){ removeTree_AVL(&(*t)->right, t, r); return;}

  	if ((*t)->right == NULL){ 
  		aux = *t;  
  		*t = (*t)->left;
    	delete aux;
    	rebalanceTree_AVL(f);
    	return;
  	}

  	if ((*t)->left != NULL){ 
  		antecessor_AVL(&(*t)->left, *t);
  		rebalanceTree_AVL(t);
  		rebalanceTree_AVL(f);
  		return;
  	}

  	aux = *t;  
  	*t = (*t)->right;
  	delete aux;
  	rebalanceTree_AVL(t);
  	rebalanceTree_AVL(f); 	
  	
}

int getWeight_AVL(Tree_AVL **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight_AVL(int left, int right){
	if(left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita_AVL(Tree_AVL **t){
	Tree_AVL *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight_AVL(getWeight_AVL(&(*t)->left), getWeight_AVL(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight_AVL(getWeight_AVL(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda_AVL(Tree_AVL **t){
	Tree_AVL *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight_AVL(getWeight_AVL(&(*t)->left), getWeight_AVL(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight_AVL(getWeight_AVL(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita_AVL(Tree_AVL **t){
	rotacaoSimplesEsquerda_AVL(&(*t)->left);
	rotacaoSimplesDireita_AVL(t);
}

void rotacaoDuplaEsquerda_AVL(Tree_AVL **t){
	rotacaoSimplesDireita_AVL(&(*t)->right);
	rotacaoSimplesEsquerda_AVL(t);
}