#include <stdio.h>
#include <string.h>

int main(){
    int my_array[] = {1,2,3,4,5};
    //Recorrem l'arrai i accedima cada component i-èssima.
    for (int i = 0; i < 5; i++){
        printf("El valor de my_array[i] es: %d \n", my_array[i]);
    }
    printf("\n");
    int *ptr;
    ptr = my_array;
    //Recorrem l'array mitjançant un punter.
    for(int j = 0; j< 5; j++){
        printf("El valor del puntero ptr es: %d \n", (*ptr + j));
    }
    return 0;
}