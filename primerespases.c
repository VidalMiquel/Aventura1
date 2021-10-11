#include <stdio.h>

int main()
{
    int x, y;
    int *px;
    x = 5;
    px = &x;
    y = *px;

    printf("La direccion asociada a x es: %p \n", &x);
    printf("El valor de x es: %d \n", x);
    printf("\n");
    printf("La dirección de px es: %p \n", &px);
    printf("El valor de px es: %p \n", px);
    printf("\n");
    printf("La dirección de y es: %p \n", &y);
    printf("Contenido de px: %d \n", *px);
    printf("El valor de y es: %d \n", y);

    return 0;
}
