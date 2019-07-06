#include <stdio.h>
#include <stdlib.h>

//2
struct s_nota{
    int valor;
    struct s_nota* sig;
};
typedef struct s_nota * t_nota;

struct s_alu{
    char* apellido;
    t_nota lstNota;
    struct s_alu* sig;
};
typedef struct s_alu * t_alu;

void listado(t_alu);

int obtenerPromedioDeLista(t_nota);
int obtenerSumaDeNotasDeLista(t_nota);
int obtenerCantidadDeNotasDeLista(t_nota);
void imprimirPromedioDeAlumnos(t_alu);

void agregarAlumno(t_alu *,char *);
void agregarNota(t_nota *, int);

int main()
{
    t_alu listaDeAlumnos = NULL;
    agregarAlumno(&listaDeAlumnos, "Saavedra");
    agregarAlumno(&listaDeAlumnos, "Tornati");
    agregarAlumno(&listaDeAlumnos, "Ahuad");
    agregarAlumno(&listaDeAlumnos, "Paredes");

    agregarNota(&(listaDeAlumnos->lstNota), 6);
    agregarNota(&(listaDeAlumnos->lstNota), 7);
    agregarNota(&(listaDeAlumnos->lstNota), 8);
    agregarNota(&(listaDeAlumnos->lstNota), 4);
    agregarNota(&(listaDeAlumnos->lstNota), 4);

    agregarNota(&(listaDeAlumnos->sig->lstNota), 4);
    agregarNota(&(listaDeAlumnos->sig->lstNota), 2);
    agregarNota(&(listaDeAlumnos->sig->lstNota), 10);
    agregarNota(&(listaDeAlumnos->sig->lstNota), 9);

    agregarNota(&(listaDeAlumnos->sig->sig->lstNota), 4);
    agregarNota(&(listaDeAlumnos->sig->sig->lstNota), 9);
    agregarNota(&(listaDeAlumnos->sig->sig->lstNota), 10);
    agregarNota(&(listaDeAlumnos->sig->sig->lstNota), 9);

    listado(listaDeAlumnos);

    return 0;
}


void listado(t_alu listaDeAlumnosAImprimir){
    printf("%10s%10s\n", "Apellido", "Promedio");
    printf("------------------------\n");

    imprimirPromedioDeAlumnos(listaDeAlumnosAImprimir);
}

int obtenerPromedioDeLista(t_nota listaDeNotas){
    int sumaDeNotasDeLaLista = obtenerSumaDeNotasDeLista(listaDeNotas);
    int cantidadDeNotasDeLaLista = obtenerCantidadDeNotasDeLista(listaDeNotas);
    int promedio = 0;

    if(cantidadDeNotasDeLaLista != 0)
        promedio = sumaDeNotasDeLaLista / cantidadDeNotasDeLaLista;


    return promedio;
}

int obtenerSumaDeNotasDeLista(t_nota listaDeNotas){

    if( listaDeNotas != NULL )
        return listaDeNotas->valor + obtenerSumaDeNotasDeLista(listaDeNotas->sig);
    else
        return 0;

}

int obtenerCantidadDeNotasDeLista(t_nota listaDeNotas){

    if( listaDeNotas != NULL )
        return 1 + obtenerCantidadDeNotasDeLista(listaDeNotas->sig);
    else
        return 0;

}

void agregarAlumno(t_alu * direccionDeLaLista,char * apellidoDelALumno){

    if( (*direccionDeLaLista) == NULL ){
        (*direccionDeLaLista) = malloc(sizeof(struct s_alu));
        (*direccionDeLaLista)->apellido = apellidoDelALumno;
        (*direccionDeLaLista)->lstNota = NULL;
        (*direccionDeLaLista)->sig = NULL;
    }
    else{
        agregarAlumno( &((*direccionDeLaLista)->sig), apellidoDelALumno );
    }

}

void agregarNota(t_nota * direccionDeLaLista, int nota){

    if( (*direccionDeLaLista) == NULL ){
        (*direccionDeLaLista) = malloc(sizeof(struct s_nota));
        (*direccionDeLaLista)->valor = nota;
        (*direccionDeLaLista)->sig = NULL;
    }
    else{
        agregarNota( &((*direccionDeLaLista)->sig), nota );
    }

}

void imprimirPromedioDeAlumnos(t_alu listaDeAlumnos){

     if( listaDeAlumnos != NULL ){
        printf("%10s%10d\n",listaDeAlumnos->apellido, obtenerPromedioDeLista(listaDeAlumnos->lstNota));
        imprimirPromedioDeAlumnos(listaDeAlumnos->sig);
    }

}
