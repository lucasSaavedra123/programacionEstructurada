#include <stdio.h>
#include <stdlib.h>

int retornarNumeroMasGrandeDelArreglo(int * arreglo);
int * retornarDireccionDelNumeroMasGrandeDelArreglo(int * arreglo);

int main()
{
    int arregloDeNumeros[] = {-10,-2,-3,-5,-8,-7,-5,0};

    printf("Numero mas grande: %d\n", retornarNumeroMasGrandeDelArreglo(arregloDeNumeros));
    printf("Su direccion de memoria es: %p\n", retornarDireccionDelNumeroMasGrandeDelArreglo(arregloDeNumeros));

    return 0;
}


int retornarNumeroMasGrandeDelArreglo(int * arreglo){

    int numeroDeFuncionActual = *(arreglo); //Numero que se guarda la funcion para luego comparar los otros numeros
    int numeroDeFuncionAnterior = 0; //Numero que se va pasando que es el mas grande que se obtuvo hasta ahora

    if( *(arreglo) != 0 ){
        numeroDeFuncionAnterior = retornarNumeroMasGrandeDelArreglo(arreglo+1); //Obtenemos el numero mas grande obtenido

        //Ponemos este if para evitar que se toma el 0. El 0 solo para toda la recursividad
        if(numeroDeFuncionAnterior == 0)
            return numeroDeFuncionActual;

        if(numeroDeFuncionActual > numeroDeFuncionAnterior )
            return numeroDeFuncionActual;//Devolvemos el numero de la funcion que pasa a ser el mas grande
        else
            return numeroDeFuncionAnterior;//Devolvemos el numero que es de otra funcion (no importa cual) y que sigue siendo el mas grande

    }
    else
        return 0; //Este ese ejecuta cuando se llega al 0. Se devuelve 0 y se compara
}

int * retornarDireccionDelNumeroMasGrandeDelArreglo(int * arreglo){

    int * direccionDelNumeroDeFuncionActual = arreglo;
    int * direccionDelNumeroDeFuncionAnterior = NULL;

    if( *(arreglo) != 0 ){
        direccionDelNumeroDeFuncionAnterior = retornarDireccionDelNumeroMasGrandeDelArreglo(arreglo+1);

        if(direccionDelNumeroDeFuncionAnterior == NULL)
            return direccionDelNumeroDeFuncionActual;

        if( *(direccionDelNumeroDeFuncionActual) > *(direccionDelNumeroDeFuncionAnterior) )
            return direccionDelNumeroDeFuncionActual;
        else
            return direccionDelNumeroDeFuncionAnterior;

    }
    else
        return NULL;
}
