#include <stdio.h>
#include <stdlib.h>

char shiftearAlaIzq(char);

int main(){
    printf("%d", shiftearAlaIzq(0b11111111));
}

char shiftearAlaIzq(char n){
    int mascara = 0b01111111;
    int resultado = (n >> 1) & mascara;

    return resultado;
}
