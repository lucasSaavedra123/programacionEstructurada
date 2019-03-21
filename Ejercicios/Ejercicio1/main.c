//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>//Incluimos una libreria

#define CONSTANTE 5 //Esto es una constante Posicion de memoria que nadie puede tocar

/*
Tipo de datos:
-Int    ---> Entero
-double ---> Float (tambien esta float )
-Char   ---> Caracteres (nos va a servir para formar a los strings)
-Char* (para strings)
-Strings y booleanos no son tipo de datos (no son un tipo de dato puro)

Uso de comillas:
" " se usa encerrar textos
' ' se usa para encerrar caracteres

Caracteres especiales:
-\n Salto de linea
-\t Tabulado

La ñ no se encuentra en el set de C
*/

//Definicion de funciones
//Es muy importante especificar que tipo de dato va a recibir
int redondeo(double n){
    int trunc = n,result;//Tomamos solamente la parte entera
    double p_decimal = n-trunc;

    if(p_decimal > 0.5 || p_decimal == 0.5)
        result = trunc+1;
    else if(p_decimal < 0.5)
        result = trunc;

    return result;
}

int piso(double n){
    int trunc = n;
    return trunc;
}

int techo(double n){
    int trunc = n,result;//Tomamos solamente la parte entera
    double p_decimal = n-trunc;

    if(p_decimal == 0)
        result = trunc;
    else
        result = trunc+1;

    return result;
}

//FUNCION PRINCIPAL.
//Main es una palabra reservada que el compilador usa para ir a una direccion de memoria determinada
//Aca va el codigo que se va a ejecutar
//el 'int' se refiere al tipo de dato que devuelve la función
//el double y el float son distintos pero double permite mayor precision
//Depende de lo que se tenga que hacer el uso entre double y float
//Caracteres 'char' Se usa comillas. Es una caja mas chica que la de los enteros
//En C puro no hay booleanos. no hay tipo de dato booleano pero lo podemos resolver con 1(true) o 0(false)
//Una cadena de caracteres es un arreglo (lista en python) que entra dentro de un espacio de la memoria

int main()
{


    //CUERPO DEL PROGRAMA
    //Primero se declaran las variables. Se le dice al compilador que guarde un espacio de la memoria
    //para guardar la varible. Suelen ser de 32 bits
    double numero; //Numero Real
    //Si creas la variable y no le asignas un valor, no sabemos que valor realmente esta.
    //Es parte de la basura de programas que estuvieron ahi
    //Por eso, es buena practica igual a 0 estos numeros al crearlos. Asi limpiamos la memoria

    //Luego tenemos el cuerpo

    /*
        Para imprimir o grabar:
        %lf --->    Numero Float
        %d  --->    Enteros
        %c  --->    Caracteres
    */

    printf("Ingrese un numero real: ");//Imprime
    //Tiene dos argumentos.
    //Uno es el formato y el otro es el valor
    //printf("%d",10);
    //long float es para los double o long float
    //printf("%d",10.5);
    //Imprime 10. Por que el formato es entero.
    //printf("%c",'x')
    //print("%s","hola ppapa")


    scanf("%lf", &numero);//el & va hacia un puntero

    /*
    Para darle formato a la salida de las impresiones

    Por ejemplo

    //El 0 va para todos
    "%0.1lf"---Al imprimir 33.5646 imprime 33.5

    //"%8d" -----> _ _ _ _ _ _ _ 5
    //"%-8d"-----> 5 _ _ _ _ _ _ _
    */

    //Lee entradas
    //scanf("formatoDeTipoDeDato",&) Tiene que coincidir el formato de la entrada con la variable



    printf("Redondeo = %d\n", redondeo(numero));
    printf("Piso = %d\n", piso(numero));
    printf("Techo = %d\n", techo(numero));

    //Por ahora, devolveremos 0
    //Arreglo Estatico configuracion de la memoria en el momento del programa
    /*
        int x[un numero] -->Hacemos un arreglo de un cantidad terminada de espacio

        x[0] = 5 --> En la posicion guarda 5

        El largo del arreglo no se puede cambiar y no se puede leer. Por eso guardar
        en una constante (lo mas prolijo) el largo.

        Los programas tienen una unidad de memoria asociada.

        Para cadenas se hace lo mismo, solo que las cadenas tienen que terminar con un ultimo caracer que es el \0

        Si queremos tomar caracter por caracter con un for, tenemos que controlar
        que no se llegue a imprimir los espacion basura.


        */





    return 0;
    //Si es 0, no hubo error. Por eso se usa el return 0.
    //Si es distinto de 0, es true. Se intepreta como error.
    //RETORNO: Corta el programa. Es buena prctica siempre dejarlo a lo ultimo

    //FIN DEL CUERPO DEL PROGRAMA
}
