#include <stdio.h>
int main()
{
    int x, *px;

    x = 12;
    px = &x;
    printf("El valor de x es: %d \n", x);
    printf("La dirección de x es: %p \n", &x);
    printf("El contenido de px es: %d \n", *px);
    printf("El valor de px es: %p \n", px);
    printf("\n");
    *px = *px + 10;
    printf("El valor de x es: %d \n", x);
    printf("La dirección de x es: %p \n", &x);
    printf("El contenido de px es: %d \n", *px);
    printf("El valor de px es: %p \n", px);
    printf("\n");
    x = *px + 10;
    printf("El valor de x es: %d \n", x);
    printf("La dirección de x es: %p \n", &x);
    printf("El contenido de px es: %d \n", *px);
    printf("El valor de px es: %p \n", px);
    printf("\n");
    *px += 1;
    printf("El valor de x es: %d \n", x);
    printf("La dirección de x es: %p \n", &x);
    printf("El contenido de px es: %d \n", *px);
    printf("El valor de px es: %p \n", px);

    return 0;
}