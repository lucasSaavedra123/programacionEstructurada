#include <stdio.h>
#include <stdlib.h>

//2
struct s_empleado{
    int codigoVendedor;
    char * nombreVendedor;
    int objetivoTarjetasAnual;
    double sueldoAnual;
}
typedef estructuraDeEmpleado;

struct s_ventas{
    int codigoVendedor;
    char nombreMes[15];
    int cantidadDeTarjetas;
}
typedef estructuraDeVenta;

struct sNodoBin{
    estructuraDeEmpleado empleadoDelNodo;

    struct s_NodoBin * nodoIzquierda;
    struct s_NodoBin * nodoDerecha;

};
typedef struct sNodoBin * tNodoBin;

void cargarArbolVendedores(tNodoBin * arbol, FILE * fVende);
void cargarVendedorAlArbolVendedores(estructuraDeEmpleado, tNodoBin *);
void liquidar(tNodoBin arbol,int idVen);
int obtenerTotalDeTarjetasVendidasPorID(int);
void guardarVentas(estructuraDeVenta **);
estructuraDeEmpleado obtenerInformacionDeEmpleadoPorID(tNodoBin,int);

int main(){

    tNodoBin arbolDeVendedores = NULL;

    FILE * archivo = fopen("vendedores.txt", "r");

    cargarArbolVendedores(&arbolDeVendedores, archivo);

    liquidar(arbolDeVendedores, 1);

    fclose(archivo);

    free(arbolDeVendedores);

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
        else if( ((*direccionDelNodo)->empleadoDelNodo).codigoVendedor >  empleadoNuevo.codigoVendedor )
            cargarVendedorAlArbolVendedores(empleadoNuevo, &((*direccionDelNodo)->nodoDerecha) );
    }

}

void liquidar(tNodoBin arbol,int idVen){
    FILE * archivoDeVentas = fopen("ventasTarjetas.dat" ,"rb");
    estructuraDeEmpleado empleado = obtenerInformacionDeEmpleadoPorID(arbol, idVen);
    int cantidadDeTarjetasVendidas = obtenerTotalDeTarjetasVendidasPorID(idVen);

    if(archivoDeVentas != NULL){

        if( empleado.codigoVendedor == 0){
            printf("No existe el empleado!\n");
        }
        else{
            printf("Vendedor: %s\n", empleado.nombreVendedor);
            printf("ID: %d\n", empleado.codigoVendedor);
            printf("Total de tarjetas vendidas (anual): %d\n", cantidadDeTarjetasVendidas);
            printf("Objetivo Anual: %d\n", empleado.objetivoTarjetasAnual);

        }

        fclose(archivoDeVentas);

    }

}

int obtenerTotalDeTarjetasVendidasPorID(int idVen){
    estructuraDeVenta * arregloDeVentas = NULL;
    int indiceDeVentas = 0;
    int totalDeTarjetas = 0;

    guardarVentas(&arregloDeVentas);

    while( arregloDeVentas[indiceDeVentas].codigoVendedor != 0 ){
        if(arregloDeVentas[indiceDeVentas].codigoVendedor == idVen){
            totalDeTarjetas = totalDeTarjetas + arregloDeVentas[indiceDeVentas].cantidadDeTarjetas;
        }

        indiceDeVentas++;
    }

    free(arregloDeVentas);

    return totalDeTarjetas;
}

void guardarVentas(estructuraDeVenta ** direccionDelArregloDeVentas ){
    estructuraDeVenta * arregloDeVentas = NULL;
    int contadorDeVentas = 0;
    FILE * archivoDeVentas = fopen("ventasTarjetas.dat", "rb");

    if(archivoDeVentas != NULL){

        arregloDeVentas = malloc(sizeof(estructuraDeVenta));

        while( fread(&arregloDeVentas[contadorDeVentas].codigoVendedor, sizeof(int), 1, archivoDeVentas) != 0 ){

            fread(arregloDeVentas[contadorDeVentas].nombreMes, sizeof(char), 15, archivoDeVentas);
            fread(&arregloDeVentas[contadorDeVentas].cantidadDeTarjetas, sizeof(int), 1, archivoDeVentas);

            contadorDeVentas++;
            arregloDeVentas = realloc(arregloDeVentas, sizeof(estructuraDeVenta) * (contadorDeVentas+1));

        }

        arregloDeVentas[contadorDeVentas].codigoVendedor = 0;

        fclose(archivoDeVentas);
    }


    (*direccionDelArregloDeVentas) = arregloDeVentas;
}

estructuraDeEmpleado obtenerInformacionDeEmpleadoPorID(tNodoBin arbol,int idVen){
    estructuraDeEmpleado empleadoEncontrado;

    if(arbol == NULL){
        empleadoEncontrado.codigoVendedor = 0;
        return empleadoEncontrado;
    }

    else{

        if( (arbol->empleadoDelNodo).codigoVendedor == idVen ){
            empleadoEncontrado = (arbol->empleadoDelNodo);
            return empleadoEncontrado;
        }
        else{
            if( (arbol->empleadoDelNodo).codigoVendedor <  idVen )
                 return obtenerInformacionDeEmpleadoPorID(arbol->nodoIzquierda, idVen );
            else if( (arbol->empleadoDelNodo).codigoVendedor >  idVen )
                 return obtenerInformacionDeEmpleadoPorID(arbol->nodoDerecha, idVen );
        }

    }


}
