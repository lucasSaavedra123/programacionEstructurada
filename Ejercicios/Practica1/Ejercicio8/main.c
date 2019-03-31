#include <stdio.h>
#include <stdlib.h>
#define FILAS 3
#define COLUMNAS 3

void transponer(int matriz[FILAS][COLUMNAS]){
    int numeroMemoria;
    int x;
    int y;

    for( y = 0; y < FILAS ; y++){
        for(x = 0; x < COLUMNAS ; x++){
            matriz[x][y] = numeroMemoria;
            matriz[x][y] = matriz[y][x];
            matrizCopia[y][x] = numeroMemoria;
        }
    }


}

void cargarMat(int matriz[FILAS][COLUMNAS]){
    int x=0;
    int y=0;

    for( y=0 ; y < FILAS ; y++ ){
        for( x=0 ; x < COLUMNAS ; x++){
            printf("Posicion [%d][%d]: ", y+1, x+1);
            scanf("%d", &matriz[y][x]);
        }
    }

}

void imprimirMat(int matriz[FILAS][COLUMNAS]){
    int x=0;
    int y=0;

    printf("\n\n");

    for( y=0 ; y < FILAS ; y++ ){

        for( x=0 ; x < COLUMNAS ; x++){
            printf("\t%d", matriz[y][x]);
        }

        printf("\n");
    }

    printf("\n");
}

int main()
{
    int matriz[FILAS][COLUMNAS];

    //Solo para matrices cuadradas
    if(FILAS == COLUMNAS){
        cargarMat(matriz);
        imprimirMat(matriz);
        transponer(matriz);
        imprimirMat(matriz);
    }
    else{
        printf("Este programa es solo para matrices cuadradas!");
    }
    return 0;
}
