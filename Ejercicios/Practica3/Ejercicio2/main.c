#include <stdio.h>
#include <stdlib.h>

//Prototipo de funciones
int * entregarPosDeMemoriaDeVariableEnArreglo(int * arregloDeNumeros, int posicionDeArreglo);

int main()
{
    int arregloDeNumeros[5];
    int * direccionDeMemoria = entregarPosDeMemoriaDeVariableEnArreglo(arregloDeNumeros, 2);

    printf("Direccion del arreglo: %p\n", arregloDeNumeros);
    printf("Direccion de la posicion buscada: %p\n", direccionDeMemoria);

    return 0;
}

int * entregarPosDeMemoriaDeVariableEnArreglo(int * arregloDeNumeros, int posicionDeArreglo){
    return arregloDeNumeros + posicionDeArreglo;
}
