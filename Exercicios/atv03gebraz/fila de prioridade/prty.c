#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "prty.h"

fila *criar(int tam){
	fila *q = (fila*)malloc(sizeof(fila));
	if (q==NULL) return NULL;

	q -> queue= (int*)malloc(sizeof(int)*tam);
	if (q->queue == NULL) return NULL;

	q -> fim = 0;
	q -> tam = tam;
	q -> inicio = 0;
	q -> qtd = 0;

	return q;
}

int enfileira(fila *q, fila *f, int dado, int prioridade){
	if  (f == NULL) return -1;
	int qtdQ =  q -> qtd;
	int qtdF = f -> qtd;

	int total = qtdQ  + qtdF;

	if ((total < f->tam) && prioridade == 0){
		f -> queue[f->fim] = dado;

		f -> qtd ++;
		f -> fim ++;
	}
	if ((total < q->tam) && prioridade > 0){
		q -> queue[q->fim] = dado;
		q -> qtd ++;
		q -> fim ++;
	}
	return 0;
}

int pop_fila(fila *f, fila *q, int qAtend){
	int totVal = f ->qtd + q ->qtd;
	int x;
	int ok; //flag pra assegurar ordem no atendimento
    ///printf("%d\n",totVal);
    ///if (totVal>=10) ok = 1;

	if (qAtend<3 && q->qtd > 0){
		if (q!= NULL && q -> qtd >0 /**&& ok == 1*/){
			x = q->queue[q->inicio];
            q -> qtd --;
			q -> inicio ++;
		}
		/*if (q -> inicio == q -> tam)
				q -> inicio = 0;*/
		qAtend+=1;
    printf("prioridade\n");
		return qAtend;
	}
	if(f != NULL && f -> qtd > 0 && (qAtend >= 3 || q->qtd == 0)  /*&& ok == 1*/){
		x = f -> queue[f ->inicio];
        //printf("asdad\n");
		f -> qtd --;
		f -> inicio ++;

		/*if (f -> inicio == f -> tam)
				f -> inicio = 0;*/
		qAtend=0;

        printf("Normal\n");
		return qAtend;
	}


}



























