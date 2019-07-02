#include <stdio.h>
#include <stdlib.h>

struct s_nodo_bin
{
    int valor;
    struct s_nodo_bin * nodoIzquierda;
    struct s_nodo_bin * nodoDerecha;
};

typedef struct s_nodo_bin * nodoArbolBinario;

void agregarNumeroAlArbolBinario(nodoArbolBinario *, int);
nodoArbolBinario * darDireccionDelNodoDelNumero(nodoArbolBinario *, int);
void eliminarArbolDeNumeros(nodoArbolBinario *);
void eliminarValorDelArbol(nodoArbolBinario *, int);
void inorder(nodoArbolBinario);

int main()
{
    nodoArbolBinario arbolBinarioDeNumeros = NULL;
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 2);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -5);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 10);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 25);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 1);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 0);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -2);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 17);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -3);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, -1);
    agregarNumeroAlArbolBinario(&arbolBinarioDeNumeros, 100);

    printf("---IMPRIMIR INORDER---\n");
    inorder(arbolBinarioDeNumeros);
    printf("\n");

    eliminarValorDelArbol(&arbolBinarioDeNumeros, 10);

    printf("---IMPRIMIR INORDER---\n");
    inorder(arbolBinarioDeNumeros);
    printf("\n");

    return 0;
}

void agregarNumeroAlArbolBinario(nodoArbolBinario * direccionDelArbolDeNumeros, int numeroNuevo){

    if( (*direccionDelArbolDeNumeros) == NULL ){
        (*direccionDelArbolDeNumeros) = malloc( sizeof(struct s_nodo_bin) );
        (*direccionDelArbolDeNumeros)->nodoDerecha = NULL;
        (*direccionDelArbolDeNumeros)->nodoIzquierda = NULL;
        (*direccionDelArbolDeNumeros)->valor = numeroNuevo;
    }

    else{
        if( (*direccionDelArbolDeNumeros)->valor > numeroNuevo )
            agregarNumeroAlArbolBinario( &((*direccionDelArbolDeNumeros)->nodoIzquierda) , numeroNuevo);
        else if( (*direccionDelArbolDeNumeros)->valor < numeroNuevo )
            agregarNumeroAlArbolBinario( &((*direccionDelArbolDeNumeros)->nodoDerecha) , numeroNuevo);
    }

}

nodoArbolBinario * darDireccionDelNodoDelNumero (nodoArbolBinario * direccionDelArbolDeNumeros, int numeroBuscado){

    if((*direccionDelArbolDeNumeros) == NULL){
        return NULL;
    }

    else if( (*direccionDelArbolDeNumeros) != NULL){
        if((*direccionDelArbolDeNumeros)->valor == numeroBuscado){
            return direccionDelArbolDeNumeros;
        }

        else
        {
            if(numeroBuscado < (*direccionDelArbolDeNumeros)->valor){
                return darDireccionDelNodoDelNumero ( &((*direccionDelArbolDeNumeros)->nodoIzquierda), numeroBuscado);
            }
            if(numeroBuscado > (*direccionDelArbolDeNumeros)->valor){
                return darDireccionDelNodoDelNumero ( &((*direccionDelArbolDeNumeros)->nodoDerecha), numeroBuscado);
            }
        }
    }

}

void eliminarArbolDeNumeros(nodoArbolBinario * direccionDelArbolDeNumeros){

    if((*direccionDelArbolDeNumeros) != NULL){
        eliminarArbolDeNumeros(&((*direccionDelArbolDeNumeros)->nodoIzquierda));
        eliminarArbolDeNumeros(&((*direccionDelArbolDeNumeros)->nodoDerecha));

        free(*direccionDelArbolDeNumeros);
        (*direccionDelArbolDeNumeros) = NULL;
    }
}

void inorder(nodoArbolBinario arbolBinarioDeNumeros){
    if(arbolBinarioDeNumeros != NULL){
        inorder(arbolBinarioDeNumeros->nodoIzquierda);
        printf("%d\n",arbolBinarioDeNumeros->valor);//Visitar al nodo padre
        inorder(arbolBinarioDeNumeros->nodoDerecha);
    }
}

void eliminarValorDelArbol(nodoArbolBinario * direccionDelArbolDeNumeros, int valor){
    nodoArbolBinario * direccionDelNodo = darDireccionDelNodoDelNumero(direccionDelArbolDeNumeros,valor);
    eliminarArbolDeNumeros(direccionDelNodo);
}
