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





















}


