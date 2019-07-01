#include <stdio.h>
#include <stdlib.h>

/*
PARA VISUALIZAR ARBOLES:
https://kanaka.github.io/rbt_cfs/trees.html
Acordarse que usamos los "arboles binarios de busqueda"
*/

struct s_nodo_bin
{
    int valor;
    struct s_nodo_bin * nodoIzquierda;
    struct s_nodo_bin * nodoDerecha;
};

typedef struct s_nodo_bin * nodoArbolBinario;

void agregarNumeroAlArbolBinario(nodoArbolBinario *, int);
void preorder(nodoArbolBinario);
void inorder(nodoArbolBinario);
void postorder(nodoArbolBinario);
void porNivel(nodoArbolBinario, int);

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

    printf("---IMPRIMIR PREORDER---\n");
    preorder(arbolBinarioDeNumeros);
    printf("\n");

    printf("---IMPRIMIR INORDER---\n");
    inorder(arbolBinarioDeNumeros);
    printf("\n");

    printf("---IMPRIMIR POSTORDER---\n");
    postorder(arbolBinarioDeNumeros);
    printf("\n");

    printf("---IMPRIMIR POR NIVEL---\n");
    porNivel(arbolBinarioDeNumeros, );
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

void preorder(nodoArbolBinario arbolBinarioDeNumeros){

    if(arbolBinarioDeNumeros != NULL){
        printf("%d\n",arbolBinarioDeNumeros->valor);//Visitar al nodo padre
        preorder(arbolBinarioDeNumeros->nodoIzquierda);
        preorder(arbolBinarioDeNumeros->nodoDerecha);
    }
}

void inorder(nodoArbolBinario arbolBinarioDeNumeros){
    if(arbolBinarioDeNumeros != NULL){
        inorder(arbolBinarioDeNumeros->nodoIzquierda);
        printf("%d\n",arbolBinarioDeNumeros->valor);//Visitar al nodo padre
        inorder(arbolBinarioDeNumeros->nodoDerecha);
    }
}

void postorder(nodoArbolBinario arbolBinarioDeNumeros){
    if(arbolBinarioDeNumeros != NULL){
        postorder(arbolBinarioDeNumeros->nodoIzquierda);
        postorder(arbolBinarioDeNumeros->nodoDerecha);
        printf("%d\n",arbolBinarioDeNumeros->valor);//Visitar al nodo padre
    }
}

void porNivel(nodoArbolBinario arbolBinarioDeNumeros, int nivel){
    if(arbolBinarioDeNumeros != NULL){

        if( nivel > 0 ){//Si estamos en el nivel 0, estamos en el nivel que queremos imprimir
            porNivel(arbolBinarioDeNumeros->nodoIzquierda, nivel - 1 );
            porNivel(arbolBinarioDeNumeros->nodoDerecha, nivel - 1 );
        }
        else if(nivel == 0){
            printf("%d\n", arbolBinarioDeNumeros->valor);
        }

    }
}
