#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char dni[9];
    char nombre [100], apellido [100];
    double monto_adeudado;
    unsigned int dia, mes,anio;
} t_datos;

void cargarCadena(char **);
int guardarRegistrosDelArchivoEn(char *,t_datos **);
void imprimirRegistrosDelArchivo(char *);
void imprimirRegistros(t_datos *);

int main()
{
    char * nombreDeArchivo = NULL;
    printf("Ingrese el nombre del archivo: ");
    cargarCadena(&nombreDeArchivo);

    imprimirRegistrosDelArchivo(nombreDeArchivo);

    return 0;
}

void cargarCadena(char ** cadena){
    int indiceDeCaracteres = 0;
    char caracter = 0;
    (*cadena) = malloc(sizeof(char));

    caracter = getchar();

    while( caracter != 10 ){
        *((*cadena)+indiceDeCaracteres) = caracter;
        indiceDeCaracteres++;

        (*cadena) = realloc((*cadena), sizeof(char) * (1 + indiceDeCaracteres));

        caracter = getchar();
    }

    *((*cadena)+indiceDeCaracteres) = '\0';

}

int guardarRegistrosDelArchivoEn(char * nombreDelArchivo, t_datos ** direccionDelArregloDeRegistros){

    FILE * archivoDeRegistros = fopen(nombreDelArchivo, "rb");
    t_datos deudaAuxiliar;
    int huboError = 0;
    int contadorDeDeudas = 0;

    if(archivoDeRegistros == NULL){
        huboError = -1;
    }
    else{

        (*direccionDelArregloDeRegistros) = malloc(sizeof(t_datos));

        while(fread(&deudaAuxiliar, sizeof(t_datos), 1, archivoDeRegistros) !=0 ){
            *((*direccionDelArregloDeRegistros)+contadorDeDeudas) = deudaAuxiliar;
            contadorDeDeudas++;
            (*direccionDelArregloDeRegistros) = realloc((*direccionDelArregloDeRegistros),sizeof(t_datos) * (contadorDeDeudas+1));
        }

        (*((*direccionDelArregloDeRegistros)+contadorDeDeudas)).dni[0] = '\0';

        fclose(archivoDeRegistros);
    }

    return huboError;

}

void imprimirRegistrosDelArchivo(char * nombreDelArchivo){
    t_datos * arregloDeRegistros = NULL;

    if(guardarRegistrosDelArchivoEn(nombreDelArchivo, &arregloDeRegistros) == -1){
        printf("No existe el archivo o hubo otro error!");
    }
    else{
        imprimirRegistros(arregloDeRegistros);
    }

}

void imprimirRegistros(t_datos * arregloDeRegistros){
    int indiceDeRegistros = 0;
    t_datos registroAuxiliar;

    while(arregloDeRegistros[indiceDeRegistros].dni[0] != '\0'){
        registroAuxiliar = arregloDeRegistros[indiceDeRegistros];
        printf("%s\t", registroAuxiliar.dni);
        printf("%s\t", registroAuxiliar.nombre);
        printf("%s\t", registroAuxiliar.apellido);
        printf("$%.0lf\t", registroAuxiliar.monto_adeudado);
        printf("%d\t", registroAuxiliar.anio);
        printf("%d\t", registroAuxiliar.mes);
        printf("%d\t\n", registroAuxiliar.dia);

        indiceDeRegistros++;
    }

}
