#ifndef PRIORIDADE_H
#define PRIORIDADE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _fila_{
	int *mat; // vetor fila
	int qtd; // quantidade atual de elementos no vetor
	int primeiro; // primeiro elemento no vetor
	int ultimo; // ultimo elemento no vetor
	int tamanho; // tamanho maximo de elementos no vetor fila
}fila;

typedef struct _fila_coordenacao_{
	fila *p; // fila prioridade
	fila *n; // fila normal
	int peso; // controle de atendimento

}coord;

fila *criar(int size);
int enqueue(fila *f, int aluno); // enfileriar
int dequeue (fila *f); // retirar elementos 
int insereCoordenacao(coord *c, int aluno, int prioridade);
int atender(coord *c);



#endif

