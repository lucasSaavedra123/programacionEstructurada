#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct s_texto {
    char * txt;
    unsigned int longitud;
};
typedef struct s_texto t_texto;

//FUNCIONES REALIZADAS ANTERIORMENTE PARA FACILITAR EL TRABAJO
int strcmp(char arreglo1[], char arreglo2[]){
    int i;
    int mayorMenorOIguales = 0;

    for(i=0; arreglo1[i] != '\0' && arreglo2[i] != '\0' && arreglo1[i] == arreglo2[i]; i++){}

    if(arreglo1[i]!=arreglo2[i]){
        if(arreglo1[i] < arreglo2[i]){
            mayorMenorOIguales = -1;
        }
        else{
            mayorMenorOIguales = 1;
        }
    }

    return mayorMenorOIguales;

}

void strcpy(char arregloCopia[], char arreglo[]){
    int i;

    for(i=0; arreglo[i]!='\0' ; i++){
        arregloCopia[i]=arreglo[i];
    }

    arregloCopia[i]='\0';
}

void cargarFrasesEnArregloDeTexto(t_texto ** punteroDeArreglo);
void ordenarAlfabeticamenteArregloDeTextos(t_texto * punteroDeArreglo);
void imprimirTexto(t_texto texto);
void escribirTextosEnArch(t_texto * punteroDeArreglo);

void escribirArchTex(const char * nomArch, t_texto);
t_texto cargarTexto();

int main(){
    t_texto * textos = NULL;

    cargarFrasesEnArregloDeTexto(&textos);
    ordenarAlfabeticamenteArregloDeTextos(textos);

    escribirTextosEnArch(textos);

    return 0;
}

void escribirArchTex(const char * nomArch, t_texto texto){

    FILE * archivo = fopen(nomArch, "a");
    int indiceLetras = 0;
    char caracter = 0;

    fprintf(archivo, "%d,", texto.longitud);

    caracter = *(texto.txt+indiceLetras);

    while(caracter != '\0' && indiceLetras < texto.longitud){
        fputc(caracter, archivo);
        indiceLetras++;
        caracter = *(texto.txt+indiceLetras);
    }

    fputc('\n', archivo);

    fclose(archivo);
}
t_texto cargarTexto(){
    char caracter = 0;
    int contadorLetras = 0;
    t_texto texto;

    texto.txt = malloc(sizeof(char));

    caracter = getche();

    while( caracter != 10 ){
        *( (texto.txt) + contadorLetras ) = caracter;

        contadorLetras++;
        texto.txt = realloc(texto.txt, (sizeof(char)*contadorLetras+sizeof(int)) );

        caracter = getche();
    }

    texto.longitud = contadorLetras;
    *(texto.txt+contadorLetras) = '\0';

    return texto;
}

void cargarFrasesEnArregloDeTexto(t_texto ** punteroDeArreglo){

    int contadorDeTextos = 0;
    t_texto textoNuevo;

    *punteroDeArreglo = malloc(sizeof(t_texto));

    textoNuevo = cargarTexto();

    while( textoNuevo.longitud != 0 ){
        *(*punteroDeArreglo + contadorDeTextos) = textoNuevo;

        contadorDeTextos++;
        *punteroDeArreglo = realloc(*punteroDeArreglo, sizeof(t_texto) * (contadorDeTextos+1) );

        textoNuevo = cargarTexto();
    }

    (*(*punteroDeArreglo + contadorDeTextos)).txt = NULL;

}

void ordenarAlfabeticamenteArregloDeTextos(t_texto * punteroDeArreglo){

    int indiceDeStructs1;
    int indiceDeStructs2;
    t_texto textoAuxiliar;

    for(indiceDeStructs1 = 0; (*(punteroDeArreglo+indiceDeStructs1)).txt != NULL ;indiceDeStructs1++){
        for(indiceDeStructs2 = indiceDeStructs1; (*(punteroDeArreglo+indiceDeStructs2)).txt != NULL ;indiceDeStructs2++){
            if(strcmp((*(punteroDeArreglo+indiceDeStructs2)).txt, (*(punteroDeArreglo+indiceDeStructs1)).txt)){
                textoAuxiliar = (*(punteroDeArreglo+indiceDeStructs1));
                (*(punteroDeArreglo+indiceDeStructs1)) = (*(punteroDeArreglo+indiceDeStructs2));
                (*(punteroDeArreglo+indiceDeStructs2)) = textoAuxiliar;
            }
        }
    }

}

void imprimirTexto(t_texto texto){
    printf("%s\n", texto.txt);
}

void escribirTextosEnArch(t_texto * punteroDeArreglos){

    int indiceDeTextos = 0;

    for(indiceDeTextos = 0; (*(punteroDeArreglos+indiceDeTextos)).txt != NULL ; indiceDeTextos++){
        escribirArchTex("frases_con_longitud.csv", *(punteroDeArreglos+indiceDeTextos) );
    }

}
