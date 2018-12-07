
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>

#include "tree.h"


using namespace std;

lista* criar(){
	lista* l = new lista[1];
  
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
		dado* t = new dado[1];
    
    if (t == NULL) return NULL;
    
    t->chave = name;
    t->direita = NULL;
    t->esquerda = NULL;
		t->ptcolaborador = ptrcolaborador;
    return t;
}

// função recursiva
dado* inserirTree(dado* pai, string name, colaborador *vetorcolaborador){
    dado* novo = criaTree(name, vetorcolaborador); // alocando um novo nó
    
    if (novo == NULL) return NULL;
    
    if (pai == NULL){ // se a arvore estiver vazia
        pai = novo;
        return novo;
        // se a arvore não estiver vazia
    }else if (name < pai -> chave){  // se o dado a ser inserido for menor que o pai
        pai->esquerda = inserirTree(pai->esquerda,name, vetorcolaborador);

    }else { // se o dado a ser inserido for maior que po pai
        pai->direita = inserirTree(pai->direita,name, vetorcolaborador);
    }
    return pai;
}


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
  //cout<<raiz->ptcolaborador->nome<<" ";
  cout<<raiz->chave<<" ";
  inOrdem(raiz->direita);
}
/*
//==================== Pre Order ============================//

void preOrdem(dado *raiz){
  if(raiz == NULL) return;

  cout<<raiz->ptcolaborador->dado<<" ";
  preOrdem(raiz->esquerda);  
  preOrdem(raiz->direita);
}
*/

//==================== Find Minimun ============================//
/*Conflito de retorno: ptcolaborador é do tipo[colaborador*] e a função tem q retornar algo do tipo [dado*]
*/

colaborador* FindMin(dado* raiz){
    dado* aux = raiz;
    if (raiz == NULL){
        printf("erro: arvore vazia!!");
        return NULL;
    }
    else if (aux->esquerda == NULL)
        return aux->ptcolaborador;

    return FindMin(aux->esquerda);
}





