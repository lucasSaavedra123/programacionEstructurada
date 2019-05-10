#include <stdio.h>
#include <stdlib.h>

char * subcadena (char * p, unsigned int i, int n);
char * leerArch(const char * nomArch);

int main(){
    char* str=NULL;
    char* subStr=NULL;
    int i=0, n=3;

    str = leerArch("frase.txt");
    subStr = subcadena (str, i, n);

    printf("%s", str);

    printf("Para i = %d y n = %d ,Se encontro el substring: ", i,n);
    printf("%s", subStr);

    return 0;
}

char * leerArch(const char * nomArch){
    char * str = NULL;
    char caracter = 0;
    int contadorDeLetras = 0;
    FILE * archivoConFrase = fopen(nomArch, "r");

    str = malloc(sizeof(char));

    caracter = fgetc(archivoConFrase);

    while(caracter != EOF){
        *(str+contadorDeLetras) = caracter;

        contadorDeLetras++;
        str = realloc(str, sizeof(char) * (contadorDeLetras+1) );

        caracter = fgetc(archivoConFrase);
    }

    *(str+contadorDeLetras) = '\0';

    fclose(archivoConFrase);

    return str;
}

char * subcadena (char * p, unsigned int i, int n){
    char * subP = NULL;
    char caracter;
    //int indiceLetras = i;
    int cantidadDeLetrasATomar = 0;
    int cantidadDeLetras = 0;
    int longitudDeCadena = 0;

    subP = malloc(sizeof(char));

    if(n < 0){
        cantidadDeLetrasATomar = -n;
    }
    else
        cantidadDeLetrasATomar = n;

    while(*(p+longitudDeCadena) != '\0')
        longitudDeCadena++;

    //Si i es mas grande que la longitud que se tiene, que ni se haga
    if(i < longitudDeCadena){

        caracter = *(p+i);

        while(caracter != '\0' && cantidadDeLetras < cantidadDeLetrasATomar){
            *(subP + cantidadDeLetras) = caracter;
            cantidadDeLetras++;
            subP = realloc(subP, sizeof(char) * cantidadDeLetras);

            if(n < 0){
                caracter = *(p+i-cantidadDeLetras);
                printf("%c", caracter);
            }
            else{
                caracter = *(p+i+cantidadDeLetras);
            }
        }
    }

    *(subP+cantidadDeLetras) = '\0';

    return subP;

}
