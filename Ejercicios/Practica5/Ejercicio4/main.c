#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarNumeroLista(nodo *, int);
void eliminarPosicionLista(nodo *, int);
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

    eliminarPosicionLista(&listaDeNumeros, 2);
    eliminarPosicionLista(&listaDeNumeros, 0);

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

void eliminarPosicionLista(nodo * direccionDelNodoDeLista, int posicion){
    nodo nodoAuxiliar = NULL;

    if( (*direccionDelNodoDeLista) != NULL ){ //Aunque pongamos un numero de posicion muy grande,
                                              //si llegamos al NULL, se corta todo.
        if( posicion == 0 ){
            nodoAuxiliar = (*direccionDelNodoDeLista);
            (*direccionDelNodoDeLista) = (*direccionDelNodoDeLista)->siguienteNodo;
            free(nodoAuxiliar);
        }

        else{
            eliminarPosicionLista( &((*direccionDelNodoDeLista)->siguienteNodo) , posicion-1 );
        }

    }

}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n", nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}
