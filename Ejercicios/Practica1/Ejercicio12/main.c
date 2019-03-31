#include <stdio.h>
#include <stdlib.h>

#define COLUMNAS 20
#define FILAS 20
#define DATOS 8

//Las filas no son obligatorias aclarar, las columnas si
void cargarMatNumDeArch(int matriz[][COLUMNAS], char nombreArchivo[]){
    FILE * archivo;

    int n0,n1,n2,n3,n4,n5,n6,n7;
    int y;

    archivo = fopen(nombreArchivo,"r");

    for(y=0; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d\n", &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n7) != EOF && y < DATOS && y < FILAS; y++){
        matriz[y][0] = n0;
        matriz[y][1] = n1;
        matriz[y][2] = n2;
        matriz[y][3] = n3;
        matriz[y][4] = n4;
        matriz[y][5] = n5;
        matriz[y][6] = n6;
        matriz[y][7] = n7;
    }

    matriz[y][0] = EOF;

    fclose(archivo);

}


void imprimirMatNum(int matriz[FILAS][COLUMNAS], int fil, int col){
    int x,y;

    for( y=0; y < FILAS && matriz[y][0] != EOF && y < fil; y++){
        for( x=0; x < COLUMNAS && x < col; x++){

                if( matriz[y][x] > 0 && x == 7 ){
                        printf("+%d\t",matriz[y][x]);
                }
                else{
                    printf("%d\t",matriz[y][x]);
                }
        }

        printf("\n");

    }

}

int main()
{
    int matriz[FILAS][COLUMNAS]={0};

    //El archivo a cargar es:
    //Puntos, Partidos Jugados, Partidos Ganados, Partidos Empatados, Partidos
    //Perdidos, Goles a favor, Goles en Contra, Diferencia de Goles

    cargarMatNumDeArch(matriz, "puntos.txt");
    imprimirMatNum(matriz,5,8);

    return 0;
}
