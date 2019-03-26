#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXCHARACTERS 100

//VER SI SE PUEDE MEJORAR ESTE PROGRAMA

int entregarAnchoUtil(char arreglo[MAXCHARACTERS]){
    int i;

    for(i = 0; arreglo[i] != '\0'; i++);//For sin cuerpo

    return i;

}

int esMayuscula(char c){
    int esMayus = 0;

    if(c >= 'A' && c <= 'Z'){
        esMayus = 1;
    }

    return esMayus;

}

int esMinuscula(char c){
    int esMinus = 0;

    if(c >= 'a' && c <= 'z'){
        esMinus = 1;
    }

    return esMinus;
}

int esLetra(char c){
    int esLetra = 0;

    if( esMinuscula(c) || esMayuscula(c) ){
        esLetra = 1;
    }

    return esLetra;

}

char darMayuscula(char c){

    if(esMinuscula(c)){
        c = c - 32;
    }

    return c;

}

char darMinuscula(char c){

    if(esMayuscula(c)){
        c = c + 32;
    }

    return c;

}

void cargarText(char arreglo[MAXCHARACTERS]){
    int contador = 0;
    char c = 0;

    c = getche();

    //Ponemos -2 para guardar el espacio suficiente por si hay que poner punto
    while( c!= 10 && contador < MAXCHARACTERS-2 ){
        arreglo[contador] = c;
        contador++;
        c = getche();
    }

    arreglo[contador] = '\0';
}

void copiarArreglo(char arreglo[MAXCHARACTERS], char arregloCopia[MAXCHARACTERS]){
    int i;
    for(i=0; i < MAXCHARACTERS; i++){
            arregloCopia[i]=arreglo[i];
    }

}

void imprimirText(char arreglo[MAXCHARACTERS]){
    int i;

    for(i = 0; arreglo[i] != '\0'; i++)
        printf("%c",arreglo[i]);
}

void recortarArregloChar(char arreglo[MAXCHARACTERS], int pos1, int pos2){
    int x=0;
    int y=0;

    while(x < MAXCHARACTERS){
        if(x < pos1 || x > pos2){
            arreglo[y]=arreglo[x];
            y++;
        }
        x++;
    }

    arreglo[y] = '\0';
}

void insertarCaracterEnArreglo(char arreglo[MAXCHARACTERS],char c, int pos){
    int x;
    char copiaArreglo[MAXCHARACTERS];

    copiarArreglo(arreglo, copiaArreglo);

    for(x = 0 ; x < MAXCHARACTERS ; x++){
            if(x == pos){
                arreglo[pos]=c;
            }
            else if(x > pos){
                    arreglo[x]=copiaArreglo[x-1];
            }
    }

}

void sacarEspaciosDeMas(char arreglo[MAXCHARACTERS]){
    int i=0;
    int pos1 = 0;
    int pos2 = 0;
    int contadorEspacios = 0;

    while(arreglo[i] == ' '){
        i++;
    }

    pos2 = i;

    recortarArregloChar(arreglo, pos1, pos2-1);

    pos1 = 0;
    pos2 = 0;

    for (i; arreglo[i] != '\0' ;i++){
        //Se podria haber usado el numero 32
        while(arreglo[i] == ' ' ){
            if (contadorEspacios==0){
                pos1 = i;
            }

            i++;
            contadorEspacios++;
        }

        pos2 = i-1;

        if(pos2 != pos1 && contadorEspacios > 1){
            recortarArregloChar(arreglo, pos1, pos2-1);
        }

        contadorEspacios = 0;
        pos1 = 0;
        pos2 = 0;

    }
}

void normalizar(char arreglo[MAXCHARACTERS]){
    //Por ahora suponemos que el primer caracter es una letra y que hay doble espacios o mas de 2 seguidos
    arreglo[0] = darMayuscula(arreglo[0]);
    sacarEspaciosDeMas(arreglo);
    insertarCaracterEnArreglo(arreglo, '.', entregarAnchoUtil(arreglo));
}

int main(){
    char arreglo[MAXCHARACTERS];

    printf("Ingrese texto (MAX %d): ", MAXCHARACTERS-2);
    cargarText(arreglo);
    printf("\n");

    printf("Texto sin corregir: ");
    imprimirText(arreglo);
    printf("\n");

    normalizar(arreglo);

    printf("Texto corregido: ");
    imprimirText(arreglo);
    printf("\n");

    return 0;
}
