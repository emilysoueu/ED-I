#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>
#include "snake.h"
#include "snake.c"


int main(){
	int start = 3;	
	
	cobra *c = criar(start);
	
	
	
	printf("BEM - VINDO AO JOGO DA COBRA!!\n\n");		
		
		criaTela(c);
			
	
	
}
