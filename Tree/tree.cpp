
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>

#include "tree.h"


using namespace std;

lista* criar(){
	lista* l = new lista;
  
	if (l == NULL) return NULL;
	
	l -> cab = NULL;
	l -> fim = NULL;
	
	return l;	
}


void insert(lista *l, colaborador *dado){
	if(l!=NULL){
		node *aux = l->cab;

		node *newnode = new node[1];
		if(newnode != NULL)	newnode->dado = dado;

		if(l->cab== NULL){
			l->cab=l->fim = newnode;
			l->cab->prox =l->fim->prox = NULL;
		}else{
			l->fim->prox =newnode;
			newnode->prev = l->fim;
			l->fim=newnode;
		}	
	}	
}

dado* criaTree(string name, colaborador *ptrcolaborador){    
		dado* t = new dado;
    
    if (t == NULL) return NULL;
    
    t->chave = name;
    t->direita = NULL;
    t->esquerda = NULL;
	t->ptcolaborador = ptrcolaborador;

    return t;
}


dado* inserirTree(dado* pai, string name, colaborador *vetorcolaborador){
    dado* novo = criaTree(name, vetorcolaborador); // alocando um novo nó
    
    if (novo == NULL) return NULL;
    
    if (pai == NULL){ // se a arvore estiver vazia
        pai = novo;
        return novo;
        // se a arvore não estiver vazia
    //}else if (name < pai -> chave){  // se o dado a ser inserido for menor que o pai
    }else if (name < pai ->ptcolaborador->nome){  // se o dado a ser inserido for menor que o pai
        pai->esquerda = inserirTree(pai->esquerda,name, vetorcolaborador);

    }else { // se o dado a ser inserido for maior que po pai
        pai->direita = inserirTree(pai->direita,name, vetorcolaborador);
    }
    return pai;
}

// ANTIGA FUNÇÃO DE BUSCA

/*
colaborador* busca(dado* raiz, string name){
    if (raiz == NULL) return NULL;
    //else if(raiz->chave == name) return raiz->ptcolaborador;
    else if(raiz->ptcolaborador->nome == name) return raiz->ptcolaborador;
    //else if(name <= raiz->chave) return busca(raiz->esquerda,name);
    else if(name <= raiz->ptcolaborador->nome) return busca(raiz->esquerda,name);
    else return busca(raiz->direita,name);
}
*/

colaborador* busca(dado* raiz, string name){
    if (raiz == NULL) return NULL;
    else if(raiz->chave == name) return raiz->ptcolaborador;
    else if(name <= raiz->chave) return busca(raiz->esquerda,name);
    else return busca(raiz->direita,name);
}
//==================== In Order ============================//

void inOrdem(dado *raiz){
  if(raiz == NULL) return;

  inOrdem(raiz->esquerda);

  cout << "Chave: " << raiz->chave << endl;

  inOrdem(raiz->direita);
}

//==================== In Order ============================//


dado* FindMin(dado* raiz){
    dado* aux = raiz;
    while (aux->esquerda != NULL) 
        aux = aux->esquerda; 

    return FindMin(aux->esquerda);
}

dado* deleteNode(dado* raiz, string chave){
  if (raiz == NULL) return raiz;
  if (chave <raiz->chave)
    raiz->esquerda = deleteNode(raiz->esquerda,chave);
  else if(chave > raiz-> chave)
    raiz->direita = deleteNode(raiz->direita,chave);
  else{
    if(raiz->esquerda == NULL){
      dado* aux = raiz->direita;
      delete(raiz);
      return aux;

    } else if (raiz -> direita == NULL){
      dado* aux = raiz->esquerda;
      delete(raiz);
      return aux;
    }
    dado* temp = FindMin(raiz->direita);
    raiz->ptcolaborador = temp->ptcolaborador;
    raiz->chave = temp->chave;
    raiz->direita = deleteNode(raiz->direita, temp->ptcolaborador->nome);

  }

  return raiz;

}





