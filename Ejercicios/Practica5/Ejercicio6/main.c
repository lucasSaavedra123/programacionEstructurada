#include <stdio.h>
#include <stdlib.h>

/*

Las operaciones que podemos definir sobre un Arbol Binario son:

-Agregar datos: si el árbol está vacío, podemos insertar valores. Si no lo está, agregaremos el dato a
izquierda, si el valor a agregar es menor que el valor del nodo donde estamos parados, o a derecha
en caso contrario. La operación es recursiva hasta alcanzar un subárbol (nodo) vacío.

-Eliminar datos: sólo podremos eliminar nodos hojas; en caso de querer eliminar un nodo que no es
hoja, deberemos eliminar todo el subárbol correspondiente.

-Recorrer un árbol: al ser una estructura no lineal, existen diferentes maneras de hacerlo. Se
desarrollarán más adelante.

*/

struct s_nodo_bin
{
    int valor;
    struct s_nodo_bin* nodoIzquierda;
    struct s_nodo_bin* nodoDerecha;
};

typedef struct s_nodo_bin * nodoArbol;

void agregarElementoAlArbol(nodoArbol * arbol, int valor);//Se supone para poner valores no repetidos
void eliminarValorDelArbol(nodoArbol * arbol, int valor);

void preorder(nodoArbol arbol); //Se imprime la informacion del nodo en estas funciones
void inorder(nodoArbol arbol);//Notar que este imprime de forma ordenada
void postOrder(nodoArbol arbol);
void porNivel(nodoArbol arbol);//FALTA ESTE

int main()
{
    nodoArbol arbolDeNumeros = NULL;
    agregarElementoAlArbol(&arbolDeNumeros, 10);
    agregarElementoAlArbol(&arbolDeNumeros, 8);
    agregarElementoAlArbol(&arbolDeNumeros, 12);
    agregarElementoAlArbol(&arbolDeNumeros, 6);
    agregarElementoAlArbol(&arbolDeNumeros, 9);
    agregarElementoAlArbol(&arbolDeNumeros, 5);
    agregarElementoAlArbol(&arbolDeNumeros, 7);
    agregarElementoAlArbol(&arbolDeNumeros, 11);
    agregarElementoAlArbol(&arbolDeNumeros, 15);

    preorder(arbolDeNumeros);
    printf("\n");
    inorder(arbolDeNumeros);
    printf("\n");
    postOrder(arbolDeNumeros);

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


void preorder(nodoArbol arbol){
    if(arbol != NULL){
        printf("%d\n",arbol->valor);
        preorder(arbol->nodoIzquierda);
        preorder(arbol->nodoDerecha);
    }
}

void inorder(nodoArbol arbol){
    if(arbol != NULL){
        inorder(arbol->nodoIzquierda);
        printf("%d\n",arbol->valor);
        inorder(arbol->nodoDerecha);
    }
}

void postOrder(nodoArbol arbol){
    if(arbol != NULL){
        postOrder(arbol->nodoIzquierda);
        postOrder(arbol->nodoDerecha);
        printf("%d\n",arbol->valor);
    }
}

void porNivel(nodoArbol arbol){
    //QUIERO VER COMO HACER ESTE
}
