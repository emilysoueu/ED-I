#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "prioridade.c"
#include "prioridade.h"

int main(){
	fila *queue = criar(5);
	fila *priority_queue = criar(5);
	coord *coordenacao = (coord*)malloc(sizeof(coord));
	
	coordenacao -> n = queue;
	coordenacao -> p = priority_queue;
	
	int aluno,cont = 0, pCont = 0,pValue = 1, atendimento;
	int filaC = 0, filaP = 0;
	
	do{
		printf("Insira a prioridade: \n");
		scanf("%d", &pValue);
		if (pValue == 0){
				printf("Convencional: \n");
				scanf("%d",&aluno);
				insereCoordenacao(coordenacao,aluno,0);
				cont++;
				filaC++;
				printf("Pessoas na fila Convencional: %d\n", filaC);
		}else{
				printf("Prioridade:\n");
				scanf("%d",&aluno);
				insereCoordenacao(coordenacao,aluno,pValue);
				cont++;
				filaP++;
				printf("Pessoas na fila Prioridade: %d\n", filaP);
		}
		if (cont >= 5){
			if (coordenacao -> n != NULL){
				do{
					atendimento = atender(coordenacao);
					printf("Atendimento Prioritario: %d\n",atendimento);
					break;
					pCont++;
				} while(pCont <3 );
				pCont = 0;
			}else{
				atendimento = atender(coordenacao);
				printf("Atendimento Convencional: %d\n",atendimento);
				break;
			}			 
	 }
		
	}while(pValue>=0);	
}


