/*
    Alumna: Rocha Arellano Ximena Yulian
    Profesor: Edgardo Franco Martinez
    Practica 5 Implementacion de Arboles Binarios
    Compilacion: gcc -c TADArbolBin.c -o TADAB.o
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADArbolBin.h"


/*Inicializar (Initialize): recibe<-árbol(*A); 
Initialize (*A)
Efecto: Recibe un árbol binario *A y lo inicializa para su trabajo normal.*/
void Initialize (arbol *A){//como recibimos arbol  = posicion = nodo*, estamos recibiendo la direccion de un un apuntador, por ende, se crea un doble apuntador
    *A=NULL;//asi, modificamos hacia donde apunta el arbol que nos ha mandado el usuario
    //(*A)->apellido = a;
    //Algo asi:     **A=&mytree: es decir, guarda la direccion de *mytree
    //para modificar a donde apunta *mytree, podemos hacerlo mytree=&
    //o bien, *A=&, ya que ambos casos equivalen a lo mismo, buscan cambiar la 
    //direccion apuntada por *mytree
}

/*Eliminar (Destroy):recibe<-árbol(*A); 
Destroy (*A)
Efecto: Recibe un árbol binario *A y lo libera completamente.
*/
void Destroy (arbol *A){//hacemos recorrido posfijo
    if (!Empty(A)) {
        Destroy(&(*A)->izq);
        Destroy(&(*A)->der);
        free(*A);
        *A = NULL;
    }
}


/*Raíz (Root):recibe<-árbol(*A); retorna -> posición
Root (*A)
Efecto: Recibe un árbol binario *A y retorna la posición de la raíz de *A, si el árbol es vacío devuelve una posición nula.
*/
posicion Root (arbol *A){
    return *A;
}

/*
Padre (Parent):recibe<-árbol(*A), posición(P); retorna -> posición
Parent(*A,P)
Efecto: Recibe un árbol binario  *A y una posición P, devuelve la posición de padre de p. 
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si P es la raíz se devuelve una posición nula.
*/
posicion Parent(arbol *A,posicion P){
    posicion par=NULL;
    int b=0;
    if (Empty(A)){
        printf("\nERROR: Parent. Arbol vacío");
        exit(1);
    } 
    if (P == NULL){
        printf("\nERROR: Parent. Posicion no válida");
        exit(1);
    }
    if (*A == P) 
        par = NULL;
    else{
        par = *A;
        while (par != NULL) {
            if ((par->izq == P) || (par->der == P)) {
                b=1;
                break;
            }

            if (strcasecmp(P->e.palabra , par->e.palabra) < 0) 
                par = par->izq;
            else 
                par = par->der;
            
        }
        if(b==0)
            par= NULL;
    }
    return par;

}


/*Hijo derecho (Right Son):recibe<-árbol(*A), posición(P); retorna -> posición
RightSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve la posición del hijo derecho de p. 
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si P no tiene hijo derecho devuelve una posición nula.
*/
posicion RightSon(arbol *A,posicion P){
    posicion RS;
    if(Empty(A)){
        printf("\nERROR: RigthSon. Arbol vacío");
        exit(1);
    }
    if (P == NULL){
        printf("\nERROR: RightSon. Posicion no válida");
        exit(1);
    }

    RS= P->der;

    return RS;
}

/*
Hijo izquierdo (LeftSon):recibe<-árbol(*A), posición(P); retorna -> posición
LeftSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve la posición del hijo izquierdo de p. 
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida. Si P no tiene hijo izquierdo devuelve una posición nula.
*/
posicion LeftSon(arbol *A,posicion P){
    posicion LS;
    if(Empty(A)){
        printf("\nERROR: LeftSon. Arbol vacío");
        exit(1);
    }
    if (P == NULL){
        printf("\nERROR: LeftSon. Posicion no válida");
        exit(1);
    }

    LS= P->izq;

    return LS;
}

/*
Buscar (Search):recibe<-árbol(*A), elemento (E); retorna -> posición
Search(*A,E)
Efecto: Recibe un árbol binario *A y un elemento E, devuelve la posición del elemento E en el árbol  *A.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si E no es encontrado devuelve una posición nula.
*/
posicion Search(arbol *A,elemento E){
    posicion ser = *A;
    int b=0, comp_tam_cad;

    if(Empty(A)){
        printf("\nERROR: Search. Arbol vacío");
        exit(1);
    }

    while (ser != NULL) {
        comp_tam_cad= strcasecmp(E.palabra, ser->e.palabra);
        if (comp_tam_cad == 0 ) {
            b=1;
            break;
        }
        if (comp_tam_cad < 0) {
            ser = ser->izq;
        } else {
            ser = ser->der;
        }
    }
    if(b==0)
        ser= NULL;

    return ser;
}

/*
Vacia (Empty):recibe<-árbol(*A); retorna -> booleano
Empty(*A)
Efecto: Recibe un árbol binario *A y devuelve verdadero en caso de que el árbol *A este vacío, devuelve falso en caso contrario.
*/
booleano Empty(arbol *A){
     return *A == NULL ? TRUE : FALSE; 
}


/*
Nodo Nulo (Null Node):recibe<-árbol(*A), posición (P); retorna -> booleano
NullNode(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve verdadero si la posición P del árbol *A es nula o incorrecta y devuelve falso en caso contrario.
*/
booleano NullNode(arbol *A,posicion P){
    return P == NULL ? TRUE : FALSE;
}

/*
Leer Nodo(Read Node):recibe<-árbol(*A), posición (P); retorna -> elemento
ReadNode(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve el elemento en la posición P del árbol *A.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida..
*/
elemento LeerNodo(arbol *A,posicion P){
    elemento e;
    if(Empty(A)){
        printf("\nERROR: LeerNodo. Arbol vacío");
        exit(1);
    }
    if (P == NULL){
        printf("\nERROR: LeerNodo. Posicion no válida");
        exit(1);
    }

    e = P->e;
    
    return e;
}


/*Nuevo Hijo Derecho(New Right Son):recibe<-árbol(*A), posición (P), elemento E; 
NewRightSon(*A,P,E)
Efecto: Recibe un árbol binario *A, una posición P y un elemento E, se añade un nodo que contenga E como hijo derecho del nodo con posición P.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si el árbol *A es vacío se agrega a un nodo raíz con E. si P ya tiene un hijo derecho, se cancela la operación.
*/
void NewRightSon(arbol *A, posicion P, elemento E) {
    if (*A == NULL) {
        // Si el árbol está vacío, inicializa la raíz con el nuevo nodo hijo derecho
         *A = (arbol)malloc(sizeof(struct nodo));
        (*A)->e = E;
        (*A)->izq = NULL;
        (*A)->der = NULL;
    } else {
        if (P == NULL) {
            // Si P es NULL pero el árbol no está vacío, asignamos directamente la raíz como P
            P = *A;
        }

        if (P != NULL) {
            if (P->der == NULL) {
                // Si P no es NULL y no tiene hijo derecho, se agrega el nuevo nodo como hijo derecho de P
                P->der = (nodo*)malloc(sizeof(nodo));
                P->der->e = E;
                P->der->izq = NULL;
                P->der->der = NULL;
            } else {
                // Si P ya tiene un hijo derecho, se cancela la operación
                printf("\nERROR: NewRightSon. P ya tiene un hijo derecho.\n");
            }
        } else {
            // Si P es NULL después de intentar asignar la raíz, se genera un mensaje de error
            printf("\nERROR: NewRightSon. Posición no válida.\n");
        }
    }
}


/*Nuevo Hijo Izquierdo(New Left Son):recibe<-árbol(*A), posición (P), elemento E; 
NewLeftSon(*A,P,E)
Efecto: Recibe un árbol binario *A, una posición P y un elemento E, se añade un nodo que contenga E como hijo izquierdo del nodo con posición P.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si el árbol *A es vacío se agrega a un nodo raíz con E; si P ya tiene un hijo Izquierdo, se cancela la operación.
*/
void NewLeftSon(arbol *A, posicion P, elemento E) {
    if (*A == NULL) {
        // Si el árbol está vacío, inicializa la raíz con el nuevo nodo hijo izquierdo
         *A = (arbol)malloc(sizeof(struct nodo));
        (*A)->e = E;
        (*A)->izq = NULL;
        (*A)->der = NULL;
    } else {
        if (P == NULL) {
            // Si P es NULL pero el árbol no está vacío, asignamos directamente la raíz como P
            P = *A;
        }

        if (P != NULL) {
            if (P->izq == NULL) {
                // Si P no es NULL y no tiene hijo izquierdo, se agrega el nuevo nodo como hijo izquierdo de P
                P->izq = (nodo*)malloc(sizeof(nodo));
                P->izq->e = E;
                P->izq->izq = NULL;
                P->izq->der = NULL;
            } else {
                // Si P ya tiene un hijo izquierdo, se cancela la operación
                printf("\nERROR: NewLeftSon. P ya tiene un hijo izquierdo.\n");
            }
        } else {
            // Si P es NULL después de intentar asignar la raíz, se genera un mensaje de error
            printf("\nERROR: NewLeftSon. Posición no válida.\n");
        }
    }
}


/*Eliminar Hijo Derecho (Delete Right Son):recibe<-árbol(*A), posición (P);
DeleteRightSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición se elimina al hijo derecho y todos sus descendientes del nodo con posición P.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida y tiene un hijo derecho.
*/
void DeleteRightSon(arbol *A,posicion P){
    if(Empty(A)){
        printf("\nERROR: DeleteRightSon. Arbol vacío");
        exit(1);
    }
    if (P == NULL){
        printf("\nERROR: DeleteRightSon. Posicion no válida");
        exit(1);
    } 
    if (P->der != NULL) {
        Destroy(&(P->der));
    }
}


/*Eliminar Hijo Izquierdo(Delete Left Son):recibe<-árbol(*A), posición (P);
DeleteLeftSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición se elimina al hijo izquierdo y todos sus descendientes del nodo con posición P.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida y tiene un hijo izquierdo.
*/
void DeleteLeftSon(arbol *A,posicion P){
    if(Empty(A)){
        printf("\nERROR: DeleteLeftSon. Arbol vacío");
        exit(1);
    }
    if (P == NULL){
        printf("\nERROR: DeleteLeftSon. Posicion no válida");
        exit(1);
    } 
    if (P->izq != NULL) {
        Destroy(&(P->izq));
    }
}


/*Eliminar Nodo(Delete Node):recibe<-árbol(*A), posición (P);
DeleteNode(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, se elimina al nodo con posición  P  y todos sus descendientes.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida. 
*/
void DeleteNode(arbol *A,posicion P){
    if(Empty(A)){
        printf("\nERROR: DeleteNode. Arbol vacío");
        exit(1);
    }
    if (P == NULL){
        printf("\nERROR: DeleteNode. Posicion no válida");
        exit(1);
    } 
    if (*A == P)
        Destroy(A);
    else {
        posicion parent = Parent(A, P);
        if (parent != NULL) { 
            if (parent->izq == P) {
                parent->izq = NULL;
            } else if (parent->der == P) {
                parent->der = NULL;
            }
            Destroy(&P);
        }
    }
}

/*
Remplazar Nodo(Replace Node):recibe<-árbol(*A), posición (P), elemento (E);
ReplaceNode(*A,P)
Efecto: Recibe un árbol binario *A, una posición P y un elemento E, se remplaza a E del nodo con posición P en *A.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. */
void ReplaceNode(arbol *A,posicion P, elemento E){
    if(Empty(A)){
        printf("\nERROR: ReplaceNode. Arbol vacío");
        exit(1);
    }
    if (P == NULL){
        printf("\nERROR: ReplaceNode. Posicion no válida");
        exit(1);
    } 
    P->e = E;
}

/* Altura (Height): recibe<-árbol(*A), posición (P); retorna -> int
Altura(*A, P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve la altura del subárbol que tiene a P como raíz.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida.
*/
int Altura(arbol *A, posicion p) {
    if (NullNode(A, p)) 
        return 0;
    
    int altura_izq = Altura(A, LeftSon(A, p));
    int altura_der = Altura(A, RightSon(A, p));

    if (altura_der > altura_izq)
        return altura_der + 1;
    else
        return altura_izq + 1; 
}

int ContarNodos(arbol *A, posicion p){
    if(NullNode(A, p))
        return 0;
    else    return(1+ ContarNodos(A, RightSon(A, p)) +  ContarNodos(A, LeftSon(A, p)));
}

