//Incluir um elemento no final de uma lista.

#include <stdio.h>
#include <stdlib.h>

typedef struct _lista_{
	int dado;
	struct _lista_ *prox;	
}lista;

lista *criar(int x){
	lista *Fila = (lista*)malloc(sizeof(lista));
	if (Fila == NULL) return NULL;
	
	Fila -> dado = x;
	Fila -> prox = NULL;
	
	return Fila;
}


void insertFila(lista **Fila, int x){
	lista *novo;
		
	novo = criar(x);
	
	if ((*Fila) -> prox == NULL){
		(*Fila)-> prox = novo;
		printf("\n\nkoala\n\n ");
	}else{
		printf("\n\nbanana\n\n ");
		lista *tmp = (*Fila) -> prox;
		while(tmp-> prox != NULL)
			tmp = tmp -> prox;
		tmp -> prox = novo;
	}
}

void printList(lista *Fila){
	int x;
	
	while(Fila != NULL){
		x = Fila -> dado;
		printf("%d ", x);
     }
		
}

int main(){
	lista *f;
	f =  NULL;
	
	insertFila(&f, 1);
	insertFila(&f, 2);
	insertFila(&f, 3);
	
	printList(f);
}

