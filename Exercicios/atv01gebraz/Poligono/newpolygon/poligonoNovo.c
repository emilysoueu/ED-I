#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newpolygon.h"

poligono *criarPolig(int qtdpontos);
int inserirPontos(poligono* pol);
int imprimirPoligono(poligono *pol);
int tamanhoLados(poligono *pol);
int destruirPol(poligono *pol);

int main (){
	int menu;
	poligono *pol;
	int lados;
	
	printf("Informe o numero de Pontos do seu Poligono: ");
	scanf("%d", &lados);
	pol = criarPolig(lados);	
	
	do {
		
		printf("=====================Menu=======================\n");
		printf("[1] - Inserir Pontos no Poligono================\n");
		printf("[2] - Mostrar Poligono==========================\n");
		printf("[4] - Destruir Poligono=========================\n");
		printf("[5] - Sair do Programa==========================\n");
		printf("================================================\n");
		printf("Sua Escolha: ");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:{
				printf("Informe os pontos do seu poligono: \n");
				inserirPontos(pol);				
				}	
			break;
			case 2:{
				printf("Estes são os pontos do seu poligono: \n");
				imprimirPoligono(pol);				
				}	
			break;
			case 3:{
				destruirPol(pol);
				printf("Seu poligono foi destruido com sucesso !!\n");
				}	
			break;
			default:
				exit (1);
		}
	}while(menu > 0 && menu < 4);
}

poligono *criarPolig(int lados){
	   int i, j=2;
	   poligono *pol = (poligono*) malloc(sizeof(poligono));
		   if (pol == NULL){
			   return NULL;
		   }
		pol -> qtdPontos = lados;
	    printf("%d\n", pol -> qtdPontos);

	   pol -> vecpoli = (int**) malloc(sizeof(int*)* pol -> qtdPontos);
		if ((pol -> vecpoli == NULL) ||  (pol -> qtdPontos < 3)){
			return NULL;
		}
		for (i=0; i<pol -> qtdPontos; i++){
			pol ->vecpoli[i] = (int*) malloc(sizeof(int)*j);
			if (pol -> vecpoli[i] == NULL){
				return NULL;
			}
		}
		 pol -> atual = -1;
		
		printf("ok\n\n");
		return pol;   
   }
   int inserirPontos(poligono* pol){
	   int i;
	   int x,y;
	   
	   if ((pol == NULL) || (pol -> vecpoli == NULL) || (pol -> qtdPontos < 3)){
		   return FALSE;		   
	   }
	   
	   
	   for (i=0; i < pol -> qtdPontos; i++){
		   printf("Informe a posição x e y do seu ponto: \n");
		   scanf ("%d", &x);
		   scanf ("%d", &y);
		   pol -> vecpoli[i][0] = x;
		   pol -> vecpoli[i][1] = y;		    
	   }  
	   
	   return TRUE;  
	   
   }
   
   int imprimirPoligono(poligono *pol){
	   if ( (pol == NULL) || ( pol -> vecpoli == NULL) || (pol -> qtdPontos < 3) ){
		   return FALSE;
	   }
	   	
	   int i;
	   printf("Este sao os pontos do seu poligono: \n");  
	   printf("X  -  Y\n"); 
	   for (i=0; i< pol -> qtdPontos; i++){		    
		   printf("\n%d  -  %d\n", pol -> vecpoli[i][0], pol -> vecpoli[i][1]);		   
	   }
	   
	   return TRUE;
	   
   }
   
 int tamanhoLados(poligono *pol){
	 if ( (pol == NULL) || (pol -> vecpoli == NULL) || (pol -> qtdPontos < 3) ){
		 return FALSE;
	 }
	 // FALTA TERMINAR	
	 return TRUE; 
 }
 
int destruirPol(poligono *pol){
	if ( (pol == NULL) && (pol -> vecpoli == NULL) && (pol -> qtdPontos < 3) ){
		return FALSE;
	}
	int i;
	
	for (i=0; i<pol -> qtdPontos; i++){
		free (pol -> vecpoli[i]); 		
	}
	free(pol -> vecpoli);
	pol -> vecpoli = NULL;
	pol = NULL;
	
	
	return TRUE;
}


