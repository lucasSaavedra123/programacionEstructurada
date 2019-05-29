#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    int valor;
    struct s_nodo * sig;
};

typedef struct s_nodo * t_nodo;

void agregarElementoAlista(int,t_nodo *);

int main()
{
    t_nodo listaDeNumeros = NULL;
    agregarElementoAlista(5,&listaDeNumeros);
    return 0;
}


void agregarElementoAlista(int numero, t_nodo * punteroAlistaDeNumeros){

    if(*(punteroAlistaDeNumeros) == NULL){
        *punteroAlistaDeNumeros = malloc(sizeof(struct s_nodo));
        (*(*punteroAlistaDeNumeros)).valor = numero;
        (*(*punteroAlistaDeNumeros)).sig = NULL;
    }
    else
        agregarElementoAlista(numero, (*(*punteroAlistaDeNumeros)).sig );
}
