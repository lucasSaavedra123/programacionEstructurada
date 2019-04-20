#include <stdio.h>
#include <stdlib.h>

#define NA 50
#define NM 10
#define NN 50

#define MAXCHARACTERS 100

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

/* FUNCIONES BASICAS */
void cargarString(char string[]);
int obtenerPosicionDeMateriaEnStructPorCodigo(t_materia materias[NM], int codigo);
int darOpcion();
int darLegajo();
int darCodigo();

/* CARGAS DE INFORMACIÓN */
void cargarAlumnos();
void cargarMaterias();
void cargarNotas(t_alumno alumnos[NA], t_materia materias[NM]);

/* IMPORTACION DE INFORMACION DESDE ARCHIVOS */
void cargarAlumnosAlArreglo(t_alumno alumnos[NA]);
void cargarMateriasAlArreglo(t_materia materias[NM]);
void cargarNotasAlArreglo(t_nota notas[NN]);
void cargarDatosAStructs(t_alumno alumnos[NA], t_materia materias[NM],t_nota notas[NN]);

/* IMPRESION DE INFORMACION */
void imprimirNotasDeAlumnoPorLegajo(t_alumno alumnos[NA], t_materia materias[NM], t_nota notas[NN], int legajo);
void imprimirNotasDeAlumnosPorMateria(t_alumno alumnos[NA], t_materia materias[NM], t_nota notas[NN], int codigo);
void imprimirMenu();

/*GUARDAR INFORMACION*/
void guardarAlumnoEnelArchivo( t_alumno alumno, char nombreDelArchivo[]);
void guardarMateriaEnelArchivo( t_materia materia, char nombreDelArchivo[]);
void guardarNotaEnElArchivo(t_nota nota, char nombreDelArchivo[]);
void guardarNotasEnElArchivo(t_nota notas[NN], char nombreDelArchivo[]);

int main()
{

    int opcion;

    t_alumno alumnos[NA];
    t_materia materias[NM];
    t_nota notas[NN];

    cargarDatosAStructs(alumnos,materias,notas);

    printf("Bienvenido al asistente de la facultad\n");

    imprimirMenu();
    opcion = darOpcion();

    while(opcion != 0){

        switch (opcion){
            case 1:
                cargarAlumnos();
                break;
            case 2:
                cargarMaterias();
                break;
            case 3:
                cargarNotas(alumnos, materias);
                break;
            case 4:
                imprimirNotasDeAlumnoPorLegajo(alumnos, materias, notas, darLegajo());
                break;
            case 5:
                imprimirNotasDeAlumnosPorMateria(alumnos, materias, notas, darCodigo());
                break;
        }

    cargarDatosAStructs(alumnos,materias,notas);
    opcion = darOpcion();

    }

    return 0;
}

/*FUNCIONES BASICAS*/
void cargarString(char string[MAXCHARACTERS]){
    char caracter = getchar();
    int indice = 0;

    /*--------------------------------
    Se verifica que el getchar no haya
    leido el caracter '\r'
    --------------------------------*/

    if( caracter == 10 ){
        caracter = getchar();
    }

    while( indice < MAXCHARACTERS-1 && caracter != 10){
        string[indice] = caracter;
        indice++;

        caracter = getchar();
    }

    string[indice] = '\0';
}
int obtenerPosicionDeMateriaEnStructPorCodigo(t_materia materias[NM], int codigo){
    int posicion = -1;
    int indiceMaterias;

    for(indiceMaterias = 0; indiceMaterias < NM && materias[indiceMaterias].codigo != 0; indiceMaterias++){
            if( materias[indiceMaterias].codigo == codigo){
                    posicion = indiceMaterias;
            }
    }

    return posicion;
}
int obtenerPosicionDeAlumnoEnStructPorLegajo(t_alumno alumnos[NA], int legajo){
    int posicion = -1;
    int indiceAlumnos;

    for(indiceAlumnos = 0; indiceAlumnos < NA && alumnos[indiceAlumnos].legajo != 0; indiceAlumnos++){
            if( alumnos[indiceAlumnos].legajo == legajo){
                    posicion = indiceAlumnos;
            }
    }

    return posicion;
}
int darOpcion(){
    int opcion;

    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
int darLegajo(){
    int legajo;

    printf("Ingrese Legajo: ");
    scanf("%d", &legajo);

    return legajo;
}
int darCodigo(){
    int codigo;

    printf("Ingrese Codigo: ");
    scanf("%d", &codigo);

    return codigo;
}

/* CARGAS DE INFORMACIÓN */
void cargarAlumnos(){

    t_alumno alumno;
    int contadorAlumnos = 0;
    int indiceMaterias = 0;

    printf("Ingresar legajo: ");
    scanf("%d", &alumno.legajo);

    while(contadorAlumnos < NA && alumno.legajo != 0){

        printf("Ingresar el nombre del alumno: ");
        cargarString(alumno.nombre);

        printf("Ingresar materias (PARAR CON 0):\n");
        scanf("%d", &alumno.materias[indiceMaterias]);

        while(indiceMaterias < 30-1 && alumno.materias[indiceMaterias] != 0){
            indiceMaterias++;
            scanf("%d", &alumno.materias[indiceMaterias]);
        }

        alumno.materias[indiceMaterias] = 0;

        guardarAlumnoEnelArchivo(alumno, "alumnos.txt");

        indiceMaterias = 0;

        while(indiceMaterias < 30){
            alumno.materias[indiceMaterias] = 0;
            indiceMaterias++;
        }

        printf("Ingresar legajo: ");
        scanf("%d", &alumno.legajo);

    }

}
void cargarMaterias(){
    t_materia materia;
    int contadorMaterias = 0;

    printf("Ingresar codigo: ");
    scanf("%d", &materia.codigo);

    while(contadorMaterias < NM && materia.codigo != 0){

        printf("Ingresar nombre de la materia: ");
        cargarString(materia.nombre);

        guardarMateriaEnelArchivo(materia, "materias.txt");

        printf("Ingresar codigo: ");
        scanf("%d", &materia.codigo);

    }

}
void cargarNotas(t_alumno alumnos[NA], t_materia materias[NM]){
    int indiceAlumnos;
    int indiceMaterias;
    int posicionMateria;
    t_nota nota;

    for(indiceAlumnos = 0; indiceAlumnos < NA && alumnos[indiceAlumnos].legajo != 0 ; indiceAlumnos++){
        for(indiceMaterias = 0; indiceMaterias < NM && alumnos[indiceAlumnos].materias[indiceMaterias] != 0 ; indiceMaterias++){
            posicionMateria = obtenerPosicionDeMateriaEnStructPorCodigo(materias, alumnos[indiceAlumnos].materias[indiceMaterias]);

            if( posicionMateria != -1 ){
                printf("Ingresar la nota de %s para la materia %s: ", alumnos[indiceAlumnos].nombre, materias[posicionMateria].nombre);
                scanf("%d", &nota.nota);

                nota.cod_materia = alumnos[indiceAlumnos].materias[indiceMaterias];
                nota.legajo_alumno = alumnos[indiceAlumnos].legajo;

                guardarNotaEnElArchivo(nota, "notas.txt");
            }

            else{
                printf("La Materia No Existe! \n");
            }

        }
    }
}

/* IMPORTACIÓN DE INFORMACION DESDE ARCHIVOS */
void cargarAlumnosAlArreglo(t_alumno alumnos[NA]){
    int indiceAlumnos;
    FILE * archivo = fopen("alumnos.txt","r");


    if(archivo == NULL){
        printf("\n");
        printf("Error al leer los alumnos");
        printf("\n");
    }
    //Si se puede abrir el archivo
    else{

        for(    indiceAlumnos = 0;
                fscanf(archivo,
                       "%d,%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
                       &alumnos[indiceAlumnos].legajo,
                       alumnos[indiceAlumnos].nombre,
                       &alumnos[indiceAlumnos].materias[0],
                       &alumnos[indiceAlumnos].materias[1],
                       &alumnos[indiceAlumnos].materias[2],
                       &alumnos[indiceAlumnos].materias[3],
                       &alumnos[indiceAlumnos].materias[4],
                       &alumnos[indiceAlumnos].materias[5],
                       &alumnos[indiceAlumnos].materias[6],
                       &alumnos[indiceAlumnos].materias[7],
                       &alumnos[indiceAlumnos].materias[8],
                       &alumnos[indiceAlumnos].materias[9],
                       &alumnos[indiceAlumnos].materias[10],
                       &alumnos[indiceAlumnos].materias[11],
                       &alumnos[indiceAlumnos].materias[12],
                       &alumnos[indiceAlumnos].materias[13],
                       &alumnos[indiceAlumnos].materias[14],
                       &alumnos[indiceAlumnos].materias[15],
                       &alumnos[indiceAlumnos].materias[16],
                       &alumnos[indiceAlumnos].materias[17],
                       &alumnos[indiceAlumnos].materias[18],
                       &alumnos[indiceAlumnos].materias[19],
                       &alumnos[indiceAlumnos].materias[20],
                       &alumnos[indiceAlumnos].materias[21],
                       &alumnos[indiceAlumnos].materias[22],
                       &alumnos[indiceAlumnos].materias[23],
                       &alumnos[indiceAlumnos].materias[24],
                       &alumnos[indiceAlumnos].materias[25],
                       &alumnos[indiceAlumnos].materias[26],
                       &alumnos[indiceAlumnos].materias[27],
                       &alumnos[indiceAlumnos].materias[28],
                       &alumnos[indiceAlumnos].materias[29]) != EOF && indiceAlumnos < NA;
                        indiceAlumnos++){}

        fclose(archivo);

    }

}
void cargarMateriasAlArreglo(t_materia materias[NM]){
    int indiceMaterias;
    FILE * archivo = fopen("materias.txt","r");


    if(archivo == NULL){
        printf("\n");
        printf("Error al leer las materias");
        printf("\n");
    }
    //Si se puede abrir el archivo
    else{
        for( indiceMaterias = 0; fscanf(archivo, "%d,%s\n", &materias[indiceMaterias].codigo, materias[indiceMaterias].nombre) != EOF && indiceMaterias < NM;indiceMaterias++){}
        fclose(archivo);
    }


}
void cargarNotasAlArreglo(t_nota notas[NN]){
    int indiceNotas;
    FILE * archivo = fopen("notas.txt","r");

    if(archivo == NULL){
        printf("\n");
        printf("Error al leer las notas");
        printf("\n");
    }
    //Si se puede abrir el archivo
    else{
        for( indiceNotas = 0; fscanf(archivo, "%d,%d,%d\n", &notas[indiceNotas].legajo_alumno, &notas[indiceNotas].cod_materia, &notas[indiceNotas].nota) != EOF && indiceNotas < NN;indiceNotas++){}

        fclose(archivo);
    }

}
void cargarDatosAStructs(t_alumno alumnos[NA], t_materia materias[NM],t_nota notas[NN]){
    cargarAlumnosAlArreglo(alumnos);
    cargarMateriasAlArreglo(materias);
    cargarNotasAlArreglo(notas);
}

/* IMPRESION DE INFORMACION */
void imprimirNotasDeAlumnoPorLegajo(t_alumno alumnos[NA], t_materia materias[NM], t_nota notas[NN], int legajo){
    int indiceMaterias;
    int indiceNotas;
    t_alumno alumno;
    int posicionDeAlumnoEnStruct = obtenerPosicionDeAlumnoEnStructPorLegajo(alumnos, legajo);
    int posicionDeMateriaEnStruct;

    printf("\n");

    if(posicionDeAlumnoEnStruct == -1){
        printf("No se encuentra el alumno.");
    }
    else{

        alumno = alumnos[posicionDeAlumnoEnStruct];

        printf("Notas de %s: \n", alumno.nombre);

        for(indiceMaterias = 0; indiceMaterias < 30 && alumno.materias[indiceMaterias] != 0; indiceMaterias++){

                posicionDeMateriaEnStruct = obtenerPosicionDeMateriaEnStructPorCodigo(materias, alumno.materias[indiceMaterias]);

                if(posicionDeMateriaEnStruct != -1){
                    printf("%s: ", materias[posicionDeMateriaEnStruct].nombre);

                    for(indiceNotas = 0; indiceNotas < NN && notas[indiceNotas].cod_materia != 0; indiceNotas++){
                        if( materias[posicionDeMateriaEnStruct].codigo == notas[indiceNotas].cod_materia && alumno.legajo == notas[indiceNotas].legajo_alumno){
                            printf("%d\n", notas[indiceNotas].nota);
                        }
                    }
                }

                else{
                    printf("\n");
                    printf("Materia Erronea!");
                    printf("\n");
                }
        }


    }

    printf("\n");

}
void imprimirNotasDeAlumnosPorMateria(t_alumno alumnos[NA], t_materia materias[NM], t_nota notas[NN], int codigo){

    int indiceNotas;
    int posicionDeMateriaEnStruct = obtenerPosicionDeMateriaEnStructPorCodigo(materias, codigo);
    int posicionDeAlumnoEnStruct;
    t_materia materia;

    printf("\n");

    if(posicionDeMateriaEnStruct == -1){
        printf("No existe la materia");
    }
    else{

        materia = materias[posicionDeMateriaEnStruct];

        printf("Notas de %s: ", materia.nombre);
        printf("\n");

        for(indiceNotas = 0; indiceNotas < NN; indiceNotas++){
            if(notas[indiceNotas].cod_materia == codigo){
                posicionDeAlumnoEnStruct = obtenerPosicionDeAlumnoEnStructPorLegajo(alumnos, notas[indiceNotas].legajo_alumno);

                if(posicionDeAlumnoEnStruct == -1){
                    printf("Alumno no existe\n");
                }
                else{
                    printf("- %s: ", alumnos[posicionDeAlumnoEnStruct].nombre);
                    printf("%d", notas[indiceNotas].nota);
                    printf("\n");
                }
            }
        }
    }

    printf("\n");
}
void imprimirMenu(){

    printf("1- Cargar Alumno \n");
    printf("2- Cargar Materia \n");
    printf("3- Cargar Notas \n");
    printf("4- Imprimir Notas de Alumno (Por Legajo) \n");
    printf("5- Imprimir Notas de materia (Por Materia) \n");
    printf("0- Salir \n\n");

}

/*GUARDAR INFORMACION*/
void guardarAlumnoEnelArchivo(t_alumno alumno, char nombreDelArchivo[]){

    int indiceMaterias = 0;
    FILE * archivo = fopen(nombreDelArchivo, "a");

    if(archivo == NULL){
        printf("\n");
        printf("Error en el guardado de alumno");
        printf("\n");
    }
    //Si se puede abrir el archivo
    else{

        fprintf(archivo, "%d,%s", alumno.legajo,alumno.nombre);

        while( alumno.materias[indiceMaterias] != 0 && indiceMaterias < 30){
            fprintf(archivo, ",%d", alumno.materias[indiceMaterias]);
            indiceMaterias++;
        }

        fprintf(archivo, "\n");
        fclose(archivo);

    }

}
void guardarMateriaEnelArchivo( t_materia materia, char nombreDelArchivo[]){
    FILE * archivo = fopen(nombreDelArchivo, "a");

    if(archivo == NULL){
        printf("\n");
        printf("Error en el guardado de la materia");
        printf("\n");
    }
    //Si se puede abrir el archivo
    else{
        fprintf(archivo,"%d,%s\n", materia.codigo, materia.nombre);
        fclose(archivo);
    }
}
void guardarNotaEnElArchivo(t_nota nota, char nombreDelArchivo[]){
    FILE * archivo = fopen(nombreDelArchivo, "a");

    if(archivo == NULL){
        printf("\n");
        printf("Error en el guardado de la nota");
        printf("\n");
    }
    //Si se puede abrir el archivo
    else{
        fprintf(archivo,"%d,%d,%d\n", nota.legajo_alumno, nota.cod_materia, nota.nota);
        fclose(archivo);
    }
}
void guardarNotasEnElArchivo(t_nota notas[NN], char nombreDelArchivo[]){
    int indiceNotas;
    FILE * archivo = fopen(nombreDelArchivo, "w");

    if(archivo == NULL){
        printf("\n");
        printf("Error en el guardado de las notas");
        printf("\n");
    }
    //Si se puede abrir el archivo
    else{
        for( indiceNotas = 0; indiceNotas < NN && notas[indiceNotas].legajo_alumno != 0; indiceNotas++){
            fprintf(archivo,"%d,%d,%d\n", notas[indiceNotas].legajo_alumno, notas[indiceNotas].cod_materia, notas[indiceNotas].nota);
        }

        fclose(archivo);
    }

}

