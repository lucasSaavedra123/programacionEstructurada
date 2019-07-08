#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1
struct sUsuario{
    int id;
    char nombre[60];
    char sexo;
    int edad;
};
typedef struct sUsuario estructuraDeUsuario;

struct sCSV{
    int ID_usuario1;
    int ID_usuario2;
};
typedef struct sCSV estructuraCSV;

struct sNodoBin{
    estructuraDeUsuario usuarioDelNodo;

    struct sNodoBin * nodoIzquierda;
    struct sNodoBin * nodoDerecha;
};
typedef struct sNodoBin * nodoDeArbolDeUsuarios;

void agregarAmigosDeIDAlArbol( nodoDeArbolDeUsuarios *, int);

void extraerUsuariosEnArbol( nodoDeArbolDeUsuarios * );
void extraerInformacionCSV( estructuraCSV **);
void extraerIDdeAmigosDeID( int **, int);
int estaIdEnRegistroCSV(int,estructuraCSV); //Devuelve el ID que acompaña al ID pasado.
                                            //Si no esta en el registro, devuelve 0
estructuraDeUsuario obtenerEstructuraDeUsuarioPorID(int);

//Funciones Para los arboles
void agregarUsuarioAlArbol(nodoDeArbolDeUsuarios *, estructuraDeUsuario);
void borrarArbol(nodoDeArbolDeUsuarios *);
estructuraDeUsuario obtenerUsuarioDelArbolConID(nodoDeArbolDeUsuarios, int);
void imprimirArbol(nodoDeArbolDeUsuarios);

int main(){
    nodoDeArbolDeUsuarios arbolDeAmigos = NULL;

    agregarAmigosDeIDAlArbol(&arbolDeAmigos, 200);

    imprimirArbol(arbolDeAmigos);

    borrarArbol(&arbolDeAmigos);

    return 0;
}


void agregarAmigosDeIDAlArbol( nodoDeArbolDeUsuarios * direccioDelArbol, int idUsuario){
    nodoDeArbolDeUsuarios arbolDeAmigos = NULL;
    estructuraDeUsuario usuarioAmigo;
    int * arregloDeIDsAmigos = NULL;
    int indice = 0;

    extraerIDdeAmigosDeID(&arregloDeIDsAmigos,idUsuario);

    while( arregloDeIDsAmigos[indice] != 0 ){
        usuarioAmigo = obtenerEstructuraDeUsuarioPorID(arregloDeIDsAmigos[indice]);
        agregarUsuarioAlArbol(&arbolDeAmigos, usuarioAmigo);
        indice++;
    }

    free(arregloDeIDsAmigos);
    (*direccioDelArbol) = arbolDeAmigos;
}

void extraerUsuariosEnArbol( nodoDeArbolDeUsuarios * direccionDelArbol ){
    nodoDeArbolDeUsuarios arbolDeUsuarios = NULL;
    estructuraDeUsuario usuarioLeido;
    FILE * archivoDeUsuarios = fopen("Usuarios.dat", "rb");

    if( archivoDeUsuarios != NULL ){

        while( fread(&usuarioLeido, sizeof(estructuraDeUsuario), 1, archivoDeUsuarios) != 0 )
            agregarUsuarioAlArbol(&arbolDeUsuarios, usuarioLeido);

        fclose(archivoDeUsuarios);
    }

    (*direccionDelArbol) = arbolDeUsuarios;
}

void extraerInformacionCSV( estructuraCSV ** direccionCSV ){
    estructuraCSV * arregloDeCSV = NULL;
    int indiceCSV = 0;
    FILE * archivoCSV = fopen("Amigos.txt", "r");

    arregloDeCSV = malloc(sizeof(estructuraCSV));

    if( archivoCSV != NULL ){

        while( fscanf(archivoCSV, "%d,%d\n", &(arregloDeCSV[indiceCSV].ID_usuario1) , &(arregloDeCSV[indiceCSV].ID_usuario2) ) != EOF ){
            indiceCSV++;
            arregloDeCSV = realloc(arregloDeCSV, sizeof(estructuraCSV) * (indiceCSV+1));
        }

        fclose(archivoCSV);

    }

    arregloDeCSV[indiceCSV].ID_usuario1 = 0;
    arregloDeCSV[indiceCSV].ID_usuario2 = 0;

    (*direccionCSV) = arregloDeCSV;
}

void extraerIDdeAmigosDeID( int ** direccionDelArreglo, int idUsuario ){
    estructuraCSV * arregloDeCSV = NULL;
    int * arregloDeIDs = NULL;
    int indiceCSV = 0;
    int indiceIDs = 0;
    int idDelAmigo = 0;

    arregloDeIDs = malloc(sizeof(int));
    extraerInformacionCSV(&arregloDeCSV);

    while( arregloDeCSV[indiceCSV].ID_usuario1 != 0 ){
        idDelAmigo = estaIdEnRegistroCSV(idUsuario, arregloDeCSV[indiceCSV]);

        if(idDelAmigo != 0){
            arregloDeIDs[indiceIDs] = idDelAmigo;
            indiceIDs++;
            arregloDeIDs = realloc(arregloDeIDs, sizeof(int)*(indiceIDs+1));
        }

        indiceCSV++;
    }

    arregloDeIDs[indiceIDs] = 0;

    free(arregloDeCSV);
    (*direccionDelArreglo) = arregloDeIDs;
}

int estaIdEnRegistroCSV(int idUsuario,estructuraCSV registroCSV){
    int id = 0;

    if(registroCSV.ID_usuario1 == idUsuario )
        id = registroCSV.ID_usuario2;
    else if(registroCSV.ID_usuario2 == idUsuario)
        id = registroCSV.ID_usuario1;

    return id;
}

estructuraDeUsuario obtenerEstructuraDeUsuarioPorID(int idUsuario){
    estructuraDeUsuario usuarioConLaID;
    nodoDeArbolDeUsuarios arbolDeUsuarios = NULL;

    usuarioConLaID.id = 0;

    extraerUsuariosEnArbol( &arbolDeUsuarios );

    usuarioConLaID = obtenerUsuarioDelArbolConID(arbolDeUsuarios, idUsuario);

    borrarArbol(&arbolDeUsuarios);
    return usuarioConLaID;
}


//Funciones para los arboles
void agregarUsuarioAlArbol(nodoDeArbolDeUsuarios * direccionDelNodo, estructuraDeUsuario usuarioNuevo){
    if( (*direccionDelNodo) == NULL ){
        (*direccionDelNodo) = malloc(sizeof(struct sNodoBin));
        (*direccionDelNodo)->usuarioDelNodo = usuarioNuevo;
        (*direccionDelNodo)->nodoIzquierda = NULL;
        (*direccionDelNodo)->nodoDerecha = NULL;
    }
    else{
        if( (*direccionDelNodo)->usuarioDelNodo.id > usuarioNuevo.id )
            agregarUsuarioAlArbol( &((*direccionDelNodo)->nodoIzquierda), usuarioNuevo);
        else if( (*direccionDelNodo)->usuarioDelNodo.id < usuarioNuevo.id )
            agregarUsuarioAlArbol( &((*direccionDelNodo)->nodoDerecha), usuarioNuevo);
    }
}

void borrarArbol(nodoDeArbolDeUsuarios * direccionDelArbol){
    if( (*direccionDelArbol) != NULL ){
        borrarArbol( &((*direccionDelArbol)->nodoIzquierda) );
        borrarArbol( &((*direccionDelArbol)->nodoDerecha) );
        free((*direccionDelArbol));
        (*direccionDelArbol) = NULL;
    }
}

estructuraDeUsuario obtenerUsuarioDelArbolConID(nodoDeArbolDeUsuarios arbolDeUsuarios, int idUsuario){
    estructuraDeUsuario usuario;
    usuario.id = 0;

    if( arbolDeUsuarios != NULL ){

        if(arbolDeUsuarios->usuarioDelNodo.id == idUsuario)
            usuario = arbolDeUsuarios->usuarioDelNodo;

        else if( arbolDeUsuarios->usuarioDelNodo.id < idUsuario )
            return obtenerUsuarioDelArbolConID(arbolDeUsuarios->nodoDerecha, idUsuario);
        else if( arbolDeUsuarios->usuarioDelNodo.id > idUsuario )
            return obtenerUsuarioDelArbolConID(arbolDeUsuarios->nodoIzquierda, idUsuario);

    }

    else{
        return usuario;
    }

    return usuario;

}

void imprimirArbol(nodoDeArbolDeUsuarios arbolDeUsuarios){
    if(arbolDeUsuarios != NULL){
        imprimirArbol(arbolDeUsuarios->nodoIzquierda);
        printf("%d,", arbolDeUsuarios->usuarioDelNodo.id);
        imprimirArbol(arbolDeUsuarios->nodoDerecha);
    }
}
