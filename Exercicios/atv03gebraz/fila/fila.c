#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

fila* criar( int max){
	fila *q = (fila*)malloc(sizeof(fila));
	
	if ((q == NULL) || max < 0) return NULL;
	q -> vetFila = (int*)malloc(sizeof(int)*max);
	
	if (q -> vetFila == NULL) return NULL;
	q -> inicio = 0;
	q -> fim = 0;
	return q;		
}
// enfileirar
int enfileirar(fila *q, int x){
	if ((q == NULL) || (q -> vetFila == NULL)) return 0;
	
	q ->vetFila[q->fim] = x;
	q -> fim ++;
	return 1;
}

// desinfileirar
void pop(fila *q){
	if ((q == NULL) || (q -> vetFila == NULL)) return ;
	
	printf("%d\n", q ->vetFila[q->inicio]);
	q ->inicio++;
	
}

// vazia

bool estaVazia(fila *q){
	if (q->inicio == q ->fim){
		return true;
	}else{
		return false;
	}	
		
	
}


