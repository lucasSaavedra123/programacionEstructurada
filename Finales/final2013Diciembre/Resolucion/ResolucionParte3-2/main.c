#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2
struct sHabitante{
    int id;
    char nombre[60];
    char sexo;
    int edad;
    int ID_Localidad;
};
typedef struct sHabitante estructuraDeHabitante;

struct sLocalidad{
    int id;
    char * nombreLocalidad;
};
typedef struct sLocalidad estructuraDeLocalidad;

struct sCSV{
    int ID_Localidad;
    int ID_Habitante;
};
typedef struct sCSV estructuraDeCSV;

void imprimirNombrePoblacionMasLongeva();

char * obtenerNombreDePoblacionMasLongeva();
int promedioDeEdadDePoblacionID(int);

int obtenerIdLocalidadDeHabitante(int);
int obtenerIdLocalidadPorNombre(char *);
void extraerLocalidades(estructuraDeLocalidad **);
void extraerHabitantes(estructuraDeHabitante **);
void extraerArchivoCSV(estructuraDeCSV **);

int main(){
    imprimirNombrePoblacionMasLongeva();
    return 0;
}

void imprimirNombrePoblacionMasLongeva(){
    char * nombreDeLaPoblacion = obtenerNombreDePoblacionMasLongeva();
    printf("%s", nombreDeLaPoblacion);
}

char * obtenerNombreDePoblacionMasLongeva(){
    char * arregloDeCaracteres = 0;
    int promedioMasAlto = 0;
    int promedioDeLocalidad = 0;
    int indiceDeLocalidades = 0;
    estructuraDeLocalidad * arregloDeLocalidades = NULL;

    extraerLocalidades( &arregloDeLocalidades );

    while( arregloDeLocalidades[indiceDeLocalidades].id != 0){
        promedioDeLocalidad = promedioDeEdadDePoblacionID(arregloDeLocalidades[indiceDeLocalidades].id);

        if(promedioDeLocalidad > promedioMasAlto){
            promedioMasAlto = promedioDeLocalidad;
            arregloDeCaracteres = arregloDeLocalidades[indiceDeLocalidades].nombreLocalidad;
        }

        indiceDeLocalidades++;
    }

    free(arregloDeLocalidades);
    return arregloDeCaracteres;
}

int promedioDeEdadDePoblacionID(int idLocalidad){
    int promedio = 0;
    int cantidadDeHabitantes = 0;
    int sumaDeEdades = 0;
    int indiceDeHabitantes = 0;
    estructuraDeHabitante * arregloDeHabitantes = NULL;

    extraerHabitantes( &arregloDeHabitantes );

    while( arregloDeHabitantes[indiceDeHabitantes].id != 0 ){

        if(arregloDeHabitantes[indiceDeHabitantes].ID_Localidad == idLocalidad ){
            cantidadDeHabitantes++;
            sumaDeEdades = sumaDeEdades + arregloDeHabitantes[indiceDeHabitantes].edad;
        }

        indiceDeHabitantes++;

    }

    if( cantidadDeHabitantes != 0 ){
        promedio = sumaDeEdades/cantidadDeHabitantes;
    }

    free(arregloDeHabitantes);
    return promedio;
}

int obtenerIdLocalidadDeHabitante(int codigoDeHabitante){
    int IdLocalidad = 0;
    int indiceCSV = 0;
    estructuraDeCSV * arregloCSV = NULL;

    extraerArchivoCSV(&arregloCSV);

    while( arregloCSV[indiceCSV].ID_Habitante != 0 ){

        if(arregloCSV[indiceCSV].ID_Habitante == codigoDeHabitante){
            IdLocalidad = arregloCSV[indiceCSV].ID_Localidad;
        }

        indiceCSV++;
    }

    free(arregloCSV);
    return IdLocalidad;
}

int obtenerIdLocalidadPorNombre(char * nombreDeLocalidad){
    estructuraDeLocalidad * arregloDeLocalidades = NULL;
    int idLocalidad = 0;
    int indiceDeLocalidad = 0;

    extraerLocalidades(&arregloDeLocalidades);

    while(arregloDeLocalidades[indiceDeLocalidad].id != 0){
        if(strcmp(nombreDeLocalidad, arregloDeLocalidades[indiceDeLocalidad].nombreLocalidad) == 0){
            idLocalidad = arregloDeLocalidades[indiceDeLocalidad].id;
        }

        indiceDeLocalidad++;
    }

    free(arregloDeLocalidades);
    return idLocalidad;
}

void extraerLocalidades(estructuraDeLocalidad ** direccionDeArreglo){
    estructuraDeLocalidad * arregloDeLocalidades = NULL;
    int indiceDeLocalidades = 0;
    int indiceDeLetras = 0;
    char * arregloDeCaracteres = 0;
    char caracterLeido = 0;
    FILE * archivo = fopen("localidades.txt", "r");

    arregloDeLocalidades = malloc(sizeof(estructuraDeLocalidad));

    if(archivo != NULL){

        while( fscanf( archivo, "%d,", &(arregloDeLocalidades[indiceDeLocalidades].id) ) != EOF ){

            arregloDeCaracteres = malloc(sizeof(char));
            caracterLeido = fgetc(archivo);

            while(caracterLeido != '\n'){
                arregloDeCaracteres[indiceDeLetras] = caracterLeido;
                indiceDeLetras++;

                arregloDeCaracteres = realloc(arregloDeCaracteres, sizeof(char)* (indiceDeLetras+1));

                caracterLeido = fgetc(archivo);
            }

            arregloDeCaracteres[indiceDeLetras] = '\0';

            arregloDeLocalidades[indiceDeLocalidades].nombreLocalidad = arregloDeCaracteres;

            indiceDeLetras = 0;
            indiceDeLocalidades++;

            arregloDeLocalidades = realloc(arregloDeLocalidades, sizeof(estructuraDeLocalidad) * (indiceDeLocalidades+1));

        }


        fclose(archivo);
    }

    arregloDeLocalidades[indiceDeLocalidades].id = 0;

    (*direccionDeArreglo) = arregloDeLocalidades;
}

void extraerHabitantes(estructuraDeHabitante ** direccionDeArreglo){
    estructuraDeHabitante * arregloDeHabitantes = NULL;
    FILE * archivo = fopen("habitantes.dat", "rb");
    int indiceHabitante = 0;

    arregloDeHabitantes = malloc(sizeof(estructuraDeHabitante));

    if(archivo != NULL){

        while( fread(&(arregloDeHabitantes[indiceHabitante].id), sizeof(int), 1, archivo) != 0 ){
            fread(&(arregloDeHabitantes[indiceHabitante].nombre), sizeof(char) * 60, 1, archivo);
            fread(&(arregloDeHabitantes[indiceHabitante].sexo), sizeof(char), 1, archivo);
            fread(&(arregloDeHabitantes[indiceHabitante].edad), sizeof(int), 1, archivo);

            arregloDeHabitantes[indiceHabitante].ID_Localidad = obtenerIdLocalidadDeHabitante(arregloDeHabitantes[indiceHabitante].id);

            indiceHabitante++;
            arregloDeHabitantes = realloc(arregloDeHabitantes, sizeof(estructuraDeHabitante) * (indiceHabitante+1));
        }

        arregloDeHabitantes[indiceHabitante].id = 0;
        fclose(archivo);
    }

    (*direccionDeArreglo) = arregloDeHabitantes;
}

void extraerArchivoCSV(estructuraDeCSV ** direccionDeArreglo){
    int indiceCSV = 0;
    estructuraDeCSV * arregloDeCSV = NULL;
    FILE * archivo = fopen("habitantesXlocalidad.txt", "r");

    arregloDeCSV = malloc(sizeof(estructuraDeCSV));

    if(archivo != NULL){

        while( fscanf(archivo, "%d,%d\n", &(arregloDeCSV[indiceCSV].ID_Localidad), &(arregloDeCSV[indiceCSV].ID_Habitante)) != EOF ){
            indiceCSV++;
            arregloDeCSV = realloc(arregloDeCSV, sizeof(estructuraDeCSV) * (indiceCSV+1));
        }

        arregloDeCSV[indiceCSV].ID_Habitante = 0;
        arregloDeCSV[indiceCSV].ID_Localidad = 0;

        fclose(archivo);

    }


    (*direccionDeArreglo) = arregloDeCSV;
}
