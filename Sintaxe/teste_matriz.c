// criando uma matriz e preenchendo

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(){
	int i, j;
	int l = 2, col = 2;
	int matriz[l][col];
	int ele;


	for (i=0; i<l; i++){
		for (j=0; j<col; j++){
			gets(ele);
			matriz[i][j] = ele;
		}
	}

	for (i=0; i<l; i++){
		for (j=0; j<col; j++){
			printf("%d\n", matriz[i][j]);
		}
	}


}
