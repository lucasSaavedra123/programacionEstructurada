#include <stdio.h>
#include <stdlib.h>

/*
Los archivos estan en binario
Tiene 0 y 1 a lado del otro

Los archivos estan en el disco o en la memoria.
Un arreglo se puede intepretar como un archivo, y al reves. El arreglo, al terminar el programa se "muere".
El arreglo no persiste. Pero el archivo no. El archivo puede persistir. Queda almacenado.

Un archivo de texto y un archivo binario SON LO MISMO. Es mas, un archivo de texto es un archivo binario.
El archivo de texto (que tambien son 0 y 1), pero, se lee cada 8 bits y se lee eso como un caracter.

El END OF FILE es que cuando se llega a leer hasta la ultima posicion (que se sabe por su peso) devuelve -1.
Aunque, la marca de finalización, se lo podemos dar nosotros.
*/


int main()
{

    //Si queremos abrir un archivo
    // fopen("xxxxx.dat", "modo");

    //Si queremos escribir
    // fwrite()

    //Si queremos leer
    // fread()

    //Si queremos cerrar el archivo
    //fclose("direccion del archivo")
    //""Liberamos al archivo""

    FILE* direccionDelArchivo = fopen("datos.dat", "w+b");//w+b escribe en binario. El + tambien permite leer
    unsigned int datos[] = {1,255,64,87,98,85,100,123,654,2};
    int T = 9;//Cantidad de elementos en el arreglo
    unsigned int * datosNuevos = malloc(sizeof(unsigned int));

    fwrite(datos, sizeof(unsigned int), T, direccionDelArchivo);//Se graba a byte

    rewind(direccionDelArchivo);//Rebobina hasta el lugar donde empieza el archivo
                                //Es importante hacerlo

    fread(datosNuevos, sizeof(unsigned int), T, direccionDelArchivo);   //Devuelve la cantidad de bytes leidos
                                                                        //Cuando es 0, se termino el archivo

    //Para leer lo que se hace por lo general es leer, ver si termino, y leer otra vez
    //Se usa el  feof(archivo)


    fclose(direccionDelArchivo);


    return 0;
}
