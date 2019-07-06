#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1
struct s_indice{
    int posicionInicial;
    int posicionFinal;
};

typedef struct s_indice t_indice;

t_indice buscarSub(char * str, char* sub);

int main(){
    t_indice indicesDeLaPalabra;
    char cadena[] = "La verdad absoluta no existe, y esto es absolutamente cierto.";

    indicesDeLaPalabra = buscarSub(cadena, "no existe, y");
    printf("Indice Inicial: %d\n", indicesDeLaPalabra.posicionInicial);
    printf("Indice FInal: %d\n", indicesDeLaPalabra.posicionFinal);
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
