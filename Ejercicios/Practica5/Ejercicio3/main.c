#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarNumeroALista(int, nodo *);
void eliminarNumeroDeLaLista(int, nodo *);
void imprimirLista(nodo);

int main()
{
    nodo listaDeNumeros = NULL;

    agregarNumeroALista(5, &listaDeNumeros);
    agregarNumeroALista(10, &listaDeNumeros);
    agregarNumeroALista(9, &listaDeNumeros);
    agregarNumeroALista(2, &listaDeNumeros);

    eliminarNumeroDeLaLista(10, &listaDeNumeros);

    imprimirLista(listaDeNumeros);

    return 0;
}

void agregarNumeroALista(int numero, nodo * direccionDelNodo){
    if( (*direccionDelNodo) == NULL ){
        (*direccionDelNodo) = malloc( sizeof(struct s_nodo) );
        (*direccionDelNodo)->valor = numero;
        (*direccionDelNodo)->siguienteNodo = NULL;
    }
    else{
        agregarNumeroALista(numero, &((*direccionDelNodo)->siguienteNodo) );
    }
}

void eliminarNumeroDeLaLista(int numero, nodo * direccionDelNodo){

    nodo nodoAuxiliar;

    if( (*direccionDelNodo) != NULL ){

        if( (*direccionDelNodo)->valor == numero ){
            nodoAuxiliar = (*direccionDelNodo);
            (*direccionDelNodo)= nodoAuxiliar->siguienteNodo;
            free(nodoAuxiliar);
        }

        else{
            eliminarNumeroDeLaLista(numero, & ((*direccionDelNodo)->siguienteNodo) );
        }

    }



}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n", nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}
