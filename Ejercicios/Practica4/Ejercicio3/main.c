#include <stdio.h>
#include <stdlib.h>

int darRestoDeDosNumerosEnteros(int dividendo, int divisor);

int main()
{
    printf("%d",darRestoDeDosNumerosEnteros(10,3));
    return 0;
}

int darRestoDeDosNumerosEnteros(int dividendo, int divisor){

    if(divisor == 0 || dividendo == 0)
        return 0;

    if(dividendo >= divisor && dividendo > 0 && divisor > 0)
        return darRestoDeDosNumerosEnteros(dividendo - divisor, divisor);
    else if(dividendo < 0 && divisor < 0)
        return darRestoDeDosNumerosEnteros(-dividendo, -divisor);
    else if(dividendo > 0 && divisor < 0)
        return darRestoDeDosNumerosEnteros(dividendo, -divisor);
    else if(dividendo < 0 && divisor > 0)
        return -darRestoDeDosNumerosEnteros(-dividendo,divisor)+divisor;
    else
        return dividendo;
}
