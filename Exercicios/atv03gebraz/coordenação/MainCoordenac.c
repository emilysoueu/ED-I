#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "coordenac.h"
#include "coordenac.c"

int main(){
	int entra,out ,qtd=0, max = 20;	
	fila *q = criar(max);		

  do{
    printf("Enfileira: \n");
		scanf("%d",&entra);
		enfileira(q,entra);
    qtd++; 

    if (qtd >= 10){
     do{
      out = pop(q);
      printf("Sai :\n%d\n",out);
      break;
     }while(!isEmpty(q));

    }

  }while(!isEmpty(q));
    
}


