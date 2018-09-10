// @emilysoueu

#include <stdio.h>
#include <stdlib.h>
#include "tadG.c"
#include "tadG.h"

int compara(void *a, void *b){
	
	
	int *a1 = (int*)a; 
	int *b1 = (int*)b;  
	
	if (*a1 > *b1) return 1;
	if (*a1 < *b1) return -1;
	
	return 0;	
}

void print(void *a){
	int *a1 = (int*)a;
	
	printf("%d \n", *a1); 
}

void deletar(void *a){ // troquei o nome remover por deletar
	int *a1= (int *)a;
	
	free(a1); // ??
}

int main(int argc, char *argv[]){
	sequencia *seq;
	
	
	seq = criar(10, compara, print, deletar);
	
	for(int i=0; i<10; i++){
		int *a =(int *)malloc(sizeof(int));		
		*a = i;
		inserir(seq, (void *)a); 
	}
	
	int chave = 2;
	
	removerTodos(seq, (void*)&chave);
	if (buscar(seq,(void*)&chave) >= 0){
		printf("achei \n");	
	}else{
		printf("nada \n");
	}
	
	listar(seq);
	destruir(&seq);
	
}
