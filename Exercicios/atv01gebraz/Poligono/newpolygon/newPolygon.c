#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "newpolygon.h"



poligono *criarPolig(int qtdpontos);
int inserirPontos(poligono* pol);

int main(){
	int opcao;
	poligono *pol;
	int tam;
				
				printf("Informe o tamanho de lados do seu poligono: \n");
				scanf("%d", &tam);	
				pol  = criarPolig(tam);
	
	do {
		printf("=====================Menu=======================\n");
		printf("[1] - Inserir POntos no Poligono================\n");
		printf("[2] - Mostrar Poligono==========================\n");
		printf("[3] - Descobrir o tamanho dos lados do Poligono=\n");
		printf("[4] - Destruir Poligono=========================\n");
		printf("[5] - Sair do Programa==========================\n");
		printf("================================================\n");
		printf("Sua Escolha: ");
		scanf("%d", &opcao);	
		
		switch(opcao){
			// preencher TAD int inserirPontos(poligono* pol, int x, int y); 
			case 1:{
				
				}	
			break;
			//Imprimir TAD float printPoli(poligono* pol); 
			case 2:{

				printPoli(pol);				
			}
			break;
			/*
			case 3:{ // tamanho dos lado e perimetro int tamanhoLados(poligono* pol); 
				tamanhoLados(pol);
			}
			break;
			case 4:{ // void destroiPol(poligono *pol); 
				printf("Destruindo Seu Poligono!!\n");
				destroiPol(pol);
				
			}
			break;
			case 5:{
				printf("Saindo do Programa!!\n");
				exit (0);
			}
			*/
			break;
			default:
				printf("Opcao Invalida!!\n");
				exit(1);
			
		}
			
	}while (opcao > 0 && opcao < 6);
	
	
}

poligono *criarPolig(int qtdpontos){
	   int i, j=2;
	   
	   poligono pol = (poligono*)malloc(sizeof(poligono));
		   if (pol == NULL){
			   return NULL;
		   }
	   pol -> vecpoli = (int**)malloc(sizeof(int*)*qtdPontos);
		if ((pol -> vecpoli == NULL) ||  (qtdPontos < 3)){
			return NULL;
		}
		for (i=0; i<qtdPontos; i++){
			pol ->vecpoli[i] = (int*)malloc(sizeof(int)*j);
			if (pol -> vecpoli[i] == NULL){
				return NULL;
			}
		}
		 pol -> atual = -1;
		
		return pol;   
   }
   int inserirPontos(poligono* pol){
	   int i;
	   int x,y;
	   
	   if ((pol == NULL) || (pol -> vecpoli == NULL) || (pol -> qtdPontos < 3)){
		   return FALSE;		   
	   }
	   
	   /
	   for (i=0; i < pol -> qtdPontos; i++){
		   printf("Informe a posição x e y do seu ponto: ");
		   scanf ("%d", &x);
		   scanf ("%d", &y);
		   pol -> vecpoli[i][0] = x;
		   pol -> vecpoli[i][1] = y;		    
	   }  
	   
	   return TRUE;  
	   
   }
   
   int imprimirPoligono(poligono *pol){
	   if (pol == NULL) || ( pol -> vecpoli == NULL) || (pol -> qtdPontos < 3){
		   return FALSE;
	   }	
	   int i;
	   printf("Este sao os pontos do seu poligono: \n");   
	   for (i=0; i< qtdPontos; i++){
		    printf("X  -  Y");
		   printf("%d  -  %d\n", pol -> vecpoli[i][0], pol -> vecpoli[i][1]);		   
	   }
	   
	   return TRUE;
	   
   }
   


/*
int tamanhoLados(poligono* pol){
	float lado; 
	float per = 0; 
	
	if (pol == NULL){
		printf ("Erro !!\n");
		return 1;
	}
	
	int i, lin = pol -> size;
	for ( i=0; i< lin; i++, pol -> size++){
		//lado = poligo[x][] - poligono [x+1][]  
		lado = pol -> vecpoli[i][0] - pol -> vecpoli[i+1][0];
			if (pol -> vecpoli[i][0] == pol ->vecpoli[pol -> size-1][0]){
				lado = pol -> vecpoli[i][0] - pol -> vecpoli[0][0];
			}
	
			printf("Lado%d: %f\n", i+1, lado);
			per += fabs(lado);			
	}
	
	printf("O perimetro do poligono eh = %f m.\n", per);
	return 0;
	
}

void destroiPol(poligono *pol){
	int i;
	
	if (pol == NULL || pol -> vecpoli == NULL){
		printf("Poligono destruido com sucesso!!\n");
	}
	for (i=0; i< pol -> size; i++){
		free(pol -> vecpoli[i]);// desaloca colunas
	}
	free(pol -> vecpoli); // desaloca linhas
		
	free(pol);
	pol = NULL;
	printf("Poligono destruido com sucesso!!\n");	
	
	
}
*/
