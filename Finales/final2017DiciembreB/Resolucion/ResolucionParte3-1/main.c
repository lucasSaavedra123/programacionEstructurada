#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_alumno{
    int nro_registro;
    char * nombre;
    char * apellido;
};
typedef struct s_alumno estructuraDeAlumno;

//Tomamos como alumno de parada aquel que tiene nro_registro igual a 0 y char * en NULL

//1
void unificar(char *, char *);//Funcion que nos piden
void extraerAlumnosDeArchivoEnArreglo(char *, estructuraDeAlumno **);
void unirAlumnosEnArreglo(estructuraDeAlumno *, estructuraDeAlumno *, estructuraDeAlumno **);
void grabarAlumnosEnArchivo(estructuraDeAlumno *, char *);
void ordenarAlumnosEnArregloPorNroRegistro( estructuraDeAlumno * );

//Funciones de ayuda
int obtenerCantidadDeAlumnosEnArreglo(estructuraDeAlumno *);
int noSonMismoAlumno(estructuraDeAlumno, estructuraDeAlumno);
int estaAlumnoEnArreglo(estructuraDeAlumno, estructuraDeAlumno *);
estructuraDeAlumno obtenerAlumnoDeParada();

int main(){
    unificar("comisionAM.csv", "comisionBM.csv");
    return 0;
}

void unificar(char * nombreDeArchivo1, char * nombreDeArchivo2){
    estructuraDeAlumno * alumnosDeLasDosComisiones = NULL;
    estructuraDeAlumno * alumnosDelArchivo1 = NULL;
    estructuraDeAlumno * alumnosDelArchivo2 = NULL;

    extraerAlumnosDeArchivoEnArreglo(nombreDeArchivo1, &alumnosDelArchivo1);
    extraerAlumnosDeArchivoEnArreglo(nombreDeArchivo2, &alumnosDelArchivo2);

    unirAlumnosEnArreglo(alumnosDelArchivo1, alumnosDelArchivo2, &alumnosDeLasDosComisiones);
    ordenarAlumnosEnArregloPorNroRegistro(alumnosDeLasDosComisiones);

    grabarAlumnosEnArchivo(alumnosDeLasDosComisiones, "comisiones.csv");

    free(alumnosDeLasDosComisiones);
    free(alumnosDelArchivo1);
    free(alumnosDelArchivo2);
}

void extraerAlumnosDeArchivoEnArreglo( char * nombreDeArchivo, estructuraDeAlumno ** direccionDelArregloDeAlumnos ){
    FILE * archivoDeAlumnos = fopen(nombreDeArchivo, "r");
    estructuraDeAlumno alumnoNuevo;
    estructuraDeAlumno alumnoDeParada = obtenerAlumnoDeParada();
    estructuraDeAlumno * arregloDeAlumnos = NULL;
    int indiceDeAlumnos = 0;
    int indiceDeLetras = 0;
    char caracterLeido = 0;

    if(archivoDeAlumnos != NULL){

        arregloDeAlumnos = malloc(sizeof(estructuraDeAlumno));

        while( fscanf(archivoDeAlumnos, "%d,", &(alumnoNuevo.nro_registro) ) != EOF ){

            indiceDeLetras = 0;
            alumnoNuevo.nombre = malloc(sizeof(char));
            caracterLeido = fgetc(archivoDeAlumnos);

            while(caracterLeido != ','){
                *(alumnoNuevo.nombre + indiceDeLetras) = caracterLeido;

                indiceDeLetras++;
                alumnoNuevo.nombre = realloc( alumnoNuevo.nombre, sizeof(char) * (indiceDeLetras+1) );

                caracterLeido = fgetc(archivoDeAlumnos);
            }

            *(alumnoNuevo.nombre + indiceDeLetras) = '\0';

            indiceDeLetras = 0;
            alumnoNuevo.apellido = malloc(sizeof(char));
            caracterLeido = fgetc(archivoDeAlumnos);

            while(caracterLeido != '\n'){
                *(alumnoNuevo.apellido + indiceDeLetras) = caracterLeido;

                indiceDeLetras++;
                alumnoNuevo.apellido = realloc( alumnoNuevo.apellido, sizeof(char) * (indiceDeLetras+1) );

                caracterLeido = fgetc(archivoDeAlumnos);
            }

            *(alumnoNuevo.apellido + indiceDeLetras) = '\0';

            *(arregloDeAlumnos+indiceDeAlumnos) = alumnoNuevo;
            indiceDeAlumnos++;

            arregloDeAlumnos = realloc(arregloDeAlumnos, sizeof(estructuraDeAlumno) * (indiceDeAlumnos+1));

        }

        *(arregloDeAlumnos+indiceDeAlumnos) = alumnoDeParada;

        fclose(archivoDeAlumnos);
    }

    //'RETORNAMOS' EL ARREGLO
    (*direccionDelArregloDeAlumnos) = arregloDeAlumnos;

}

void unirAlumnosEnArreglo(estructuraDeAlumno * arregloDeAlumnos1, estructuraDeAlumno * arregloDeAlumnos2, estructuraDeAlumno ** direccionDelArregloAGuardar){
    estructuraDeAlumno * arregloDeAlumnosUnion = malloc(sizeof(estructuraDeAlumno));
    estructuraDeAlumno alumnoDeParada = obtenerAlumnoDeParada();
    int indiceDeAlumnos = 0;
    int indiceDeAlumnosUnion = 0;

    arregloDeAlumnosUnion[0] = alumnoDeParada;

    if( arregloDeAlumnos1 != NULL){
        while(noSonMismoAlumno(arregloDeAlumnos1[indiceDeAlumnos],alumnoDeParada)){
            if(!estaAlumnoEnArreglo(arregloDeAlumnos1[indiceDeAlumnos], arregloDeAlumnosUnion)){
                arregloDeAlumnosUnion[indiceDeAlumnosUnion] = arregloDeAlumnos1[indiceDeAlumnos];
                indiceDeAlumnosUnion++;
                arregloDeAlumnosUnion = realloc( arregloDeAlumnosUnion, sizeof(estructuraDeAlumno) * (indiceDeAlumnosUnion+1) );
                arregloDeAlumnosUnion[indiceDeAlumnosUnion] = alumnoDeParada;
            }

            indiceDeAlumnos++;

        }

    }

    indiceDeAlumnos = 0;

    if( arregloDeAlumnos2 != NULL){
        while(noSonMismoAlumno(arregloDeAlumnos2[indiceDeAlumnos],alumnoDeParada)){
            if(!estaAlumnoEnArreglo(arregloDeAlumnos2[indiceDeAlumnos], arregloDeAlumnosUnion)){
                arregloDeAlumnosUnion[indiceDeAlumnosUnion] = arregloDeAlumnos2[indiceDeAlumnos];
                indiceDeAlumnosUnion++;
                arregloDeAlumnosUnion = realloc( arregloDeAlumnosUnion, sizeof(estructuraDeAlumno) * (indiceDeAlumnosUnion+1) );
                arregloDeAlumnosUnion[indiceDeAlumnosUnion] = alumnoDeParada;
            }

            indiceDeAlumnos++;

        }
    }

    (*direccionDelArregloAGuardar) = arregloDeAlumnosUnion;
}

void ordenarAlumnosEnArregloPorNroRegistro(estructuraDeAlumno * arregloDeAlumnos){
    estructuraDeAlumno alumnoDeParada = obtenerAlumnoDeParada();
    estructuraDeAlumno alumnoAuxiliar;
    int indiceDeAlumnos1 = 0;
    int indiceDeAlumnos2 = 0;

    for(indiceDeAlumnos1 = 0; noSonMismoAlumno(arregloDeAlumnos[indiceDeAlumnos1], alumnoDeParada) ;indiceDeAlumnos1++){
        for(indiceDeAlumnos2 = indiceDeAlumnos1; noSonMismoAlumno(arregloDeAlumnos[indiceDeAlumnos2], alumnoDeParada) ;indiceDeAlumnos2++){
            if(arregloDeAlumnos[indiceDeAlumnos2].nro_registro < arregloDeAlumnos[indiceDeAlumnos1].nro_registro){
                alumnoAuxiliar = arregloDeAlumnos[indiceDeAlumnos1];
                arregloDeAlumnos[indiceDeAlumnos1] = arregloDeAlumnos[indiceDeAlumnos2];
                arregloDeAlumnos[indiceDeAlumnos2] = alumnoAuxiliar;
            }
        }
    }

}

void grabarAlumnosEnArchivo(estructuraDeAlumno * arregloDeAlumnos, char * nombreDeArchivo){

    FILE * archivoDeAlumnos = fopen(nombreDeArchivo, "w");
    estructuraDeAlumno alumnoDeParada = obtenerAlumnoDeParada();
    int indiceDeAlumnos = 0;

    if(archivoDeAlumnos != NULL){

        while(noSonMismoAlumno(alumnoDeParada, arregloDeAlumnos[indiceDeAlumnos])){
            fprintf(archivoDeAlumnos, "%d,%s,%s\n",   arregloDeAlumnos[indiceDeAlumnos].nro_registro,
                                                    arregloDeAlumnos[indiceDeAlumnos].nombre,
                                                    arregloDeAlumnos[indiceDeAlumnos].apellido );

            indiceDeAlumnos++;

        }

        fclose(archivoDeAlumnos);
    }



}

estructuraDeAlumno obtenerAlumnoDeParada(){
    estructuraDeAlumno alumnoDeParada;

    alumnoDeParada.nro_registro = 0;
    alumnoDeParada.nombre = NULL;
    alumnoDeParada.apellido = NULL;

    return alumnoDeParada;
}

int noSonMismoAlumno(estructuraDeAlumno alumno1, estructuraDeAlumno alumno2){
    int noSonMismo = 1;

    if(alumno1.nro_registro == alumno2.nro_registro //&&
       /* strcmp(alumno1.apellido, alumno2.apellido) == 0 &&
        strcmp(alumno1.nombre, alumno2.nombre) == 0*/){
        noSonMismo = 0;
        }


    return noSonMismo;
}

int estaAlumnoEnArreglo(estructuraDeAlumno alumno, estructuraDeAlumno * arregloDeAlumnos){
    int estaAlumno = 0;
    int indiceDeAlumnos = 0;
    estructuraDeAlumno alumnoDeParada = obtenerAlumnoDeParada();

    if(arregloDeAlumnos != NULL){
        while(noSonMismoAlumno(arregloDeAlumnos[indiceDeAlumnos], alumnoDeParada)){

            if(!noSonMismoAlumno(alumno, arregloDeAlumnos[indiceDeAlumnos]))
                estaAlumno = 1;

            indiceDeAlumnos++;
        }
    }

    return estaAlumno;
}
