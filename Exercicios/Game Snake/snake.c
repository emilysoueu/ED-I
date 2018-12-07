#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//#include "snake.h"

cobra* criar(int x){
	cobra *c = (cobra*)malloc(sizeof(cobra));
	if (c == NULL) return NULL;

	c ->snake = (int*)malloc(sizeof(int)*x);
	if (c->snake == NULL) return NULL;
	
	c -> p = (pos*)malloc(sizeof(pos));
	
	c -> qtd = 3;
	c -> topo = 0;
	c -> fim = 0; 
	c -> max = x;
	c -> p -> x = 15;
    c -> p -> y = 20;
    c -> p -> direction = 1;// direita


	return c;
}

void criaTela(cobra *c){ // cria o espaço do jogo;
	int i,j, largura=70, altura=34;
	char spacegame[largura][altura];
	
	bool gameover = false;
	bool tem_cobra;
	
		
	// pontuação
	int pontos =0;
	
	// posição da fruta;
	int frX = altura/2, frY = largura/2; // fisn de teste
	
	// posição da cabeça da cobra
	int tailX = c -> p -> x , tailY = c -> p -> y;
	
	// posição da cauda da cobra
	int caudaX = c ->p ->x - c -> qtd, caudaY= c -> p ->y;	
	
	
	
	// direção
	char dir;
	
	// controle pra diminuir as 5 vidas caso a cabeça encontre a parede	
	int cab = 1;
	do{		
			
		int tamanho = c->qtd;
		system("clear");	
		if (pontos == 28) // fim de jogo
        printf("\n\n     YOU Win the Game !!  \n\n");
	    printf("PONTOS: %d\n",pontos );
	
	for(i=0; i<altura; i++) {
          for(j=0; j<largura; j++){
            if(i==altura-1|| j ==0 || i==0 || j==largura-1){
              spacegame[i][j]='#'; 
             
               // colisao
			if (caudaY > 70 || caudaY < 0 || caudaX >34  || caudaX <0){
				gameover = true;
			}
              
              if (tailX == i && tailY == j){
				  while(cab <=5){
				   c -> snake[c -> topo++];
				    c->qtd--;
				    cab++;
				}
				}	
				//diminui sempre que encosta na parede 5 unidades
					if (tamanho <= 0)
					gameover = true;
									
							  
            }else{		
				   // desenhar a cobra
                  tem_cobra = false;	
                  
					 for(int k = 0; k< tamanho; k++){					
						
						if (c->p->direction == 0){ // cima
							if ((i == c->p->x + k) && ( j == c->p->y))
								tem_cobra = true;							
							
						}else if (c->p->direction == 1){ //direita
							if ((i == c->p->x ) && ( j == c->p->y - k))
								tem_cobra = true;
							
								
						}else if (c->p->direction == 2){ // baixo
							if ((i == c->p->x - k ) && ( j == c->p->y))
								tem_cobra = true;
							
								
						}else if (c->p->direction == 3){ // esquerda
							
							if ((i == c->p->x ) && ( j == c->p->y + k))
								tem_cobra = true;
							}
						}
						
				if ((i == frX && j == frY)){
					spacegame[i][j]='0';
				}
				else if(tem_cobra){
					spacegame[i][j] = '*';
				}								    				 
				else{
					 spacegame[i][j]=' ';
				 }
				 
			}
			printf("%c ",spacegame[i][j]);

            
        }
    printf("\n");
  }
    printf("Fruta: [%d, %d]\n", frX, frY);
	printf("Cabeça da cobra: [%d, %d] \n",c->p->x, c->p->y);
	printf("Cauda da cobra: [%d, %d] \n",caudaX, caudaY);
	printf("Tamanho da cobra: %d \n", c ->qtd);
   	printf("Sentido: <w,a,s,d> + enter \n");
    scanf("%c", &dir);  
	
   
   switch (dir){
	   // cima
		case 'w':
		case 'W':{
			c -> p -> direction = 0;
			tailX --;	
			c -> p ->x --;	
			caudaX = c -> p -> x + c -> qtd; // se a cabeça da subindo a cauda ta pra baixo;			
			
		}		
		break;
		//esquerda
		case 'a':
		case 'A':{
			c -> p -> direction = 3;
			tailY --;
			c -> p ->y --;
			caudaY = c -> p -> y + c -> qtd;
				
			
		}
		break;
		//baixo
		case 's':
		case 'S':{
			c -> p -> direction = 2;
			tailX ++;
			c -> p ->x ++;	
			caudaX = c -> p -> x - c -> qtd;
			
		}
		break;
		//direita
		case 'd':
		case 'D':{
			c -> p -> direction = 1;
			tailY++;
			c -> p ->y ++;	
			caudaY = c -> p -> y - c -> qtd;
			
		}
		break;		
	}
	
	// frutinha
	if (tailX == frX && frY == tailY){
		pontos ++;
		frX = (rand () % altura -1)+1;
		frY = (rand () % largura  -1)+1;
		//aumenta // sempre que encosta na fruta
		c->snake[c->fim] = '*';
		c->fim ++;
		c->qtd++;
			if (c -> fim == c -> max -1);
			c -> fim = 0;
		
	}	
	
	if (gameover)
	printf("\n\n     GAME OVER !!  \n\n");	
	
	}while(!gameover);	
		   
	   
 }






