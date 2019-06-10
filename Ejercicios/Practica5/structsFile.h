struct s_nodo{
    int valor;
    struct s_nodo * siguienteNodo;
};
typedef struct s_nodo * nodo;

struct s_cola{
    nodo nodoFrente;
    nodo nodoAtras;
};
typedef struct s_cola cola;

struct s_nodo_bin
{
    int valor;
    struct s_nodo_bin* nodoIzquierda;
    struct s_nodo_bin* nodoDerecha;
};
typedef struct s_nodo_bin * nodoArbol;
