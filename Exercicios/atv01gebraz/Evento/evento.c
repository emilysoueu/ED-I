#include <stdlib.h>
#include <stdio.h>
#include "evento.h"




evento* geraVector(int entradas); 
void mostraTudo(evento* eve); 
int colocar(evento* eve, int chave); 

int main(){
	  int tam, chave;

    int i;

    printf("Esse eh o seu vetor TAD para registrar entradas em um evento: \n");
    printf(" Informe a quantidade de entradas na secao: \n");
    scanf("%d", &tam);

    evento *eve = geraVector(tam);
    printf("Insira os IDs de entradas\n");

    for (i=0; i < tam;i++){
        scanf("%d", &chave);
        colocar(eve, chave);
    }

    printf("Aqui estão todos os IDs presentes no evento: \n");
    mostraTudo(eve);

return 0;
}


evento* geraVector(int tam){
	
	evento *eve = (evento*) malloc(sizeof(evento));
	
	if ((eve == NULL)  || (tam == 0)){
		return NULL;
	}
	eve -> idvector = (int*) malloc(sizeof(int)*tam);
	
	if (eve -> idvector == NULL){		
		return NULL;
	}	
		
	eve -> entradas = tam;
	printf("%d\n", eve -> entradas);
	eve -> atual = 0;
	return eve;

}

int colocar(evento* eve, int chave){
	    if ((eve == NULL) || (eve -> entradas < 0) ){
			return -1;
		}
		
		
			if ((eve-> idvector!= NULL) && (eve -> entradas >= eve-> atual)){
				eve-> idvector[eve-> atual] = chave;
				eve-> atual ++;
				
			}
		 return 1;

			
    }


void mostraTudo(evento* eve){
	int i;
	int id;

	if(eve == NULL){
		return;
	}
	
    for(i = 0; i < eve->entradas; i++){
		id = eve->idvector[i];
        printf("%d\n",id);
    }
return;
}
