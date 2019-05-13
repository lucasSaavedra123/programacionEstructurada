#include <stdio.h>
#include <stdlib.h>

int multiplicarDosNumerosEnteros(int numero1, int numero2);

int main()
{
    printf("%d\n", multiplicarDosNumerosEnteros(45,2));
    printf("%d\n", multiplicarDosNumerosEnteros(-2,-50));
    printf("%d\n", multiplicarDosNumerosEnteros(10,7));

    return 0;
}

int multiplicarDosNumerosEnteros(int numero1, int numero2){

    if(numero2 == 0)
        return 0;

    if(numero2 > 0)
        return numero1 + multiplicarDosNumerosEnteros(numero1,numero2-1);
    else if(numero2 < 0)
        return -numero1 + multiplicarDosNumerosEnteros(numero1,numero2+1);
    else
        return numero1;

}
