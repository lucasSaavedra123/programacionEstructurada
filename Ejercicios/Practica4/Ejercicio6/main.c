#include <stdio.h>
#include <stdlib.h>

void ordenarCrecientementeArreglo(int * arreglo);
void imprimirArreglo(int * arreglo);

int * retornarDireccionDelNumeroMasGrandeDelArreglo(int * arreglo);

int main()
{
    int arregloDeNumeros[5] = {10,1,2,3,0};
    int i;

    imprimirArreglo(arregloDeNumeros);
    ordenarCrecientementeArreglo(arregloDeNumeros);
    imprimirArreglo(arregloDeNumeros);

    return 0;
}

void ordenarCrecientementeArreglo(int * arreglo){

    int numeroEnLaDireccionDelPuntero = *(arreglo);
    int direccionDelNumeroMasGrandeEnElArreglo = retornarDireccionDelNumeroMasGrandeDelArreglo(arreglo);

    if(numeroEnLaDireccionDelPuntero != 0)
        ordenarCrecientementeArreglo(arreglo+1);

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

void imprimirArreglo(int * arreglo){
    int indiceDeArreglo = 0;

    for(indiceDeArreglo = 0; *(arreglo+indiceDeArreglo) != 0 ;indiceDeArreglo++){
        printf("Numero %d: %d\n", indiceDeArreglo, *(arreglo+indiceDeArreglo));
    }

    printf("\n");
}
