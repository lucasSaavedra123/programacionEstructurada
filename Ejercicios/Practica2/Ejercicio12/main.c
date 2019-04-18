#include <stdio.h>
#include <stdlib.h>

char togglearLetra(char);

int main()
{
    printf("%c", togglearLetra('z'));
    return 0;
}

char togglearLetra(char letra){
    return letra ^ 0b00100000;
}
