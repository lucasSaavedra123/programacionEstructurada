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
