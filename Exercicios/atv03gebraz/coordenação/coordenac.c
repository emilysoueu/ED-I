#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "coordenac.h"

//====================FUNCTIONS=========================//

fila *criar(int max){
	fila* q = (fila*)malloc(sizeof(fila));	
	if (q == NULL) return NULL;
		
	q->coor = (int*)malloc(sizeof(int)*max);
	if (q->coor == NULL) return NULL;
	
	q->inicio = 0;
	q ->fim = 0;
	
	return q;	
}


int enfileira(fila *q, int dado){
	q ->coor[q->fim] = dado;
	q ->fim++;
	
	return 1;	
}


int pop(fila *q){
	int x;
	x =  q->coor[q->inicio];		
   q->coor[q->inicio] = q->coor[q->inicio+1]; 
   q->inicio++;
	return x;
}

bool isEmpty(fila *q){
	if (q -> inicio == q ->fim){
		return true;
	}else{
		return false;
	}
}


