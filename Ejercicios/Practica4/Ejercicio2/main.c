#include <stdio.h>
#include <stdlib.h>

int dividirDosNumerosEnteros(int dividendo, int divisor);

int main()
{
    printf("%d\n", dividirDosNumerosEnteros(-20,5));
    return 0;
}

int dividirDosNumerosEnteros(int dividendo, int divisor){

    /*
    Para dividir dos numeros positivos, lo que se hace es tomar el dividendo y se le resta el divisor
    hasta que la resta te quede menos que el divisor (aca nos queda el resto)

    Si los dos son negativos, se los pasa a positivo y se llama la funcion y sigue funcionando como si los dos
    fueran positivos

    Si uno es negativo, se pasa el negativo a positivo, y despues el resultado de la función se le pone menos.
    El resultado del que se habla es como si la función tenga los dos valores positivos.
    */

    int resta = 0;

    if(divisor == 0 || dividendo == 0)
        return 0;

    if(divisor > 0 && dividendo > 0 && resta > 0){
        resta = dividendo - divisor;
        return 1 + dividirDosNumerosEnteros(resta, divisor);
    }

    else if( (divisor < 0 && dividendo < 0) || (divisor > 0 && dividendo < 0) || (divisor < 0 && dividendo > 0)){
        if(divisor < 0 && dividendo < 0)
            return dividirDosNumerosEnteros(-dividendo,-divisor);
        else if(divisor > 0 && dividendo < 0)
            return -dividirDosNumerosEnteros(dividendo,-divisor);
        else if(divisor < 0 && dividendo > 0)
            return -dividirDosNumerosEnteros(-dividendo,divisor);
    }

    else
        return 1;
}

/* ESTA FUNCION ES PARA LLEVAR AL DIVIDENDO HACIA 0, PERO AL FINAL NO SE USO.
int decrecimientoHaciaCero(int dividendo, int divisor){

    if(dividendo > 0 && divisor > 0)
        return dividendo - divisor;
    else if(dividendo < 0 && divisor < 0)
        return dividendo - divisor;
    else if(dividendo > 0 && divisor < 0)
        return dividendo + divisor;
    else if(dividendo < 0 && divisor > 0)
        return dividendo + divisor;
    else
        return 0;

}
*/
