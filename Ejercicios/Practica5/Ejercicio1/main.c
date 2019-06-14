#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void agregarNumeroALista(int, nodo *);
void imprimirLista(nodo);
void imprimirEnReversaLista(nodo);

int main()
{
    nodo listaDeNumeros = NULL;

    agregarNumeroALista(5, &listaDeNumeros);
    agregarNumeroALista(10, &listaDeNumeros);
    agregarNumeroALista(9, &listaDeNumeros);
    agregarNumeroALista(2, &listaDeNumeros);

    imprimirEnReversaLista(listaDeNumeros);

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

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n", nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}

void imprimirEnReversaLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        imprimirEnReversaLista(nodoDeLista->siguienteNodo);
        printf("%d\n", nodoDeLista->valor);
    }
}
