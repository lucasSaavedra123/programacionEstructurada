#include <stdio.h>
#include <stdlib.h>

//http://bitwisecmd.com/

//Mascara dia:0b11111000000000000000 5 bits
//Mascara mes:0b00000111100000000000 4 bits
//Mascara ano:0b00000000011111111111 11 bits

typedef struct s_fecha{
    int dia;
    int mes;
    int ano;
} t_fecha;

//Funciones prototipo
int entregarFechaConDia( int fechaEncriptada, int dia);
int entregarFechaConMes( int fechaEncriptada, int mes);
int entregarFechaConAno( int fechaENcriptada, int ano);

int entregarDiaDeLaFecha(int fechaEncriptada);
int entregarMesDeLaFecha(int fechaEncriptada);
int entregarAnoDeLaFecha(int fechaEncriptada);

void insertarFechaEnArchivo(t_fecha fechaNueva,char * nombreDelArchivo);
void extraerFechasDelArchivo(t_fecha ** arregloDeFechas,char * nombreDelArchivo);

int encriptarFecha(t_fecha fechaNueva);
t_fecha desencriptarFecha(int fechaEncriptada);

int main()
{
    t_fecha * arregloDeFechas = NULL;
    int i = 0;

    extraerFechasDelArchivo(&arregloDeFechas, "fechas.txt");
}

int entregarFechaConDia( int fechaEncriptada, int dia){
    int mascaraDia = ~0b11111000000000000000;
    int fechaConDiaLimpia = mascaraDia & fechaEncriptada;

    fechaEncriptada = (fechaConDiaLimpia | (dia << 15) );

    return fechaEncriptada;
}
int entregarFechaConMes( int fechaEncriptada, int mes){
    int mascaraMes = ~0b00000111100000000000;
    int fechaConMesLimpia = mascaraMes & fechaEncriptada;

    fechaEncriptada = (fechaConMesLimpia | (mes << 11) );

    return fechaEncriptada;
}
int entregarFechaConAno( int fechaEncriptada, int ano){
    int mascaraAno = ~0b00000000011111111111;
    int fechaConAnoLimpia = mascaraAno & fechaEncriptada;

    fechaEncriptada = (fechaConAnoLimpia | ano );

    return fechaEncriptada;
}

int entregarDiaDeLaFecha(int fechaEncriptada){
     int diaDeLaFecha = 0;
     int mascaraDia = 0b11111000000000000000;

     diaDeLaFecha = (mascaraDia & fechaEncriptada) >> 15;

     return diaDeLaFecha;
}
int entregarMesDeLaFecha(int fechaEncriptada){
     int mesDeLaFecha = 0;
     int mascaraMes = 0b00000111100000000000;

     mesDeLaFecha = (mascaraMes & fechaEncriptada) >> 11;

     return mesDeLaFecha;
}
int entregarAnoDeLaFecha(int fechaEncriptada){
     int anoDeLaFecha = 0;
     int mascaraAno = 0b00000000011111111111;

     anoDeLaFecha = (mascaraAno & fechaEncriptada);

     return anoDeLaFecha;
}

void insertarFechaEnArchivo(t_fecha fechaNueva,char * nombreDelArchivo){
    FILE * archivoDeFechas = fopen(nombreDelArchivo, "a");
    int fechaEncriptada = 0;

    fechaEncriptada = encriptarFecha(fechaNueva);

    fprintf(archivoDeFechas,"%d\n", fechaEncriptada);

    fclose(archivoDeFechas);

}
void extraerFechasDelArchivo(t_fecha ** arregloDeFechas,char * nombreDelArchivo){
    FILE * archivoDeFechas = fopen(nombreDelArchivo, "r");
    t_fecha nuevaFecha;
    t_fecha fechaDeParo;
    int contadorDeFechas = 0;
    int fechaEncriptada;

    fechaDeParo.dia = 0;
    fechaDeParo.mes = 0;
    fechaDeParo.ano = 0;

    *arregloDeFechas = malloc(sizeof(t_fecha));

    while( fscanf(archivoDeFechas, "%d\n", &fechaEncriptada) != EOF ){

        nuevaFecha = desencriptarFecha(fechaEncriptada);

        *(*(arregloDeFechas)+contadorDeFechas) = nuevaFecha;

        contadorDeFechas++;
        *arregloDeFechas = realloc(*arregloDeFechas, sizeof(t_fecha) * (contadorDeFechas+1) );
    }

    //La ultima fecha tendra todo 0

    *(*(arregloDeFechas)+contadorDeFechas) = fechaDeParo;

    fclose(archivoDeFechas);
}

int encriptarFecha(t_fecha fechaNueva){
    int fechaEncriptada = 0;

    fechaEncriptada = entregarFechaConDia(fechaEncriptada, fechaNueva.dia);
    fechaEncriptada = entregarFechaConMes(fechaEncriptada, fechaNueva.mes);
    fechaEncriptada = entregarFechaConAno(fechaEncriptada, fechaNueva.ano);

    return fechaEncriptada;
}
t_fecha desencriptarFecha(int fechaEncriptada){
    t_fecha fecha;

    fecha.dia = entregarDiaDeLaFecha(fechaEncriptada);
    fecha.mes = entregarMesDeLaFecha(fechaEncriptada);
    fecha.ano = entregarAnoDeLaFecha(fechaEncriptada);

    return fecha;
}
