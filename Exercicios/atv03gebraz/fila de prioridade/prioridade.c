#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "prioridade.h"

//======================== functions =====================//

fila *criar(int max){
	fila *q = (fila*)malloc(sizeof(fila));
	if ((q == NULL) || (max <=0)) return NULL;
	
	q->dados= (int*)malloc(sizeof(int)*max);
	if (q->dados == NULL) return NULL;
	
	q->inicio = 0;
	q->fim = 0;
	
	q->queue= (int*)malloc(sizeof(int)*3); // 3 = quantidade pra atendimento
	if (q->queue == NULL) return NULL;	
	q -> beg = 0;
	q -> end = 0;
	
	return q;
}	

bool isEmpty(fila *q){
	if (q == NULL) return true;
	
	if ((q -> fim) == (q->inicio) || (q -> end) ==(q -> beg))
		return true;
	else
		return false;	
}

// op = opção de fila 1 = prioridade e 2 = normal;
int inserir(fila *q, int x,int op){
	if ((q == NULL) || (q->queue == NULL)) return 0;
	
	if (op == 1){ // fila de prioridade	
		q-> queue[q->end] = x;
		q->end++;
		return 1;	
	}else{ // fila normal
		q-> dados[q->fim] = x;
		q->fim++;
		return 1;		
	}	
}

// op = opção de fila 1 = prioridade e 2 = normal;
int pop(fila *q, int op){
	if ((q == NULL) || (q->queue == NULL)) return 0;
	if (op == 1){
		int x;
		x = q->queue[q->beg];
		q->queue[q->beg] = q->queue[q->beg+1];
		q->beg ++;	
		return x;
	}else{ // fila normal 
		int x;
		x = q->dados[q->inicio];
		q->dados[q->inicio] = q->dados[q->inicio+1];
		q->inicio ++;	
		return x;
	}
	
		
}
