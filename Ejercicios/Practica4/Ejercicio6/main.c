#include <stdio.h>
#include <stdlib.h>

void ordenarCrecientementeArreglo(int * arreglo);
void imprimirArreglo(int * arreglo);

int * retornarDireccionDelNumeroMasChicoDelArreglo(int * arreglo);

int main()
{
    int arregloDeNumeros[5] = {10,1,2,3,0};

    imprimirArreglo(arregloDeNumeros);
    ordenarCrecientementeArreglo(arregloDeNumeros);
    imprimirArreglo(arregloDeNumeros);

    return 0;
}

void ordenarCrecientementeArreglo(int * arreglo){

    int numeroEnLaDireccionDelPuntero = (*arreglo);
    int * direccionDelNumeroMasChicoEnElArreglo = retornarDireccionDelNumeroMasChicoDelArreglo(arreglo);
    int numeroDeLaDireccionBuscada;

    if(numeroEnLaDireccionDelPuntero != 0){
        numeroDeLaDireccionBuscada = *direccionDelNumeroMasChicoEnElArreglo;

        (*direccionDelNumeroMasChicoEnElArreglo)=numeroEnLaDireccionDelPuntero;
        (*arreglo)=numeroDeLaDireccionBuscada;

        ordenarCrecientementeArreglo(arreglo+1);
    }

}

int * retornarDireccionDelNumeroMasChicoDelArreglo(int * arreglo){

    int * direccionDelNumeroDeFuncionActual = arreglo;
    int * direccionDelNumeroDeFuncionAnterior = NULL;

    if( *(arreglo) != 0 ){
        direccionDelNumeroDeFuncionAnterior = retornarDireccionDelNumeroMasChicoDelArreglo(arreglo+1);

        if(direccionDelNumeroDeFuncionAnterior == NULL)
            return direccionDelNumeroDeFuncionActual;

        if( *(direccionDelNumeroDeFuncionActual) < *(direccionDelNumeroDeFuncionAnterior) )
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
