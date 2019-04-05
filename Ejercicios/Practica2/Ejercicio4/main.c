#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXCHARACTERS 100


struct persona{
    int dni;
    char nombre[MAXCHARACTERS];
    char pais[MAXCHARACTERS];
};

void agregarPersonaAlArchivo(struct persona personaNueva, char nombreDelArchivo[]){
    FILE* archivo = fopen(nombreDelArchivo,"w");

    //Lo hacemos en varias instrucciones para que sea comodo de visualizar
    fprintf(archivo, "%d,", personaNueva.dni);
    fprintf(archivo, "%s,", personaNueva.nombre);
    fprintf(archivo, "%s\n", personaNueva.pais);

    fclose(archivo);
}

int main()
{
    return 0;
}
