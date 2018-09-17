#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"
#include "fila.c"

int main(){
//criar( int max);
//enfileirar(fila *q, int x);
//pop(fila *q);
//estaVazia(fila *q);

int max,valor;

printf("Informe o tamanho da sua fila: \n");
scanf("%d",&max);

fila *q = criar(max);
if (estaVazia(q)){
	for (int i =0; i<max; i++){
		printf("Insira: \n");
		scanf("%d",&valor);
		enfileirar(q,valor);
	}
}
 printf("Desenfileirando fila: \n");
 for (int i=0; i<max; i++){
	 pop(q);
 }



	
}
