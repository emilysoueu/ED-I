#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* UM BANCO DE DADOS SIMPLES*/

#define CLASSES 3
#define GRADES 30

int grade[CLASSES][GRADES]; // CONSTANTE

void enter_grades(void); // digita notas de alunos
int get_grades(int num); // le  nota de alunos
void disp_grades(int g[][GRADES]); // mostra nota de alunos

void main (void){
	char ch, str[80];

	for(;;){
		do{
			printf("(D)igitar notas\n");
			printf("(M)ostrar notas\n");
			printf("(S)air\n");
			gets(str); // recebe a opção do usuario e atribui o primeiro caractere p/ variável ch

			ch = toupper(*str); /// toupper ==> converte letras maiusculas em minusculas
		}while(ch != 'D' && ch != 'M' && ch != 'S');

		switch(ch){
			case 'D':
				enter_grades();
			break;
			case 'M':
				disp_grades(grade);
			break;
			case 'S':
				exit(0);
			break;
		}// close switch

	}// close for
}// close main


/* DIGITA A NOTA DOS ALUNOS*/
void enter_grades(){
	int t, i;

	for (t=0; t<CLASSES; t++){
		printf("Turma # %d: \n", t+1 );
		for(i=0; i<GRADES; i++)
		grade [t][i] = get_grades(i);
	}// close for
} // close função

/*Lê UMA NOTA*/
get_grades(int num){
	char s[80];
	printf("Digite a nota do aluno # %d: \n", num +1 );
	gets(s);

	return (atoi(s));
} // close função

/*MOSTRA NOTAS*/
void disp_grades(int g[][GRADES]){
	int t, i;

	for (t=0; t<CLASSES; t++){
		printf("Turma # %d: \n", t+1 );
			for (i=0; i<GRADES; i++)
				printf("Aluno # %d eh %d\n", i+1, g[t][i] );
	}// close for
} //close função
























