#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "prioridade.h"



//==================fila.c===============//

fila *criar(int size){
	fila *f = (fila*)malloc(sizeof(fila));
	if (f == NULL) return NULL;
	
	f->mat = (int*)malloc(sizeof(int)*size);
	if (f->mat == NULL) return NULL;
	
	f -> qtd = 0;
	f -> primeiro= -1;
	f -> ultimo = -1;
	f -> tamanho = size;
	
	return f;
}


int enqueue(fila *f, int aluno){ // enfileriar
	if (f!= NULL){
		if (f -> primeiro != f -> ultimo){
			f->mat[f->ultimo] = aluno;
			f->ultimo = (f->ultimo+1) % f->tamanho; // o que significa isso msm???
			if (f->primeiro < 0){
				f-> primeiro = 0;
			f -> qtd ++;
			return 1;
			}
		}		
	}
	return 0;
}

int dequeue (fila *f){ // retirar elementos 
	if ((f!= NULL) && (f ->qtd>0)){
		int tmp = f->mat[f->primeiro];
		f -> primeiro = (f->primeiro+1) % f-> tamanho;
		f -> qtd --;
		return tmp;
	}
	return -1;
}

int insereCoordenacao(coord *c, int aluno, int prioridade){

	if (prioridade)
		return enqueue(c->p, aluno);

	return enqueue(c -> n, aluno);

}

int atender(coord *c){
	if((c -> peso <3) &&(c->p->qtd >0)){
		c->peso++;

		return dequeue(c->p);
	}

	c-> peso = 0;
	return dequeue(c->n);


}
