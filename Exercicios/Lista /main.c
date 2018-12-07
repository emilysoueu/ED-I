#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "lista.c"

int main(){
	
	lista *tmp = NULL;
	
	tmp = criarlista();
	
	
	insereLista(tmp,1);
	
	imprimir(tmp);
	
	
	
}
