#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

//PARCIAL 2//

//Ejercicio 1
void reconstruir_matriz(int * backup, char matriz[N][M]);
unsigned int entregarColumnaDeBackup(unsigned int backup);
unsigned int entregarFilaDeBackup(unsigned int backup);
unsigned char entregarLetraDeBackup(unsigned int backup);

//Ejercicio 2
typedef struct {
    int fila;
    int columna;
} s_pos_mat;

s_pos_mat * posiciones_vacias(char matriz[N][M]);

//Ejercicio 3
int sumaImpar(int n, int m);

int main()
{
    int backup[] = {0,0,0};
    char matriz[N][N];
    int indiceDeFilas = 0;
    int indiceDeColumnas = 0;
    int indiceDeArreglo = 0;
    s_pos_mat * arregloDePosicionesVacias = NULL;

    printf("Prueba del ejercicio 1: \n");

    for(indiceDeFilas = 0; indiceDeFilas < N; indiceDeFilas++){
        for(indiceDeColumnas = 0; indiceDeColumnas < N; indiceDeColumnas++){
            matriz[indiceDeFilas][indiceDeColumnas] = '-';
        }
    }

    backup[0] = backup[0] | 'n';
    backup[0] = backup[0] << 8 | 1;
    backup[0] = backup[0] << 8 | 2;

    backup[1] = backup[1] | 'a';
    backup[1] = backup[1] << 8 | 0;
    backup[1] = backup[1] << 8 | 0;

    reconstruir_matriz(backup, matriz);

    for(indiceDeFilas = 0; indiceDeFilas < N; indiceDeFilas++){
        for(indiceDeColumnas = 0; indiceDeColumnas < N; indiceDeColumnas++){
            printf("%c\t", matriz[indiceDeFilas][indiceDeColumnas]);
        }
        printf("\n");
    }

    printf("Prueba del ejercicio 2: \n");

    arregloDePosicionesVacias = posiciones_vacias(matriz);

    while( arregloDePosicionesVacias[indiceDeArreglo].columna != N && arregloDePosicionesVacias[indiceDeArreglo].fila != N ){

        printf("Columna: %d, ", arregloDePosicionesVacias[indiceDeArreglo].columna);
        printf("Fila: %d\n", arregloDePosicionesVacias[indiceDeArreglo].fila);

        indiceDeArreglo++;
    }

    printf("Prueba del ejercicio 3: \n");
    printf("La suma es (sin funcion):%d\n", 1+3+5+7+9);
    printf("Suma de numeros impares entre 1 y 10: %d", sumaImpar(1,10));

    return 0;
}

//Funcion del ejercicio 1
void reconstruir_matriz(int * backup, char matriz[N][M]){
    int columnaDeLaLetra = 0;
    int filaDeLaLetra = 0;
    int indiceDeBackup = 0;
    char letra = 0;

    while( backup[indiceDeBackup] != 0 ){
        columnaDeLaLetra = entregarColumnaDeBackup(backup[indiceDeBackup]);
        filaDeLaLetra = entregarFilaDeBackup(backup[indiceDeBackup]);
        letra = entregarLetraDeBackup(backup[indiceDeBackup]);

        matriz[filaDeLaLetra][columnaDeLaLetra] = letra;

        indiceDeBackup++;
    }

}

unsigned int entregarColumnaDeBackup(unsigned int backup){
    unsigned int mascaraColumna = 255;

    return mascaraColumna & backup;
}

unsigned int entregarFilaDeBackup(unsigned int backup){
    unsigned int mascaraFila = 255 << 8;

    return (mascaraFila & backup) >> 8;
}

unsigned char entregarLetraDeBackup(unsigned int backup){
    unsigned int mascaraLetra = 255 << 16;

    return (mascaraLetra & backup) >> 16;
}

//Funcion del ejercicio 2
s_pos_mat * posiciones_vacias(char matriz[N][M]){
    int contadorDePosiciones = 0;
    int indiceDeFilas = 0;
    int indiceDeColumnas = 0;

    s_pos_mat * arregloNuevoDePosicionesVacias = malloc(sizeof(s_pos_mat));

    for(indiceDeFilas = 0; indiceDeFilas < N ;indiceDeFilas++){
        for(indiceDeColumnas = 0; indiceDeColumnas < N ;indiceDeColumnas++){
            if(matriz[indiceDeFilas][indiceDeColumnas] == '-'){
                (arregloNuevoDePosicionesVacias+contadorDePosiciones)->columna = indiceDeColumnas;
                (arregloNuevoDePosicionesVacias+contadorDePosiciones)->fila = indiceDeFilas;

                contadorDePosiciones++;

                arregloNuevoDePosicionesVacias = realloc(arregloNuevoDePosicionesVacias, sizeof(s_pos_mat) * (contadorDePosiciones+1));
            }
        }
    }

    (*(arregloNuevoDePosicionesVacias+contadorDePosiciones)).columna = N;
    (*(arregloNuevoDePosicionesVacias+contadorDePosiciones)).fila = N;

    return arregloNuevoDePosicionesVacias;

}

//Funcion del ejercicio 3
int sumaImpar(int n, int m){

    if(n < m){
        if( n%2 != 0){
            return n + sumaImpar(n+1,m);
        }
        else
            return sumaImpar(n+1,m);
    }
    else
        return 0;



}
