/*Escreva um algoritmo para determinar se uma string de caracteres de entrada é da
forma: a D b D c D...D z onde cada string, a, 6, ..., z, é da forma da string definida no
Exercício 3 (Por conseguinte, uma string estará no formato correto se consistir em
qualquer número de strings desse tipo, separadas pelo caractere 'D'.) Em cada ponto,
você só poderá ler o próximo caractere da string.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct _pilha_{
	char *palavra;
	int fim;
	int qtd;
	int max;
}pilha;

pilha *criar(int tam){
	pilha *p = (pilha*)malloc(sizeof(pilha));
	if (p == NULL) return NULL;
	
	p -> palavra = (char*)malloc(sizeof(char)*tam);
	if (p->palavra == NULL)  return NULL;
	
	p->fim =0;
	p->qtd =0;
	p->max = tam;
	
	return p;	
}


void push(pilha *p, char c){
	p->palavra[p->fim] = c;
	p->fim ++;
	p->qtd ++;
}

char pop(pilha *p){
	char c;
	c = p -> palavra[p->fim];
	p -> fim --;
	p -> qtd --;
	
	return c;	
}


int main(){
	int max = 3;
	pilha *p = criar(max);
	int i,d;
	char c;
	
	push(p,'a');
	push(p,'D');
	push(p,'a');
	
	for(i=0; i<max; i++){
		c = pop(p);
		if (i%2 != 0){
			if (c == 'D'){ // nas posições impares		
				d = 0;
			}else{
				d=1;
				break;
		 }				
	   }		
	}
	
	if (d == 0) 
		printf("Entrada Valida\n");
	else
		printf("Entrada Nao Valida\n");
}



