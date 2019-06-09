#include <stdio.h>
#include <stdlib.h>

/*
El primer elemento del arbol se lo llama arbol raiz
y solo puede haber un solo principal.

Los demas elementos son elementos 'hojas'.

Cada división entre 'nodos' se lo llama nivel.

En los arboles se puede agregar, eliminar y recorrer

Recordar que los datos en un arbol se dan de manera ordenada
Lo veremos ahora en la recursividad

Aca vemos arboles binarios.


Hay 4 formas de recorrido:
-Recorrido en pre-order.
    Visita el nodo padre,
    recorre el subarbol izquierdo,
    y despues recorre el subarbol derecho.

-Recorrido en in-order.
    Recorre el subarbol izquierdo,
    visita el nodo padre,
    y recorre el subarbol derecho.

-Recorrido en post-order. (Sirve para eliminar)
    Recorre el subarbol izquierdo,
    recorre el subarbol derecho,
    y luego visita al nodo padre.

-Recorrido por niveles. (Este no lo vamos a ver)


*/

void agregar(t_nodo_bin * arbol, int valor);

int main()
{
    return 0;
}

void agregar(t_nodo_bin * arbol, int valor){
    if(*arbol == NULL){

    }
    else{
        if(valor < (*arbol)->valor)
            agregar(&(*arbol)->izq, valor);
        else
            agregar(&(*arbol)->der, valor);

        //Los va ingresando ordenadamente
    }
}
