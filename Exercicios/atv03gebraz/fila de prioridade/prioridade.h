#ifndef PRIORIDADE_H
#define PRIORIDADE_H

typedef struct _fila_{
	int *dados;
	int inicio;
	int fim;
	int *queue;
	int beg;
	int end;
}fila;



fila  *criar(int );
bool isEmpty(fila *q);
int inserir(fila  *q, int x, int op );
int pop(fila  *q, int op);

#endif

 
