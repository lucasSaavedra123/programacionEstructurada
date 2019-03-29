#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXCHARACTERS 100

/*
    Buffer de entrada

    Memoria temporal.
    Si usamos scanf, la memoria temporal puede quedar con basura
    Se usa fflush() con stdin como primer argumento. Se limpia en el buffer de la entrada
    del teclado

*/

void intercambiarCaracteres(char oldChar , char newChar, char string[MAXCHARACTERS]){

    int i;

    for(i=0 ; string[i]!='\0' ; i++){
            if(string[i] == oldChar){
                string[i] = newChar;
            }
    }

}

void cargarArreglo(char arreglo[MAXCHARACTERS]){
    int contador = 0;
    char c = 0;

    c = getche();

    //El numero 10 se refiere al caracter '\r'
    while( c!= 10 && contador < MAXCHARACTERS-1 ){
        arreglo[contador] = c;
        contador++;
        c = getche();
    }

    arreglo[contador] = '\0';//asi terminan todas las cadenas

    //No hace falta retonarlo
    //C solo permite devolver una variable
    //No un conjunto, como es un arreglo
}

int main(){

    char stringText[MAXCHARACTERS];
    char oldChar;//1 byte. Un entero ocupa 4bytes
    char newChar;

    printf("Ingrese texto: ");
    cargarArreglo(stringText);

    printf("\n");

    printf("Ingrese carácter a reemplazar: ");
    oldChar=getche();

    printf("\n");

    printf("Ingrese caracter de reemplazo: ");
    newChar=getche();

    printf("\n");

    intercambiarCaracteres(oldChar,newChar,stringText);

    printf("%s",stringText);

    return 0;
}
