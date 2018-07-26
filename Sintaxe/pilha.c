#include <stdio.h>
#include <stdlib.h>
#define size 5

void push (int i);
int pop ();

int *tos, *p1, stack[size];

void main(){
	int value;
	tos = stack; /* Faz tos conter o topo da pilha*/
	p1 = stack; /*Inicializa p1*/

	do{
		printf(" Digite o valor: \n");
		scanf ("%d", &value);
			if (value != 0){
				push(value);
			}else{
				printf("Valor do Topo eh %d\n", pop() );
			}
	}while(value != -1);


}

void push(int i){
	p1++;
	if (p1 == (tos + size)){
		printf("Estouro da pilha\n");
		exit(1);
	}
	*p1 = i;
}

pop(){
	if (p1 == tos){
		printf("Estouro da pilha\n");
		exit(1);
	}
	p1 --;
	return *(p1 + 1);
}
