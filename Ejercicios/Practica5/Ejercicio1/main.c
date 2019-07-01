#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarNumeroLista(nodo *, int);
void imprimirLista(nodo);
void imprimirListaReversa(nodo);

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
    printf("---LISTA REVERSA---\n");
    imprimirListaReversa(listaDeNumeros);

    return 0;
}

void agregarNumeroLista(nodo * direccionDelNodoDeLaLista, int nuevoNumero){

    if( (*direccionDelNodoDeLaLista) == NULL ){
        (*direccionDelNodoDeLaLista) = malloc( sizeof(struct s_nodo) );
        (*direccionDelNodoDeLaLista)->siguienteNodo = NULL;
        (*direccionDelNodoDeLaLista)->valor = nuevoNumero;
    }
    else{
        agregarNumeroLista(&( (*direccionDelNodoDeLaLista)->siguienteNodo), }nuevoNumero);
    }

}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n", nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}

void imprimirListaReversa(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        imprimirListaReversa(nodoDeLista->siguienteNodo);
        printf("%d\n", nodoDeLista->valor);
    }
}
