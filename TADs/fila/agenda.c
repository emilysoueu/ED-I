// @emilysoueu
// exemplo simples de fila (queue)
//30.07.2018


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char *p[MAX], *qretrieve();
int spos = 0;
int rpos = 0;
void enter(), qstore(char *q), review(), delete();

void main(){
	char s[80];
	register int t;

	for(t=0; t<MAX; t++){
		p[t] = NULL;
		/** inicializa a matriz com nulos */
	}

	for (;;){
		printf("Inserir, Listar, Remover, Sair\n");
		gets(s);
		*s = toupper(*s);

		switch(*s){
			case 'E':
				enter();
			break;
			case'L':
				review();
			break;
			case 'R':
				delete();
			break;
			case 'Q':
				exit(0);
		}// close switch
	}// close for
}// close main

///Insere um evento na fila
void enter(){
	char s[256], *p;

	do{
		printf("Insira um evento %d: ", spos +1 );
		gets(s);
		if(*s == 0)  break; ///nenhuma entrada

		p = malloc(strlen(s)+1);

			if (!p){
				printf("Sem memoria\n");
				return;
			}

		strcpy(p, s);

			if(*s) qstore(p);

	}while(*s);
}// close function

///ve o que ha na fila

void review(){
	register int t;

	for(t = rpos; t<spos; t++){
		printf("%d. %s\n", t+1, p[t] );
	}
}

/// apaga um evento na fila

void delete(){
	char *p;

	if ((p = qretrieve()) == NULL)
		return;
	printf("%s\n", p );
}

/// Armazena um evento

void qstore(char *q){

	if (spos == MAX){
		printf("Lista cheia\n");
		return;
	}

	p[spos] = q;
	spos ++;
}

/// recupera um evento

char *qretrieve(){
	if (rpos == spos){
		printf("Sem eventos\n");
		return NULL;
	}
	rpos ++;
	return p[rpos-1];
}
