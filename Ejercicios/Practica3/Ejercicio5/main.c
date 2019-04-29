#include <stdio.h>
#include <stdlib.h>

typedef struct{
int a, b, c;
}t_tres;

//Funciones prototipo
void ordenarDeMenorMayorNumerosDeEstructura( t_tres * estructuraDeTresNumeros);

int main()
{

    t_tres estructuraDeTresNumeros;

    estructuraDeTresNumeros.a = 2;
    estructuraDeTresNumeros.b = 0;
    estructuraDeTresNumeros.c = 1;

    printf("Numeros sin orden: \n");

    printf("%d\n", estructuraDeTresNumeros.a);
    printf("%d\n", estructuraDeTresNumeros.b);
    printf("%d\n", estructuraDeTresNumeros.c);

    ordenarDeMenorMayorNumerosDeEstructura(&estructuraDeTresNumeros);

    printf("Numeros con orden: \n");

    printf("%d\n", estructuraDeTresNumeros.a);
    printf("%d\n", estructuraDeTresNumeros.b);
    printf("%d\n", estructuraDeTresNumeros.c);

    return 0;
}

void ordenarDeMenorMayorNumerosDeEstructura( t_tres * punteroDeEstructura){
    int numeroMemoria;

    if( (*punteroDeEstructura).a > (*punteroDeEstructura).b ) {
        numeroMemoria = (*punteroDeEstructura).a;
        (*punteroDeEstructura).a = (*punteroDeEstructura).b;
        (*punteroDeEstructura).b = numeroMemoria;
    }

    if( (*punteroDeEstructura).a > (*punteroDeEstructura).c ) {
        numeroMemoria = (*punteroDeEstructura).a;
        (*punteroDeEstructura).a = (*punteroDeEstructura).c;
        (*punteroDeEstructura).c = numeroMemoria;
    }

    if( (*punteroDeEstructura).b > (*punteroDeEstructura).c ) {
        numeroMemoria = (*punteroDeEstructura).b;
        (*punteroDeEstructura).b = (*punteroDeEstructura).c;
        (*punteroDeEstructura).c = numeroMemoria;
    }



}
