#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n, o , p;
    char p1[26], p2[50];
    double a, b, c;
}
t_varios;

//FUNCIONES PROTOTIPO
void intercambiarStructs( t_varios * struct1, t_varios * struct2);

int main()
{
    t_varios struct1, struct2;

    intercambiarStructs(&struct1, &struct2);

    return 0;
}

void intercambiarStructs( t_varios * struct1, t_varios * struct2){
    t_varios structAux;

    structAux = *struct1;
    *struct1 = *struct2;
    *struct2 = *struct1;
}
