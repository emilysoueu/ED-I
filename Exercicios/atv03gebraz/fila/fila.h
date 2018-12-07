#ifndef FILA_H
#define FILA_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct _fila_{
	int *vetFila; // vetor de dados
	int inicio;   // inicio da fila;
	int fim;      // fim da fila
	int max;      //quantidade maxima de elementos na fila	
}fila;

// criar

fila* criar( int max);
int enfileirar(fila *q, int x);
void pop(fila *q);
bool estaVazia(fila *q);



#endif
