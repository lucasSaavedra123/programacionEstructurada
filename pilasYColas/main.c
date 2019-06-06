#include <stdio.h>
#include <stdlib.h>

//Pilas Y Colas
/*
Pilas:
-Elementos apilados
-El primero en entrar es el ultimo en salir
-Diseñaremos las funciones 'apilar' y 'desapilar'
                            'push'       'pop'
-Pila solo tiene información del que sigue

Colas:
-Imaginemos una cola de personas

    PERSONA1    PERSONA2    PERSONA3

La ultima que entro es la persona 3
Pero la primera en salir es la persona 1

-Tenemos las funciones 'queue' y 'dequeue'
-Cada cola tiene información de la que tenia antes y la que tiene despues
*/


/*EN PILAS*/

struct s_nodo{
    int valor;
    struct s_nodo * sig;
};

typedef struct s_nodo * t_nodo;

void push(t_nodo *, int);
int pop(t_nodo *); //Devuelve el valor del elemento

/*EN PILAS*/


/*EN COLAS*/
struct s_cola{
    t_nodo frente;
    t_nodo ultima;
};
typedef struct s_cola t_cola;

void queue(t_cola *, int);
int dequeue(t_cola *); //Devuelve el valor del element

/*EN COLAS*/

int main()
{


    return 0;
}

/*FUNCIONES DE PILAS*/
void push(t_nodo * pila, int valor){
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo));//t_nodo no es realmente necesario ponerlo, pero depende del compilador y tambien puede resultar mas formal
    aux->valor = valor;
    aux->sig = *pila;
    *pila = aux;
}

int pop(t_nodo * pila){
    int valor;
    t_nodo aux = *pila;

    valor = aux->valor;
    *pila = aux->sig;
    free(aux);

    return valor;
}
/*FUNCIONES DE PILAS*/


/*FUNCIONES DE PILAS*/
void queue(t_cola * cola, int valor){
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sig = NULL;//No tiene predecesor

    if(cola->frente == NULL && cola->ultima == NULL){
        //Si es el primer elemento...
        cola->frente = aux;
        cola->ultima = aux;
    }
    else{
        cola->ultima->sig = aux;
        cola->ultima = aux;
    }

}

int dequeue(t_cola * cola){
    int valor;
    t_nodo aux = cola->frente;
    cola->frente = cola->frente->sig;
    valor = aux->valor;
    free(aux);

    if(cola->frente == NULL){
        cola->ultima = NULL;
    }

    return valor;
}

/*FUNCIONES DE PILAS*/
