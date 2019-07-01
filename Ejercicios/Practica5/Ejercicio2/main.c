#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void insertarNumeroLista(nodo *, int);
void imprimirLista(nodo);
void imprimirListaReversa(nodo);

int main()
{
    nodo listaDeNumeros = NULL;

    insertarNumeroLista(&listaDeNumeros, 1);
    insertarNumeroLista(&listaDeNumeros, 20);
    insertarNumeroLista(&listaDeNumeros, 5);
    insertarNumeroLista(&listaDeNumeros, 0);
    insertarNumeroLista(&listaDeNumeros, 30);
    insertarNumeroLista(&listaDeNumeros, -14);

    imprimirLista(listaDeNumeros);

    return 0;
}

void insertarNumeroLista(nodo * direccionDelNodoDeLaLista, int nuevoNumero){

    nodo nodoAuxiliar = NULL;

    if( (*direccionDelNodoDeLaLista) == NULL || (*direccionDelNodoDeLaLista)->valor > nuevoNumero ){//Es Clave el orden de esta condicional. Si lo ponemos al reves no anda directamente
        nodoAuxiliar = malloc( sizeof(struct s_nodo) );
        nodoAuxiliar->siguienteNodo = (*direccionDelNodoDeLaLista);
        nodoAuxiliar->valor = nuevoNumero;
        (*direccionDelNodoDeLaLista) = nodoAuxiliar;
    }

    else{
        insertarNumeroLista(&((*direccionDelNodoDeLaLista)->siguienteNodo) , nuevoNumero);
    }


}


void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n", nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}
