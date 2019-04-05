#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CANTIDAD 10
#define COLUMNAS 2
#define FILAS 10

struct punto{
    float x;
    float y;
};

double darNormaDe(struct punto punto){
    double norma = sqrt(pow(punto.x,2)+pow(punto.y,2));
    return norma;
}

void cargarPuntosDeDosCoordenadas(struct punto arregloDePuntos[CANTIDAD]){
    int i;
    FILE * archivo;

    archivo = fopen("puntos.csv","r");

    for(i=0; fscanf(archivo,"%f,%f,",&arregloDePuntos[i].x, &arregloDePuntos[i].y) != EOF && i < FILAS; i++){}

    fclose(archivo);
}

double darMinimaDistanciaEntreDosPuntos(struct punto arregloDePuntos[CANTIDAD]){
    struct punto puntoDeDiferencia;
    int i,l;
    double distanciaMinima=0;
    double distanciaEntrePuntos=0;

    puntoDeDiferencia.x = arregloDePuntos[0].x - arregloDePuntos[1].x;
    puntoDeDiferencia.y = arregloDePuntos[0].y - arregloDePuntos[1].y;
    distanciaMinima = darNormaDe(puntoDeDiferencia);

    for(i=0; i < CANTIDAD; i++){
        for(l=i+1; l < CANTIDAD; l++){
            puntoDeDiferencia.x = arregloDePuntos[i].x - arregloDePuntos[l].x;
            puntoDeDiferencia.y = arregloDePuntos[i].y - arregloDePuntos[l].y;
            distanciaEntrePuntos= darNormaDe(puntoDeDiferencia);

            if (distanciaEntrePuntos < distanciaMinima){
                    distanciaMinima = distanciaEntrePuntos;
            }
        }
    }

    return distanciaMinima;
}

double darMinimaDistanciaEntreDosPuntosConsecutivos(struct punto arregloDePuntos[CANTIDAD]){
    struct punto puntoDeDiferencia;
    int i;
    double distanciaMinima=0;
    double distanciaEntrePuntos=0;

    puntoDeDiferencia.x = arregloDePuntos[0].x - arregloDePuntos[1].x;
    puntoDeDiferencia.y = arregloDePuntos[0].y - arregloDePuntos[1].y;
    distanciaMinima = darNormaDe(puntoDeDiferencia);

    for(i=1; i < CANTIDAD; i++){
        puntoDeDiferencia.x = arregloDePuntos[i].x - arregloDePuntos[i+1].x;
        puntoDeDiferencia.y = arregloDePuntos[i].y - arregloDePuntos[i+1].y;
        distanciaEntrePuntos= darNormaDe(puntoDeDiferencia);

        if (distanciaEntrePuntos < distanciaMinima){
                distanciaMinima = distanciaEntrePuntos;
        }
    }

    return distanciaMinima;
}

void imprimirMinimaDistanciaEntreDosPuntos(struct punto arregloDePuntos[CANTIDAD]){
    double distanciaMinima = darMinimaDistanciaEntreDosPuntos(arregloDePuntos);
    printf("\nLa minima distancia entre puntos es %lf.\n", distanciaMinima);
}

void imprimirMinimaDistanciaEntreDosPuntosConsecutivos(struct punto arregloDePuntos[CANTIDAD]){
    double distanciaMinima = darMinimaDistanciaEntreDosPuntosConsecutivos(arregloDePuntos);
    printf("\nLa minima distancia entre puntos (de forma consecutiva) es %lf.\n", distanciaMinima);
}

int main()
{
    struct punto arregloDePuntos[CANTIDAD];

    cargarPuntosDeDosCoordenadas(arregloDePuntos);

    imprimirMinimaDistanciaEntreDosPuntos(arregloDePuntos);
    imprimirMinimaDistanciaEntreDosPuntosConsecutivos(arregloDePuntos);

    return 0;
}
