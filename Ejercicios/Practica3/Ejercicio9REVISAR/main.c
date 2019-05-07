#include <stdio.h>
#include <stdlib.h>

char * subcadena (char * p, unsigned int i, unsigned int n);
char * leerArch();

int main()
{
    char cadena[5] = {0};
    char * subcad = NULL;

    cadena[0] = '1';
    cadena[1] = 'k';
    cadena[2] = 'l';
    cadena[3] = 'o';
    cadena[4] = 'p';
    cadena[5] = '\0';

    subcad = subcadena(cadena, 1, 3);

    return 0;
}

char * subcadena (char * p, unsigned int i, unsigned int n){
    char * pSubCadena = malloc( (n+1) * sizeof(char));
    int indiceDeCadena = 0;

    while( *(p+indiceDeCadena) != '\0' && indiceDeCadena < n ){
        *(pSubCadena+indiceDeCadena) = *(p+(i+indiceDeCadena));
        indiceDeCadena++;
    }

    *(pSubCadena+indiceDeCadena) = '\0';

    return pSubCadena;
}
