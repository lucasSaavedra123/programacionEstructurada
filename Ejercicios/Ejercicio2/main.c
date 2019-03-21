#include <stdio.h>
#include <stdlib.h>

int suma(int n1, int n2){
    return n1+n2;
}

int resta(int n1, int n2){
    return n1-n2;
}

int producto(int n1, int n2){
    return n1*n2;
}

int division(int n1, int n2){
    if(n2 == 0)
        printf("ERROR!");
    else
        return n1/n2;
}


int main()
{
    int entero1;
    int entero2;
    char charOperacion;

    printf("Ingrese primer numero: ");
    scanf("%d", &entero1);

    printf("Ingrese primer numero: ");
    scanf("%d", &entero2);

    getchar();//Toma el segundo caracter del enter y se lo queda

    printf("Ingrese una operación [+ - * /]: ");
    charOperacion = getchar();

    if(charOperacion == '+')
        printf("%d",suma(entero1,entero2));
    else if(charOperacion == '-')
        printf("%d",resta(entero1,entero2));
    else if(charOperacion == '*')
        printf("%d",producto(entero1,entero2));
    else if(charOperacion == '/')
        printf("%d",division(entero1,entero2));
    else
        printf("ERROR!");

    return 0;

}
