#include <stdio.h>
#include <stdlib.h>

//Definimos a un nodo
struct s_nodo{
    int valor;
    struct s_nodo * sig;
};

typedef struct s_nodo * nodo;

//Prototipo de funciones para listas
//En este ejercicio me planteo las funciones para utilizar listas
//Las listas admiten agregar, quitar elementos, recorrerla (por ejemplo para imprimirla),
//y agregar en forma ordenada (si la lista define un orden interno).

void agregarValorAlaLista(int valor, nodo * punteroAlNodo);
void eliminarValorDeLista(int valor, nodo * punteroAlNodo);
//Funcion de recorrimiento de lista. Imprimimos los elementos

void imprimirLista(nodo nodoDeLista);//Imprime la lista
void imprimirElementosDeLista(nodo nodoDeLista);//Imprime la list usando la función anterior pero lo hace mas prolijo

void imprimirListaAlReves(nodo nodoDeLista);
void imprimirElementosDeListaAlReves(nodo nodoDeLista);

int main()
{
    nodo listaDeNumeros = NULL;

    agregarValorAlaLista(14,&listaDeNumeros);
    agregarValorAlaLista(17, &listaDeNumeros);
    agregarValorAlaLista(20, &listaDeNumeros);
    agregarValorAlaLista(23, &listaDeNumeros);

    imprimirElementosDeLista(listaDeNumeros);
    imprimirElementosDeListaAlReves(listaDeNumeros);

    return 0;
}

void agregarValorAlaLista(int valor, nodo * punteroAlNodo){

    if( *punteroAlNodo == NULL){
        *(punteroAlNodo) = malloc(sizeof(struct s_nodo));
        (*(punteroAlNodo))->valor = valor;
        (*(punteroAlNodo))->sig = NULL;
    }
    else{
        agregarValorAlaLista(valor, &((*(punteroAlNodo))->sig));
    }

}

void eliminarValorDeLista(int valor,nodo * punteroAlNodo){

    nodo auxiliar = NULL;

    if((*punteroAlNodo) != NULL ){

        printf("%d-", (*punteroAlNodo)->valor);

        if( (*punteroAlNodo)->valor == valor ){
            auxiliar = (*punteroAlNodo);
            (*punteroAlNodo) = (auxiliar)->sig;
            free(auxiliar);

            eliminarValorDeLista(valor, punteroAlNodo); //Esto permite borrar todos los valores que coincidan con el valor pasado. Fijarse si esta bien
        }
        else{
            eliminarValorDeLista(valor, &((*punteroAlNodo)->sig));
        }
    }

}

void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n",nodoDeLista->valor);
        imprimirLista(nodoDeLista->sig);
    }
}

void imprimirElementosDeLista(nodo nodoDeLista){
    printf("\n-------LISTA-------\n");
    imprimirLista(nodoDeLista);
    printf("-----FIN LISTA-----\n");
}

void imprimirListaAlReves(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        imprimirListaAlReves(nodoDeLista->sig);
        printf("%d\n",nodoDeLista->valor);
    }
}

void imprimirElementosDeListaAlReves(nodo nodoDeLista){
    printf("\n --LISTA AL REVES--\n");
    imprimirListaAlReves(nodoDeLista);
    printf("-----FIN LISTA-----\n");
}
