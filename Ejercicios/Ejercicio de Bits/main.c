#include <stdio.h>
#include <stdlib.h>

//http://bitwisecmd.com/

//Funciones prototipo
int entregarFechaConDia( int fecha, int dia);
int entregarFechaConMes( int fecha, int mes);
int entregarFechaConAno( int fecha, int ano);

int entregarDiaDeLaFecha(int fecha);
int entregarMesDeLaFecha(int fecha);
int entregarAnoDeLaFecha(int fecha);

int main()
{
    int fecha = 2047;

    int dia = 12;//5 Bit
    int ano = 99;//7 bit
    int mes = 5;//4 bit

    printf("%d", entregarAnoDeLaFecha(fecha));
}


/*int entregarFechaConDia( int fecha, int dia){
    //El dia son 5 bits. Los colocaremos adelante

}
int entregarFechaConMes( int fecha, int mes){}*/

int entregarFechaConAno(int fecha, int ano){
    return  fecha & 2047;
}
/*
int entregarDiaDeLaFecha(int fecha){}
int entregarMesDeLaFecha(int fecha){}*/

int entregarAnoDeLaFecha(int fecha){}

