#include <stdio.h>
#include <stdlib.h>

#define FILAS 25
#define COLUMNAS 25
#define N 25

void cargarMatTextDeArch(char matriz[][N], char nombreArchivo[]){
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

    for(y=0; c != EOF; y++ ){
        for(x=0; c != EOF && c != '\n'; x++ ){
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

void cargarMatNumDeArch(int matriz[][N], char nombreArchivo[]){
    FILE * archivo;

    int n0,n1,n2,n3,n4,n5,n6,n7;
    int y;

    archivo = fopen(nombreArchivo,"r");

    for(y=0; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d\n", &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n7) != EOF && y < FILAS-1; y++){
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

void imprimirTabla(int datos[][N], char cabeceras[][N], char items[][N], int fil, int col){
    int x;
    int y;

    printf("\n");

    //Imprimimos las cabeceras
    for(y=0; y<col+1; y++){
        if(y==0){
            printf("%s\t\t",cabeceras[y]);
        }
        else{
            printf("%s\t",cabeceras[y]);
        }
    }

    printf("\n");

    for(y=0; y<col+1; y++){
        if(y==0){
            printf("----------");
        }
        else{
            printf("--------");
        }

    }

    printf("\n");

    //Imprimimos los items a medida que pasan los datos
    for(y=0; y<fil; y++){
        printf("%s\t\t",items[y]);
        for(x=0; x<col; x++){
            if( datos[y][x] > 0 && x == 7 ){
                    printf("+%d\t",datos[y][x]);
            }
            else{
                printf("%d\t",datos[y][x]);
            }
        }
        printf("\n");

    }
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
    char cabeceras[FILAS][COLUMNAS] = {0};
    char items[FILAS][COLUMNAS] = {0};
    int datos[FILAS][COLUMNAS] = {0};

    cargarMatTextDeArch(cabeceras,"cabeceras.txt");
    cargarMatTextDeArch(items,"items.txt");
    cargarMatNumDeArch(datos, "datos.txt");

    imprimirTabla(datos,cabeceras,items,5,8);

}
