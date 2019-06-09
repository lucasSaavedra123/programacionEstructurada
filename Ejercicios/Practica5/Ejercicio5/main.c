#include <stdio.h>
#include <stdlib.h>

//En este ejercicio me planteo las funciones para utilizar pilas y colas

//Definimos a un nodo
struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

//Prototipo de funciones para pilas
/*
Sobre una pila sólo es posible realizar las siguientes operaciones:

Push: permite agregar un elemento
Pop: permite quitar un elemento y obtener que dicho elemento almacenaba

La implementación de una pila podemos hacerla sobre una lista simplemente enlazada, usando el inicio de
la lista como tope de la pila. Lo hacemos así porque es el único extremo que cambia, y el que tenemos más
“a mano”: si utilizáramos el final de la lista como tope, tendríamos que recorrerla en su totalidad tanto para
agregar como para eliminar un elemento.

*/

void push(nodo * punteroAlNodo, int valor);
int pop(nodo * punteroAlNodo);

void imprimirPila(nodo pila);//ESTARIA MAL RECORRER ASI UNA PILA. LO MISMO A LAS COLAS. PERO ESTO ES SOLO PARA VISUALIZARLOS
void imprimirElementosDeLaPila(nodo pila);

//Prototipo de funciones para colas
/*
Sobre una cola sólo es posible realizar las siguientes operaciones:

Queue o encolar: agrega un elemento al final de la cola.
Dequeue o desencolar: quita un elemento del frente de la cola.

Implementaremos una cola sobre una lista simplemente enlazada. Las inserciones se producirán al final de la
lista, y las eliminaciones, desde el principio.
Dado que necesitaremos operar por ambos extremos de la lista implementación, es conveniente mantener
punteros tanto al frente como al final en forma simultánea. De esta manera, en ningún caso deberemos
recorrer la lista en su totalidad para agregar o quitar elementos.
Para poder manipular ambos extremos en forma simultánea, utilizaremos una estructura auxiliar.

*/

struct s_cola{
    nodo nodoFrente;
    nodo nodoAtras;
};

typedef struct s_cola cola;

void queue(cola * direccionDeCola, int valor);
int dequeue(cola * direccionDeCola);

int main()
{
    nodo pilaDeNumeros = NULL;
    cola colaDeNumeros;

    colaDeNumeros.nodoFrente = NULL;
    colaDeNumeros.nodoAtras = NULL;

    //PRUEBA DE PILAS

    push(&pilaDeNumeros, 7);
    push(&pilaDeNumeros, 6);
    push(&pilaDeNumeros, 10);
    push(&pilaDeNumeros, 2);

    imprimirElementosDeLaPila(pilaDeNumeros);

    printf("Notar que los elementos se fueron apilando...\n\n");

    printf("Hacemos 'pop' una vez y nos devuelve %d\n", pop(&pilaDeNumeros));

    imprimirElementosDeLaPila(pilaDeNumeros);


    //PRUEBA DE COLAS
    queue(&colaDeNumeros, 5);
    queue(&colaDeNumeros, 10);
    queue(&colaDeNumeros, 12);
    queue(&colaDeNumeros, 2);

    printf("\nSale el primer numero agregado de la cola. Ese numero es %d.\n",dequeue(&colaDeNumeros));

    return 0;
}

//FUNCIONES DE PILAS
void push(nodo * punteroAlNodo, int valor){

    nodo nodoAuxiliar = malloc( sizeof(struct s_nodo) );    //Nodo en el que se guarda la informacion que vamos a poner
    nodoAuxiliar->valor = valor;                            //Guardamos el valor en ese nodo
    nodoAuxiliar->siguienteNodo = (*punteroAlNodo);         //Guardamos la direccion del nodo que estará debajo de nosotros
    (*punteroAlNodo) = nodoAuxiliar;                        //Reemplazamos la direccion de la pila por la nueva (que es la del nodo auxiliar)

    //Recordar que la pila tiene la informacion del ultimo nodo agregado.
    //Las listas tenian la informacion de la primera que se habia agregado

}

int pop(nodo * punteroAlNodo){
    int numeroBorrado = (*punteroAlNodo)->valor;
    nodo nodoAuxiliar = (*punteroAlNodo);

    //La nueva direccion de la pila pasa a ser del que tenia abajo
    (*punteroAlNodo) = (*punteroAlNodo)->siguienteNodo;

    //Liberamos el espacio que no vamos a usar mas
    free(nodoAuxiliar);

    return numeroBorrado;
}


void imprimirPila(nodo pila){
    if(pila->siguienteNodo != NULL){
        printf("%d\n", pila->valor);
        imprimirPila(pila->siguienteNodo);
    }
    else{
        printf("%d\n", pila->valor);
    }
}

void imprimirElementosDeLaPila(nodo pila){
    printf("\n-----PILA-----\n");
    imprimirPila(pila);
    printf("-----PILA-----\n");
}


//FUNCIONES DE COLAS
void queue(cola * direccionDeCola, int valor){
    nodo nodoAuxiliar = NULL;

    nodoAuxiliar = malloc( sizeof(struct s_nodo) );
    nodoAuxiliar->valor = valor;
    nodoAuxiliar->siguienteNodo = NULL;

    if( direccionDeCola->nodoAtras == NULL && direccionDeCola->nodoFrente == NULL ){
        //Esto se hace en el caso de meter el primer elemento
        direccionDeCola->nodoAtras = nodoAuxiliar;
        direccionDeCola->nodoFrente = nodoAuxiliar;
    }
    else{
        //Esto se hace si ya hay algun elemento en la cola
        direccionDeCola->nodoAtras->siguienteNodo = nodoAuxiliar;   //El nodo que esta atras
                                                                    //(antes de que ingrese el nuevo)
                                                                    //se guarda el nodo que llega
                                                                    //y luego el nuevo nodo es el que
                                                                    //pasa a estar atras de todo
        direccionDeCola->nodoAtras = nodoAuxiliar;
    }
}

int dequeue(cola * direccionDeCola){
    int numeroDescolado = 0;
    nodo nodoAuxiliar = direccionDeCola->nodoFrente;
    numeroDescolado = nodoAuxiliar->valor;

    direccionDeCola->nodoFrente = direccionDeCola->nodoFrente->siguienteNodo;

    free(nodoAuxiliar);

    if (direccionDeCola->nodoFrente == NULL)
    {
        direccionDeCola->nodoAtras = NULL;
    }


    return numeroDescolado;


}




