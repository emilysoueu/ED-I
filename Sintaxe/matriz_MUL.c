#include <stdio.h>
#include <stdlib.h>
#include <ctyme>

int main (){
	int linA, colA; // tamanhos das linhas e colunas das matrizes
	int linB, colB;

	int **A, **B, **C; // matrizes

	int i,j,k; // controle dos laços

	printf("Insira as dimensões da matriz A: [linhas][colunas]\n");
	scanf("%d %d", &linA, colA);

	printf("Insira as dimensões da matriz B: [linhas][colunas]\n");
	scanf("%d %d", &linB, colB);

	A = (int **) malloc(linA *sizeof(int*));
		for(i=0; i<linA;i++)
			A[i] = (int*)malloc(colA *sizeof(int));

	B = (int **) malloc(linB *sizeof(int *));
		for(i=0; i<linB; i++)
			B[i] = (int *)malloc(colB*sizeof(int));

		if (colA != linB){
			printf("Impossivel realizar multiplicacao.\n");
			exit (1);
		}else{
			C = (int **) malloc( linA * sizeof(int*));
				for(i=0; i<linA; i++)
					C[i] = (int*) malloc(colB * sizeof(int));
		}

	//A
	for (i=0; i<linA; i++){
		for (j=0; j<colA; j++){
			printf("Insira os elementos da matriz A: \n");
			 scanf("%d", A[i][j] );
		}
	}

	//B
	for (i=0; i<linB; i++){
		for (j=0; j<colB; j++){
			printf("Insira os elementos da matriz B: \n");
			 scanf("%d", B[i][j] );
		}
	}

	// C = A*B ==> matriz resultante

	for(i=0; i<linA; i++){
		for(j=0; j<linB; j++){
			C[i][j] = 0;
			for(k=0; k<linB; k++)
				C[i][j]+= A[i][k] * B[k][j];
				printf("%d ", C[i][j]);
		}
		printf("\n");
	}


}