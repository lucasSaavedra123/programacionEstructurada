#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXCHARACTERS 100
#define MAXCANTIDAD 2


struct persona{
    int dni;
    char nombre[MAXCHARACTERS];
    char pais[MAXCHARACTERS];
};


void agregarPersonaAlArchivo(struct persona personaNueva, char nombreDelArchivo[]){
    FILE* archivo = fopen(nombreDelArchivo,"a");

    //Lo hacemos en varias instrucciones para que sea comodo de visualizar
    fprintf(archivo, "%d,", personaNueva.dni);
    fprintf(archivo, "%s,", personaNueva.nombre);
    fprintf(archivo, "%s\n", personaNueva.pais);

    fclose(archivo);
}

void cargarPersonas(){
    struct persona personaNueva;
    int contador;

    printf("Ingrese DNI (0 Para frenar el registro): ");
    scanf("%d", &personaNueva.dni);

    while(personaNueva.dni != 0 && contador < MAXCANTIDAD){

        printf("Ingrese nombre: ");
        scanf("%s", personaNueva.nombre);

        printf("Ingrese pais: ");
        scanf("%s", personaNueva.pais);

        printf("%d\n", personaNueva.dni);
        printf("%s\n", personaNueva.nombre);
        printf("%s\n", personaNueva.pais);

        agregarPersonaAlArchivo(personaNueva, "personas.txt");

        contador++;

        if(contador < MAXCANTIDAD){
        printf("Ingrese DNI (0 Para frenar el registro): ");
        scanf("%d", &personaNueva.dni);
        }

    }

}


int main()
{
    cargarPersonas();

    return 0;
}
