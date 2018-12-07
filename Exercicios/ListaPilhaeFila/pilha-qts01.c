/*Use as operações push, pop, top e empty para construir operações que façam o
seguinte:
*
a. Definir i com o segundo elemento a partir do topo da pilha, deixando a pilha sem seus dois elementos superiores. ============================ ok
b. Definir i com o segundo elemento a partir do topo da pilha, deixando a pilha inalterada.	==================================================== ok
c. Dado um inteiro n, definir i como o enésimo elemento a partir do topo da pilha, deixando a pilha sem seus n elementos superiores. =========== ok
d. Dado um inteiro n, definir i como o enésimo elemento a partir do topo da pilha, deixando a pilha inalterada ================================= ok
e. Definir i como o último elemento da pilha, deixando a pilha vazia. ========================================================================== ok
f. Definir i como o último elemento da pilha, deixando a pilha inalterada.(Dica: use outra pilha auxiliar. ===================================== ok
g. Definir i como o terceiro elemento a partir do final da pilha.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _pilha_{
	int *stack;
	int topo;
	int tam;
}pilha;

pilha *criar(int tam);
bool empty(pilha *p);
void push(pilha *p, int x);
int pop(pilha *p);

int main(){
	int x, tam = 5, inteiro;	
	pilha *p = criar(tam);
	
	
	inteiro = 63;
	printf("PILHA ORIGINAL\n");
	/**
	//inserindo elementos na pilha
	for (int i=1; i<=tam; i++){
		x = i;
		push(p,x);	
	}	
	//retirando elementos da pilha
	for (int i=0; i<tam; i++){      
		x = pop(p);
		printf("%d ",x);
	}
	printf("\n\n");
	*/
	// letra a 
	
	for (int i=1; i<=tam; i++){
		x = i;
		push(p,x);
		if (i == tam-2){ ///quando i estiver na segunda posição a partir do topo
			x = pop(p); /// retiro o elemento que está na 2 pos
			push(p,inteiro); /// insiro meu elemento
			break;	         ///paro a inserção de elementos, perdendo dessa forma meus 2 elementos a partir do topo // letra a
		}
		
		//push(p,NULL);
	}
	
	//retirando elementos da pilha
	printf("Pilha: \n");
	for (int i=0; i<tam-2; i++){ // letra a
		x = pop(p);
		printf("%d ",x);
	}

	
	
	//letra b
	/**
	//inserindo elementos na pilha
	for (int i=1; i<=tam; i++){
		x = i;
		push(p,x);
		if (i == tam-2){ ///quando i estiver na segunda posição a partir do topo
			x = pop(p); /// retiro o elemento que está na 2 pos
			push(p,inteiro); /// insiro meu elemento
			/// letra b
			//break;	         ///paro a inserção de elementos, perdendo dessa forma meus 2 elementos a partir do topo // letra a
		}
		
		//push(p,NULL);
	}
	
	//retirando elementos da pilha
	printf("Pilha: \n");
	///for (int i=0; i<tam-2; i++){ // letra a
	for (int i=0; i<tam; i++){      // letra b
		x = pop(p);
		printf("%d ",x);
	}
	*/
	
	// letra c
	/**
	
	printf("Iforme a pos a partir do topo da pilha pra definir i: \n");
	scanf("%d",&n);
	
	//inserindo elementos na pilha
	for (int i=1; i<=tam; i++){
		x = i;
		push(p,x);
		if (i == tam-n){ ///quando i estiver na enesima posição a partir do topo
			x = pop(p); /// retiro o elemento que está na n+1 posicao	
			push(p,inteiro);/// insiro meu elemento
			/// letra c
			break;        ///paro a inserção de elementos, perdendo dessa forma meus n elementos a partir do topo // letra c				 
		}		
		
	}
	
	//retirando elementos da pilha
	printf("Pilha: \n");
	for (int i=0; i<tam-n; i++){ // letra c
		x = pop(p);
		printf("%d ",x);
	}
	*/
	///=============================
	// letra d
	/**
	printf("Iforme a pos a partir do topo da pilha pra definir i: \n");
	scanf("%d",&n);
	
	//inserindo elementos na pilha
	for (int i=1; i<=tam; i++){
		x = i;
		push(p,x);
		if (i == tam-n){ ///quando i estiver na enesima posição a partir do topo
			x = pop(p); /// retiro o elemento que está na n+1 posicao	
			push(p,inteiro);/// insiro meu elemento
		}
		
	}
	
	//retirando elementos da pilha
	printf("Pilha: \n");
	for (int i=0; i<tam; i++){      // letra d
		x = pop(p);
		printf("%d ",x);
	}
	*/
	
	// letras E e f	
	 
	 // letra e
	 /**
	//inserindo elementos na pilha
	for (int i=1; i<=tam; i++){
		x = i;
		push(p,x);
		if (i == 1){ ///quando i estiver na ultima posição a partir do topo (no caso da pilha, a primeira pos a ser inserida)
			x = pop(p); /// retiro o elemento que está na ultima posicao	
			push(p,inteiro);/// insiro meu elemento
			/// letra e
			//break;        ///paro a inserção de elementos, perdendo dessa forma todos os elementos da pilha// letra e			 
		}		
		
	}

	//retirando elementos da pilha
	printf("Pilha: \n"); 
	x = pop(p); 
	* 
	*/
	
	//letra f;
	/**
	 pilha *aux = criar(tam); 
	 
	 // inserindo elementos
	 for (int i=1; i<=tam; i++){
		 x = i;
		push(p,x); /// insere elementos na pilha principal		
		int valor = pop(p);
		push(aux,valor); /// retiro da principal e ponho na auxiliar
		
	 }	 
	 
	 for (int i=1; i<=tam; i++){		
		 int y = pop(aux); /// retirando da fila auxiliar
		 push(p,y);	       /// inserindo na principal
		  if (i == tam){		  
			push(p,inteiro); ///insiro elemento na ultima posição da principal
			}
		 int elm = pop(p); /// imprimindo principal
		 printf("%d ",elm);
	 } 		 
	
	*/
	// letra g
	/**
	//inserindo elementos na pilha
	for (int i=1; i<=tam; i++){
		x = i;
		push(p,x);
		if (i == tam-2){
			push(p,inteiro);
		}
	}
	
	//retirando elementos da pilha
	printf("Pilha: \n");
	for (int i=0; i<tam; i++){      // letra b
		x = pop(p);
		printf("%d ",x);
	}
	*/	
}

pilha *criar(int tam){
	pilha *p = (pilha*)malloc(sizeof(pilha));
	if ((p == NULL) || (tam < 0)) return NULL;
	
	p -> stack= (int*)malloc(sizeof(int));
	if (p->stack == NULL) return NULL;
	
	p -> topo = -1;
	p-> tam  = tam;
	return p;	
	
}

bool empty(pilha *p){
	if (p->topo == -1)
		return true;
	else if(p -> topo > p->tam)
		return false;
	
}

void push(pilha *p, int x){
	if ((p == NULL) || (p -> stack == NULL)) ;
	
	if (empty ){ // se a pilha estiver vazia
		p->stack[p->topo+1] = x;
		p ->topo ++;
	}
}

// letras a e b

int pop(pilha *p){
	if ((p == NULL) || (p -> stack == NULL)) return 0;
	int x;

	
	x = p->stack[p->topo]; 
	p->topo --;
	
	return x;
		
	
	
}


