#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define FILAS 100
#define COLUMNAS 25
#define MAX 100
#define N 25

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

void ordenarTexto(char matriz [][N]){

    int y;
    int x;
    char arregloMemoria[N] = {0};

    for(y=0; matriz[y][0] != '\0' ; y++){
        for(x=0; matriz[x][0] != '\0'; x++){
            if(strcmp(matriz[y],matriz[x]) < 0){ //Si entrega un numero menor a 0, entonces matriz[y] es menor.
                strcpy(arregloMemoria,matriz[y]);
                strcpy(matriz[y],matriz[x]);
                strcpy(matriz[x],arregloMemoria);
            }
        }
    }

}

void imprimirMatText(char matriz[FILAS][COLUMNAS]){
    int x;
    int y;

    for( y=0; y < FILAS && matriz[y][0] != '\0'; y++){
        for( x=0; x < COLUMNAS && matriz[y][x] != '\0'; x++){
                printf("%c",matriz[y][x]);
        }
        printf("\n");
    }

}

void cargarMatTextDeArch(char matriz[FILAS][COLUMNAS], char nombreArchivo[MAX]){
    FILE * archivo;
    char c;
    int y;
    int x;

    //Abrimos el archivo
    archivo = fopen(nombreArchivo,"r");//Cargamos el archivo

    if(archivo == NULL){
        printf("Error al abrir el archivo!");
    }

    c = fgetc(archivo);

    for(y=0; c != EOF && y < FILAS-1; y++ ){
        for(x=0; c != EOF && x < COLUMNAS-1 && c != '\n'; x++ ){
            matriz[y][x] = c;
            c = fgetc(archivo);
        }

        matriz[y][x] = '\0';
        c = fgetc(archivo);
    }

    matriz[y][0] = '\0';

    //EOF es uan constante que esta asociada con el caracter de fin de fichero
    if(fclose(archivo) == EOF){
        printf("Error al cerrar el archivo!");
    }
}

int main(){
    char matText[FILAS][COLUMNAS] = {0};

    cargarMatTextDeArch(matText,"equipos.txt");

    printf("Sin Ordenar: \n");
    imprimirMatText(matText);
    printf("\n");

    ordenarTexto(matText);

    printf("Ordenado: \n");
    imprimirMatText(matText);

    return 0;
}
