#include <stdio.h>
#include <stdlib.h>

//http://bitwisecmd.com/

int main()
{
    int fecha = 0;

    int dia = 12;//5 Bit
    int ano = 99;//7 bit
    int mes = 5;//4 bit

    int mascaraDia = 0b11111;
    int mascaraMes = 0b1111;
    int mascaraAno = 127 << 13;

    fecha = fecha | ano;
    fecha = fecha << 4;

    fecha = fecha | mes;
    fecha = fecha << 5;

    fecha = fecha | dia;
    fecha = fecha << 4;

    printf("%d ", fecha & mascaraDia);
    printf("%d ", fecha & mascaraMes);
    printf("%d ", fecha & mascaraAno);

    printf("%d\n", fecha);



}
