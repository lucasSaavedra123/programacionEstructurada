#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//Prototipo de Funciones

char * cargarCadena(){
    int contadorDeCaracteres = 0;
    char caracterIngresado = getche();
    char * cadena = malloc(sizeof(char));

    if( caracterIngresado != '0' ){
        while( caracterIngresado != 10 ){
            *(cadena+contadorDeCaracteres) = caracterIngresado;
            contadorDeCaracteres++;
            cadena = realloc(cadena, sizeof(char)*(contadorDeCaracteres+1));
            caracterIngresado = getche();
        }
    }
    else
        return NULL;

    *(cadena+contadorDeCaracteres) = '\0';

    return cadena;


}
void cargarCadenas(char *** direccionDelConjuntoDeCadenas){
    int contadorDeCadenas = 0;
    char * direccionDeCadenaNueva = NULL;

    *(direccionDelConjuntoDeCadenas) = malloc( sizeof(char *) );

    direccionDeCadenaNueva = cargarCadena();

    while(direccionDeCadenaNueva != NULL){

        *((*direccionDelConjuntoDeCadenas)+contadorDeCadenas) = direccionDeCadenaNueva;

        contadorDeCadenas++;

        *(direccionDelConjuntoDeCadenas) = realloc( *(direccionDelConjuntoDeCadenas), sizeof(char * ) * (contadorDeCadenas+1) );

        direccionDeCadenaNueva = cargarCadena();

    }

    *((*direccionDelConjuntoDeCadenas)+contadorDeCadenas) = NULL;

}

//Gonz's function

char * retornarCadenaMasChica(char ** cadena){
    char * frase = *(cadena);
    char * min = NULL;

    if(frase != NULL){
        min = retornarCadenaMasChica(cadena+1);

        if(min == NULL)//Te falto esto
            return frase;

        if(strcmp(min,frase) < 0)
            return min;
        else
            return frase;

    }
    else
        return NULL;



}

char ** retornarDireccionDeLaCadenaMasChica(char ** cadena){
    char ** direccionActual = cadena;
    char ** direccionAnterior = NULL;

    if(direccionActual != NULL){
        direccionAnterior = retornarDireccionDeLaCadenaMasChica(cadena+1);

        if(direccionAnterior == NULL)//Te falto esto
            return direccionActual;

        if(strcmp(*direccionAnterior,*direccionActual) < 0)
            return direccionAnterior;
        else
            return direccionActual;
    }
    else
        return NULL;



}

void ordenarCadenasDeCaracteres(char ** direccionDeLaCadena){
    char * cadenaActual = *direccionDeLaCadena;
    char ** posicionDeCadenaChica = retornarDireccionDeLaCadenaMasChica(direccionDeLaCadena);
    char * cadenaMasChica = *(posicionDeCadenaChica);


    printf("%s\n", cadenaActual);
    printf("%s\n", cadenaMasChica);

    if( cadenaActual != NULL ){

        *(posicionDeCadenaChica) = cadenaActual;
        *(direccionDeLaCadena) = cadenaMasChica;

        ordenarCadenasDeCaracteres(direccionDeLaCadena+1);
    }


}


int retornarNumeroMasGrandeDelArreglo(int * arreglo);
int retornarNumeroMasChicoDelArreglo(int * arreglo);
int * retornarDireccionDelNumeroMasGrandeDelArreglo(int * arreglo);

char * retornarDireccionDelCaracterMasChico(char * cadena);

void ordenarCadenaDeCaracteres(char * cadena);

int MCD(int numero1, int numero2);
int MCM(int numero1, int numero2);

int main()
{

    int arregloDeNumeros[] = {1,2,3,4,5,1,-5,6,9,7,0};
    char cadenaDeCaracteres[] = "soylucassaavedra";
    char ** arregloDeCadenas = NULL;
    int indice = 0;

    printf("Numero mas chico del arreglo: %d\n", retornarNumeroMasChicoDelArreglo(arregloDeNumeros));
    printf("Numero mas grande del arreglo: %d\n", retornarNumeroMasGrandeDelArreglo(arregloDeNumeros));

    printf("El maximo comun divisor entre 50 y 17 es: %d\n", MCD(50,17));
    printf("El maximo comun divisor entre 117 y 2 es: %d\n", MCD(42,12));
    printf("El maximo comun divisor entre 68 y 12 es: %d\n\n", MCD(68,12));

    printf("El maximo comun divisor entre 25 y 5 es: %d\n", MCM(25,5));
    printf("El maximo comun divisor entre 117 y 2 es: %d\n", MCM(117,2));
    printf("El maximo comun divisor entre 3 y 5 es: %d\n\n", MCM(3,5));

    ordenarCadenaDeCaracteres(cadenaDeCaracteres);
    printf("%s\n\n", cadenaDeCaracteres);

    cargarCadenas(&arregloDeCadenas);

    printf("%s\n", arregloDeCadenas[0]);
    printf("%s", retornarCadenaMasChica(arregloDeCadenas));

    ordenarCadenasDeCaracteres(arregloDeCadenas);

    /*for(indice = 0; arregloDeCadenas[indice] != NULL; indice++)
        printf("%s", arregloDeCadenas[indice]);*/


    return 0;
}

int retornarNumeroMasGrandeDelArreglo(int * arreglo){

    int numeroActual = *(arreglo);
    int numeroMasGrandeHastaAhora = 0;

    if(numeroActual != 0){
        numeroMasGrandeHastaAhora = retornarNumeroMasGrandeDelArreglo(arreglo+1);

        if(numeroMasGrandeHastaAhora == 0)
            return numeroActual;
        else{
            if(numeroActual > numeroMasGrandeHastaAhora)
                return numeroActual;
            else
                return numeroMasGrandeHastaAhora;
        }

    }
    else
        return numeroActual;

}

int retornarNumeroMasChicoDelArreglo(int * arreglo){

    int numeroActual = *(arreglo);
    int numeroMasChicoHastaAhora = 0;

    if(numeroActual != 0){
        numeroMasChicoHastaAhora = retornarNumeroMasChicoDelArreglo(arreglo+1);

        if(numeroMasChicoHastaAhora == 0)
            return numeroActual;
        else{
            if(numeroActual < numeroMasChicoHastaAhora)
                return numeroActual;
            else
                return numeroMasChicoHastaAhora;
        }

    }

    else
        return numeroActual;

}


char * retornarDireccionDelCaracterMasChico(char * cadena){
    char * direccionActual = cadena;
    char * direccionDelCaracterMasChicoHastaAhora = NULL;
    char caracterActual = *direccionActual;
    char caracterMasChicoHastaAhora = 0;

    if(caracterActual != '\0'){
        direccionDelCaracterMasChicoHastaAhora = retornarDireccionDelCaracterMasChico(direccionActual+1);

        if(direccionDelCaracterMasChicoHastaAhora == NULL)
            return direccionActual;
        else{
            caracterMasChicoHastaAhora = *direccionDelCaracterMasChicoHastaAhora;

            if(caracterActual < caracterMasChicoHastaAhora)
                return direccionActual;
            else
                return direccionDelCaracterMasChicoHastaAhora;

        }

    }
    else
        return NULL;





}


void ordenarCadenaDeCaracteres(char * arreglo){
    char * direccionDelCaracterMasChico = retornarDireccionDelCaracterMasChico(arreglo);
    char * direccionActual = arreglo;
    char caracterActual = *direccionActual;
    char caracterMasChico = 0;

    if( direccionDelCaracterMasChico != NULL ){
        caracterMasChico = *direccionDelCaracterMasChico;

        *direccionActual = caracterMasChico;
        *direccionDelCaracterMasChico = caracterActual;

        ordenarCadenaDeCaracteres(arreglo+1);

    }


}



int MCD( int numero1, int numero2){

    if(numero2 > numero1)
        return MCD(numero2, numero1);

    if(numero2 == 0)
        return numero1;
    else
        return MCD(numero2, numero1%numero2);
}

int MCM(int numero1, int numero2){

    int aux = 0;

    if(numero1>numero2){
        aux = numero1;
        numero1= numero2;
        numero2 = aux;
    }

    if(numero2%numero1 == 0)
        return numero2;
    else
        return numero2+MCM(numero1-1,numero2);


}
