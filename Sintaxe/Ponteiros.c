// Revisão LP - ED - UFMA
// @emilysoueu
//24/07/2018

/* A função putstr() - escreve uma string no dispositivo de saida padrao
*/

// Indexa s como uma matriz

void puts(char *s){
	register int t;
	for (t=0; s[t]; t++)
		putchar(s[t]);
}

// Acessa s como um ponteiro

void putstr(char *s){
	while(char *s)
		putchar(*s++);
}

//================================================>

// múltipla indireção

int valor;  // variavel que possui um valor
int *pValor; // ponteiro para variavel valor;
int **pPtrValor; // ponteiro para o ponteiro da variavel valor;

pValor = &valor;

pPtrValor = &pValor;

printf("%d\n", **pPtrValor ); // imprime VALOR;

//================================================>
// Iniciaização de pteiros

/*Procura um nome*/

search(char *p[], char *name){
	register int t;

	for (t=0; p[t]; t++){
		if (!strcmp(p[t], name))
			return t;
	}

	return -1; /*não encontrado*/
}

//--------------------------------------------->

#include <stdio.h>
#include <string.h>

char *p = "alo mundo";

void main(void){
	register int t;

	// imprime o conteudo da string de tras pra frente
	printf(p);
	for (t = strlen(p) - 1; t>-1; t--)
		printf("%c", p[t]);
}
