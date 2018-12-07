// insere no fim da lista -
// remove do fim da lista - remove o ultimo elemento inserido na lista

#include <stdlib.h>
#include <stdio.h>

typedef struct _Lista_{
	int dado;
	struct _Lista_ *prox;	
} lista;

lista *criar(int x){
	lista *l = (lista*)malloc(sizeof(lista));	
	if (l == NULL) return NULL;
	
	l -> dado = x;
	l -> prox = NULL;
	
	return l;
}

int insertLista(lista **l, int x){
	lista *novo = criar(x);
	
	if (*l != NULL){
		novo -> prox = *l;
		*l = novo;
		return 1;
	}else{
		*l = novo;
	}
	return 0;
}

int removeLista(lista **l){ // remover do final da lista 
	lista *atual, *ant, *rem; 
	int ret;
	
	if (*l != NULL){
		if ((*l) -> prox == NULL){
			//printf("\n\n aqui oh\n\n");
			rem = *l;
			*l = NULL;
			
		}else{ // l -> prox != NULL
			//printf("\n\n hava um nana\n\n");
			ant = *l;
			atual = (*l) -> prox;
			if (atual -> prox == NULL){
				rem = atual;
				ant -> prox = NULL;
			}
			
		}
		
	}
	
	ret = rem -> dado;
	free(rem);

	
	return ret;
}

void printList(lista *l){
	int x;
	lista *tmp =  l;
	
	while(tmp != NULL){
		x = tmp -> dado;
		printf("%d ", x);
		tmp = tmp -> prox;
	}
}

int main(){
	lista *aquela;
	aquela = NULL;
	int x;
	
	insertLista(&aquela, 1);
	insertLista(&aquela, 2);
	insertLista(&aquela, 3);
	insertLista(&aquela, 4);
	insertLista(&aquela, 5);
	
	printf("Lista Antes\n");
	printList(aquela);
	
	x = removeLista(&aquela);
	printf("\nValor removido: %d \n", x);
	printf("Lista Depois\n");	
	printList(aquela);
	printf("\n");
	
	x = removeLista(&aquela);
	printf("\nValor removido: %d \n", x);
	printf("Lista Depois\n");	
	printList(aquela);
	printf("\n");
	
	x = removeLista(&aquela);
	printf("\nValor removido: %d \n", x);
	printf("Lista Depois\n");	
	printList(aquela);
	printf("\n");
	
	
	
}




