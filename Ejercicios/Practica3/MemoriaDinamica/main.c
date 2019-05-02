#include <stdio.h>
#include <stdlib.h>

//Memoria Dinamica

/*
Basicamente tratamos de manejar la memoria desde nuestro programa
La memoria es manejada por el sistema operativo. Un programa es un proceso
para el sistema operativo.

Stack ---> Espacio de programa fijo. Se carga el programa aca adentro. Tanto con sus variables.
Este es manejado por el sistema operativo. Si no se especifica donde crearla, se crea aca

Heap ---> Espacio de programa dinamico. Es un pedazo de memoria 'comunitario'. Todos pueden
acceder

-void * malloc(size_t);---> Le pasamos de parametro un numero entero (cantidad de bytes)
Representa la cantidad de memoria que se reserva en bytes. Reserva memoria
Devuelve un puntero al direccion de memoria del espacio que vos reservaste
Si no se pudo asignar, devuelve NULL

VOID * significa 'puntero a cualquier cosa' (a cualquier tipo)(no se especifica que tipo de dato)

-void* realloc(void*, size_t);--->Se realoja el espacio de la memoria. Devuelve nueva direccion
La dirección vieja la libera

-void free(void*);--->Libera un espacio de memoriay la seguimos teniendo en nuestro poder

*/


int cargarArreglo(int * arreglo){

        int i=0, aux;

        arreglo = (int *) malloc(sizeof(int));
        //Sizeof nos da el espacio de bytes que ocupa el tipo de dato
        //El (int *) hace que sea puntero de entero

        printf("Ingreso de dato o cero para salir: ");
        scanf("%d", &aux);

        while( aux != 0){
            *(arreglo+i) = aux;

            i++;

            arreglo = realloc(arreglo, (i+1) * sizeof(int));

            if(arreglo == NULL)
                return -1;

            scanf("%d", &aux);
        }

        *(arreglo+i) = 0;

        return 0;

}

void imprimirArrD(int * arreglo){

    int i;

    //*(arreglo+i) se puede escribir como arreglo[i]

    for(i = 0; *(arreglo+i) != 0; i++){
        printf("%d - ", *(arreglo+i));
    }


    /*No hay manera de saber donde para el arreglo o su largo*/
    /*Solo podemos pararlo con un elemento de parada*/
}


int main(){

        //En este ejemplo cargamos un arreglo
        int * arreglo = NULL;
        cargarArreglo(arreglo);
        imprimirArrD(arreglo);
        free(arreglo);//Se libera aca

        return 0;
}
