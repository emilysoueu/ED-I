#include <stdio.h>
#include <stdlib.h>

char matriz[3][3]; /*Matriz do jogo*/

char check(void);
void init_matriz(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matriz(void);

void main(){
	char done;

	printf("Este eh o jogo da velha!!\n");
	printf("Você estara jogando contra o computador\n");

	done = ' ';

	init_matriz();

	do{
		disp_matriz();
		get_player_move();

		done = check(); /*Verifica se ha um vencedor*/

		if (done != ' ')
			break; /*Vencedor*/

		get_computer_move();

		done = check(); /*Verifica se ha um vencedor*/
	}while(done == ' ');

	if (done == 'X'){
		printf("Voce ganhou !!\n");
	}else{
		printf("Eu ganhei !!\n");
	}

	disp_matriz(); /*Mostra posições finais*/
}

/*INICIALIZA A MATRIZ*/
void init_matriz(){
	int i,j;

	for(i=0; i<3; i++){
		for(j=0; j<3; j++)

		matriz[i][j] = ' ';
	}
}

/*OBTEM A SUA JOGADA*/
void get_player_move(){
	int x,y;

	printf("Digite as coordenadas para o X: ");
	scanf("%d%d",&x, &y);
	x --; y--;

	if (matriz[x][y] != ' '){
		printf("Posicao Invalida, tente novamente!!\n");
		get_player_move();
	}else{
		matriz[x][y] = 'X';
	}
}

/*OBTEM A JOGADA DO COMPUTADOR*/
void get_computer_move(){
	int i, j;
	for(i=0; i<3; i++){
		for (j=0; j<3;  j++)
			if (matriz[i][j]==' ')
				break;
		if (matriz[i][j]==' ')
				break;
		if (i*j == 9){
			printf("EMPATE\n");
			exit(0);
		}else{
			matriz[i][j] = 'O';
		}
	}
}


/*MOSTRA A MATRIZ NA TELA*/

void disp_matriz(){
	int t;
	for(t=0; t<3; t++){
		printf("%c | %c | %c ", matriz[t][0], matriz[t][1], matriz[t][2] );
		if (t!= 2){
			printf("\n---|---|---\n");
		}
		printf("\n");
	}
}

/*VERIFICA SE HA UM VENCEDOR*/
char check(){
    int i;
	for(i=0; i<3; i++) /*Verifica linhas*/
		if (matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]);

	return matriz[i][0];


	for (i=0; i<3; i++)
		if (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]);

	return matriz[0][i];

/*TESTA AS DIAGONAIS*/

if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2])
	return matriz [0][0];
if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])
	return matriz[2][0];

return ' ';
}



























































