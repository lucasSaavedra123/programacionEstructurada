#include <stdio.h>
#include <stdlib.h>
#include "../structsFile.h"
#include "funcionesDeArboles.h"

void agregarElementoAlArbol(nodoArbol * arbol, int valor);//Se supone para poner valores no repetidos

int main()
{
    return 0;
}

void agregarElementoAlArbol(nodoArbol * arbol, int valor){

        if (*arbol == NULL){
            *arbol = malloc(sizeof(struct s_nodo_bin));
            (*arbol)->valor = valor;
            (*arbol)->nodoIzquierda = NULL;
            (*arbol)->nodoDerecha = NULL;
        }

        else{
            //Por izquierda van a estar los numeros mas chicos
            //Es una forma de ingresar datos a un arbol
            //Es por eso que los datos presentan un orden
            if (valor < (*arbol)->valor)
                agregarElementoAlArbol(& ((*arbol)->nodoIzquierda), valor);
            else
                agregarElementoAlArbol(& ((*arbol)->nodoDerecha), valor);
        }
}
