#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define FILAS 5
#define COLUMNAS 10

int esMayuscula(char c){
    int esMayus = 0;

    if(c >= 'A' && c <= 'Z'){
        esMayus = 1;
    }

    return esMayus;

}

int esMinuscula(char c){
    int esMinus = 0;

    if(c >= 'a' && c <= 'z'){
        esMinus = 1;
    }

    return esMinus;
}

int esLetra(char c){
    int esLetra = 0;

    if( esMinuscula(c) || esMayuscula(c) ){
        esLetra = 1;
    }

    return esLetra;

}

char darMayuscula(char c){

    if(esMinuscula(c)){
        c = c - 32;
    }

    return c;

}

char darMinuscula(char c){

    if(esMayuscula(c)){
        c = c + 32;
    }

    return c;

}

int sonMismaLetra(char letra1, char letra2){
    int sonMismaLetra = 0;

    if ( esMinuscula(letra1) ){
        letra1 = darMayuscula(letra1);
    }

    if ( esMinuscula(letra2) ){
        letra1 = darMayuscula(letra2);
    }

    if (letra1 == letra2){
        sonMismaLetra = 1;
    }

    return sonMismaLetra;
}

void ordenarMatText(char matriz[FILAS][COLUMNAS]){
    int x;
    int y;
    int z;
    int w;

    char memoria;

    //Ordenarlo por mayusculas y minusculas tambien
    for( y=0; y < FILAS && matriz[y][0] != '\0'; y++ ){
        for( x=0; x < COLUMNAS && matriz[y][x] != '\0' ; x++ ){
            for( z=0; z < FILAS && matriz[z][0] != '\0'; z++){
                for( w=0; w < COLUMNAS && matriz[z][w] != '\0'; w++ ){
                    if(darMinuscula(matriz[y][x]) < darMinuscula(matriz[z][w])){
                        memoria = matriz[y][x];
                        matriz[y][x] = matriz[z][w];
                        matriz[z][w] = memoria;
                    }
                }
            }
        }
    }
}

void cargarMatText(char matriz[FILAS][COLUMNAS]){
    int x;
    int y;
    char c= ' ';

    for( y=0; y < FILAS-1 && c!=10 ; y++){

        for( x=0; x < COLUMNAS-1 && c!=10; x++){
            c = getche();
            matriz[y][x] = c;
        }

        matriz[y][x] = '\0';
    }

    matriz[y][0] = '\0';

}

void imprimirMatText(char matriz[FILAS][COLUMNAS]){
    int x;
    int y;

    for( y=0; y < FILAS && matriz[y][0] != '\0'; y++){
        for( x=0; x < COLUMNAS && matriz[y][x] != '\0'; x++){
                printf("%c",matriz[y][x]);
        }
    }

}

int main(){
    char matriz[FILAS][COLUMNAS];

    cargarMatText(matriz);
    printf("\n");
    imprimirMatText(matriz);

    ordenarMatText(matriz);
    printf("\n");
    imprimirMatText(matriz);

    return 0;
}
