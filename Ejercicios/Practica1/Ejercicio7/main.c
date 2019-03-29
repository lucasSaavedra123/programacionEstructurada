#include <stdio.h>
#include <stdlib.h>
#define FILAS 2
#define COLUMNAS 2

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

float promMat(int matriz[FILAS][COLUMNAS]){
    int x=0;
    int y=0;
    float sum = 0;
    float prom = 0;

    for( y=0 ; y < FILAS ; y++ ){
        for( x=0 ; x < COLUMNAS ; x++){
            sum = sum + matriz[y][x];
        }
    }

    prom = sum / (FILAS*COLUMNAS);

    return prom;
}

int main()
{
    int matriz[FILAS][COLUMNAS];

    printf("Ingresar numeros para una matriz %d X %d: \n", FILAS, COLUMNAS);

    cargarMat(matriz);

    printf("\nMatriz ingresada:");

    imprimirMat(matriz);

    printf("Promedio de los valores de la matriz: %.2f", promMat(matriz));
}
