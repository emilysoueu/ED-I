///Implemente uma fila usando duas pilhas.//

#include <stdio.h>
#include <stdlib.h>

typedef struct _pilha_{
	int *stack;
	int topo;
	int max;
	int qtd;
}pilha;

pilha *criar(int max){
	pilha *p = (pilha*)malloc(sizeof(pilha));
	if ((p == NULL) || (max <=0)) return NULL;
	
	p -> stack = (int*)malloc(sizeof(int)*max);
	if (p -> stack == NULL) return NULL;
	
	p -> topo = 0;
	p -> qtd = 0;
	p -> max = max;
	
	return p;
}

void push(pilha *p, int x){
	// aqui eu tive q ue incrementar depois; agora pronto
	//p -> topo ++;
	p -> stack[p->topo] = x;
	p -> topo ++;
	p -> qtd ++;
}

int pop(pilha *p){
	if ((p == NULL) || (p->stack == NULL)) return -1;
	
	int x;
	//p -> topo --;
	x = p->stack[p->topo];
	p -> topo --;
	p -> qtd --;
	
	return x;	
}

int main(){
	int max = 10;
	pilha *p1 = criar(max); // pilha 1
	pilha *p2 = criar(max); //pilha 2
	int i,cont = 0,x;
	
	/// pra eliminar os elementos da pilha 1 eu preciso mandar todo mundo pra pilha 2
	/// ultimo elemento da p1 apartir do topo, elimmina e insere todo mundo de novo
	
	
	for (i =1; i<=max; i++){
		x = i;
		push(p1,x); // inserindo elementos na pilha
	}
	

	// removendo elementos da pilha 1
	printf("PILHA\n");
	//int tam = max;
	int tam = max; ///alterei
	int k = 1;
	do{
		push(p2,pop(p1)); // inserindo a saida de p1 em p2
		cont++;           // incrmenta o contador de inserções em pilha 2
		if (cont == tam-k){ // se a quantidade das minhas inserções for igual a qutd de elemtos anteriores ao que eu vou retirar de p1
			//printf("entrou\n");			
			x = pop(p1); // retiro o primeiro elemento da minha pilha (ultimo a partir do topo)
			printf("%d\n", x);
			cont = 0;	  // zero o contador de inserções em pilha 2
			for (i =1; i<=tam-k; i++){
				push(p1,pop(p2)); //
			}	
			k++;		
		}
					
			
		
	}while(p1 -> qtd >= 0);
	
	
	
	
	
	
	
	
	
	
	
	
	
}

