#include "rb.hpp"

Tree_RB* CreateTree_RB(){
  return NULL;
}

void insertFixUp_RB(Tree_RB **raiz, Tree_RB *child){
  Tree_RB *tio;

  while((child != *raiz) && (child->pai->cor == false)){
      
      if(child->pai == child->pai->pai->left){
        
        tio = child->pai->pai->right;

        //caso 1:Tree_RB
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->right){
            child = child->pai;
            rotacaoSimplesEsquerda_RB(raiz, child);
          }
          
          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesDireita_RB(raiz, child->pai->pai);
        }

      }else{
        
        tio = child->pai->pai->right;
        
        //caso 1
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->left){
            child = child->pai;
            rotacaoSimplesDireita_RB(raiz, child);
          }

          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesEsquerda_RB(raiz, child->pai->pai);      
        }

      }

  }

  (*raiz)->cor = true;
}


void insertTree_RB(Tree_RB **t, Tree_RB **pai, Tree_RB **raiz, Record_RB r){
  
  if(*t == NULL){
    *t = new Tree_RB;
    //*t = (Tree_RB*)malloc(sizeof(Tree_RB));
    (*t)->left = NULL; 
    (*t)->right = NULL; 
    (*t)->pai = pai!=t?*pai:NULL;
    (*t)->cor = false; //false: vermelho  true:preto
    (*t)->reg = r; 
    insertFixUp_RB(raiz, *t);
    
  } else { 

    if(r.key < (*t)->reg.key){
      insertTree_RB(&(*t)->left, t, raiz, r);
      return;
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_RB(&(*t)->right, t, raiz, r);
      return;
    }

  }

}


int pesquisa_RB(Tree_RB **t, Tree_RB **aux, Record_RB r){

  if(*t == NULL){
    return 0;
  }

  if((*t)->reg.key > r.key){ pesquisa_RB(&(*t)->left, aux, r); return 1;}
  if((*t)->reg.key < r.key){ pesquisa_RB(&(*t)->right, aux, r); return 1;}

  *aux = *t;
  return 1;
}

void rotacaoSimplesEsquerda_RB(Tree_RB **raiz, Tree_RB *child){
  Tree_RB *x, *y;

  x = child;
  y = child->right;
  x->right = y->left;

  if(y->left != NULL)
    y->left->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL)
    *raiz = y;

  else{

    if(x == x->pai->left)
      x->pai->left = y;

    else
      x->pai->right = y;
  
  }

  y->left = x;
  x->pai = y;
}


void rotacaoSimplesDireita_RB(Tree_RB **raiz, Tree_RB *child){
  Tree_RB *x, *y;

  x = child;
  y = child->left;
  x->left = y->right;

  if(y->right != NULL)
    y->right->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL){
    *raiz = y;
  }

  else{

    if(x == x->pai->right)
      x->pai->right = y;

    else
      x->pai->left = y;
  
  }

  y->right = x;
  x->pai = y;
  
}

void delete_RB(Tree_RB **t, Tree_RB *value){
    Tree_RB *y = value;
    Tree_RB *x;
    bool originalColor = y->cor;

    if (value->left == NULL){
        x = value->right;
        if (x == NULL){
            x = new Tree_RB;
            x->reg.value = "404";
            x->cor = true;
            value->right = x;
        }

        RBTransplant(t,value,value->right);
        x->pai = value->pai;

    }else if(value->right == NULL){
        x = value->left;
        if (x == NULL){

            x = new Tree_RB;
            x->reg.value = "404";
            x->cor = true;
            value->left = x;
        }
        
        RBTransplant(t,value,value->left);
          x->pai = value->pai;
    }else{

        y = TreeMinimun(&value->left); //Arrumar
        originalColor = y->cor;
        x = y->left;
        if (x == NULL){

            x = new Tree_RB;
            x->pai = y;
            x->reg.value = "404";
            x->cor = true;
            y->left = x;
        }
        if (y->pai == value){

            x->pai = y;
        }else{

            RBTransplant(t,y,y->left);
            y->left = value ->left;
            y->left->pai = y;
        }

        RBTransplant(t,value,y);
        y->right = value->right;
        y->right->pai = y;
        y->cor = value->cor;
    }

    Tree_RB *aux = x;
    if (originalColor){
        RBDeleteFixup(t,x);
        if (aux->reg.value == "404"){
          if (aux == aux->pai->left){
            aux->pai->left = NULL;
          }else{
            aux->pai->right = NULL;
            delete aux;
          }
        }
    }

    delete value;
}

void RBTransplant(Tree_RB **t, Tree_RB *value, Tree_RB *sucessor){

    if (value->pai == NULL){
        (*t) = sucessor;
    }else if(value == value->pai->left){
        value->pai->left = sucessor;
    }else{
        value->pai->right = sucessor;
    sucessor->pai = value->pai;
    }
}

void removeRB(Tree_RB **raiz, Tree_RB **t, Record_RB r){
    if (*t == NULL){ 
        return;
    }

    if (r.value < (*t)->reg.value){ removeRB(raiz, &(*t)->left, r); return; }
    if (r.value > (*t)->reg.value){ removeRB(raiz, &(*t)->right, r); return; }

    if ((*raiz)->right == NULL && (*raiz)->left == NULL){delete (*raiz);(*raiz) = NULL; return;}

    delete_RB(raiz,(*t));  
}

Tree_RB *TreeMinimun(Tree_RB **t){
    if ((*t)->right != NULL){
        return TreeMinimun(&(*t)->right);
    } else{
        return (*t);
    }
    
    return NULL;
} 

void RBDeleteFixup(Tree_RB **t, Tree_RB *x){
    while (x != (*t) && x->cor){
        if (x == x->pai->left){
            Tree_RB* w = x->pai->right;
        if (w != NULL){
            if (!w->cor){
                w->cor = true;
                x->pai->cor = false;
                rotacaoSimplesEsquerda_RB(t,x->pai);
                w = x->pai->right;
            }
        }
            
            if ((w->right == NULL || w->right->cor) && (w->left == NULL || w->left->cor)){
                w->cor = false;
                x = x->pai;
            }else if(w->right == NULL || w->right->cor){
                w->left->cor = true;
                w->cor = false;
                rotacaoSimplesDireita_RB(t,w);
                w = x->pai->right;
            }
            
            if(w->right != NULL && !w->right->cor){
                w->cor = x->pai->cor;
                x->pai->cor = true;
                w->right->cor = true;
                rotacaoSimplesEsquerda_RB(t,x->pai);
                x = (*t);
            }
        }else{
            x = x->pai;

            Tree_RB* w = x->pai->left;
            if (w != NULL){
                if (!w->cor){
                    w->cor = true;
                    x->pai->cor = false;
                    rotacaoSimplesDireita_RB(t,x->pai);
                    w = x->pai->left;
                }
                if ((w->right == NULL || w->right->cor) && (w->left == NULL || w->left->cor)){
                    if(w != NULL)
                        w->cor = false;
                    x = x->pai;
                } else if(w->left == NULL || w->left->cor){
                    w->right->cor = true;
                    w->cor = false;
                    rotacaoSimplesEsquerda_RB(t,w);
                    w = x->pai->left;
                }
                if(w->left != NULL && !w->left->cor){
                    w->cor = x->pai->cor;
                    x->pai->cor = true;
                    w->left->cor = true;
                    rotacaoSimplesDireita_RB(t,x->pai); 
                    x = (*t);
                }
            }else{
              x = x->pai;
            }
          }
        }
    x->cor = true;
  }