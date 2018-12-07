/**10. Faça um procedimento RemoveElemento( int fila Q, int x) que elimina um certo x de
uma fila Q sem alterar a ordem dos demais elementos.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct _fila_{
	int *queue;
	int beg;
	int end;
	int qtd;
	int max;	
}fila;

fila *criar(int max){
	fila *f = (fila*)malloc(sizeof(fila));
	if ((f == NULL) || max <= 0) return NULL;
	
	f -> queue= (int*)malloc(sizeof(int));
	if (f->queue == NULL) return NULL;
	
	f -> beg = 0;
	f -> end = 0;
	f -> qtd = 0;
	f -> max = max;
	
	return f;	
}

void push(fila *f, int valor){
	if ((f == NULL) || (f -> queue == NULL)) printf("Erro de Alocacao\n");
	
	f -> queue[f->end] = valor;
	f -> end ++;
	f -> qtd++;
}

int pop(fila *f){
		if ((f == NULL) || (f -> queue == NULL)) return -1;
		
		int x;
		x = f->queue[f->beg];
		f -> beg ++;
		f -> qtd --;
		
		return x;	
}

int main(){
	int max= 5, bus,i,x;
	fila *f1 = criar(max);
	fila *faux = criar(max);
	/**
	push(f1,1);
	push(f1,2);
	push(f1,3);
	push(f1,4);
	push(f1,5);
	
	printf("Fila Principal: \n");
	x = pop(f1);
	printf("%d ", x);
	x = pop(f1);
	printf("%d ", x);
	x = pop(f1);
	printf("%d ", x);
	x = pop(f1);
	printf("%d ", x);
	x = pop(f1);
	printf("%d ", x);
	
	push(f1,1);
	push(f1,2);
	push(f1,3);
	push(f1,4);
	push(f1,5);
	*/
	
	for (i =1; i<=max; i++){
		x =i;
		push(f1,x);
	}
	printf("\nInforme numero de busca: \n");
	scanf("%d",&bus);
	
	
	for (i=0; i<max; i++){
		x = pop(f1); // retiro elemento do inicio da fila principal
		if (x != bus){ // comparo se eh igual ao numero que estou buscando
			///printf("removendo %d ", x); // if true, removo da fila;
		///}else{
			push(f1,x); // if false, continuo removendo do inicio e inserindo na fila auxiliar
		}
		//push(f1,pop(faux)); // removo da auxiliar e insiro novamente na principal
	}
	
	printf("\nFila apos remocao: \n");
	/**
	x = pop(f1);
	printf("%d ", x);
	x = pop(f1);
	printf("%d ", x);
	x = pop(f1);
	printf("%d ", x);
	x = pop(f1);
	printf("%d ", x);
	*/
	
	for(i=0;i<max-1;i++){
		x= pop(f1);
		printf("%d ",x);
	}
	
	
}
