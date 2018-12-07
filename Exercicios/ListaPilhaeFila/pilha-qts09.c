/**
 9. Implemente uma pilha dupla, assim chamada por manter duas pilhas (dois topos)
compartilhando um mesmo vetor, com economia de memória. Uma pilha dupla
possui, dois push ́s, dois pop ́s e assim por diante
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _pilha_{
	int *stack;
	int top1;
	int top2;
	int qtd1;
	int qtd2;
	int max;
}pilha;

pilha *criar(int max){
	pilha *p = (pilha*)malloc(sizeof(pilha));
	if ((p == NULL) || (max <=0)) return NULL;
	
	p -> stack =(int*)malloc(sizeof(int));
	if ((p== NULL) || p -> stack == NULL) return NULL;
	
	p -> top1 = 0;
	p -> top2 = 1;
	p -> qtd1 = 0;
	p -> qtd2 = 0;
	p -> max = max;
	
	return p;
}

void push1(pilha *p, int valor){
	
	p -> stack[p->top1++] = valor;
	p -> top1 ++;		
	p -> qtd1 ++;
}

void push2(pilha *p, int valor){
	
	p -> stack[p->top2++] = valor;
	p -> top2 ++;	
	p -> qtd2 ++;
}

int pop1(pilha *p){
	int x;
	p -> top1 --;
	p -> top1 --;
	x = p -> stack[p->top1];
	//p -> top1 --;
	//p -> qtd1 --;
	
	return x;
	
}

int pop2(pilha *p){
	int x;
	p -> top2 --;
	p -> top2 --;
	x = p -> stack[p->top2];
	//p -> top2 --;
	p -> qtd2 --;
	
	return x;
}

int main(){
	int max = 6, x;
	pilha *p = criar(max);
	
	push1(p,1);
	push1(p,2);
	push1(p,3);
	
	push2(p,4);
	push2(p,5);
	push2(p,6);
	
	printf("PILHA 1: \n");
	///x = pop1(p);
	///printf("ok %d \n", x);
	x = pop1(p);
	printf("ok %d \n", x);
	x = pop1(p);
	printf("ok %d \n", x);
	x = pop1(p);
	printf("ok %d \n", x);
	
	printf("\n\n ");
	printf("PILHA 2: \n");	
	///printf("ok %d \n", x);
	x = pop2(p);
	printf("ok %d \n", x);
	x = pop2(p);
	printf("ok %d \n", x);
	x = pop2(p);
	printf("ok %d \n", x);
	
	// pq eu tenho que fazer 4 pops pra remover todos os elementos se eu fiz só 3 pushs??
	
}


