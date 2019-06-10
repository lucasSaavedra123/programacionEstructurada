void agregarElementoAlArbol(nodoArbol * arbol, int valor);//Se supone para poner valores no repetidos

void preorder(nodoArbol arbol); //Se imprime la informacion del nodo en estas funciones
void inorder(nodoArbol arbol);//Notar que este imprime de forma ordenada
void postOrder(nodoArbol arbol);
void porNivel(nodoArbol arbol);//FALTA ESTE

void agregarElementoAlArbol(nodoArbol * arbol, int valor){

        if (*arbol == NULL){
            *arbol = malloc(sizeof(struct s_nodo_bin));
            (*arbol)->valor = valor;
            (*arbol)->nodoIzquierda = NULL;
            (*arbol)->nodoDerecha = NULL;
        }

        else{
            //Por izquierda van a estar los numeros mas chicos
            //Es una forma de ingresar datos a un arbol
            //Es por eso que los datos presentan un orden
            if (valor < (*arbol)->valor)
                agregarElementoAlArbol(& ((*arbol)->nodoIzquierda), valor);
            else
                agregarElementoAlArbol(& ((*arbol)->nodoDerecha), valor);
        }
}

void preorder(nodoArbol arbol){
    if(arbol != NULL){
        printf("%d\n",arbol->valor);
        preorder(arbol->nodoIzquierda);
        preorder(arbol->nodoDerecha);
    }
}

void inorder(nodoArbol arbol){
    if(arbol != NULL){
        inorder(arbol->nodoIzquierda);
        printf("%d\n",arbol->valor);
        inorder(arbol->nodoDerecha);
    }
}

void postOrder(nodoArbol arbol){
    if(arbol != NULL){
        postOrder(arbol->nodoIzquierda);
        postOrder(arbol->nodoDerecha);
        printf("%d\n",arbol->valor);
    }
}
