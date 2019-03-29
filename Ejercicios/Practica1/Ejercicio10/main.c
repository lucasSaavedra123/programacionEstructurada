#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define FILAS 50
#define COLUMNAS 50
#define MAX 100

void imprimirMatText(char matriz[FILAS][COLUMNAS]){
    int x;
    int y;

    for( y=0; y < FILAS && matriz[y][0] != '\0'; y++){
        for( x=0; x < COLUMNAS && matriz[y][x] != '\0'; x++){
                printf("%c",matriz[y][x]);
        }
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
        for(x=0; c != EOF && x < COLUMNAS-1; x++ ){
            matriz[y][x] = c;
            c = fgetc(archivo);
        }

        matriz[y][x] = '\0';

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
    imprimirMatText(matText);


}

