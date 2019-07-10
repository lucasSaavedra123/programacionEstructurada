#include <stdio.h>
#include <stdlib.h>

/*
PARA VISUALIZAR ARBOLES:ructurada/Ejercicios/Practica5/
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
    return 0;
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
