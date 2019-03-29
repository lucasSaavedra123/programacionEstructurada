#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void limpiarArregloInt(int arreglo[MAX]){
    int i;

    for(i=0; i < MAX-1; i++)
        arreglo[i]=0;
}

int estaEnArr(int arreglo[MAX], int numero){
    int i;
    int estaEnArreglo = 0;

    for(i = 0; arreglo[i] != 0 && i < MAX ; i++){
        if(arreglo[i]==numero){
            estaEnArreglo=1;
        }
    }

    return estaEnArreglo;
}

int esPos(int n){
    int esPositivo = 0;

    if( n >= 0 ){
        esPositivo = 1;
    }
    else{
        esPositivo = 0;
    }

    return esPositivo;

}

void cargarArrPNR(int arreglo[MAX]){
    int i = 0;
    int n = 0;

    scanf("%d", &n);

    while( n != 0 && i < MAX-1 ){
        if(!esPos(n)){
            printf("Error. Solo numeros positivos.\n");
        }
        else if(estaEnArr(arreglo,n)){
            printf("Error. Ya esta en la lista.\n");
        }
        else{
            arreglo[i] = n;
            i++;
        }

        scanf("%d", &n);

    }

    arreglo[i] = 0;


}

void imprimirArr(int arreglo[MAX]){
    int i;

    printf("\nNumeros:\n");

    for(i = 0; arreglo[i] != 0; i++)
        printf("arreglo[%d] = %d\n", i, arreglo[i]);
}

int main(){

    int arregloInt[MAX];
    limpiarArregloInt(arregloInt);
    cargarArrPNR(arregloInt);
    imprimirArr(arregloInt);

}
