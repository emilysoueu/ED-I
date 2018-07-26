#include <stdio.h>

#define MAX 100
#define LEN 80

char text[MAX][LEN];

/*UM EDITOR DE TEXTO MUITO SIMPLES*/

 void main(){
 	register int t, i, j;

 	printf("Digite uma linha vazia para sair: \n");

 	for (t=0; t<max; t++){
 		printf("%d: \n", t );
 		gets(text[t]);
 			if (!*text[t]){
 				break;
 			}
 	}

 	for (i=0; i<t; i++){
 		putchar(text[i][j]);
 	putchar('\n');
 	}
 }