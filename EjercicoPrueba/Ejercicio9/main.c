#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char * cargarStrDin1();//Solo para hacer pruebas

char * subcadena (char * p, unsigned int i, unsigned int n);
char * leerArch(const char * nomArch);

int main()
{
    char * p;

    p = cargarStrDin1();

    return 0;
}

char * subcadena(char * p, unsigned int i, unsigned int n){

}

char * leerArch(const char * nomArch);

char * cargarStrDin1(){
    char * arregloCadena = (char *) malloc(sizeof(char));
    int contadorLetras = 0;
    char caracter = 0;

    caracter = getche();

    while( caracter != 10 ){
        *(arregloCadena + contadorLetras) = caracter;

        contadorLetras++;

        arregloCadena = realloc(arregloCadena, (contadorLetras+1) * sizeof(int));

        caracter = getche();
    }

    *(arregloCadena + contadorLetras) = '\0';

    return arregloCadena;

}
