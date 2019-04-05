#include <stdio.h>
#include <stdlib.h>
#define FILAS 25
#define COLUMNAS 25
#define N 25

struct equipo{
    char nombre[N];

    int cantPartidosGanados;
    int cantPpartidosPerdidos;
    int cantPartidosEmpatados;
    int cantGolesAFavor;
    int cantGolesEnContra;
};

void strcpy(char arregloCopia[], char arreglo[]){
    int i;

    for(i=0; arreglo[i]!='\0' ; i++){
        arregloCopia[i]=arreglo[i];
    }

    arregloCopia[i]='\0';
}

void intercambiarArreglos(int arreglo1[N], int arreglo2[N]){
    int i;
    int numeroMemoria;

    for(i=0; i<N ; i++){
            numeroMemoria = arreglo1[i];
            arreglo1[i] = arreglo2[i];
            arreglo2[i] = numeroMemoria;
    }
}

void copiarArreglo(int arregloNuevo[N], int arregloACopiar[N]){
    int i;

    for( i=0; i < N; i++){
        arregloNuevo[i] = arregloACopiar[i];
    }
}

void cargarEquipos(struct equipo arregloDeEquipos[CANTIDAD], char nombreDeArchEquipos[], char nombreDeArchDatos[]){

    archivo = fopen("puntos.csv","r");

    for(i=0; fscanf(archivo,"%f,%f,",&arregloDePuntos[i].x, &arregloDePuntos[i].y) != EOF && i < FILAS; i++){}

    fclose(archivo);
}

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

    int y;

    archivo = fopen(nombreArchivo,"r");

    for(y=0; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d\n", &matriz[y][0], &matriz[y][1], &matriz[y][2],
                                                         &matriz[y][3], &matriz[y][4], &matriz[y][5],
                                                         &matriz[y][6], &matriz[y][7]) != EOF && y < FILAS-1; y++){}
    matriz[y][0] = EOF;

    fclose(archivo);

}

void imprimirTabla(int datos[][N], char cabeceras[][N], char items[][N], int fil, int col){
    int x;
    int y;

    printf("\n");

    //Imprimimos las cabeceras
    for(y=0; y<col+1; y++){
            printf("%-8s",cabeceras[y]);
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
        printf("%-8s",items[y]);
        for(x=0; x<col; x++){
            if( datos[y][x] > 0 && x == 7 ){
                    printf("+%-7d",datos[y][x]);
            }
            else{
                printf("%-8d",datos[y][x]);
            }
        }
        printf("\n");

    }
}

int main()
{

    return 0;
}
