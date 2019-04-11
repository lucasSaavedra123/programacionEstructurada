#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#define MAXCHARACTERS 100
#define MAXPERSONAS 50

struct persona{
    int dni;
    char nombre[MAXCHARACTERS];
    char pais[MAXCHARACTERS];
};

int strcmp(char arreglo1[], char arreglo2[]){
    int i;
    int mayorMenorOIguales = 0;

    for(i=0; arreglo1[i] != '\0' && arreglo2[i] != '\0' && arreglo1[i] == arreglo2[i]; i++){}

    if(arreglo1[i]!=arreglo2[i]){
        if(arreglo1[i] < arreglo2[i]){
            mayorMenorOIguales = -1;
        }
        else{
            mayorMenorOIguales = 1;
        }
    }

    return mayorMenorOIguales;

}

void strcpy(char arregloCopia[], char arreglo[]){
    int i;

    for(i=0; arreglo[i]!='\0' ; i++){
        arregloCopia[i]=arreglo[i];
    }

    arregloCopia[i]='\0';
}

void importarPersonasDelArchivoAlStruct(char nombreDelArchivo[], struct persona arregloDePersonas[MAXPERSONAS]){
    int i;
    FILE* archivo = fopen(nombreDelArchivo, "r");

    for( i=0; fscanf(archivo, "%d,%[^,],%s",   &arregloDePersonas[i].dni,
                                                arregloDePersonas[i].nombre,
                                                arregloDePersonas[i].pais) != EOF && i < MAXPERSONAS-1; i++){}

    arregloDePersonas[i].dni = EOF;

    fclose(archivo);
}

void imprimirTablaPersonas(struct persona arregloDePersonas[MAXPERSONAS]){
    int i;

    printf("\n");

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

     printf("\n");

}

void mostrarMenu(){
    printf("1- Ver Listado ordenado por nombre\n");
    printf("2- Ver Listado ordenado por documento\n");
    printf("3- Ver Listado ordenado por país\n");
    printf("4- Salir del programa\n");
}

int esOpcionValida(int opcion){
    int esOpcionValida = 0;

    if(opcion > 0 && opcion <= 4){
            esOpcionValida = 1;
    }

    return esOpcionValida;
}

int darOpcionMenu(){
    int opcion;

    mostrarMenu();

    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);

    while(!esOpcionValida(opcion)){
        printf("ERROR! Ingrese Opcion válida: ");
        scanf("%d", &opcion);
    }

    return opcion;

}

void intercambiarStrings(char string1[], char string2[]){
    char arregloMemoria[MAXCHARACTERS] = {0};

    strcpy(arregloMemoria, string2);
    strcpy(string2, string1);
    strcpy(string1, arregloMemoria);
}

void ordenarArregloStructPorNombre(struct persona arregloDePersonas[MAXPERSONAS]){
    int x,y;
    int memoria;

    for(x=0; arregloDePersonas[x].dni != EOF ; x++){

        for(y=x; arregloDePersonas[y].dni != EOF; y++){

            if( strcmp(arregloDePersonas[y].nombre, arregloDePersonas[x].nombre) < 0 ){
                    memoria = arregloDePersonas[x].dni;
                    arregloDePersonas[x].dni = arregloDePersonas[y].dni;
                    arregloDePersonas[y].dni = memoria;

                    intercambiarStrings(arregloDePersonas[y].nombre, arregloDePersonas[x].nombre);
                    intercambiarStrings(arregloDePersonas[y].pais, arregloDePersonas[x].pais);
            }
        }
    }
}

void ordenarArregloStructPorDNI(struct persona arregloDePersonas[MAXPERSONAS]){
    int x,y;
    int memoria;

    for(x=0; arregloDePersonas[x].dni != EOF ; x++){

        for(y=x; arregloDePersonas[y].dni != EOF; y++){

            if( arregloDePersonas[x].dni > arregloDePersonas[y].dni ){
                    memoria = arregloDePersonas[x].dni;
                    arregloDePersonas[x].dni = arregloDePersonas[y].dni;
                    arregloDePersonas[y].dni = memoria;

                    intercambiarStrings(arregloDePersonas[y].nombre, arregloDePersonas[x].nombre);
                    intercambiarStrings(arregloDePersonas[y].pais, arregloDePersonas[x].pais);
            }
        }
    }
}

void ordenarArregloStructPorPais(struct persona arregloDePersonas[MAXPERSONAS]){
    int x,y;
    int memoria;

    for(x=0; arregloDePersonas[x].dni != EOF ; x++){

        for(y=x; arregloDePersonas[y].dni != EOF; y++){

            if( strcmp(arregloDePersonas[y].pais, arregloDePersonas[x].pais) < 0 ){
                    memoria = arregloDePersonas[x].dni;
                    arregloDePersonas[x].dni = arregloDePersonas[y].dni;
                    arregloDePersonas[y].dni = memoria;

                    intercambiarStrings(arregloDePersonas[y].nombre, arregloDePersonas[x].nombre);
                    intercambiarStrings(arregloDePersonas[y].pais, arregloDePersonas[x].pais);
            }
        }
    }
}

int main()
{
    int opcion;
    struct persona arregloDePersonas[MAXPERSONAS];

    importarPersonasDelArchivoAlStruct("personas.txt", arregloDePersonas);

    opcion = darOpcionMenu();

    while(opcion != 4){

        if(opcion == 1){
            ordenarArregloStructPorDNI(arregloDePersonas);
            imprimirTablaPersonas(arregloDePersonas);
        }
        else if(opcion == 2){
            ordenarArregloStructPorNombre(arregloDePersonas);
            imprimirTablaPersonas(arregloDePersonas);
        }
        else if(opcion == 3){
            ordenarArregloStructPorPais(arregloDePersonas);
            imprimirTablaPersonas(arregloDePersonas);
        }

       opcion = darOpcionMenu();
    }

    return 0;
}
