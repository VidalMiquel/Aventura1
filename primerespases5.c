#include <stdio.h>
#include <string.h>

int mediaArray(int nombres[], int size);
int mediaPuntero(int *pA, int size);
int main(){

int numeros[] = {10,20,30,40,50};
//Realitzam la mitja passant per parametre l'array i la tractam com a tal.
printf("La media de los valores que conforman la array es: %d \n", mediaArray(numeros, 5));
printf("\n");
//Realitzam la mitja passant per parametre l'array i la tractam com a punter.
//També podrime declara una variable punter int *pt = numeros. Passariem per parametre el punter pt.
//int *pt = numeros;
printf("La media de los valores que conforman el puntero es: %d \n", mediaPuntero(numeros, 5));

}

int mediaPuntero(int *pA, int size){
    int avg = 0;
    int suma = 0;
    for(int i = 0; i < size; i++ ){
        suma += *pA;
        pA++;
    }
    avg = suma /size;
}

int mediaArray(int nombres[], int size){

    int avg = 0;
    int suma = 0;
    for (int i = 0; i< size; i++){
        suma += nombres[i];
    }
    avg = suma / size;
    return avg;
}