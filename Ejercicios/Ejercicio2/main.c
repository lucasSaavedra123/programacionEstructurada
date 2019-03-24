#include <stdio.h>
#include <stdlib.h>

float suma(float n1, float n2){
    return n1+n2;
}

float resta(float n1, float n2){
    return n1-n2;
}

float producto(float n1, float n2){
    return n1*n2;
}

float division(float n1, float n2){
    if(n2 == 0){
        printf("ERROR!");
        return 0;
    }
    else
        return n1/n2;
}


int main()
{
    float numero1;
    float numero2;
    char charOperacion;

    printf("Ingrese primer numero: ");
    scanf("%f", &numero1);

    printf("Ingrese primer numero: ");
    scanf("%f", &numero2);

    getchar();//Toma el segundo caracter del enter y se lo queda

    printf("Ingrese una operación [+ - * /]: ");
    charOperacion = getchar();

    if(charOperacion == '+')
        printf("%.0f",suma(numero1,numero2));
    else if(charOperacion == '-')
        printf("%.0f",resta(numero1,numero2));
    else if(charOperacion == '*')
        printf("%.0f",producto(numero1,numero2));
    else if(charOperacion == '/')
        printf("%.2f",division(numero1,numero2));
    else
        printf("ERROR!");

    return 0;

}
