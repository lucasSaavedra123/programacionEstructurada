#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//FUNCIONES PROPIAS

int entregarAnchoUtil(int arreglo[MAX]){
    int i;

    for(i = 0; arreglo[i] != 0; i++);//For sin cuerpo

    return i;

}

void limpiarArregloInt(int arreglo[MAX]){
    int i;

    for(i=0; i < MAX-1; i++)
        arreglo[i]=0;
}

void cargarArr(int arreglo[MAX]){
    int i = 0;
    int n = 0;

    scanf("%d",&n);

    while( i < MAX-1 && n!=0 ){
        arreglo[i] = n;
        i++;

        if(i < MAX - 1){
            scanf("%d",&n);
        }
    }

    //Nos fijamos si el usuario no termino con 0
    if(i == MAX-1){
        arreglo[MAX-1]=0;
    }
    else if (i == 0){
        arreglo[0] = 0;
    }
}

void imprimirArr(int arreglo[MAX]){
    int i;

    printf("\nNumeros:\n");

    for(i = 0; arreglo[i] != 0; i++)
        printf("arreglo[%d] = %d\n", i, arreglo[i]);
}

void ordenarArr(int arreglo[MAX]){
    int x;
    int y;
    int nAuxiliar = 0;
    int anchoArregloUtil = entregarAnchoUtil(arreglo);//ancho sin el numero 0

    for( x = 0 ; x < anchoArregloUtil ; x++ ){
        for( y = 0 ; y < anchoArregloUtil ; y++ ){
            if(arreglo[x] > arreglo[y]){
                nAuxiliar = arreglo[x];
                arreglo[x] = arreglo[y];
                arreglo[y] = nAuxiliar;
            }
        }
    }
}

void invertirArr(int arreglo[MAX]){
    int i;
    int nAuxiliar = 0;
    int anchoArregloUtil = entregarAnchoUtil(arreglo);//ancho sin el numero 0

    for( i=0 ; i < anchoArregloUtil/2 ; i++ ){
        nAuxiliar = arreglo[i];
        arreglo[i] = arreglo[anchoArregloUtil-1-i];
        arreglo[anchoArregloUtil-1-i] = nAuxiliar;
    }

}

int main(){

    int integerArray1[MAX];
    int integerArray2[MAX];//Este sera ordenado

    limpiarArregloInt(integerArray1);
    limpiarArregloInt(integerArray2);

    printf("Escriba numeros (Maximo %d numeros) para el primer arreglo y finalice con 0: ", MAX-1);
    cargarArr(integerArray1);
    invertirArr(integerArray1);

    printf("Arreglo invertido: \n");
    imprimirArr(integerArray1);

    printf("Escriba numeros (Maximo %d numeros) para el segundo arreglo y finalice con 0: ", MAX-1);
    cargarArr(integerArray2);

    ordenarArr(integerArray2);

    printf("Arreglo ordenado: \n");
    imprimirArr(integerArray2);

    return 0;
}
