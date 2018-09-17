#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "prioridade.c"
#include "prioridade.h"
/*3) Adicione a lei na fila da coordenação:
inclua a ideia de prioridade da fila da coordenação. Assim idosos, deficientes, gestantes e mulheres com criança de colo, entram numa fila diferente de prioridade.
o atendimento deve priorizar a fila de prioridade na razão 3 para 1. Ou seja, devem ser chamada 3x mais pessoas da fila de prioridade do que da fila normal
*/
int main(){
	int max = 8;
	int menu;
	int elm,out;
	int normal = 0, priority = 0;
	
	//criar fila normal
	fila *q = criar(max);	
	
	
	do{
		printf("Informe o tipo de fila:\n");
		printf("1 - Prioridade\n2 - Normal\n0 - Sair");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:{				
				do{
					printf("Insira Prioridade: \n");
					scanf("%d",&elm);
					inserir(q,elm,1);
					priority ++;
					if(priority >= 1){
						 do{
						  out = pop(q,2);
						  printf("Sai :\n%d\n",out);
						  break;
						 }while(!isEmpty(q)); // fim do
					  }//fim if
				   }while(menu == 1);
				}break;
			case 2: {
				do{
					printf("Insira Normal: \n");
					scanf("%d",&elm);
					inserir(q,elm,2);
					normal ++;
					break;
					if(normal >= 10){
						 do{
						  out = pop(q,2);
						  printf("Sai :\n%d\n",out);
						  break;
						}while(!isEmpty(q));// fim do
					}// fim if					
				}while(menu == 2);				
			}break;
		}//fim switch
	 }while(menu>0);
	
}


	
	
	

