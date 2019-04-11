#include <stdio.h>
#include <stdlib.h>
#define MAXCHARACTERS 100
#define MAXPERSONAS 50

struct persona{
    int dni;
    char nombre[MAXCHARACTERS];
    char pais[MAXCHARACTERS];
};

void importarPersonasDelArchivoAlStruct(char nombreDelArchivo[], struct persona arregloDePersonas[MAXPERSONAS]){
    int i;
    FILE* archivo = fopen(nombreDelArchivo, "r");

    for( i=0; fscanf(archivo, "%d,%[^,],%s",   &arregloDePersonas[i].dni,
                                                arregloDePersonas[i].nombre,
                                                arregloDePersonas[i].pais) != EOF && i < MAXPERSONAS-1; i++){}

    arregloDePersonas[i].dni = EOF;

    fclose(archivo);
}

void imprimirTablaPersonas(){
    int i;
    struct persona arregloDePersonas[MAXPERSONAS];

    importarPersonasDelArchivoAlStruct("personas.txt", arregloDePersonas);

    //Cabeceras
    printf("%-20s","Documento");
    printf("%-20s","Nombre");
    printf("%-20s","Pais");

    printf("\n");

    for(i=0; i<60;i++){
        printf("=");
    }

    printf("\n");

    for(i=0; arregloDePersonas[i].dni != EOF ;i++){
        printf("%-20d",arregloDePersonas[i].dni);
        printf("%-20s",arregloDePersonas[i].nombre);
        printf("%-20s",arregloDePersonas[i].pais);
        printf("\n");
    }

}



int main()
{

    imprimirTablaPersonas();

    return 0;
}
