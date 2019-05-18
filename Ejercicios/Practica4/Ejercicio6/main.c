#include <stdio.h>
#include <stdlib.h>

void ordenarCrecientementeArreglo(int * arreglo);

int main()
{
    int arregloDeNumeros[5] = {10,1,2,3,0};
    ordenarCrecientementeArreglo(arregloDeNumeros);
    return 0;
}

void ordenarCrecientementeArreglo(int * arreglo){

    if( *(arreglo) != 0 ){
        ordenarCrecientementeArreglo(arreglo+1);

        if( *(arreglo) != 0 ){
            ordenarCrecientementeArreglo(arreglo+1);

        }
    }
}
