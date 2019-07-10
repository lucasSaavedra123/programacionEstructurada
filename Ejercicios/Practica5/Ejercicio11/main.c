#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char dni[9];
    char nombre [100], apellido [100];
    double monto_adeudado;
    unsigned int dia, mes,anio;
} t_datos;

void copiarArchivo(char *, char *);
int guardarRegistrosDelArchivoEn(char *,t_datos **);
int noEstaElDNIEnArreglo(char *, t_datos *);
void imprimirRegistrosDelArchivo(char *);
void imprimirRegistros(t_datos *);


int main(){
    copiarArchivo("deudores.dat", "deudores2.dat");
    imprimirRegistrosDelArchivo("deudores2.dat");
    return 0;
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
void copiarArchivo(char * nombreArchivoFuente, char * nombreArchivoDestino){

    t_datos * arregloDeRegistros = NULL;
    t_datos * arregloDeRegistrosSinRepetir = NULL;
    int indice1 = 0;
    int indice2 = 0;
    int indice3 = 0;
    int huboError = guardarRegistrosDelArchivoEn(nombreArchivoFuente, &arregloDeRegistros);

    if(!huboError){

        arregloDeRegistrosSinRepetir = malloc(sizeof(t_datos));

        for( indice1=0; arregloDeRegistros[indice1].dni[0] != '\0' ;indice1++){
                if(noEstaElDNIEnArreglo(arregloDeRegistros[indice1].dni, arregloDeRegistrosSinRepetir)){

                    arregloDeRegistrosSinRepetir[indice2] = arregloDeRegistros[indice1];
                    arregloDeRegistrosSinRepetir[indice2].monto_adeudado = 0;
                    arregloDeRegistrosSinRepetir[indice2].mes = 0;
                    arregloDeRegistrosSinRepetir[indice2].dia = 0;
                    arregloDeRegistrosSinRepetir[indice2].anio = 0;

                    for( indice3 = indice1; arregloDeRegistros[indice3].dni[0] != '\0';indice3++){
                        if( strcmp(arregloDeRegistrosSinRepetir[indice2].dni, arregloDeRegistros[indice3].dni) == 0 ){
                            arregloDeRegistrosSinRepetir[indice2].monto_adeudado = arregloDeRegistrosSinRepetir[indice2].monto_adeudado + arregloDeRegistros[indice3].monto_adeudado;
                        }
                    }

                    guardarDeudaEn(&arregloDeRegistrosSinRepetir[indice2], nombreArchivoDestino);
                    indice2++;
                    arregloDeRegistrosSinRepetir = realloc(arregloDeRegistrosSinRepetir, sizeof(t_datos) * (indice2+1) );

                }

        }

        arregloDeRegistrosSinRepetir[indice2].dni[0] = '\0';

    }

    else{
        printf("Hubo Error!");
    }


}

void guardarDeudaEn(t_datos * deuda, char * nombreDelArchivo){
    FILE * archivo = fopen(nombreDelArchivo, "ab");

    fwrite(deuda, sizeof(t_datos), 1, archivo);

    fclose(archivo);
}

int noEstaElDNIEnArreglo(char * dni, t_datos * arregloDeRegistros){
    int noEsta = 1;
    int indice = 0;

    while( arregloDeRegistros[indice].dni[0] != '\0' ){
        if(strcmp(arregloDeRegistros[indice].dni,dni) == 0){
            noEsta = 0;
        }

        indice++;
    }

    return noEsta;
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
