#include <stdio.h>
#include <stdlib.h>

int devolverEnteroConChars(unsigned char,unsigned char,unsigned char,unsigned char);
int shiftearAlaIzquierda8Bits(int);

int main()
{}

int devolverEnteroConChars(unsigned char char1,unsigned char char2,unsigned char char3,unsigned char char4){
    int resultado = 0;

    resultado = resultado | char1;
    shiftearAlaIzquierda8Bits(resultado);

    resultado = resultado | char2;
    shiftearAlaIzquierda8Bits(resultado);

    resultado = resultado | char3;
    shiftearAlaIzquierda8Bits(resultado);

    resultado = resultado | char4;
    shiftearAlaIzquierda8Bits(resultado);

    return resultado;
}

int shiftearAlaIzquierda8Bits(int n){
    return n << 8;
}
