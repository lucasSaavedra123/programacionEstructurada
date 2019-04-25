#include <stdio.h>
#include <stdlib.h>


/*

PUNTERO: Es una variable. Sirve para guardar direcciones de memoria

*/

int main()
{
    int numero1,numero2,tot;
    char a = 64; //Es de tipo caracter
    char * puntero_a = NULL;    //Se define un puntero. Este guardará direcciones de memoria
                                //Este es un puntero de un caracter. Puntero char. Si no se le asigna nada, tiene basura.
                                //Podemos igualarlo a NULL (es mas generico para los sistemas operativos).
                                //Un puntero puede tener hasta 4 bytes

    puntero_a = &a; //El ampersan aca da la dirección de memoria de la variable
                    //Para cambiar la direccion de memoria, hay que pedirle permiso al sistema operativo

    //Area de memoria estatica, no se puede modificar
    //Area de memoria dinamica, se puede modificar, cambiar

    //El programa se carga en un sistema operativo
    //Proceso es el programa junto con otras cosas

    /*

    Hay variables tanto para el proceso y para todos los otros
    que haya en el sistema

    */

    /*Impresion de la informacion*/


    /*

    * --->Da el contenido de la memoria

    * 54 = Dame en contenido de la posicion 54

    */

    printf("El contenido de a es %d\n",a);
    printf("El contenido de a es %d\n", *puntero_a);//Se puede conseguir la información haciendo * y un puntero (nos da el contenido de esa dirección)
    printf("El contenido de a es %d\n", *(&a));
    printf("La dirección de a es %d\n", puntero_a);
    printf("La dirección de a es %d\n", &a);

    /*

    Las funciones estan espacios de memoria distintas
    Es por eso que al pasar enteros a otra funcion,
    Si 'a' la la paso a la 'a' de la otra función, ya no tienen nada que ver
    Con los punteros podemos hacer que las funciones se comuniquen entre si

    Las funciones tienen un espacio de memoria diferente
    */

    /*Un arreglo es un puntero*/


    tot = suma(numero1,numero2);
    suma2(numero1,numero2, &tot);

    printf("%d", tot);

    return 0;
}

void suma(int a, int b){
    return a + b;
}

void suma2 (int a, int b, int * suma){
    //Pasamos la referencia de la variable

    *suma = a + b; //Guardame la suma en la direccion de la memoria suma

}
