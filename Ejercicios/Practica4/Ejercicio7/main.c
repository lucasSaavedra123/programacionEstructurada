#include <stdio.h>
#include <stdlib.h>

unsigned int contar_vocales (char *);
int esVocal(char);

int main()
{
    printf("%d", contar_vocales("Hola"));
    return 0;
}

unsigned int contar_vocales (char * cadenaDeCaracteres){

    char primerCaracterDeLaCadena = *(cadenaDeCaracteres);

    if(primerCaracterDeLaCadena != '\0'){
        if( esVocal(primerCaracterDeLaCadena) )
            return 1 + contar_vocales(cadenaDeCaracteres+1);
        else
            return 0 + contar_vocales(cadenaDeCaracteres+1);
    }
    else
        return 0;
}

int esVocal(char letra){

    char cadenaDeLetrasVocales[] = {'a','e','i','o','u','A','E','I','O','U','\0'};
    int esVocal = 0;
    int indice;

    for(indice = 0; cadenaDeLetrasVocales[indice] != '\0' ; indice++){
        if(cadenaDeLetrasVocales[indice] == letra)
            esVocal = 1;
    }

    return esVocal;

}
