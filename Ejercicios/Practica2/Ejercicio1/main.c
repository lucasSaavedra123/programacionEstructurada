#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct punto{
    float x;
    float y;
};


double darNormaDe(struct punto punto){
    double norma = sqrt(pow(punto.x,2)+pow(punto.y,2));
    return norma;
}


int puntoMasLejanoAlOrigen(struct punto punto1, struct punto punto2){
    double normaPunto1 = darNormaDe(punto1);
    double normaPunto2 = darNormaDe(punto2);
    int puntoMasLejano = 0;

    if (normaPunto1 > normaPunto2){
        puntoMasLejano = 1;
    }
    else if (normaPunto1 < normaPunto2){
        puntoMasLejano = 2;
    }
    else{
        puntoMasLejano = 0;
    }

    return puntoMasLejano;

}

void imprimirPuntoMasLejanoDelOrigen(struct punto punto1, struct punto punto2){
    int numPuntoMasLejano = puntoMasLejanoAlOrigen(punto1,punto2);

    if(numPuntoMasLejano == 1){
            printf("El punto 1 (%.2f,%.2f) es el punto mas lejano", punto1.x, punto1.y);
    }

    else if(numPuntoMasLejano == 2){
        printf("El punto 2 (%.2f,%.2f) es el punto mas lejano", punto2.x,punto2.y);
    }
    else{
        printf("Ambos puntos estan a igual de distancia.");
    }
}


int main()
{
    struct punto punto1;
    struct punto punto2;

    printf("Cargar cordenada X del punto 1: ");
    scanf("%f", &punto1.x);

    printf("Cargar cordenada Y del punto 1: ");
    scanf("%f", &punto1.y);

    printf("Cargar cordenada X del punto 2: ");
    scanf("%f", &punto2.x);

    printf("Cargar cordenada Y del punto 2: ");
    scanf("%f", &punto2.y);

    imprimirPuntoMasLejanoDelOrigen(punto1, punto2);

}
