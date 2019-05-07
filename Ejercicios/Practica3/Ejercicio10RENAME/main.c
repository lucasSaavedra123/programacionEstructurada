#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct s_texto {
    char * txt;
    unsigned int longitud;
};

typedef struct s_texto t_texto;

void escribirArchTex(const char * nomArch, t_texto);
t_texto cargarTexto();

int main()
{
    escribirArchTex("data5.csv", cargarTexto());
    return 0;
}

void escribirArchTex(const char * nomArch, t_texto texto){

    FILE * archivo = fopen(nomArch, "w");
    int indiceLetras = 0;
    char caracter = 0;

    printf("\n%d", texto.longitud);

    fprintf(archivo, "%d,", texto.longitud);

    caracter = *(texto.txt+indiceLetras);

    while(caracter != '\0' && indiceLetras < texto.longitud){
        fputc(caracter, archivo);
        indiceLetras++;
        caracter = *(texto.txt+indiceLetras);
    }

    fclose(archivo);
}

t_texto cargarTexto(){
    char caracter = 0;
    int contadorLetras = 0;
    t_texto texto;

    texto.txt = malloc(sizeof(char));

    caracter = getche();

    while( caracter != '\r' ){
        *( (texto.txt) + contadorLetras ) = caracter;

        contadorLetras++;
        texto.txt = realloc(texto.txt, sizeof(char)*contadorLetras );

        caracter = getche();
    }

    texto.longitud = contadorLetras;
    *(texto.txt+contadorLetras) = '\0';

    return texto;
}
