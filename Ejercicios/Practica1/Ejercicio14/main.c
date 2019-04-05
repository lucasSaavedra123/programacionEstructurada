#include <stdio.h>
#include <stdlib.h>
#define FILAS 12
#define COLUMNAS 31

void strcpy(char arregloCopia[], char arreglo[]){
    int i;

    for(i=0; arreglo[i]!='\0' ; i++){
        arregloCopia[i]=arreglo[i];
    }

    arregloCopia[i]='\0';
}

void copiarArregloInt(int arregloNuevo[FILAS], int arregloACopiar[FILAS]){
    int i;

    for( i=0; i<FILAS; i++){
            arregloNuevo[i]=arregloACopiar[i];
    }

}

void cargarMatNumDeArch(int matriz[][COLUMNAS], char nombreArchivo[]){
    FILE * archivo;

    int y;

    archivo = fopen(nombreArchivo,"r");

    for(y=0; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n"
                                                        ,&matriz[y][0], &matriz[y][1], &matriz[y][2], &matriz[y][3], &matriz[y][4], &matriz[y][5],
                                                         &matriz[y][6], &matriz[y][7],&matriz[y][8], &matriz[y][9], &matriz[y][10], &matriz[y][11],
                                                         &matriz[y][12], &matriz[y][13], &matriz[y][14], &matriz[y][15], &matriz[y][16], &matriz[y][17],
                                                         &matriz[y][18], &matriz[y][19], &matriz[y][20], &matriz[y][21], &matriz[y][22], &matriz[y][23],
                                                         &matriz[y][24], &matriz[y][25], &matriz[y][26], &matriz[y][27], &matriz[y][28], &matriz[y][29], &matriz[y][30])
                                                          != EOF && y < FILAS; y++){}

    fclose(archivo);

}

void imprimirMes(int numeroDeMes){
    char nombreDelMes[20] = {0};

    switch(numeroDeMes){

        case 1:
            strcpy(nombreDelMes, "Enero");
            break;

        case 2:
            strcpy(nombreDelMes, "Febrero");
            break;

        case 3:
            strcpy(nombreDelMes, "Marzo");
            break;

        case 4:
            strcpy(nombreDelMes, "Abril");
            break;

        case 5:
            strcpy(nombreDelMes, "Mayo");
            break;

        case 6:
            strcpy(nombreDelMes, "Junio");
            break;

        case 7:
            strcpy(nombreDelMes, "Julio");
            break;

        case 8:
            strcpy(nombreDelMes, "Agosto");
            break;

        case 9:
            strcpy(nombreDelMes, "Septiembre");
            break;

        case 10:
            strcpy(nombreDelMes, "Octubre");
            break;

        case 11:
            strcpy(nombreDelMes, "Noviembre");
            break;

        case 12:
            strcpy(nombreDelMes, "Diciembre");
            break;

        default :
            strcpy("Mes Incorrecto", nombreDelMes);
    }

    printf("%s", nombreDelMes);


}

int darTemperaturaMinimaAnual(int matriz[FILAS][COLUMNAS]){
    int x,y;
    int temperaturaMinima = matriz[0][0];

    for(y=0; y < FILAS;y++){
        for(x=0; x < COLUMNAS && matriz[y][x] != -100; x++){
                if(matriz[y][x] < temperaturaMinima){
                    temperaturaMinima = matriz[y][x];
                }
        }
    }

    return temperaturaMinima;

}

int darTemperaturaMaximaAnual(int matriz[FILAS][COLUMNAS]){
    int x,y;
    int temperaturaMaxima = matriz[0][0];

    for(y=0; y < FILAS;y++){
        for(x=0; x < COLUMNAS && matriz[y][x] != -100; x++){
                if(matriz[y][x] > temperaturaMaxima){
                    temperaturaMaxima = matriz[y][x];
                }
        }
    }

    return temperaturaMaxima;
}

float darPromedioMat(int matriz[FILAS][COLUMNAS]){
    int x,y;
    int c = 0;
    float suma = 0;
    float promedio = 0;

    for(y=0; y < FILAS;y++){
        for(x=0; x < COLUMNAS && matriz[y][x] != -100; x++){
                c++;
                suma = suma + matriz[y][x];
        }
    }

    promedio = suma/c;

    return promedio;
}

float darPromedioArreglo(int arreglo[FILAS]){
    int z;
    int c = 0;
    float suma = 0;
    float promedio = 0;

    for(z=0; z < FILAS;z++){
        c++;
        suma = suma + arreglo[z];
    }

    promedio = suma/c;

    return promedio;
}

int darNumeroDelMesMasCaluroso(int matriz[FILAS][COLUMNAS]){
    int i;
    float promedioDelMes = darPromedioArreglo(matriz[0]);
    float promedioNuevo = 0;
    int numeroDelMes = 1;

    for(i=0; i < FILAS ;i++){

        promedioNuevo = darPromedioArreglo(matriz[i]);

        if(promedioDelMes < promedioNuevo){
                promedioDelMes = promedioNuevo;
                numeroDelMes = i+1;
        }
    }

    return numeroDelMes;
}

int darNumeroDelMesMasFrio(int matriz[FILAS][COLUMNAS]){
    int i;
    float promedioDelMes = darPromedioArreglo(matriz[0]);
    float promedioNuevo = 0;
    int numeroDelMes = 1;

    for(i=0; i < FILAS ;i++){

        promedioNuevo = darPromedioArreglo(matriz[i]);

        if(promedioDelMes > promedioNuevo){
                promedioDelMes = promedioNuevo;
                numeroDelMes = i+1;
        }
    }

    return numeroDelMes;
}

int sumarNumDeMat(int matriz[FILAS][COLUMNAS]){
    int x,y;
    float suma = 0;

    for(y=0; y < FILAS;y++){
        for(x=0; x < COLUMNAS && matriz[y][x] != -100; x++){
                suma = suma + matriz[y][x];
        }
    }

    return suma;


}

void imprimirTemperaturaMaximaAnual(int matrizTemperaturas[FILAS][COLUMNAS]){
    int temperaturaMaximaAnual = darTemperaturaMaximaAnual(matrizTemperaturas);
    printf("\nLa temperatura maxima anual es de \%d grados.\n", temperaturaMaximaAnual);
}
void imprimirTemperaturaMinimaAnual(int matrizTemperaturas[FILAS][COLUMNAS]){
    int temperaturaMinimaAnual = darTemperaturaMinimaAnual(matrizTemperaturas);
    printf("\nLa temperatura minima anual es de \%d grados.\n", temperaturaMinimaAnual);
}
void imprimirPromAnual(int matrizTemperaturas[FILAS][COLUMNAS]){
    float promedioAnual = darPromedioMat(matrizTemperaturas);
    printf("\nEl promedio anual es de %.2f grados.\n", promedioAnual);
}
void imprimirPromediosMensuales(int matrizTemperaturas[FILAS][COLUMNAS]){
    int i;

    printf("\nPromedios de temperatura Por Mes: \n");

    for(i=0;i < 12;i++){
        imprimirMes(i+1);
        printf(": %.2f\n",darPromedioArreglo(matrizTemperaturas[i]));
    }

    printf("\n");
}
void imprimirMesMasCaluroso(int matrizTemperaturas[FILAS][COLUMNAS]){

    int numeroDeMes = darNumeroDelMesMasCaluroso(matrizTemperaturas);
    float promedioDelMes = darPromedioArreglo(matrizTemperaturas[numeroDeMes-1]);

    printf("\n");
    printf("El mes mas caluroso es ");
    imprimirMes(numeroDeMes);
    printf("(%.2f)", promedioDelMes);
    printf("\n");
}
void imprimirMesMasFrio(int matrizTemperaturas[FILAS][COLUMNAS]){

    int numeroDeMes = darNumeroDelMesMasFrio(matrizTemperaturas);
    float promedioDelMes = darPromedioArreglo(matrizTemperaturas[numeroDeMes-1]);

    printf("\n");
    printf("El mes mas frio es ");
    imprimirMes(numeroDeMes);
    printf("(%.2f)", promedioDelMes);
    printf("\n");
}
void imprimirNumDeMediciones(int matrizMediciones[FILAS][COLUMNAS]){
    int totalMediciones = sumarNumDeMat(matrizMediciones);

    printf("\nEl total de las mediciones hechas es de %d\n", totalMediciones);
}

int main()
{
    int matrizTemperaturas[FILAS][COLUMNAS]={0};
    int matrizMediciones[FILAS][COLUMNAS]={0};

    cargarMatNumDeArch(matrizTemperaturas,"temperaturas.txt");
    cargarMatNumDeArch(matrizMediciones,"diasMedidos.txt");

    imprimirTemperaturaMaximaAnual(matrizTemperaturas);
    imprimirTemperaturaMinimaAnual(matrizTemperaturas);
    imprimirPromAnual(matrizTemperaturas);
    imprimirPromediosMensuales(matrizTemperaturas);
    imprimirMesMasCaluroso(matrizTemperaturas);
    imprimirMesMasFrio(matrizTemperaturas);
    imprimirNumDeMediciones(matrizMediciones);

}
