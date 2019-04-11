#include <stdio.h>
#include <stdlib.h>

#define NA 50
#define NM 10

typedef struct{
    char nombre[100];
    int legajo, materias[30];
}
t_alumno;

typedef struct{
    char nombre[100];
    int codigo;
}
t_materia;

typedef struct{
    int legajo_alumno;
    int cod_materia,nota;
}
t_nota;

void cargarString(char string[100]){
    int contador = 0;
    int c = getchar();

    /*--------------------------------
    Se verifica que el getchar no haya
    leido el caracter '\r'
    --------------------------------*/

    if( c == 10 ){
        c = getchar();
    }

    while( c!= 10 && contador < 100-1 ){
        string[contador] = c;
        contador++;
        c = getchar();
    }

    string[contador] = '\0';

}

void cargarAlumnos(){

    int i=0;
    t_alumno alumnos[NA];
    FILE * archivoDeAlumnos = fopen("alumnos.txt","a");

    printf("Ingresar el legajo del alumno: ");
    scanf("%d", &alumnos[i].legajo);

    while(i < NA && alumnos[i].legajo !=0){

        printf("Ingresar el nombre del alumno: ");
        cargarString(alumnos[i].nombre);

        printf("%s\n", alumnos[i].nombre);

        fprintf(archivoDeAlumnos, "%d,%s\n", alumnos[i].legajo, alumnos[i].nombre);

        i++;

        printf("Ingresar el legajo del alumno: ");
        scanf("%d", &alumnos[i].legajo);



    }

    fclose(archivoDeAlumnos);
}

void cargarMaterias(){

    int i=0;
    t_materia materias[NA];
    FILE * archivoDeMaterias = fopen("materias.txt","a");

    printf("Ingresar el codigo de la materia: ");
    scanf("%d", &materias[i].codigo);

    while(i < NM && materias[i].codigo !=0){

        printf("Ingresar el nombre de la materias: ");
        cargarString(materias[i].nombre);

        fprintf(archivoDeMaterias, "%d,%s\n", materias[i].codigo, materias[i].nombre);

        i++;

        printf("Ingresar el codigo de la materia: ");
        scanf("%d", &materias[i].codigo);

    }

    fclose(archivoDeMaterias);
}

void cargarNotas(t_alumno alumnos[NA], t_materia materias[NM]){}

void subirNotasAlArchivo(t_notas notas[]){}

void exportarAlumnos(t_alumno alumnos[NA]){
    int i;
    FILE * archivoDeAlumnos = fopen("alumnos.txt","r");

    for(i=0; i < NA && fscanf(archivoDeAlumnos, "%d,%s\n", &alumnos[i].legajo, alumnos[i].nombre) != EOF ; i++){}

    fclose(archivoDeAlumnos);
}

void exportarMaterias(t_materia materias[NM]){
    int i;
    FILE * archivoDeMaterias = fopen("materias.txt","r");

    for(i=0; i < NM && fscanf(archivoDeMaterias, "%d,%s\n", &materias[i].codigo, materias[i].nombre) != EOF ; i++){}

    fclose(archivoDeMaterias);
}


int main()
{
    t_alumno arregloDeAlumnos[NA];
    t_materia arregloDeMaterias[NM];

    exportarAlumnos(arregloDeAlumnos);
    exportarMaterias(arregloDeMaterias);

    cargarNotas(arregloDeAlumnos, arregloDeMaterias);

    return 0;
}
