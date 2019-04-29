#include <stdio.h>
#include <stdlib.h>

//Prototipo de funciones
void intercambiarVariables(int * puntero1, int * puntero2);

int main()
{
    int numero1 = 5;
    int numero2 = 10;

    printf("Numero 1: %d\n", numero1);
    printf("NUmero 2: %d\n", numero2);

    printf("Se realiza el intercambio\n");

    intercambiarVariables(&numero1, &numero2);

    printf("Numero 1: %d\n", numero1);
    printf("NUmero 2: %d\n", numero2);

    return 0;
}

void intercambiarVariables(int * puntero1, int * puntero2){
    int memoriaDeNumero;

    memoriaDeNumero = *puntero1;
    *puntero1 = *puntero2;
    *puntero2 = memoriaDeNumero;
}
