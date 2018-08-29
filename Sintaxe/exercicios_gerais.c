#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// ========================================================> 1
///1.  Dada uma seqüência de números inteiros não-nulos, seguida por 0, imprimir seus quadrados.

/*
int quad(int num);

int main (){
    int n;
    int dobro;


    printf("Informe um numero: \n");
    scanf("%d", &n);

   dobro =  quad(n);

   printf("O dobro do numero informado eh: %d", dobro);

}

int quad(int num){
    return num*num;
}
*/
// ========================================================> 2
/// Dado um número inteiro positivo n, calcular a soma dos n primeiros números inteiros positivos.
/*
int main (){
    int i, n;
    int soma = 0;


    printf("Informe um numero: \n");
    scanf("%d", &n);



    for (i=1; i<= n; i++){
            soma += i;
    }

    printf("A soma dos %d primeiros numeros eh %d", i-1, soma);
}
*/

///3.  Dado um número inteiro positivo n, imprimir os n primeiros naturais ímpares.
/*
int main(){
    int i = 0 , n;
    int imp;

    printf("Informe um numero: \n");
    scanf("%d", &n);

    imp = n;

   for (i=0; i<=(n*2); i++){
            if (i % 2 != 0){
                 printf("%d ", i);
            }

    }

}
*/

/// 4. Dados um inteiro x e um inteiro não-negativo n, calcular x n.
/// OBS : pow(base, expoente);

/*
int main (){
    int num, exp;
    int res;

    printf("Informe a base e o expoente: \n");
    scanf("%d %d", &num, &exp);

    res = (pow(num,exp));

    printf("%d", res);
}
*/
///Uma loja de discos anota diariamente durante o mês de março a quantidade de discos vendidos. Determinar em que dia desse mês ocorreu a maior venda e qual foi a quantidade de discos vendida nesse dia.
/**
int main (){
    int tam = 3;
    int mes[tam];
    int maior = 0, dia;

    printf("Insira a quantidade de vendas do dia: \n");

    for (int i =0; i<tam; i++){
        scanf("%d", &mes[i]);
    }


    maior = mes[0];
    for (int i =0; i<tam; i++){
        if (mes[i] > maior){
            maior = mes[i];
            dia = i;

        }
    }

    printf(" A maior quantidade vendida: %d\nNo dia : %d",maior,dia +1 );


} // close main
*/


