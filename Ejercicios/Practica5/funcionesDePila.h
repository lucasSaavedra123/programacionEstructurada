
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
