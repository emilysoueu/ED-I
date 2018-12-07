/**11. Seja uma seqüência de E's e D's que significam ações de empilhar e desempilhar,
respectivamente, elementos em/de uma certa pilha S, faça um algoritmo que verifique
uma seqüência qualquer e retorne OK ou NOK para o caso de seqüência bem formada
ou mal formada.
Exemplo: EEEEEDD (bem formada); EDEDEEDDDEEE (mal formada).
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

int main(){
	int max = 6;
	pilha *p = criar(max);
	int contE =0, contD=0;
	char c, word;
	
	for (int i = 0; i< max; i++){
		printf("IN: ");
		//c = getchar();
		scanf("%c\n", &c);
		printf("%c\n", c);		
		push(p,c);
	}
	for(int i = 0; i< max; i++){
		word= pop(p);
		if (word == 'E' ){
			contE ++;
		}else{
			contD ++;
		}
	}
	
	if (contE>=contD)
		printf("OK\n");
	else
		printf("NOK\n");
		
		// Ta pegando de 2 em 2, em c++ eu usaria algo como cin.ignore
		
}
