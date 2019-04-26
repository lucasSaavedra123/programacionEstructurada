#include <stdio.h>
#include <stdlib.h>

/*
Al guardar 'a', podemos verlo como una secuencia de bits que es 01100001 (97, igual que en el ASCII).
El numero binario es posicional, cada posicion tiene un 'peso'.

byte es otro tipo de dato


OPERADORES LÓGICOS BINARIOS

&: AND a nivel bit
!: OR inclusivo a nivel bit
(piquito dsps lo pongo) OR Exclusivo (XOR) a nivel bit

*/

int main()
{
    unsigned char l1 = 113;      //Letra 'q' 01110001
    unsigned char l2 = 122;      //Letra 'z' 01111010
    unsigned char l3 = l1 & l2;  //          01111011
    unsigned char l4 = l1 | l2;

    //Si tiene signo, el primer bit es el MSB (Most Significative Bit)
    //Existe otro operador que es el niuflo ~. Necesita de un solo byte para funcionar
    //~ es un negador

    char l5 = ~l2;

    //Esta el >> y el <<. Shiftean.
    //Empuja


    char x = 97;    //01100001 //si pone solo char es signed.
    x = x >> 2;     //xx011000

    //Se pone X por que si es unsigned es 0, ahora si es signed, no se sabe lo que es.

    x = 100;         //01000001
    x = x << 3;     //00001000

    //Se suele usar mascaras
    //Se filtra información

    char mask = 129; //10000001

    //No tomamos importancia quien precede a quien
    //Usamos parentesis
    if ( (x & mask) == mask){
        printf("correcto");
    }
    else{
        printf("incorrecto");
    }


}

