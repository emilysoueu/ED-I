#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _evento_{
	int *idvector;
	int entradas;
	int atual;
} evento;

evento* geraVector(int entradas); // ok
int mostraTudo(evento* eve, int entradas); 
int colocar(evento* eve, int chave); // ok

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
    mostraTudo(eve, tam); 
    
   
   
    
    
}


evento* geraVector(int entradas){
	
	if (entradas < 0){
		return NULL;
	}
	evento* eve;
	//evento* eve = (evento*) malloc(sizeof(evento));
	eve = (evento*)calloc(1,sizeof(evento));

	if (eve == NULL){
		return NULL;
	}
	//eve -> entradas = (int*)malloc(sizeof(int*)*entradas);
	eve -> idvector = (int*)calloc(entradas,sizeof(int*));
	
	if (eve -> entradas == NULL){
		free(eve);
		eve = NULL;
		return NULL;
	}
	
	eve -> entradas = entradas;
	eve -> atual = 0;
	return eve;
	
} 

int colocar(evento* eve, int chave){
	    if (eve != NULL){
			if ((eve-> idvector!= NULL) && (eve -> entradas > eve-> atual)){
				eve-> idvector[eve-> atual] = chave;
				eve-> atual ++;
				return 1;

			}
    }

    return 0;
    	
  
}

int mostraTudo(evento* eve, int entradas){
	int res;
	
	if(eve == NULL){
		return -1;
	}
		res = eve -> idvector[eve -> atual];
		eve -> atual ++;
		return res;
			
}

// ERRO NÃO CONSIGO IMPRIMIR O VETOR TAD
	

	



