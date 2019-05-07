#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char * cargarStrDin();
int esNull(void * puntero);

int main()
{

    printf("%s", cargarStrDin());

    return 0;
}

char * cargarStrDin(){
    char * arregloCadena = (char *) malloc(sizeof(char));
    int contadorLetras = 0;
    char caracter = 0;

    caracter = getche();

    while( caracter != 10 ){
        *(arregloCadena + contadorLetras) = caracter;

        contadorLetras++;

        arregloCadena = realloc(arregloCadena, (contadorLetras+1) * sizeof(int));

        if(esNull(arregloCadena)){
            return NULL;
        }

        caracter = getche();
    }

    *(arregloCadena + contadorLetras) = '\0';

    return arregloCadena;

}

int esNull(void * puntero){
    int esNull = 0;

    if(puntero == NULL){
        esNull = 1;
    }

    return esNull;
}
