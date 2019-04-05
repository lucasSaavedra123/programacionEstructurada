#include <stdio.h>
#include <stdlib.h>

//Nosotros podemos crear nuestro tipos de datos
/*
Si en C queremos representar un punto necesimatos 3 valores
-Valor en X
-Valor en Y
-Valor en Z

Necesitamos 3 variables. Es sencillo esto pero capaz que para poder representar a un punto
o algo mas complicado, capaz habra que crear mayor cantidad de variables y puede resultar feo/ineficiente.

Para eso, creamos una estructura de datos o nuestro tipo de datos. La idea es crear a un contenedor que tiene
varias vabriables por dentro.

Se la crea con un 'struct':
(Recordar que s_punto ahora es un tipo de dato, no es una varible)
Al crear una variable del tipo 's_punto' ponemos struct s_punto y le asignamos valores.
*/

struct s_tiempo{
    int h,m,s;
};

//El tipo de dato es 'struct s_punto'
struct s_punto{
    char nombre[50];
    double x;
    double y;
    double z;
    struct s_tiempo tiempo;
};
//En la memoria cada double esta puesta una a lado de la otra.
//Al ser un mismo tipo de dato, las c3 variables se encuentran juntas

//un typedef lleva un nombre original a otro nombre. Es como un alias

typedef struct s_punto punto;


int main()
{
    struct s_punto p1,p2;
    punto p3,p4;
    punto puntos[100];//Creamos un arreglo que tiene variables del tipo for
    struct s_tiempo tiempo = {0,0,0};



    scanf("%lf", &p1.x);
    scanf("%lf", &p1.y);
    scanf("%lf", &p1.z);
    scanf("%lf", &puntos[1].x);

    p1.nombre[0]='S';
    p1.nombre[1]='o';
    p1.nombre[2]='l';
    p1.nombre[3]='\0';

    scanf("%d", &puntos[1].tiempo.h);
    scanf("%d", &puntos[1].tiempo.m);
    scanf("%d", &puntos[1].tiempo.s);

    printf("%s",p1.nombre);

    printf("%lf", p1.x);
    printf("%lf", p1.x);
    printf("%lf", p1.y);

    printf("%lf", puntos[1].x);

    printf("%d", puntos[1].tiempo.h);
    printf("%d", puntos[1].tiempo.m);
    printf("%d", puntos[1].tiempo.s);

}
