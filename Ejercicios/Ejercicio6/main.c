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

void limpiarArreglo(char arreglo[MAXCHARACTERS]){
    int i;

    for(i=0; i < MAXCHARACTERS; i++)
        arreglo[i]=0;
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
    int anchoArreglo = entregarAnchoUtil(arreglo);
    char copiaArreglo[MAXCHARACTERS];

    copiarArreglo(arreglo,copiaArreglo);
    limpiarArreglo(arreglo);

    while(x < anchoArreglo){
        if(x < pos1 || x > pos2){
            arreglo[y]=copiaArreglo[x];
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
    int anchoArreglo = entregarAnchoUtil(arreglo);

    //El numero 32 es para el caracter ' '

    for( i=0 ; i < anchoArreglo ; i++){
        if(arreglo[i] == ' '){

            //Si el espacio del principio, si o si sacamos todos
            if(i==0){
                recortarArregloChar(arreglo,i,i);
            }
            else{
                i++;
            }

            while(arreglo[i] == ' '){
                recortarArregloChar(arreglo,i,i);
            }
        }

    }

}

void capitalizarArreglo(char arreglo[MAXCHARACTERS]){
    int i;
    int anchoUtil = entregarAnchoUtil(arreglo);

    for(i=0;!esLetra(arreglo[i]) && i < anchoUtil;i++){}

    arreglo[i]=darMayuscula(arreglo[i]);
}

void normalizar(char arreglo[MAXCHARACTERS]){
    int anchoUtil = entregarAnchoUtil(arreglo);//Coincide con la posicion del \0

    sacarEspaciosDeMas(arreglo);
    capitalizarArreglo(arreglo);

    if(arreglo[anchoUtil-1] != '.'){
        insertarCaracterEnArreglo(arreglo, '.', anchoUtil);
    }
}

int main(){
    char arreglo[MAXCHARACTERS];

    printf("Ingrese texto (MAX %d): ", MAXCHARACTERS-2);
    cargarText(arreglo);
    printf("\n");

    printf("Texto sin corregir:\n");
    imprimirText(arreglo);
    printf("\n");

    normalizar(arreglo);

    printf("Texto corregido:\n");
    imprimirText(arreglo);
    printf("\n");

    return 0;
}
