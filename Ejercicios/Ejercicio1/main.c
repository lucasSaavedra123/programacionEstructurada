//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>//Incluimos una libreria

int redondeo(double n){
    int trunc = n,result;//Tomamos solamente la parte entera
    double p_decimal = n-trunc;

    if(p_decimal > 0.5 || p_decimal == 0.5)
        result = trunc+1;
    else if(p_decimal < 0.5)
        result = trunc;

    return result;
}

int piso(double n){
    int trunc = n;
    return trunc;
}

int techo(double n){
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
    double numero;

    printf("Ingrese un numero real: ");
    scanf("%lf", &numero);

    printf("Redondeo = %d\n", redondeo(numero));
    printf("Piso = %d\n", piso(numero));
    printf("Techo = %d\n", techo(numero));

    return 0;
}
