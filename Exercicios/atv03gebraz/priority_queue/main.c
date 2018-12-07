#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "prty.h"
#include "prty.c"

int main(){
	fila *f; // fila normal
    fila *q; // fila prioridade
    int max = 5;
    int pValue; // prioridade;
    
    int aluno,dado;
	int filaC = 0, filaP = 0;
    
    f = criar(max);
    q = criar(max);
    /**
    do{
		printf("Insira a prioridade: \n");
		scanf("%d", &pValue);
		if (pValue == 0){
				printf("Convencional: \n");
				scanf("%d",&aluno);
				enfileira(q, f, aluno, pValue);
				filaC++;
				printf("Pessoas na fila Convencional: %d\n", filaC);
		}else{
				printf("Prioridade:\n");
				scanf("%d",&aluno);
				enfileira(q, f, aluno, pValue);
				filaP++;
				printf("Pessoas na fila Prioridade: %d\n", filaP);
		 }
	
		}while(filaC + filaP<max);
		*/
		
		enfileira(q, f, 1, 1);
		enfileira(q, f, 2, 1);
		enfileira(q, f, 10, 0);
		enfileira(q, f, 3, 1);
		enfileira(q, f, 20, 0);
		
		int i;
		printf("Fila da coordencao: \n");
		for(i=0;i<max;i++){
			dado = pop_fila(q,f,0);						
			printf("\n%d\n",dado);
        }
    
    
}
