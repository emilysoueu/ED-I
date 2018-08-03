/** calculadora simples usando postfix, para treinar conhecimentosd e pilha(stack)
/  insira: operando - enter - operando - enter - operador.
/ @emilysoueu
/ 03 -08 - 2018
*/
#include <stdio.h>
#include <stdlib.h>

#define max 100

int *p; /// apontara para uma região da memóra livre
int *tos; /// apontara para o topo da pilha
int *bos; /// apontara para o final da pilha

void push(int i);
int pop(void);

void main (){
	int a,b;
	char s[80];

	p = (int*) malloc(sizeof(int)); /// obtem a memoria da pilha
	if (!p){
		printf("Falha de alocacao.\n");
		exit(1);
	}
	tos = p;
	bos = p+max-1;

	printf("Calculadora de Quatro funcoes!!\n");
	printf("Digite s pra sair.\n");

	do{
		printf(": \n");
		gets(s);
		switch(*s){
			case '+':
				a = pop();
				b = pop();
				printf("%d\n", a+b);
				push(a+b);

			break;
			case '-':
			    a = pop();
				b = pop();
				printf("%d\n", a-b);
				push(b-a);

			break;
			case '*':
				a = pop();
				b = pop();
				printf("%d\n", b*a);
				push(a*b);
			break;
			case '/':
				a = pop();
				b = pop();
				printf("%d\n", b/a);
				push(b/a);
			break;
			case '.': /// mostra o conteuo do topo da pilha
				a = pop();
				push(a);
				printf("O valor atul da pilha eh: %d\n",a);

			break;
			default:
				push(atoi(s));
		}

	}while(*s != 's');

}

/*Põe um elemento na pilha*/
void push(int i){
	if(p>bos){
		printf("Stack is Overflow\n");
		return;
		}
	*p = i;
	 p++;
}

/*Retira um elemento da pilha*/
pop (void){
	p--;
	if(p<tos){
		printf("Pilha is Underflow\n");
		return 0;
	}
	return *p;

}
