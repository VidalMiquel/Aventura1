#include <stdio.h>
//Passam per paràmetre un punter a a i b
void funcionReferencia(int *a, int *b);
//Passam per parametre dos integers.
void funcionValor(int a, int b);

int main()
{
    int x, y;
    x = 2;
    y = 5;
    printf("El valor antes del paso por referencia de la variable x es: %d \n", x);
    printf("El valor antes del paso por referencia de la varibale y es: %d \n", y);
    printf("\n");
    funcionReferencia(&x,&y);
    printf("El valor despues del paso por referencia de la variable x es: %d \n", x);
    printf("El valor despues del paso por referencia de la varibale y es: %d \n", y);
    printf("\n");
    x = 2;
    y = 5;
    printf("El valor antes del paso por valor de la variable x es: %d \n", x);
    printf("El valor antes del paso por valor de la varibale y es: %d \n", y);
    printf("\n");
    funcionValor(x,y);
    printf("El valor despues del paso por valor de la variable x es: %d \n", x);
    printf("El valor despues del paso por valor de la varibale y es: %d \n", y);
    return 0;
}

void funcionReferencia(int *a, int *b)
{

    *a = 0;
    *b = 0;

    return ;
}

void funcionValor(int a, int b)
{

    a = 3;
    b = 3;

    return;
}