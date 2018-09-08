/*a) Implemente um pequeno programa que registra ID de entrada num evento. 
 * O ID é um número aleatório de 4 dígitos que identifica o participante da seção. 
 * Existe um número máximo de participantes na seção. No final, o programa deve informar quais participantes estavam presentes na seção.
 */
 #ifndef EVENTO_H
    #define EVENTO_H
    
   typedef struct _evento_{
	int *idvector;
	int entradas;
	int atual;
	 } evento;
evento* geraVector(int entradas); 

void mostraTudo(evento* eve); 

int colocar(evento* eve, int chave);

#endif

