#include <stdio.h>
#include <stdlib.h>
#include "funcionesDeListas.h"

void eliminarPosicionDeLista(int posicion, nodo * punteroAlNodo);

int main()
{
    nodo lista = NULL;

    agregarValorAlaLista(2, &lista);
    agregarValorAlaLista(4, &lista);
    agregarValorAlaLista(10, &lista);
    agregarValorAlaLista(3, &lista);

    imprimirElementosDeLista(lista);

    eliminarPosicionDeLista(2, &lista);

    imprimirElementosDeLista(lista);

    return 0;
}

void eliminarPosicionDeLista(int posicion, nodo * punteroAlNodo){

    nodo auxiliar = NULL;

    if( posicion > 0 && (*punteroAlNodo) != NULL){
        eliminarPosicionDeLista(posicion-1, & ((*punteroAlNodo)->siguienteNodo) );
    }
    else{
        if((*punteroAlNodo) != NULL){
            //Quiere decir que estamos en la posicion que buscamos ya que posicion es igual a 0
            auxiliar = (*punteroAlNodo);
            (*punteroAlNodo) = (*punteroAlNodo)->siguienteNodo;
            free(auxiliar);
        }
    }

}
