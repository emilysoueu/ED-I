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
