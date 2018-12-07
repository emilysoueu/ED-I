/*Escreva um algoritmo para determinar se uma string de caracteres de entrada é da
forma: xCy, onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso de x
(isto é, se x = "ABABBA", y deve equivaler a "ABBABA"). Em cada ponto, você só
poderá ler o próximo caractere da string.*/
#include <stdio.h>
#include <stdlib.h>


typedef struct _stack_{
	char *palavra;
	int fim;
	int qtd;
	int max;
}pilha;

typedef struct _fila_{
	char *palavra;
	int fim;
	int inicio;
	int qtd;
	int max;
}fila;

pilha *criar(int tam){
	pilha *p = (pilha*)malloc(sizeof(pilha));
	if (p == NULL || tam <= 0) return NULL;
	
	p -> palavra = (char*)malloc(sizeof(char)*tam);
	if (p -> palavra == NULL) return NULL;
	
	p -> fim = -1;
	p -> qtd = 0;
	p -> max = tam;
	
	return p;
	
}

void push(pilha *p, char letra){
	if (p == NULL ||p -> palavra == NULL) return ;
	
	p -> fim ++;
	p -> palavra[p->fim] = letra;	
	p -> qtd ++;
}


char pop (pilha *A){
	char c = A -> palavra[A -> fim];
		A -> fim --;
		A -> qtd --;	
	return c;	
}

fila *criar_fila(int tam){
	fila *f = (fila *)malloc(sizeof(fila));
	if (f == NULL || tam <= 0) return NULL;
	
	f -> palavra = (char*)malloc(sizeof(char)*tam);
	if (f -> palavra == NULL) return NULL;
	
	f -> fim = 0;
	f -> qtd = 0;
	f -> max = tam;
	f -> inicio = 0;
	
	return f;
	
}

void push_fila(pilha *p, char letra){
	if (p == NULL ||p -> palavra == NULL) return ;
	
	p -> palavra[p->fim] = letra;
	p -> fim ++;	
	
}


char pop_fila (fila *B){
	char c = B-> palavra[B -> inicio];
		B -> inicio++;
		B -> qtd --;	
	return c;
	
}


int main(){
	int max = 3;
	pilha *A = criar(max);
	fila  *B = criar_fila(max);
	int igual[3];
	char a,b;
	int ok ;
	
	
	push(A,'a');
	push(A,'b');
	push(A,'c');
	push_fila(B,'c');
	push_fila(B,'b');
	push_fila(B,'a');
	
		
		
	for (int i=0; i<max; i++){
		a = pop(A);
		printf("A - %c\n",a);
		b = pop_fila(B);
		printf("B  - %c\n",b);
		if ( a == b ){
			printf("estive aqui\n");					
			igual[i] = 	0;
		}else{
			igual[i] = 	1;
		}	
	}

		
	
	for (int i =0; i< max; i++){
		printf("%d ", igual[i]);
	}
	
	
	for (int i=0; i<max; i++){
		if ( igual[i]> 0){
			ok = 1;	
			break;
		}else{
			ok = 0;
		}			
	}
	
	if (ok == 0)
		printf("Entrava Valida");
	else
		printf("Entrava Nao Valida");	
	
	
}
