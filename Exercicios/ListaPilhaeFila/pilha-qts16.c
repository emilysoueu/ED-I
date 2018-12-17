/**16.Dado uma pilha P qualquer, transcreva seus elementos para uma Fila f de tal maneira
que o último elemento da pilha, deve ser o primeiro da fila e assim em diante.
*/

// ultimo d pilha - primeiro a ser inserido?
// ultimo da pilha - primeiro a sair? ---- fico com essa

#include <stdio.h>
#include <stdlib.h>

typedef struct _pilha_{
	int *stack;
	int topo;
	int qtd;
	int maxp;
}pilha;

typedef struct _fila_{
	int *queue;
	int beg;
	int end;
	int qtd;
	int maxf	
} fila;

pilha *criar_pilha(int max){
	pilha *p = (pilha *)malloc(sizeof(pilha));
	if (p == NULL || max <= 0) return NULL;
	
	p -> stack = (int*)malloc(sizeof(int));
	if (p->stack == NULL) return NULL;
	
	p -> topo = -1;
	p -> qtd  = 0;
	p -> maxp = max;
	
	return p;
	
}

void push(pilha *p, int valor){
	if (p == NULL || p-> stack == NULL) printf("Nao alocado\n");
	
	p -> topo ++;
	p -> stack[p->topo] = valor;	
	p -> qtd ++;
}

int pop(pilha *p){
	if (p == NULL || p-> stack == NULL) return -1;
	
	int x;
	x = p -> stack[p->topo];
	p -> topo --;
	p -> qtd --;
	
	return x;
	
}

fila *criar_fila(int max){
	fila* f = (fila*)malloc(sizeof(fila));
	if (f == NULL) return NULL;
	
	f -> queue = (int*)malloc(sizeof(int));
	if (f->queue == NULL) return NULL;
	
	f -> beg = 0;
	f -> end = -1;
	f -> qtd = 0;
	f ->maxf = max;
	
	return f;	
}

void enqueue(fila *f, int valor){
	if (f == NULL || f -> queue == NULL) return ;
	
	f -> queue [f->end] = valor;
	f -> end++;
	f -> qtd ++;

	
}

int dequeue(fila *f){
	if (f == NULL || f -> queue) return -1;
	
	int y;
	y = f -> queue[f->beg];
	f -> beg ++;
	f -> qtd--;
	
	return y;
}

int main(){
	int max = 3;
	pilha *p;
	fila *f;
	
	p = criar_pilha(max);
	f = criar_fila(max);
	int i ,x;
	
	// insere na pilha
	for (int i =1; i<= max; i++){
		x = i;
		push(p,x);
	}
	//mostra a pilha
	printf("Pilha:\n");
	for (int i =1; i<= max; i++){
		x = pop(p);
		printf("\n%d ",x);
	}
	
	//insere novamene na pilha
	for (int i =1; i<= max; i++){
		x = i;
		push(p,x);
	}
	
	// insere na fila;
	for (i=0; i<max; i++){
		enqueue(f,pop(p));		
	}
	//mostra a fila
	printf("\nFila:\n");
	for (int i =1; i<= max; i++){
		int k = dequeue(f);
		printf("\n%d ",k);
	}
		
	// ta dando algum erro na hora de passar pra fila
	
	
	
}

