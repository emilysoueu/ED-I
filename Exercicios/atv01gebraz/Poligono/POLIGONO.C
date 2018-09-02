#include <stdio.h>
#include <stdlib.h>
///#include "POLIGONO.h"

typedef struct _polig_{
	float **vecpoli; // vetor tad ---- vecpoli[x][y]
	float x;        // pos em x
	float y;       // pos em y
	int pos;      // indice do  vetor
	int size;    // tamanho do vetor
}poligono;

poligono *criarPolig(int size); // ok
int inserirPontos(poligono* pol, int x, int y); /// mais ou menos 
void printPoli(poligono* pol);
int tamanhoLados(poligono* pol);
void destroiPol(poligono *pol); // ok

int main(){
	
}

poligono *criarPolig(int size){
	if (size < 3){
		printf("numero de lados invalido!!\n"); // TRIANGULO MENOR POLIGONO
		return NULL;
	}	
	
	poligono *pol =(poligono*) malloc(sizeof(poligono)); // Inicializando ponteiro pol	
	if (pol == NULL){
		return NULL;
	}
	
	pol -> vecpoli =(float**) malloc(pol -> size * sizeof(float*)); // alocando linhas
	if (pol->vecpoli == NULL){
		printf("Erro ao alocar matriz(linhas)\n");
		return NULL;
	}
	for (int i=0; i< pol -> size; i++){ 
		pol -> vecpoli[i] = (float *) malloc(2 * sizeof(float)); // alocando colunas (@2 = 2 colunas x e y)
			if (pol -> vecpoli[i] == NULL){
				printf("Erro ao alocar matriz(colunas\n)");
				return 0;
			}
	   }		
}


int inserirPontos(poligono* pol, float px, float py){
// INSERIR PONTOS ORDENANDAMENTE ???
	int i,j;

	if (pol == NULL || (pol -> pos) < (pol -> size) ){
		return -1;
	}		
	 while((i < pol -> size)){		
		if (pol -> *vecpoli[pol -> x] == px){		
			pol -> *vecpoli[i][1] = px;
			pol -> *vecpoli[i][1] = py;
	     }else{
			 if(pol ->  *vecpoli[pol -> i] < px){
				 pol -> *vecpoli[pol -> i+=1] = px;
				 pol -> *vecpoli[pol -> i+=1] = py
;			 }else{
				pol -> vecpoli[i][1] = px;
				pol -> vecpoli[i][1] = py;	
			 }	
		 }	
	return 1;
	
}

void printPoli(poligono* pol){
	// mostrar pontos poligonos
}
int tamanhoLados(poligono* pol){
	// tamanho dos lados e perímetro do polígono
	
}

void destroiPol(poligono *pol){
	int i;
	
	if (pol == NULL || pol -> vecpoli == NULL){
		printf("Poligono destruido com sucesso!!\n");
		// pq não consigo retornar true
	}
	for (i=0; i< pol -> size; i++){
		free(pol -> vecpoli[i]);// desaloca colunas
	}
	free(pol -> vecpoli); // desaloca colunas
		
	free(pol);
	pol = NULL;
	printf("Poligono destruido com sucesso!!\n");	
	
	
}
