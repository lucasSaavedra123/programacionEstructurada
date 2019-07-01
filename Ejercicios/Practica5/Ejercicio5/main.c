#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

struct s_cola{
    nodo nodoFrente;
    nodo nodoFinal;
};

typedef struct s_cola cola;

void push(nodo *, int);
int pop(nodo *);
void queue(cola *, int);
int dequeue(cola *);


int main()
{
    nodo pilaDeNumeros = NULL;

    cola colaDeNumeros;
    colaDeNumeros.nodoFrente = NULL;
    colaDeNumeros.nodoFinal = NULL;

    push(&pilaDeNumeros, 2);
    push(&pilaDeNumeros, -5);
    push(&pilaDeNumeros, 0);
    push(&pilaDeNumeros, 1);
    push(&pilaDeNumeros, 21);

    printf("---ELEMENTOS DE LA PILA---\n");
    while(pilaDeNumeros != NULL){
        printf("%d\n", pop(&pilaDeNumeros));
    }
    printf("\n");

    queue(&colaDeNumeros, 10);
    queue(&colaDeNumeros, 6);
    queue(&colaDeNumeros, -5);
    queue(&colaDeNumeros, 7);

    printf("---ELEMENTOS DE LA COLA---\n");
    while(colaDeNumeros.nodoFinal != NULL){
        printf("%d\n", dequeue(&colaDeNumeros));
    }
    printf("\n");
    return 0;
}

void push(nodo * direccionDelNodoDeLaPila, int numeroNuevo){
    nodo nuevoNodo = malloc( sizeof(struct s_nodo) );
    nuevoNodo->valor = numeroNuevo;
    nuevoNodo->siguienteNodo = (*direccionDelNodoDeLaPila);
    (*direccionDelNodoDeLaPila) = nuevoNodo;
}

int pop(nodo * direccionDelNodoDelaPila){
    nodo nodoAuxiliar = NULL;
    int primerNumeroDeLaPila = 0;

    nodoAuxiliar = (*direccionDelNodoDelaPila);
    primerNumeroDeLaPila = nodoAuxiliar->valor;
    (*direccionDelNodoDelaPila) = nodoAuxiliar->siguienteNodo;
    free(nodoAuxiliar);

    return primerNumeroDeLaPila;
}

void queue(cola * direccionDeLaCola, int nuevoNumero){
    nodo nodoNuevo = NULL;
    nodoNuevo = malloc(sizeof(struct s_nodo));
    nodoNuevo->valor = nuevoNumero;
    nodoNuevo->siguienteNodo = NULL;

    if(direccionDeLaCola->nodoFinal == NULL && direccionDeLaCola->nodoFrente == NULL){
        direccionDeLaCola->nodoFinal = nodoNuevo;
        direccionDeLaCola->nodoFrente = nodoNuevo;
    }
    else{
        direccionDeLaCola->nodoFinal->siguienteNodo = nodoNuevo;
        direccionDeLaCola->nodoFinal = nodoNuevo;
    }

}

int dequeue(cola * direccionDeLaCola){
    int primerNumeroDeLaCola = 0;
    nodo nodoAuxiliar =  direccionDeLaCola->nodoFrente;
    direccionDeLaCola->nodoFrente = direccionDeLaCola->nodoFrente->siguienteNodo;
    primerNumeroDeLaCola =  nodoAuxiliar->valor;

    free(nodoAuxiliar);

    if(direccionDeLaCola->nodoFrente == NULL){
        direccionDeLaCola->nodoFinal = NULL;
    }

    return primerNumeroDeLaCola;
}
