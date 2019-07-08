#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

//1
struct s_empleado{
    int codigoVendedor;
    char * nombreVendedor;
    int objetivoTarjetasAnual;
    double sueldoAnual;
}
typedef estructuraDeEmpleado;

struct sNodoBin{
    estructuraDeEmpleado empleadoDelNodo;

    struct s_NodoBin * nodoIzquierda;
    struct s_NodoBin * nodoDerecha;

};
typedef struct sNodoBin * tNodoBin;

void cargarArbolVendedores(tNodoBin * arbol, FILE * fVende);
void cargarVendedorAlArbolVendedores(estructuraDeEmpleado, tNodoBin *);

int main(){

    tNodoBin arbolDeVendedores = NULL;
    FILE * archivo = fopen("vendedores.txt", "r");

    cargarArbolVendedores(&arbolDeVendedores, archivo);

    fclose(archivo);
    return 0;
}

void cargarArbolVendedores(tNodoBin * arbol, FILE * fVende){
    estructuraDeEmpleado empleadoNuevo;
    char caracterNuevo;
    char * arregloDeCaracteres = NULL;
    int indiceDeLetras = 0;

    if(fVende != NULL){

        while( fscanf(fVende, "%d,", &(empleadoNuevo.codigoVendedor)  ) != EOF ){

            indiceDeLetras = 0;
            arregloDeCaracteres = malloc(sizeof(char));
            caracterNuevo = fgetc(fVende);

            while(caracterNuevo != ','){
                arregloDeCaracteres[indiceDeLetras] = caracterNuevo;
                indiceDeLetras++;
                arregloDeCaracteres = realloc(arregloDeCaracteres, sizeof(char) * (indiceDeLetras+1));
                caracterNuevo = fgetc(fVende);
            }

            empleadoNuevo.nombreVendedor = arregloDeCaracteres;

            fscanf(fVende, "%d,", &(empleadoNuevo.objetivoTarjetasAnual) );
            fscanf(fVende, "%lf\n", &(empleadoNuevo.sueldoAnual) );

            cargarVendedorAlArbolVendedores(empleadoNuevo, arbol);

        }

    }

}


void cargarVendedorAlArbolVendedores(estructuraDeEmpleado empleadoNuevo, tNodoBin * direccionDelNodo){

    if( (*direccionDelNodo) == NULL ){
        (*direccionDelNodo) = malloc(sizeof(struct sNodoBin));
        (*direccionDelNodo)->empleadoDelNodo = empleadoNuevo;
        (*direccionDelNodo)->nodoIzquierda = NULL;
        (*direccionDelNodo)->nodoDerecha = NULL;
    }
    else{
        if( ((*direccionDelNodo)->empleadoDelNodo).codigoVendedor <  empleadoNuevo.codigoVendedor )
            cargarVendedorAlArbolVendedores(empleadoNuevo, &((*direccionDelNodo)->nodoIzquierda) );
        if( ((*direccionDelNodo)->empleadoDelNodo).codigoVendedor >  empleadoNuevo.codigoVendedor )
            cargarVendedorAlArbolVendedores(empleadoNuevo, &((*direccionDelNodo)->nodoDerecha) );
    }

}
