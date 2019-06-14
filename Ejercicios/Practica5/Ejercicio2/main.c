#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void insertarNumeroALista(int, nodo *);
void imprimirLista(nodo);

int main()
{
    nodo listaDeNumeros = NULL;

    insertarNumeroALista(2, &listaDeNumeros);
    insertarNumeroALista(1, &listaDeNumeros);
    insertarNumeroALista(10,&listaDeNumeros);
    insertarNumeroALista(5, &listaDeNumeros);
    insertarNumeroALista(4, &listaDeNumeros);


    imprimirLista(listaDeNumeros);

    return 0;
}

void insertarNumeroALista(int numero, nodo * direccionDelNodo){

    nodo nodoAuxiliar; //Al correr el valor, lo tiramos aca y listo

    if( (*direccionDelNodo) == NULL ){

        (*direccionDelNodo) = malloc( sizeof(struct s_nodo) );
        (*direccionDelNodo)->valor = numero;
        (*direccionDelNodo)->siguienteNodo = NULL;

    }
    else{

        if( (*direccionDelNodo)->valor > numero ){

            nodoAuxiliar = malloc(sizeof(struct s_nodo));
            (*nodoAuxiliar) = (*(*direccionDelNodo));//Ya guardamos este nodo en otro lado
            (*direccionDelNodo)->valor = numero;
            (*direccionDelNodo)->siguienteNodo = nodoAuxiliar;

        }
        else{

            insertarNumeroALista(numero, &((*direccionDelNodo)->siguienteNodo));

        }

    }

}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n", nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}
