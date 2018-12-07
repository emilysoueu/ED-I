#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

lista *criarlista(){ // cria lista
	lista *L = (lista*)malloc(sizeof(lista));
	if (L !=NULL){
		L -> first = NULL;
		return L;
	}
}

// pega a primeira posição da lista
int *firstPos(lista *tmp){
	if (tmp != NULL){
		if (tmp -> first != NULL){
			tmp -> cur = tmp -> first;
			return tmp -> cur ->data;
			
		}
	}
	
	return NULL;
}


// pega o proximo nó caso exista
int *poxNode(lista *tmp){
	if (tmp != NULL){
		if (tmp -> cur != NULL){
			tmp -> cur = tmp -> cur -> prox;
			if (tmp -> cur != NULL){
				return tmp -> cur -> data;
			}
		}
	}
	return 0;
}

// insere no começo da lista
void insereLista(lista *L, int x){
	node *novo, *p;
	
	if (L != NULL){
		if (L -> first != NULL){
			novo = (node*) malloc(sizeof(node));
			if (novo != NULL){
				novo -> data = x;
				novo -> prox = NULL;
				L -> first = novo;
			}
		}
	}else{
		novo = (node*)malloc(sizeof(node));
		if (novo != NULL){
			novo -> data = x;
			novo -> prox = NULL;
			p = L -> first;
			while (p-> prox != NULL){
				p = p -> prox;
			}
			p -> prox = novo;			
		}
	}
	 
}

// mostra lista

void imprimir(node *L){
	if (L != NULL){
		printf("%d ", L -> data);
		}
		
		
}



