/*Elabore um algoritmo que não use uma pilha para ler uma seqüência de operações
push e pop, e determine se está ocorrendo underflow (ultrapassa o tamanho do vetor) ou não em alguma operação
pop.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _fila_{
	int *dados;
	int inicio;
	int fim;
	int qtd;
	int max;	
}fila;

fila *criar(int max){
	fila *f = (fila*)malloc(sizeof(fila));
	if (f == NULL) return NULL;
	
	f->dados = (int*)malloc(sizeof(int));
	if (f->dados == NULL) return NULL;
	
	f -> inicio = 0;
	f -> fim = 0;
	f -> qtd = 0;
	f -> max  = max;
	
	return f;
}

void push(fila *f, int valor){
	f -> dados[f->fim] = valor;
	f -> fim ++;
	f -> qtd ++;
}

int pop(fila *f){
	int x;
	x = f-> dados[f->inicio];
	f -> inicio ++;
	f -> qtd --;
	
	return x;	
}

int main(){
	int max = 3;
	int x;	
	fila *f = criar(max);
	
	/**push(f,1);
	push(f,2);
	push(f,3);
	*/
	
	//underflow -> remover elementos de uma pilha/fila vazia
	//overflow  -> inserir elementos em uma pilha/ fila cheia
	
	for (int i =1; i<=5; i++){ // cade o 4?
		x = i;
		if (f-> qtd <= max){ // se a quantidade de elemetos for menor que a capacidade máxima
		push(f,x);           // insere elemento
	   }else{
		   printf("UNDERFLOW a partir do elemento %d \n",x);
		   break;		   
	   }
	}
	
	for (int i =0; i<max; i++){
		x = pop(f);
		printf("%d ",x);
	}
	
}

