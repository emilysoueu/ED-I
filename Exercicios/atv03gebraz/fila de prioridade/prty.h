#ifndef PRTY_H
#define PRTY_H

typedef struct _fila_{
	int *queue;
	int inicio;
	int fim;
	int qtd;
	int tam;
}fila;


fila *criar(int tam);

int enfileira(fila *q, fila *f, int valor, int prioridade);

int pop_fila(fila *f, fila *q, int qAtend);

#endif
