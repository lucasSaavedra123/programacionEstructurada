#include <stdio.h>
#include <stdlib.h>

int darRestoDeDosNumerosEnteros(int dividendo, int divisor);

int main()
{

    return 0;
}

int darRestoDeDosNumerosEnteros(int dividendo, int divisor){

    printf("Dividendo: %d\n",dividendo);
    printf("Divisor: %d\n",divisor);


    if(divisor == 0)
        return 0;

    if(dividendo >= divisor && dividendo > 0)
        return darRestoDeDosNumerosEnteros(dividendo-divisor, divisor);
    else if(dividendo >= divisor && divisor < 0)
        return darRestoDeDosNumerosEnteros(dividendo+divisor, divisor);
    else
        return dividendo;

}

