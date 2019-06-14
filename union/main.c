#include <stdio.h>
#include <stdlib.h>

void imprimirArreglo(int * arreglo){
    int indice = 0;

    for(indice = 0; arreglo[indice] != 0 ;indice++)
        printf("%d,", arreglo[indice]);

    printf("\n");
}

int noEstaNumeroEnArreglo(int numero, int * arreglo){
    int noEstaNumero = 1;
    int indice = 0;

    while(arreglo[indice] != 0){
        if(arreglo[indice] == numero)
            noEstaNumero = 0;

        indice++;
    }


    return noEstaNumero;

}

void agregarNumeroEnArreglo(int numero, int ** arreglo){
    int contadorDeNumeros = 0;
    int indice = 0;

    /*Se supone que el arreglo ya arranco en 0*/

    while( *((*arreglo)+indice) != 0 ){
        contadorDeNumeros++;
        indice++;
    }

    (*arreglo) = realloc((*arreglo), sizeof(int)*(contadorDeNumeros+2)); //Va mas dos por que tenes que guardar el 0 y el nuevo numero
    *((*arreglo)+contadorDeNumeros) = numero;
    *((*arreglo)+contadorDeNumeros+1) = 0;

}

void hacerUnionEntreArreglosYGuardaloEn(int * arreglo1, int * arreglo2, int ** arregloUnion){

    int indice = 0;

    /*Lo arrancamos en 0*/
    (*arregloUnion) = malloc(sizeof(int));
    *(*arregloUnion) = 0;

    for(indice = 0; arreglo1[indice] != 0; indice++){
        if( noEstaNumeroEnArreglo(arreglo1[indice], *(arregloUnion)) )
            agregarNumeroEnArreglo(arreglo1[indice], arregloUnion);
    }

    for(indice = 0; arreglo2[indice] != 0; indice++){
        if( noEstaNumeroEnArreglo(arreglo2[indice], *(arregloUnion)) )
            agregarNumeroEnArreglo(arreglo2[indice], arregloUnion);
    }

}


int main()
{
    int arregloDeNumeros1[] = {1,5,4,6,9,7,8,1,2,3,6,4,8,5,12,-5,0};
    int arregloDeNumeros2[] = {1,5,4,-5,7,25,41,87,98,45,-5,0};
    int * arregloDeUnion = NULL;

    hacerUnionEntreArreglosYGuardaloEn(arregloDeNumeros1, arregloDeNumeros2, &(arregloDeUnion));

    imprimirArreglo(arregloDeNumeros1);
    imprimirArreglo(arregloDeNumeros2);
    imprimirArreglo(arregloDeUnion);


    return 0;
}
