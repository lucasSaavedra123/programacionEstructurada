#include <stdio.h>
#include <stdlib.h>

void imprimirRepresentacionBinariaDeChar(char caracter);

int main()
{
    imprimirRepresentacionBinariaDeChar('c');
    imprimirRepresentacionBinariaDeChar('C');
    return 0;
}

void imprimirRepresentacionBinariaDeChar(char caracter){
    int contador;
    int resultado;

    int mascara = 0b10000000;

    for(contador = 0; contador < 8 ; contador++){
        resultado = caracter & mascara;

        if(resultado == 128){
            printf("1");
        }
        else{
            printf("0");
        }

        caracter = caracter << 1;
    }

    printf("\n");

}
