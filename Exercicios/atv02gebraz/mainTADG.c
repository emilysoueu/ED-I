// @emilysoueu
//12/09/2018

// 3) uma nova função de inserção que ao verificar que o QTD é maior do que o tamanho do vetor,
// faça uma busca dentro do vetor por algum elemento que foi removido (conforme questão 1) e insira esse elemento nessa posição.
 

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "TADg.c"
#include "tadg.h"

int compara(void *a, void *b){
	
	if(a == NULL) return 1; // change booa funfa
	
	int *a1 = (int*)a; 
	int *b1 = (int*)b;  
	
	if (*a1 > *b1) return 1;
	if (*a1 < *b1) return -1;
	
	return 0;	
}

void print(void *a){
	 int *a1 = (int*)a;
	
  
  if(a == NULL) return;  // qts 01
	
	printf("\n%d\n", *a1); 
}
void deletar(void *a){ // troquei o nome remover por deletar
	int *a1= (int *)a;
	
	free(a1);
	a1 = NULL;
	
	
	
}

int main(){
	int tam, menu;	
	sequencia *seq;	
	
	printf("Informe o tamanho da sua sequencia: ");
	scanf("%d", &tam);	
	//tam = 3;
	
	seq = criar(tam, compara, print, deletar);
	
	do{
		printf("====Menu====\n");
		printf("1 - Inserir Elemento\n");
		printf("2 - Buscar  Elemento\n");
		printf("3 - Listar  Elemento\n");
		printf("4 - Remover Elemento\n");
		printf("5 - Destruir  Sequencia\n");
		printf("6 - Sair do Programa\n");
		printf("Sua escolha: \n");
		scanf("%d", &menu);
			switch(menu){
				// inserir elemetos
				case 1:{
					
					for(int i=0; i<tam; i++){
						int *a =(int *)malloc(sizeof(int));	
						printf("Insira: \n");
						scanf("%d",&*a); // ?? certo					
						inserir(seq, (void *)a);  /// a partir de 5 começa a dar problema
					    }					
					}break;
				case 2:{
					int chave;
					
					printf("Informe o elemento de busca: ");
					scanf("%d", &chave);
					
					if (buscar(seq,(void*)&chave) >= 0){
							printf("achei \n");	
						}else{
							printf("nada \n");
						}					
					}break;
				case 3:{
					printf("Elementos da sequencias: \n");
					listar(seq);	
					
					}break;
				case 4:{
					int chave;
					
					printf("Informe elemento para remoção: ");
					scanf("%d", &chave);
					
					remover(seq, (void*)&chave);
					
					}break;
				case 5:{
					
					destruir(&seq);		
					
					printf("Sequencia destruida com sucesso: \n");
					
					}break;
				case 6:{
					exit(0);
					printf("Saindo do programa!!");					
					}break;
					
			}	
		
		
		}while(menu!= 0);	
}
