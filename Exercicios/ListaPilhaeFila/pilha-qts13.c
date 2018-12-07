/** 13.Elabore um método para manter duas pilhas dentro de um único vetor linear
$[spacesize] de modo que nenhuma das pilhas incorra em estouro até que toda a
memória seja usada, e uma pilha inteira nunca seja deslocada para outro local dentro
do vetor. Escreva rotinas em C, push1, push2, pop1 e pop2, para manipular as duas
pilhas. (Dica: as duas pilhas crescem na direção da outra.)
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct _duplaP_{
	int *stack;
	int topo1;
	int topo2;
	int qtd1;
	int qtd2;
	int max1;
	int max2;
}pilha;

pilha *criar(int max){
	pilha *p = (pilha*)malloc(sizeof(pilha));
	if ((p == NULL) || (max<=0)) return NULL;
	
	p -> stack= (int*)malloc(sizeof(int));
	if ((p == NULL)||(p->stack == NULL)) return NULL;
	
	p -> topo1 = -1;
	p -> topo2 = max-1;
	p -> qtd1 = 0;
	p -> qtd2 = 0;
	p -> max1 = max/2;
	p -> max2 = max;

	
	return p;
}

// pilha que cresce pra direita
void push1(pilha *p, int valor){
	if ((p == NULL)||(p->stack == NULL)) printf("ERoo de alocação");
	
	p -> topo1 ++;
	p -> stack[p->topo1] = valor;
	p -> qtd1 ++;
	
	if (p -> qtd1 == p -> max1){
		printf("Pilha 1 cheia!!\n");
	}
}

// pilha que cresce pra esquerda
void push2(pilha *p, int valor){
	if ((p == NULL)||(p->stack == NULL)) printf("ERoo de alocação");
	
	p -> topo2 --;
	p -> stack[p->topo2] = valor;
	p -> qtd2 ++;	
	
	if (p -> qtd2 == p -> max2-1){
		printf("Pilha 2 cheia!!\n");
	}
}

// pilha que diminui pra esquerda
// problemas aqui
int pop1(pilha *p){
	if ((p == NULL)||(p->stack == NULL)) return -1;
	
	int x;
	x = p -> stack[p->topo1];
	p -> topo1 --;
	p -> qtd1 --;
	
	return x;
}



// pilha que diminui pra direita
int pop2(pilha *p){
	if ((p == NULL)||(p->stack == NULL)) return -1;
	
	int x;
	x = p -> stack[p->topo2];
	p -> topo2 ++;
	p -> qtd2 --;
	
	return x;
}


int main(){
	int max = 4, x;
	pilha *p = criar(max);
	
	// inserindo na pilha 1
	push1(p,1);
	///printf("ok 1\n");
	push1(p,2);
	///printf("ok 1\n");
	
	// inserindo na pilha 2
	push2(p,3);
	///printf("ok 2\n");
	push2(p,4);
	///printf("ok 2\n");
	
	printf("Pilha 1\n");
	x=pop1(p);	
	printf("%d\n", x);
	x=pop1(p);
	printf("%d\n", x);
	printf("Pilha 2\n");
	x=pop2(p);
	printf("%d\n", x);
	x=pop2(p);
	printf("%d\n", x);
	
	// problemas no pop1 ele engole o 2
	
	
}
