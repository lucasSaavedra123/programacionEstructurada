//Voy agregando las funciones aca a medida que voy avanzando con los ejercicios asi no repite continuamente codigo

//Definimos a un nodo
struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};

typedef struct s_nodo * nodo;

//Prototipo de funciones para listas
void agregarValorAlaLista(int valor, nodo * punteroAlNodo);
void agregarValorAlaListaOrdenadamenteASC(int valor, nodo * punteroAlNodo);

void eliminarValorDeLista(int valor,nodo * punteroAlNodo);

//Funcion de recorrimiento de lista. Imprimimos los elementos
void imprimirLista(nodo nodoDeLista);//Imprime la lista
void imprimirElementosDeLista(nodo nodoDeLista);//Imprime la list usando la función anterior pero lo hace mas prolijo
void imprimirListaAlReves(nodo nodoDeLista);
void imprimirElementosDeListaAlReves(nodo nodoDeLista);

void agregarValorAlaLista(int valor, nodo * punteroAlNodo){

    if( *punteroAlNodo == NULL){
        *(punteroAlNodo) = malloc(sizeof(struct s_nodo));
        (*(punteroAlNodo))->valor = valor;
        (*(punteroAlNodo))->siguienteNodo = NULL;
    }
    else{
        agregarValorAlaLista(valor, &((*(punteroAlNodo))->siguienteNodo));
    }

}

void agregarValorAlaListaOrdenadamenteASC(int valor, nodo * punteroAlNodo){
        nodo nuevoEspacio = NULL;   //Aca guardamos el lugar
                                    //donde vamos a poner el numero a mover para
                                    //dejar ordenada la lista

        if((*punteroAlNodo) == NULL){
            //Llego a ser el ultimo elemento de la lista
            (*punteroAlNodo) = malloc(sizeof(struct s_nodo));
            (*punteroAlNodo)->valor = valor;
            (*punteroAlNodo)->siguienteNodo = NULL;
        }

        else{
           //Tiene informacion. Entonces la comparamos.
            if((*punteroAlNodo)->valor > valor){

                nuevoEspacio = malloc(sizeof(struct s_nodo));   //Asignamos el nuevo espacio
                                                                //donde guardaremos la informacion
                                                                //del nodo actual

                (*nuevoEspacio) = *(*punteroAlNodo);            //Copiamos los datos

                (*punteroAlNodo)->valor = valor;                //Reemplamos los datos
                (*punteroAlNodo)->siguienteNodo = nuevoEspacio;

            }

            else{
                agregarValorAlaListaOrdenadamenteASC(valor, &( (*punteroAlNodo)->siguienteNodo) );
            }

        }
}

void eliminarValorDeLista(int valor,nodo * punteroAlNodo){

    nodo auxiliar = NULL;

    if((*punteroAlNodo) != NULL ){

        if( (*punteroAlNodo)->valor == valor ){
            auxiliar = (*punteroAlNodo);
            (*punteroAlNodo) = (auxiliar)->siguienteNodo;
            free(auxiliar);

            //eliminarValorDeLista(valor, punteroAlNodo); //Esto permite borrar todos los valores que coincidan con el valor pasado. Fijarse si esta bien
        }
        else{
            eliminarValorDeLista(valor, &((*punteroAlNodo)->siguienteNodo));
        }
    }

}


void imprimirLista(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        printf("%d\n",nodoDeLista->valor);
        imprimirLista(nodoDeLista->siguienteNodo);
    }
}

void imprimirElementosDeLista(nodo nodoDeLista){
    printf("\n-------LISTA-------\n");
    imprimirLista(nodoDeLista);
    printf("-----FIN LISTA-----\n");
}

void imprimirListaAlReves(nodo nodoDeLista){
    if(nodoDeLista != NULL){
        imprimirListaAlReves(nodoDeLista->siguienteNodo);
        printf("%d\n",nodoDeLista->valor);
    }
}

void imprimirElementosDeListaAlReves(nodo nodoDeLista){
    printf("\n --LISTA AL REVES--\n");
    imprimirListaAlReves(nodoDeLista);
    printf("-----FIN LISTA-----\n");
}
