#ifndef SNAKE_H
#define SNAKE_H




typedef struct _direcao_{
	int x;
	int y;
	int direction;
}pos;

typedef struct _snake_{
	int *snake;
	int topo;
	int fim;
	int qtd ;
	int max;
	pos *p; // struct direção da snake
}cobra;



cobra* criar(int x);
void criaTela(); // cria o gameSpace;
void aumenta(cobra *c, char x);
void showSnake(cobra *c);

#endif
