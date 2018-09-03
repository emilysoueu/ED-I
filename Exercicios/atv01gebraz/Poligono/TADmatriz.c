#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


typedef struct matriz{
	int linhas;
	int colunas;
	double **matriz;
}Matriz;


Matriz* novaMatriz(int lin, int col){
	int i;
	Matriz *m = (Matriz*)malloc(sizeof(Matriz*));//aloca na memoria um espaço para o struct matriz
	if(m == NULL){
		printf("Erro ao alocar memoria!\n");
		exit(1);
	}
	if(lin < 1 || col < 1){
		printf("Matriz invalida!\n");
		exit(2);
	}
	m->colunas = col;
	m->linhas = lin;
	m->matriz = (double**)malloc(lin*sizeof(double*));//aloca na memoria um espaço as linhas da matriz, feita de ponteiros de double
	if(m->matriz == NULL){
		printf("Erro ao alocar memoria!\n");
		exit(3);
	}
	for(i = 0; i < lin; i++){
		m->matriz[i] = (double*)calloc(col,sizeof(double)); //aloca na memoria um vetor de double para cada linha da matriz
		if(m->matriz[i] == NULL){
			printf("Erro ao alocar memoria!\n");
			exit(4);
		}		
	}
	return m;
}


void preencherMatriz(Matriz *m){
	int lin, col, i, j;
	double temp;
	lin = m->linhas;
	col = m->colunas;
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			printf("Elemento A%i%i: ", i+1, j+1);
			scanf("%lf", &temp);
			m->matriz[i][j] = temp;
		}
	}
}


void exibirMatriz(Matriz *m){
	int lin, col, i, j;
	lin = m->linhas;
	col = m->colunas;
	//printf("%i", lin);
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			printf("%.0lf ", m->matriz[i][j]);
		}
		printf("\n");
	}
}


Matriz* somarMatriz(Matriz *m1, Matriz *m2){
	Matriz *S;
	int lin_m1, lin_m2, col_m1, col_m2, i, j;
	lin_m1 = m1->linhas;
	lin_m2 = m2->linhas;
	col_m1 = m1->colunas;
	col_m2 = m2->colunas;
	if(lin_m1 != lin_m2 || col_m1 != col_m2){
		printf("Matrizes incompativeis!\n");
		exit(5);
	}
	S = novaMatriz(lin_m1, col_m1);
	for(i = 0; i < lin_m1; i++){
		for(j = 0; j < col_m1; j++){
			S->matriz[i][j] = m1->matriz[i][j] + m2->matriz[i][j];
		}
	}
	return S;
}


Matriz* subtrairMatriz(Matriz *m1, Matriz *m2){
	Matriz *S;
	int lin_m1, lin_m2, col_m1, col_m2, i, j;
	lin_m1 = m1->linhas;
	lin_m2 = m2->linhas;
	col_m1 = m1->colunas;
	col_m2 = m2->colunas;
	if(lin_m1 != lin_m2 || col_m1 != col_m2){
		printf("Matrizes incompativeis!\n");
		exit(6);
	}
	S = novaMatriz(lin_m1,col_m1);
	for(i = 0; i < lin_m1; i++){
		for(j = 0; j < col_m1; j++){
			S->matriz[i][j] = m1->matriz[i][j] - m2->matriz[i][j];
		}
	}
	return S;
}


Matriz* transposta(Matriz *m){
	int lin, col, i, j;
	Matriz *T;
	lin = m->linhas;
	col = m->colunas;
	T = novaMatriz(col, lin);
	for(i = 0; i < lin; i++){
		for(j = 0; j < col; j++){
			T->matriz[j][i] = m->matriz[i][j];
		}
	}
	return T;
}


Matriz* produtoMatriz(Matriz *m1, Matriz *m2){
	int lin1, lin2, col1, col2, i, j, k;
	double temp = 0;
	Matriz *P;
	lin1 = m1->linhas;
	col1 = m1->colunas;
	lin2 = m2->linhas;
	col2 = m2->colunas;
	if(col1 != lin2){
		printf("Matrizes incompativeis!\n");
		exit(7);
	}
	P = novaMatriz(lin1, col2);
	for(i = 0; i < lin1; i++){
		for(k = 0; k < col2; k++){
			for(j = 0; j < col1; j++){
				temp += (m1->matriz[i][j]) * (m2->matriz[j][k]);
			}
			P->matriz[i][k] = temp;
			temp = 0;
		}
	}
	return P;
}