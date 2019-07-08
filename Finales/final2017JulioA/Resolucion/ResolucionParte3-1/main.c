#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1
struct s_nodoDeLocalidades {
    int ID_localidad;
    char * nombreDeLaLocalidad;
    double promedioDeAltura;
    double minimaAltura;
    double maximaAltura;

    struct s_nodoDeListaDeLocalidades * localidadSiguiente;
};
typedef struct s_nodo * nodoDeLocalidades;

nodoDeLocalidades maxCinco(int, int);

int main(){

    nodoDeLocalidades listaDeLocalidadDelAnio =  maxCinco();

    return 0;
}

nodoDeLocalidades maxCinco(int n, int anio){
    nodoDeLocalidades listaDeLocalidades = NULL;
    nodoDeLocalidades listaDeLocalidadesDelAnio = NULL;



    return listaDeLocalidadesDelAnio;
}
