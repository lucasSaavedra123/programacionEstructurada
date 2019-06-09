#include <stdio.h>
#include <stdlib.h>
#include "funcionesDeListas.h"

void eliminarValorDeLista(int valor,nodo * punteroAlNodo);

int main()
{
    nodo lista = NULL;
    agregarValorAlaLista(1,&lista);
    agregarValorAlaLista(10,&lista);
    agregarValorAlaLista(2,&lista);
    agregarValorAlaLista(5,&lista);
    agregarValorAlaLista(3,&lista);
    agregarValorAlaLista(5,&lista);

    imprimirElementosDeLista(lista);

    printf("\nBorramos el primer 5...\n");
    eliminarValorDeLista(5, &lista);

    imprimirElementosDeLista(lista);

    return 0;
}

void eliminarValorDeLista(int valor,nodo * punteroAlNodo){

    nodo auxiliar = NULL;

    if((*punteroAlNodo) != NULL ){

        if( (*punteroAlNodo)->valor == valor ){
            auxiliar = (*punteroAlNodo);
            (*punteroAlNodo) = (auxiliar)->siguienteNodo;
            free(auxiliar);

            //eliminarValorDeLista(valor, punteroAlNodo); //Esto permite borrar todos los valores que coincidan con el valor pasado. Fijarse si esta bien
        }
        else{
            eliminarValorDeLista(valor, &((*punteroAlNodo)->siguienteNodo));
        }
    }

}
