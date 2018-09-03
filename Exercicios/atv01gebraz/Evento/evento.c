#include <stdlib.h>
#include <stdio.h>
//#include <evento.h>


typedef struct _evento_{
	int *idvector;
	int entradas;
	int atual;
} evento;

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


evento* geraVector(int entradas){

	if (entradas < 0){
		return NULL;
	}
	//evento* eve;
	evento *eve = (evento*) malloc(sizeof(evento));
	///eve = (evento*)calloc(1,sizeof(evento));

	if (eve == NULL){
		return NULL;
	}
	///eve -> entradas = (int*) malloc(sizeof(int));
	eve -> idvector = (int*) malloc(sizeof(int));

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
	    if ((eve == NULL) || eve -> entradas < 0){
			return -1;
		}
		
		eve -> atual = 0;
		
			if ((eve-> idvector!= NULL) && (eve -> entradas > eve-> atual)){
				eve-> idvector[eve-> atual] = chave;
				eve-> atual ++;
				return 1;

			}
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
