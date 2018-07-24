#include <stdio.h>
#include <stdlib.h>

int main(){
	int choice;



	do{
		printf("Escolha uma das opcoes:\n");
		printf("1 - Inserir nome\n");
		printf("2 - Procurar nome\n");
		printf("3 - Deletar nome\n");
		printf("4 - Sair do Programa\n");
		scanf("%d", &choice);


		switch(choice){
	    case 1:
            printf("Case 1\n");
        break;
        case 2:
            printf("case 2\n");
        break;
        case 3:
            printf("case 3\n");
        break;
        case 4:
            printf("CASE 4\n");
        break;
        default:
            exit(1);
        break;
	}




	}while (choice > 0  && choice < 5);



}
