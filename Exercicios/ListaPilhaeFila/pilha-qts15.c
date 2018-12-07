/**15.Escreva a função BUSCA_E_REMOVE(pilha p, valor v) que buscar o valor v numa
pilha p e remove esse elemento da pilha usando apenas as operações de pop e push.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct _pilha_{
	char *stack;
	int topo;
	int qtd;
	int max;
	
}pilha;


pilha *criar(int max){
	pilha *p = (pilha*)malloc(sizeof(pilha));
	if ((p == NULL) || (max <= 0)) return NULL;
	
	p -> stack = (char*)malloc(sizeof(char));
	if (p->stack == NULL) return NULL;
	
	p-> topo = -1;
	p-> qtd = 0;
	p-> max = max;
	
	return p;
}

void push(pilha *p, char word){
	p -> topo ++;
	p -> stack[p->topo] = word;
	p -> qtd++;
}

char pop(pilha *p){
	if ((p==NULL) || (p->stack == NULL)) printf("nao alocado\n");
	char c;
	c = p -> stack[p->topo];
	p -> topo --;
	p -> qtd --;
	
	return c;
}

// posso usar uma pilha auxiliar?

int BUSCA_E_REMOVE(pilha *p, int v){
	int x;	
	int tam = p -> max;
	pilha *temp = criar(tam); //paux
	
	
	
	for(int i = 0; i< p -> max; i++){
		x = pop(p); // retiro da pilha principal
		if (x != v){ // caso n seja o valor que estou procurando
			push(temp,x); // insiro na pilha auxiliar
		}
		
		push(p,pop(temp)); // reinsiro na pilha principal
	}
}

int main(){
	int max = 3,x, valor;
	pilha *p = criar(max);
	
	for(int i =0; i< max; i++){
		x = i;
		push(p,x);
	}
	
	printf("Pilha original: \n");
	for(int i =0; i< max; i++){
		x = pop(p);
		printf("%d ",x);
	}
	
	for(int i =0; i< max; i++){
		x = i;
		push(p,x);
	}
	
	printf("Insira o valor de Busca: \n");
	scanf("%d ", &valor);
	
	BUSCA_E_REMOVE(p,valor);
	
	printf("Pilha apos remocao: \n");
	for(int i =0; i< max-1; i++){
		x = pop(p);
		printf("%d ",x);
	}
	
	// problemas ele removeu o errado
	// com 2 funciona
	
	
}
