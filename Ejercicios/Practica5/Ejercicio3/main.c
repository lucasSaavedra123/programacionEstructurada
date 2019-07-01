#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarNumeroLista(nodo *, int);
void eliminarNumeroLista(nodo *, int);
void imprimirLista(nodo);

int main(){

    nodo listaDeNumeros;
    listaDeNumeros = NULL;

    agregarNumeroLista(&listaDeNumeros, 1);
    agregarNumeroLista(&listaDeNumeros, 20);
    agregarNumeroLista(&listaDeNumeros, -3);
    agregarNumeroLista(&listaDeNumeros, 15);
    agregarNumeroLista(&listaDeNumeros, 0);

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);
    printf("\n");

    eliminarNumeroLista(&listaDeNumeros, 20);
    eliminarNumeroLista(&listaDeNumeros, 0);

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);


    return 0;
}

void agregarNumeroLista(nodo * direccionDelNodoDeLaLista, int nuevoNumero){

    if( (*direccionDelNodoDeLaLista) == NULL ){
        (*direccionDelNodoDeLaLista) = malloc( sizeof(struct s_nodo) );
        (*direccionDelNodoDeLaLista)->siguienteNodo = NULL;
        (*direccionDelNodoDeLaLista)->valor = nuevoNumero;
    }
    else{
        agregarNumeroLista(&( (*direccionDelNodoDeLaLista)->siguienteNodo), nuevoNumero);
    }

}

void eliminarNumeroLista(nodo * direccionDelNodoDeLista, int numeroEliminar){
    nodo nodoAuxiliar = NULL;

    if( (*direccionDelNodoDeLista) != NULL){

        if( (*direccionDelNodoDeLista)->valor == numeroEliminar ){
            nodoAuxiliar = (*direccionDelNodoDeLista);
            (*direccionDelNodoDeLista) = (*direccionDelNodoDeLista)->siguienteNodo;
            free(nodoAuxiliar);
        }
        else{
            eliminarNumeroLista( &((*direccionDelNodoDeLista)->siguienteNodo), numeroEliminar );
        }

    }
}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n", nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}
