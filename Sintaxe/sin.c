// Revisão LP - ED - UFMA
// @emilysoueu
//23/07/2018

// ------------------------> exemplo 1

#include <stdio.h>

void main (void){
	int target, source; 
	int *m;

	source = 10; // atribuindo valor 10 a variavel source
	m = &source; // m recebe o endereço de source

	target = *m; // target recebe o o valor da variavel que esta no endereço m

	printf("%d", target);  
}

// ---------------------------> exemplo 2

typedef struct employee
{
	char nome[80];
	int age;
	float wage;
}emp;

struct  employee *p = &emp; // endereço de emp em p

/* o seguinte código atribui o valor 123.3 ao elemento wage 
da estrutura emp
*/

emp.wage = 123.23;

// a mesma atribuição usando ponteiro para emp

p -> wage = 123.23;

// -----------------------------> exemplo 3
// adivinhar numero mágico

#include <stdio.h>
#include <stdlib.h>

int main (){
	int magic, guess;

	//magic = rand();
  magic = 10;
 printf("%d",magic);

	printf("\nInforme o numero magico: \n");
	scanf("%d", &guess);


	if (guess == magic){
		printf("** Certo ** \n");
    printf("%d", "eh o numero magico\n", &magic);
	}else{
		printf("Errado\n");
    if (guess > magic){
      printf("Muito Alto\n");
   }else{ 
     printf("Muito Baixo\n");
    }    
  }

  // imprimindo uma parada estranha quando termina certo
	
}

// -------------------------------> exemplo 4
// laço de repetição

wait_for_char(void){
	char ch;

	ch = '\0'; // inicializa ch

	while (ch != 'A'){
		ch = getchar();
	}

	return ch;
}

//-------------------------------> exemplo 5
// adicionando espaços no final de uma string

#include <stdio.h>
#include <string.h>

void pad(char *s, int length);

void main(){
	char str[80];

	strcpy(str, "isto eh um teste");
	pad(str,40);
	printf("%d", strlen(str));
}

/// Acrescenta espaços ao final da string

void pad(char *s, int length){
	l = strlen(s); // encontra o comprimento

	while(l < length){
		s[l] = ' '; // insere um espaço;
	
	 	l++;
	 }

	 s[l] = '\0'; // strings precisam com um caractere nulo
}

/*---------------------------------------------> 
Descobrir o tamanho de uma matriz
*/

tamanho_matriz = sizeof(tipo) * tamanho da matriz

// Gerando ponteiro para uma matriz

int *p;
int matriz[4];

p = matriz  || p = &matriz[0] // a segunda forma quase nunca é utilizada

// -------------------------------------------->
/* Passando Matrizes Unidimensionais para matrizes:

	Em C, você não pode passar uma matriz inteira como um arumento
	para uma função. Você pode porém passar um ponteiro para uma função,
	especificando o nome da matriz sem um índice.
*/

void main(){
	int i[10];

	func1(i);
}

void func1 (int *x) /* ponteiro */

void func1 (int x[10]) /* Matriz dimensionada    */

void func1 (int x[]) /* Matriz  não - dimensionada */

// Todos os tres métodos possuem resultados idênticos, pois cada um diz ao compilador que um ponteiro inteiro vai ser recebido

//--------------------------------------------------------->
// Funções de manipulação String

#include <stdlib.h>
#include <string.h>

void main (){
	char s1[80],  s2[80];

  gets(s1);
	gets (s2);

	printf("Comprimentos das Strings %d %d \n",strlen(s1), strlen(s2));
	printf("Concatenando Strings:\n");
	strcat(s1,s2);
	printf("%s\n",s1);
	strcpy(s1, "Isso eh um teste.\n");
	printf(s1);

	if (strchr("alo", 'o')){
		printf("o esta em alo\n");
	}

	if (strstr("ola aqui", "alo")){
		printf("Ola encontrado\n");
	}
}

//----------------------------------------------------->
// Matrizes de String

char str_array[30][80];

gets(str_array[2]) // acessando a penas a linha 2

// Passando Matrizes Unidimensionais para funções

int matriz[4][3][6][5];

func1(int M[][3][6][5]) //Você deve declarar todos menos a primeira dimensão



















































}


