/**14.Escreva uma função que receba duas filas P1 e P2, de inteiros, e seja capaz de
remover suas repetições entre si, mantendo a mesma sequencia de atendimento da
fila.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct _fila_{
	int *queue;
	int beg;
	int tail;
	int qtd;
	int max;
}fila;

fila *criar(int max){
	fila *p = (fila*)malloc(sizeof(fila));	
	if ((p == NULL) || (max<=0)) return NULL;
	
	p -> queue = (int*)malloc(sizeof(int));
	if (p->queue == NULL) return NULL;
	
	p -> beg = 0;
	p -> tail = -1;
	p -> qtd = 0;
	p -> max = max;
	
	return p;
}

void push(fila *p, int valor){
	if ((p==NULL)||(p->queue == NULL)) return;
	
	p -> tail ++;
	p -> queue[p -> tail] = valor;	
	p -> qtd ++;
}

int pop(fila *p){
	if ((p==NULL)||(p->queue == NULL)) return-1;
	int valor;
	
	valor = p -> queue[p -> beg];	
	p -> beg ++;
	p -> qtd --;
	
	return valor;	
}

int main(){
	int max = 3, x, y;
	int i,j;
	
	fila *f1 = criar(max);
	fila *f2 = criar(max);
	
	for (i=0; i<max; i++){
		x = pop(f1);
			for (j=0; j<max; j++){
				if (x != (y = pop(f2)) );
			}
		
		
	}
}

// não sei fazer essa função de comparar e remover














