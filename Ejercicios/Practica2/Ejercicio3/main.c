#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 100
#define N 25

struct equipo{
    char nombre[N];

    int cantPartidosGanados;
    int cantPartidosPerdidos;
    int cantPartidosEmpatados;
    int cantGolesAFavor;
    int cantGolesEnContra;
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


void cargarEquiposEnArreglo(struct equipo arregloDeEquipos[CANTIDAD],char nombreDeArchivoDeItems[], char nombreDeArchivoDeDatos[]){
    FILE * archivoDeItems;
    FILE * archivoDeDatos;
    int indiceDeEquipos;

    //Abrimos el archivo
    archivoDeItems = fopen(nombreDeArchivoDeItems,"r");//Cargamos el archivo
    archivoDeDatos = fopen(nombreDeArchivoDeDatos,"r");//Cargamos el archivo

    //%[^,]

    for( indiceDeEquipos = 0; indiceDeEquipos < CANTIDAD-1 && fscanf(archivoDeItems, "%s\n", arregloDeEquipos[indiceDeEquipos].nombre) != EOF; indiceDeEquipos++){
        fscanf(archivoDeDatos, "%d,%d,%d,%d,%d\n",
                                                            &arregloDeEquipos[indiceDeEquipos].cantPartidosGanados,
                                                            &arregloDeEquipos[indiceDeEquipos].cantPartidosPerdidos,
                                                            &arregloDeEquipos[indiceDeEquipos].cantPartidosEmpatados,
                                                            &arregloDeEquipos[indiceDeEquipos].cantGolesAFavor,
                                                            &arregloDeEquipos[indiceDeEquipos].cantGolesEnContra);
    }

    arregloDeEquipos[indiceDeEquipos].nombre[0] = '\0';

    fclose(archivoDeDatos);
    fclose(archivoDeItems);

}

void imprimirTabla(struct equipo arregloDeEquipos[CANTIDAD], char nombreDeArchivoDeCabeceras[]){

    struct equipo equipoAuxiliar;
    int indiceDeEquipos;
    int indiceDeCabeceras;
    int cantidadDeCabeceras = 0;

    int difDeGoles;
    int puntos;
    int cantPartidosJugados;

    char cabecera[N];

    FILE * archivoDeCabeceras = fopen(nombreDeArchivoDeCabeceras, "r");

    printf("\n");

    //Imprimimos las cabeceras
    for(indiceDeCabeceras = 0; fscanf(archivoDeCabeceras, "%s\n", cabecera) != EOF; indiceDeCabeceras++){
            printf("%-8s",cabecera);
            cantidadDeCabeceras++;
    }

    fclose(archivoDeCabeceras);

    printf("\n");

    for(indiceDeCabeceras = 0; cantidadDeCabeceras > indiceDeCabeceras; indiceDeCabeceras++){
        printf("--------");
    }

    printf("\n");

    //Imprimimos los items a medida que pasan los datos
    for(indiceDeEquipos=0; arregloDeEquipos[indiceDeEquipos].nombre[0] != '\0' ; indiceDeEquipos++){
            printf("%-8s", arregloDeEquipos[indiceDeEquipos].nombre);

            puntos = arregloDeEquipos[indiceDeEquipos].cantPartidosGanados * 3 + arregloDeEquipos[indiceDeEquipos].cantPartidosEmpatados;

            printf("%-8d", puntos);


            cantPartidosJugados = arregloDeEquipos[indiceDeEquipos].cantPartidosGanados + arregloDeEquipos[indiceDeEquipos].cantPartidosPerdidos + arregloDeEquipos[indiceDeEquipos].cantPartidosEmpatados;

            printf("%-8d", cantPartidosJugados);

            printf("%-8d", arregloDeEquipos[indiceDeEquipos].cantPartidosGanados);
            printf("%-8d", arregloDeEquipos[indiceDeEquipos].cantPartidosPerdidos);
            printf("%-8d", arregloDeEquipos[indiceDeEquipos].cantPartidosEmpatados);
            printf("%-8d", arregloDeEquipos[indiceDeEquipos].cantGolesAFavor);
            printf("%-8d", arregloDeEquipos[indiceDeEquipos].cantGolesEnContra);

            difDeGoles = arregloDeEquipos[indiceDeEquipos].cantGolesAFavor - arregloDeEquipos[indiceDeEquipos].cantGolesEnContra;

            printf("%-8d", difDeGoles);

            printf("\n");

    }
}

int main()
{
    struct equipo arregloDeEquipos[CANTIDAD];

    cargarEquiposEnArreglo(arregloDeEquipos,"items.txt", "datos.txt");

    imprimirTabla(arregloDeEquipos, "cabeceras.txt");
}

