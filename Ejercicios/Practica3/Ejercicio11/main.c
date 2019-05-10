#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a,b;
} t_dosint;

//Prototipo de funciones
void intercambiarVariables(int * puntero1, int * puntero2);

int main()
{
    t_dosint structDeDosEnteros;

    structDeDosEnteros.a = 5;
    structDeDosEnteros.b = 10;

    intercambiarVariables(&structDeDosEnteros.a, &structDeDosEnteros.b);

    printf("%d\n", structDeDosEnteros.a);
    printf("%d\n", structDeDosEnteros.b);
    return 0;
}

void intercambiarVariables(int * puntero1, int * puntero2){
    int memoriaDeNumero;

    memoriaDeNumero = *puntero1;
    *puntero1 = *puntero2;
    *puntero2 = memoriaDeNumero;
}
