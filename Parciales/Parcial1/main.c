#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//PARCIAL 1//

//Ejercicio 1
char * subCadena (char * cad, int ini, int cant);

//Ejercicio 2
struct s_texto{
    char * txt;
    int lon;
};
typedef struct s_texto t_texto;

t_texto * cargarTexto();

//Ejercicio 3
int cantImpar(int * arr);
int esPar(int numero);

int main()
{
    char cadena[] = "Todo debe simplificarse";
    t_texto * punteroDeEstructura = NULL;
    int arregloDeNumeros[] = {1,2,4,5,3,6,2,4,1,0};

    printf("Prueba del Ejercicio 1: \n");
    printf("%s\n", subCadena(cadena, 0, 2));
    printf("%s\n", subCadena(cadena, 3, 4));
    printf("%s\n", subCadena(cadena, 3, 0));
    printf("%s\n", subCadena(cadena, 19, 4));
    printf("%s\n", subCadena(cadena, 19, 20));



    printf("Prueba del Ejercicio 2: \n");
    punteroDeEstructura = cargarTexto();

    printf("Contenido de la estructura: %s\n", (*punteroDeEstructura).txt);
    printf("Longitud del texto: %d\n", (*punteroDeEstructura).lon);

    printf("Prueba del Ejercicio 3: \n");
    printf("Cantidad de impares: %d\n", cantImpar(arregloDeNumeros));




    return 0;
}

//Funcion del ejercicio 1
char * subCadena (char * cad, int ini, int cant){
    char * subCadena = NULL;
    int contadorDeLetras = 0;

    if(cad != NULL){
        subCadena = malloc(sizeof(char));
        while( *(cad+ini+contadorDeLetras) != '\0' && contadorDeLetras < cant && subCadena != NULL )
        {
            *(subCadena+contadorDeLetras) = *(cad+ini+contadorDeLetras);

            subCadena = realloc(subCadena, sizeof(char)* (contadorDeLetras+1));
            contadorDeLetras++;
        }

        if(subCadena != NULL)
            *(subCadena+contadorDeLetras) = '\0';

    }

    return subCadena;
}

//Funcion del ejercicio 2
t_texto * cargarTexto(){

    t_texto * direccionDeLaEstructura = NULL;
    t_texto estructuraNueva;
    char caracterIngresado = 0;
    int contadorDeCaracteresIngresados = 0;

    direccionDeLaEstructura = malloc(sizeof(t_texto));

    estructuraNueva.txt = malloc(sizeof(char));

    caracterIngresado = getche();

    while(caracterIngresado != 10){
        *(estructuraNueva.txt+contadorDeCaracteresIngresados) = caracterIngresado;

        contadorDeCaracteresIngresados++;

        estructuraNueva.txt = realloc(estructuraNueva.txt, sizeof(char) * (contadorDeCaracteresIngresados+1));

        caracterIngresado = getche();
    }

    *(estructuraNueva.txt+contadorDeCaracteresIngresados) = '\0';
    estructuraNueva.lon = contadorDeCaracteresIngresados;

    *(direccionDeLaEstructura) = estructuraNueva;

    return direccionDeLaEstructura;
}

//Ejercicio 3
int cantImpar(int * arr){

    if(*(arr) != 0){
        if(esPar(*(arr)))
            return 1 + cantImpar(arr+1);
        else
            return cantImpar(arr+1);
    }
    else
        return 0;


}

int esPar(int numero){
    int esPar = 0;

    if( numero%2 == 0)
        esPar = 1;

    return esPar;
}

