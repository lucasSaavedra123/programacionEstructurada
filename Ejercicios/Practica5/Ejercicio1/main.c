#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarNumeroLista(int, nodo *);
void imprimirLista(nodo);
void imprimirListaReversa(nodo);

int main(){

    nodo listaDeNumeros;
    listaDeNumeros = NULL;

    agregarNumeroLista(4, &listaDeNumeros);
    agregarNumeroLista(10, &listaDeNumeros);
    agregarNumeroLista(-3, &listaDeNumeros);
    agregarNumeroLista(25, &listaDeNumeros);
    agregarNumeroLista(-8, &listaDeNumeros);

    printf("-------LISTA-------\n");
    imprimirLista(listaDeNumeros);
    printf("\n");
    printf("---LISTA REVERSA---\n");
    imprimirListaReversa(listaDeNumeros);

    return 0;
}

void agregarNumeroLista(int nuevoNumero, nodo * direccionDelNodoDeLaLista){

    if( (*direccionDelNodoDeLaLista) == NULL ){
        (*direccionDelNodoDeLaLista) = malloc( sizeof(struct s_nodo) );
        (*direccionDelNodoDeLaLista)->siguienteNodo = NULL;
        (*direccionDelNodoDeLaLista)->valor = nuevoNumero;
    }
    else{
        agregarNumeroLista(nuevoNumero, &( (*direccionDelNodoDeLaLista)->siguienteNodo) );
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
