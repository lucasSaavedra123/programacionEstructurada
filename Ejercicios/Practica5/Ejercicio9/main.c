#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXCHARACTERS 100

typedef struct {
    char dni[9];
    char nombre [100], apellido [100];
    double monto_adeudado;
    unsigned int dia, mes,anio;
} t_datos;

void cargarCadena(char *);
void cargarDNI(char *);
void cargarPersonaEn(t_datos *);
void guardarDeudaEn(t_datos *,char *);
void cargarDatos();


int main()
{
    cargarDatos();
    return 0;
}

void cargarCadena(char cadena[MAXCHARACTERS]){
    int indiceDeCaracteres = 0;
    char caracter = 0;

    caracter = getche();

    while( caracter != 10 && indiceDeCaracteres < MAXCHARACTERS ){
        cadena[indiceDeCaracteres] = caracter;
        indiceDeCaracteres++;
        caracter = getche();
    }

    cadena[indiceDeCaracteres] = '\0';

}

void cargarDNI(char cadena[9]){
    int indiceDeCaracteres = 0;
    char caracter = 0;

    caracter = getche();

    while( caracter != 10 && indiceDeCaracteres < 9 ){
        cadena[indiceDeCaracteres] = caracter;
        indiceDeCaracteres++;
        caracter = getche();
    }

    cadena[indiceDeCaracteres] = '\0';

}

void cargarDatos(){
    t_datos deuda;

    cargarPersonaEn(&deuda);

    while(deuda.dni[0] != '0'){
        guardarDeudaEn(&deuda, "deudores.dat");
        cargarPersonaEn(&deuda);
    }
}

void cargarPersonaEn(t_datos * direccionDeDatos){
    printf("Ingresar DNI (para finalizar, ingrese 0): ");
    cargarDNI(direccionDeDatos->dni);

    if( direccionDeDatos->dni[0] != '0' ){
        printf("Ingresar Nombre: ");
        cargarCadena(direccionDeDatos->nombre);

        printf("Ingresar Apellido: ");
        cargarCadena(direccionDeDatos->apellido);

        printf("Ingresar monto adeudado (ARS): ");
        scanf("%lf", &(direccionDeDatos->monto_adeudado));

        printf("Año: ");
        scanf("%d", &(direccionDeDatos->anio));

        printf("Mes: ");
        scanf("%d", &(direccionDeDatos->mes));

        printf("Dia: ");
        scanf("%d", &(direccionDeDatos->dia));
        getch();

    }
}

void guardarDeudaEn(t_datos * deuda, char * nombreDelArchivo){
    FILE * archivo = fopen(nombreDelArchivo, "ab");

    fwrite(deuda, sizeof(t_datos), 1, archivo);

    fclose(archivo);
}
