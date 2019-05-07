#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char * cargarStrDin1();
void cargarStrDin2(char ** pCadena);
void escribirArch(char * nomArch, char * cadena);
void imprimirArch(char * nomArch);
int esNull(void * puntero);

int main()
{
    char * string = NULL;

    //Sacar comentario a una sola linea a la vez
    //string = cargarStrDin1();
    //cargarStrDin2(&string);
    escribirArch("archivo.txt",string);
    imprimirArch("archivo.txt");

    return 0;
}

char * cargarStrDin1(){
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
void cargarStrDin2(char ** pCadena){
    *pCadena = (char *) malloc(sizeof(char));
    int contadorLetras = 0;
    char caracter = 0;

    caracter = getche();

    while( caracter != 10 ){
        *(*pCadena + contadorLetras) = caracter;

        contadorLetras++;
        *pCadena= realloc(*pCadena, (contadorLetras+1) * sizeof(int));

        caracter = getche();
    }

    *(*pCadena + contadorLetras) = '\0';
}
void escribirArch(char * nomArch, char * cadena){
    FILE * archivo = fopen(nomArch, "w");
    char caracter = 0;
    int indiceDeCadena = 0;

    caracter = *cadena;

    while(caracter != '\0'){
        fputc(caracter, archivo);
        indiceDeCadena++;
        caracter = *(cadena+indiceDeCadena);
    }

    fclose(archivo);
}
void imprimirArch(char * nomArch){
    FILE * archivo = fopen(nomArch, "r");
    char caracter = 0;
    int indiceDeCadena = 0;

    caracter = fgetc(archivo);

    while(caracter != EOF){
        printf("%c", caracter);
        indiceDeCadena++;
        caracter = fgetc(archivo);
    }

    fclose(archivo);
}
int esNull(void * puntero){
    int esNull = 0;

    if(puntero == NULL){
        esNull = 1;
    }

    return esNull;
}
