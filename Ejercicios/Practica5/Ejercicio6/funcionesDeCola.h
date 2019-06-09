//En este ejercicio me planteo las funciones para utilizar pilas y colas

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

void queue(cola * direccionDeCola, int valor);
int dequeue(cola * direccionDeCola);

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
