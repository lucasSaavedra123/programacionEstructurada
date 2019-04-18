#include <stdio.h>
#include <stdlib.h>

int devolverCantidadDeUnos(unsigned int);

int main (){
    printf("%d", devolverCantidadDeUnos(0b1111110010));
    return 0;
}

int devolverCantidadDeUnos(unsigned int n){
    int resultado = 0;
    int mascara = 1;
    int i;

    for( i=0; i < 32; i++){
            if( (n & mascara) == 1){
                resultado++;
            }

            n = n >> 1;

    }

    return resultado;
}
