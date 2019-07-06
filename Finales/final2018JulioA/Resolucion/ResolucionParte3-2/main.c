#include <stdio.h>
#include <stdlib.h>

//2
struct s_indice{
    int posicionInicial;
    int posicionFinal;
};
typedef struct s_indice t_indice;

struct s_nodo{
    int numeroDeLinea;
    struct s_indice indice;
    struct s_nodo * siguienteIndice;
};
typedef struct s_nodo * t_nodo;


t_indice buscarSub(char * str, char* sub);
t_nodo indices (char * sub);
void extraerFrasesDelArchivoEnArreglo( char *, char *** );
void agregarInformacionDeIndiceALista(int,t_indice,t_nodo *);
void imprimirIndices(t_nodo);
void borrarCaracteresPorPosicion(char *,int,int);

int main(){
    t_nodo listaDeIndices = NULL;

    listaDeIndices = indices("da");

    imprimirIndices(listaDeIndices);

}

t_indice buscarSub(char * str, char * sub){
    t_indice estructuraConIndices;
    int indiceDeCadena = 0;
    int indiceDeSubCadena = 0;
    int seEncontroSubCadena = 0;

    estructuraConIndices.posicionFinal = -1;
    estructuraConIndices.posicionInicial = -1;

    while( str[indiceDeCadena] != '\0' &&  !seEncontroSubCadena ){

        if( str[indiceDeCadena] == sub[indiceDeSubCadena] ){
            estructuraConIndices.posicionFinal = indiceDeCadena;
            estructuraConIndices.posicionInicial = indiceDeCadena;

            while(  str[indiceDeCadena] == sub[indiceDeSubCadena] &&
                    str[indiceDeCadena] != '\0' &&
                    sub[indiceDeSubCadena] != '\0' ){

                estructuraConIndices.posicionFinal = indiceDeCadena;

                indiceDeSubCadena++;
                indiceDeCadena++;
            }

            if(sub[indiceDeSubCadena] == '\0')
                seEncontroSubCadena = 1;

            else if(str[indiceDeCadena] == '\0'){
                estructuraConIndices.posicionFinal = -1;
                estructuraConIndices.posicionInicial = -1;
                return estructuraConIndices;
            }

            else if(str[indiceDeCadena] != sub[indiceDeSubCadena]){
                estructuraConIndices.posicionFinal = -1;
                estructuraConIndices.posicionInicial = -1;
            }

            indiceDeSubCadena = 0;

        }

        indiceDeCadena++;

    }

    return estructuraConIndices;
}
t_nodo indices( char * sub ){
    t_nodo listaDeIndices = NULL;
    t_indice actualIndice;
    int indiceDeFrases = 0;
    int indiceDeLetras = 0;
    char ** arregloDeFrases = NULL;

    extraerFrasesDelArchivoEnArreglo("frases.txt", &arregloDeFrases);

    actualIndice = buscarSub( arregloDeFrases[indiceDeFrases], sub );

    while(arregloDeFrases[indiceDeFrases][0] != '\0' ){

        actualIndice = buscarSub( arregloDeFrases[indiceDeFrases], sub );

        if(actualIndice.posicionInicial != -1 && actualIndice.posicionFinal != -1){
            agregarInformacionDeIndiceALista(indiceDeFrases, actualIndice, &listaDeIndices);

            indiceDeLetras =actualIndice.posicionInicial;

            while( indiceDeLetras < actualIndice.posicionFinal ){
                arregloDeFrases[indiceDeFrases][indiceDeLetras] = '\n';
                indiceDeLetras++;
            }

            arregloDeFrases[indiceDeFrases][indiceDeLetras] = '\n';

        }

        indiceDeFrases++;

    }

    return listaDeIndices;
}

void extraerFrasesDelArchivoEnArreglo( char * nombreDeArchivo, char *** direccionDelArregloDeFrases ){
    FILE * archivoDeFrases = fopen(nombreDeArchivo, "r");
    char ** arregloDeFrases = NULL;
    char * arregloDeCaracteres = NULL;
    char caracterLeido = 0;
    int indiceDeLetras = 0;
    int indiceDeFrases = 0;

    if(archivoDeFrases != NULL){

        arregloDeFrases = malloc( sizeof(char *) );
        arregloDeCaracteres = malloc( sizeof(char) );

        caracterLeido = fgetc(archivoDeFrases);

        while( caracterLeido != EOF ){

            while(  caracterLeido != '\n' ){

                arregloDeCaracteres[indiceDeLetras] = caracterLeido;

                indiceDeLetras++;
                arregloDeCaracteres = realloc(arregloDeCaracteres, sizeof(char) * (indiceDeLetras+1) );

                caracterLeido = fgetc(archivoDeFrases);

            }

            arregloDeCaracteres[indiceDeLetras] = '\0';
            arregloDeFrases[indiceDeFrases] = arregloDeCaracteres;

            indiceDeFrases++;
            arregloDeFrases = realloc(arregloDeFrases, sizeof(char *) * (indiceDeFrases+1) );

            caracterLeido = fgetc(archivoDeFrases);

            indiceDeLetras = 0;
            arregloDeCaracteres = malloc( sizeof(char) );

        }

        arregloDeCaracteres[0] = '\0';
        arregloDeFrases[indiceDeFrases] = arregloDeCaracteres;

        fclose(archivoDeFrases);
    }

    (*direccionDelArregloDeFrases) = arregloDeFrases;
}

void imprimirIndices(t_nodo listaDeIndices){

    if( listaDeIndices != NULL ){
        printf("(%d,",listaDeIndices->numeroDeLinea);
        printf("%d,", listaDeIndices->indice.posicionInicial);
        printf("%d)\n", listaDeIndices->indice.posicionFinal);
        imprimirIndices(listaDeIndices->siguienteIndice);
    }


}

void agregarInformacionDeIndiceALista(int numeroDeLinea, t_indice indices, t_nodo * direccionDelNodo){
    if( (*direccionDelNodo) == NULL ){
        (*direccionDelNodo) = malloc(sizeof(struct s_nodo));
        (*direccionDelNodo)->indice = indices;
        (*direccionDelNodo)->numeroDeLinea = numeroDeLinea;
        (*direccionDelNodo)->siguienteIndice = NULL;
    }
    else{
        agregarInformacionDeIndiceALista(numeroDeLinea, indices, &((*direccionDelNodo)->siguienteIndice));
    }
}
