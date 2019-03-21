#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHARACTERS 100

char darStringCharCambiado(char string, char oldChar , char newChar){

    int i;

    for(i=0 ; i < strlen(string) ; i++){
            if(string[i] == oldChar)
                string[i] = newChar;
    }

    return string;
}

int main()
{

    char stringText[MAXCHARACTERS];
    char oldChar;
    char newChar;

    printf("Ingrese texto: ");
    scanf("%[^\n]s ",stringText);

    getchar();

    printf("Ingrese carácter a reemplazar: ");
    oldChar=getchar();

    getchar();

    printf("Ingrese carácter de reemplazo: ");
    newChar=getchar();

    printf("%s",darStringCharCambiado(stringText, oldChar, newChar));

    return 0;
}
