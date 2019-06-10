void preorder(nodoArbol arbol); //Se imprime la informacion del nodo en estas funciones
void inorder(nodoArbol arbol);//Notar que este imprime de forma ordenada
void postOrder(nodoArbol arbol);
void porNivel(nodoArbol arbol);//FALTA ESTE

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
