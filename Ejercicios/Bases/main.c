//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>//Incluimos una libreria

/*
Tipo de datos:
-Int    ---> Entero
-double ---> Float (tambien esta float )
-Char   ---> Caracteres (nos va a servir para formar a los strings)
-Char* (para strings)
-Strings y booleanos no son tipo de datos (no son un tipo de dato puro)

Uso de comillas:
" " se usa encerrar textos
' ' se usa para encerrar caracteres

Caracteres especiales:
-\n Salto de linea
-\t Tabulado

La ñ no se encuentra en el set de C
*/

//Definicion de funciones
int redondeo(double n)
{
    int trunc = n,result;//Tomamos solamente la parte entera
    double p_decimal = n-trunc;

    if(p_decimal > 0.5 || p_decimal == 0.5)
        result = trunc+1;
    else if(p_decimal < 0.5)
        result = trunc;

    return result;
}

int piso(double n)
{
    int trunc = n;
    return trunc;
}

int techo(double n)
{
    int trunc = n,result;//Tomamos solamente la parte entera
    double p_decimal = n-trunc;

    if(p_decimal == 0)
        result = trunc;
    else
        result = trunc+1;

    return result;
}

int main()
{
    //Primero se declaran las variables
    double numero; //Numero Real

    //Luego tenemos el cuerpo

    /*
    Para imprimir o grabar:
    %lf --->    Numero Float
    %d  --->    Enteros
    %c  --->    Caracteres
    */

    printf("Ingrese un numero real: ");
    scanf("%lf", &numero);

    printf("Redondeo = %d\n", redondeo(numero));
    printf("Piso = %d\n", piso(numero));
    printf("Techo = %d\n", techo(numero));

    //Por ahora, devolveremos 0
    return 0;
}
