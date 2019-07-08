#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

//1
struct sActor{
    char apellido[50];
    char nombre[50];
    int codigo;
};
typedef struct sActor estructuraDeActor;

struct sPelicula{
    int codigo;
    char nombre[50];
    int anoDeEstreno;
};
typedef struct sPelicula estructuraDePelicula;

struct sCSV{
    int codigoPelicula;
    int codigoActor;
};
typedef struct sCSV estructuraCSV;

void imprimirPeliculas(estructuraDePelicula *);
void imprimirPeliculasDeActor(int);

void obtenerCodigosDeActoresDePelicula(int **,estructuraCSV *,int);
int obtenerLargoDeArreglo(int *);

void guardarPeliculasEnArreglo(estructuraDePelicula **);
void guardarActoresEnArreglo(estructuraDeActor **);
void guardarInfoCSVEnArreglo(estructuraCSV **);

void grabarPelicula(estructuraDePelicula pelicula){
    FILE * archivoDePeliculas = fopen("Peliculas.dat","ab");
    fwrite(&pelicula, sizeof(estructuraDePelicula), 1, archivoDePeliculas);
    fclose(archivoDePeliculas);
}
void grabarActor(estructuraDeActor actor){
    FILE * archivoDeActores = fopen("Actores.dat","ab");
    fwrite(&actor, sizeof(estructuraDeActor), 1, archivoDeActores);
    fclose(archivoDeActores);
}


int main(){
   /* estructuraDePelicula pelicula;
    pelicula.anoDeEstreno = 2008;
    pelicula.codigo = 8;
    strcpy(pelicula.nombre, "007: Quantum");

    grabarPelicula(pelicula);


    estructuraDeActor actor;
    actor.codigo = 4;
    strcpy(actor.nombre, "Daniel");
    strcpy(actor.apellido, "Radcliffe");

    grabarActor(actor);
*/

    imprimirPeliculasDeActor(2);
    return 0;
}

void imprimirPeliculas(estructuraDePelicula * arregloDePeliculas){
    int indiceDePeliculas = 0;

    while(arregloDePeliculas[indiceDePeliculas].codigo != 0){
        printf("%-25s", arregloDePeliculas[indiceDePeliculas].nombre);
        printf("%-5d\n", arregloDePeliculas[indiceDePeliculas].anoDeEstreno);

        indiceDePeliculas++;
    }

}

void imprimirPeliculasDeActor(int codigoDeActor){
    estructuraDePelicula * arregloDePeliculasDondeActuoSolo = malloc(sizeof(estructuraDePelicula));
    estructuraDePelicula * arregloDePeliculas = NULL;
    estructuraCSV * arregloCSV = NULL;
    int indiceDePeliculas = 0;
    int * arregloDeCodigoDeActores = NULL;
    int indiceDePeliculas2 = 0;
    int largoDeArreglo = 0;

    guardarInfoCSVEnArreglo(&arregloCSV);
    guardarPeliculasEnArreglo(&arregloDePeliculas);

    imprimirPeliculas(arregloDePeliculas);

    printf("Peliculas del actor con ID %d\n", codigoDeActor);

    while( arregloDePeliculas[indiceDePeliculas].codigo != 0 ){
                obtenerCodigosDeActoresDePelicula(&arregloDeCodigoDeActores,arregloCSV,arregloDePeliculas[indiceDePeliculas].codigo);
                largoDeArreglo = obtenerLargoDeArreglo(arregloDeCodigoDeActores);

                if(largoDeArreglo == 1 && arregloDeCodigoDeActores[0] == codigoDeActor){
                    arregloDePeliculasDondeActuoSolo[indiceDePeliculas2] = arregloDePeliculas[indiceDePeliculas];
                    indiceDePeliculas2++;
                    arregloDePeliculasDondeActuoSolo = realloc(arregloDePeliculasDondeActuoSolo, sizeof(estructuraDePelicula) * (indiceDePeliculas2+1));
                }

                free(arregloDeCodigoDeActores);
                indiceDePeliculas++;
    }

    arregloDePeliculasDondeActuoSolo[indiceDePeliculas2].codigo = 0;

    imprimirPeliculas( arregloDePeliculasDondeActuoSolo );

    free(arregloDePeliculasDondeActuoSolo);
    free(arregloCSV);
    free(arregloDePeliculas);
    free(arregloDeCodigoDeActores);
}

int obtenerLargoDeArreglo(int * arregloDeNumeros){
    int largo = 0;
    int indiceDeArreglo = 0;

    while( arregloDeNumeros[indiceDeArreglo] != 0 ){
        indiceDeArreglo++;
    }

    largo = indiceDeArreglo;

    return largo;
}

void obtenerCodigosDeActoresDePelicula(int ** direccionDeArreglo,estructuraCSV * arregloCSV, int codigo){
    int indiceCSV = 0;
    int indiceDeArreglo = 0;
    int * arregloDeCodigos = malloc(sizeof(int));

    while(arregloCSV[indiceCSV].codigoPelicula != 0){

        if(arregloCSV[indiceCSV].codigoPelicula == codigo){
            arregloDeCodigos[indiceDeArreglo] = arregloCSV[indiceCSV].codigoActor;
            indiceDeArreglo++;
            arregloDeCodigos = realloc(arregloDeCodigos,sizeof(int) * (indiceDeArreglo+1));
        }

        indiceCSV++;
    }

    arregloDeCodigos[indiceDeArreglo] = 0;
    (*direccionDeArreglo) = arregloDeCodigos;
}

void guardarPeliculasEnArreglo(estructuraDePelicula ** direccionDelArreglo){
    FILE * archivoDePeliculas = fopen("Peliculas.dat","rb");
    int indiceDePeliculas = 0;
    estructuraDePelicula * arregloDePeliculas = malloc(sizeof(estructuraDePelicula));

    if(archivoDePeliculas != NULL){

        while( fread(&(arregloDePeliculas[indiceDePeliculas]), sizeof(estructuraDePelicula), 1, archivoDePeliculas) != 0 ){
            indiceDePeliculas++;
            arregloDePeliculas = realloc(arregloDePeliculas, sizeof(estructuraDePelicula) * (indiceDePeliculas+1) );
        }

        fclose(archivoDePeliculas);
    }

    arregloDePeliculas[indiceDePeliculas].codigo = 0;

    (*direccionDelArreglo) = arregloDePeliculas;
}
void guardarActoresEnArreglo(estructuraDeActor ** direccionDelArreglo){
    FILE * archivoDeActores = fopen("Actores.dat","rb");
    int indiceDeActores = 0;
    estructuraDeActor * arregloDeActores = malloc(sizeof(estructuraDeActor));

    if(archivoDeActores != NULL){

        while( fread(&(arregloDeActores[indiceDeActores]), sizeof(estructuraDeActor), 1, archivoDeActores) != 0 ){
            indiceDeActores++;
            arregloDeActores = realloc(arregloDeActores, sizeof(estructuraDeActor) * (indiceDeActores+1) );
        }

        fclose(archivoDeActores);
    }

    arregloDeActores[indiceDeActores].codigo = 0;

    (*direccionDelArreglo) = arregloDeActores;
}

void guardarInfoCSVEnArreglo(estructuraCSV ** direccionDelArreglo){
    FILE * archivoCSV = fopen("Peliculas_Actores.txt","r");
    int indiceDeLinea = 0;
    estructuraCSV * arregloDeLineas = malloc(sizeof(estructuraCSV));

    if(archivoCSV != NULL){

        while( fscanf(archivoCSV, "%d,%d\n", &(arregloDeLineas[indiceDeLinea].codigoPelicula), &(arregloDeLineas[indiceDeLinea].codigoActor)) != EOF ){
            indiceDeLinea++;
            arregloDeLineas = realloc(arregloDeLineas, sizeof(estructuraCSV) * (indiceDeLinea+1) );
        }

        fclose(archivoCSV);
    }

    arregloDeLineas[indiceDeLinea].codigoActor = 0;
    arregloDeLineas[indiceDeLinea].codigoPelicula = 0;

    (*direccionDelArreglo) = arregloDeLineas;
}
