#include <stdio.h>
#include <stdlib.h>

void invertir(int * arreglo, unsigned int longitud);

int main(void) {
  int arregloDeNumeros[5] = {5,2,3,3,6};

  printf("%d\n", arregloDeNumeros[0]);
  printf("%d\n", arregloDeNumeros[1]);
  printf("%d\n", arregloDeNumeros[2]);
  printf("%d\n", arregloDeNumeros[3]);
  printf("%d\n\n", arregloDeNumeros[4]);

  invertir(arregloDeNumeros, 5);

  printf("%d\n", arregloDeNumeros[0]);
  printf("%d\n", arregloDeNumeros[1]);
  printf("%d\n", arregloDeNumeros[2]);
  printf("%d\n", arregloDeNumeros[3]);
  printf("%d\n\n", arregloDeNumeros[4]);

  return 0;
}
void invertir(int * arreglo, unsigned int longitud){

  int numeroMemoria = 0;

  if(longitud > 1){
    numeroMemoria = *(arreglo);
    *(arreglo) = *(arreglo+longitud-1);
    *(arreglo+longitud-1) = numeroMemoria;

    invertir(arreglo+1, longitud-2);
  }

}
