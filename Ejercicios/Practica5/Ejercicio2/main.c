#include <stdio.h>
#include <stdlib.h>
#include "funcionesDeListas.h" //Tiene tambien al struct de nodo

void agregarValorAlaListaOrdenadamenteASC(int valor, nodo * punteroAlNodo);

int main()
{
    nodo lista = NULL;

    //Probamos con todos estos valores y despues lo imprimimos
    agregarValorAlaListaOrdenadamenteASC(1,&lista);
    agregarValorAlaListaOrdenadamenteASC(6,&lista);
    agregarValorAlaListaOrdenadamenteASC(2,&lista);
    agregarValorAlaListaOrdenadamenteASC(-1,&lista);
    agregarValorAlaListaOrdenadamenteASC(25,&lista);
    agregarValorAlaListaOrdenadamenteASC(10,&lista);
    agregarValorAlaListaOrdenadamenteASC(-1,&lista);

    imprimirElementosDeLista(lista);

    return 0;
}

void agregarValorAlaListaOrdenadamenteASC(int valor, nodo * punteroAlNodo){
        nodo nuevoEspacio = NULL;   //Aca guardamos el lugar
                                    //donde vamos a poner el numero a mover para
                                    //dejar ordenada la lista

        if((*punteroAlNodo) == NULL){
            //Llego a ser el ultimo elemento de la lista
            (*punteroAlNodo) = malloc(sizeof(struct s_nodo));
            (*punteroAlNodo)->valor = valor;
            (*punteroAlNodo)->siguienteNodo = NULL;
        }

        else{
           //Tiene informacion. Entonces la comparamos.
            if((*punteroAlNodo)->valor > valor){

                nuevoEspacio = malloc(sizeof(struct s_nodo));   //Asignamos el nuevo espacio
                                                                //donde guardaremos la informacion
                                                                //del nodo actual

                (*nuevoEspacio) = *(*punteroAlNodo);            //Copiamos los datos

                (*punteroAlNodo)->valor = valor;                //Reemplamos los datos
                (*punteroAlNodo)->siguienteNodo = nuevoEspacio;

            }

            else{
                agregarValorAlaListaOrdenadamenteASC(valor, &( (*punteroAlNodo)->siguienteNodo) );
            }

        }
}
