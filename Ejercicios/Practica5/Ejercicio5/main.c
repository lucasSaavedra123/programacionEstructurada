#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

void push(int, nodo *);
int pop(nodo *);

int main()
{
    nodo pilaDeNumeros = NULL;
    push(5, &pilaDeNumeros);

    return 0;
}

void push(int valor, nodo * direccionDelNodo){
    nodo direccionNueva = malloc( sizeof(struct s_nodo) );

    direccionNueva->valor = valor;
    direccionNueva->siguienteNodo = (*direccionDelNodo);

    (*direccionDelNodo) = direccionNueva;
}

int pop(nodo * direccionDelNodo){

}
