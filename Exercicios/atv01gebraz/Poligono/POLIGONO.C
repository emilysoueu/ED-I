#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "POLIGONO.h"



poligono* criarPolig(int size);   
int inserirPontos(poligono *pol, float x, float y); 
float printPoli(poligono *pol); 
int tamanhoLados(poligono *pol); 
void destroiPol(poligono *pol); 

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
				int i;
				float x,y;
				for (i=0; i< tam; i++){
					printf("Insira a coordenada x: \n");
					scanf("%f", &x);
					printf("Insira a coordenada y: \n");
					scanf("%f", &y);
					inserirPontos(pol,x,y);						
					}					
				}	
			break;
			//Imprimir TAD float printPoli(poligono* pol); 
			case 2:{
				printf("Estes sao os pontos que compoe seu poligono: \n");
				printPoli(pol);				
			}
			break;
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
			break;
			default:
				printf("Opcao Invalida!!\n");
				exit(1);
			
		}
			
	}while (opcao > 0 && opcao < 6);
	
	
}

poligono *criarPolig(int linhas){ // linhas = quantidade de linhas
	if (linhas < 3){
		printf("numero de lados invalido!!\n"); // TRIANGULO MENOR POLIGONO
		return NULL;
	}	
	
	poligono *pol =(poligono*) malloc(sizeof(poligono)); // Inicializando ponteiro pol	
	if (pol == NULL){
		return NULL;
	}
	 pol -> size = linhas ;
	
	pol -> vecpoli =(float**) malloc(linhas * sizeof(float*)); // alocando linhas
	if (pol->vecpoli == NULL){
		printf("Erro ao alocar matriz(linhas)\n");
		return NULL;
	}
	for (int i=0; i < linhas; i++){ 
		pol -> vecpoli[i] = (float *) malloc(2 * sizeof(float)); // alocando colunas (@2 = 2 colunas x e y)
			if (pol -> vecpoli[i] == NULL){
				printf("Erro ao alocar matriz(colunas\n)");
				return 0;
			}
	   }
	   printf("Poligono criado com sucesso!!\n");
	   return pol;		
}


int inserirPontos(poligono *pol, float px, float py){
	int i,lin;
	
	if ((pol == NULL ) || pol -> size < 3){
		return -1;
	}	

	lin = pol -> size;
	pol -> size = 0;
	i = 0 ;
	

	while (pol -> size < lin){		
		if (pol -> vecpoli[pol -> size][i] == px){		
			pol -> vecpoli[pol -> size][i] = px;
			pol -> vecpoli[i][1] = py;			
	     }else{
			 if(pol ->  vecpoli[pol -> size][i] < px){
				 pol -> vecpoli[pol -> size+=1][i] = px;
				 pol -> vecpoli[i][pol -> size+=1] = py;							 
;			 }else{
				pol -> vecpoli[pol -> size][i] = px;
				pol -> vecpoli[i][pol -> size] = py;
								
			 }	
		 }	
		 i++;
		 pol -> size ++;
	}
	return 1;
	
}

float printPoli(poligono* pol){
	
	 int i,lin;
	 float a,b;
	 if ((pol == NULL) || (pol -> size < 3)){
		 return 0;
	}
	lin = pol -> size;
	pol -> size = 0;
		
		for (i=0; i< lin; i++){
			a = pol -> vecpoli[pol -> size][i];
			printf("X%d = %f ,",i,a);
			b = pol -> vecpoli[i][pol -> size];
			printf("Y%d = %f \n",i,b);
		}
		return 1;		 
	 
}

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
