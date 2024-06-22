/*
    Alumna: Rocha Arellano Ximena Yulian
    Profesor: Edgardo Franco Martinez
	Practica 5 Implementacion de Arboles Binarios
*/
#ifndef __TADArbolBin_H
#define __TADArbolBin_H

#define TRUE 1
#define FALSE 0

typedef unsigned char booleano;

typedef struct elemento{	
	char p[101];
	char d[251];
} elemento;

typedef struct nodo{
	struct nodo *izq;
	struct nodo *der;
	elemento e;
}nodo;

typedef nodo* posicion;

typedef posicion arbol;

/*Inicializar (Initialize): recibe<-árbol(*A); 
Initialize (*A)
Efecto: Recibe un árbol binario *A y lo inicializa para su trabajo normal.*/
void Initialize (arbol *A);


/*Eliminar (Destroy):recibe<-árbol(*A); 
Destroy (*A)
Efecto: Recibe un árbol binario *A y lo libera completamente.
*/
void Destroy (arbol *A);


/*Raíz (Root):recibe<-árbol(*A); retorna -> posición
Root (*A)
Efecto: Recibe un árbol binario *A y retorna la posición de la raíz de *A, si el árbol es vacío devuelve una posición nula.
*/
posicion Root (arbol *A);

/*
Padre (Parent):recibe<-árbol(*A), posición(P); retorna -> posición
Parent(*A,P)
Efecto: Recibe un árbol binario  *A y una posición P, devuelve la posición de padre de p. 
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si P es la raíz se devuelve una posición nula.
*/
posicion Parent(arbol *A,posicion P);


/*Hijo derecho (Right Son):recibe<-árbol(*A), posición(P); retorna -> posición
RightSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve la posición del hijo derecho de p. 
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si P no tiene hijo derecho devuelve una posición nula.
*/
posicion RightSon(arbol *A,posicion P);

/*
Hijo izquierdo (LeftSon):recibe<-árbol(*A), posición(P); retorna -> posición
LeftSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve la posición del hijo izquierdo de p. 
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida. Si P no tiene hijo izquierdo devuelve una posición nula.
*/
posicion LeftSon(arbol *A,posicion P);

/*
Buscar (Search):recibe<-árbol(*A), elemento (E); retorna -> posición
Search(*A,E)
Efecto: Recibe un árbol binario *A y un elemento E, devuelve la posición del elemento E en el árbol  *A.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si E no es encontrado devuelve una posición nula.
*/
posicion Search(arbol *A,elemento E);

/*
Vacia (Empty):recibe<-árbol(*A); retorna -> booleano
Empty(*A)
Efecto: Recibe un árbol binario *A y devuelve verdadero en caso de que el árbol *A este vacío, devuelve falso en caso contrario.
*/
booleano Empty(arbol *A);


/*
Nodo Nulo (Null Node):recibe<-árbol(*A), posición (P); retorna -> booleano
NullNode(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve verdadero si la posición P del árbol *A es nula o incorrecta y devuelve falso en caso contrario.
*/
booleano NullNode(arbol *A,posicion P);

/*
Leer Nodo(Read Node):recibe<-árbol(*A), posición (P); retorna -> elemento
ReadNode(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, devuelve el elemento en la posición P del árbol *A.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida..
*/
elemento LeerNodo(arbol *A,posicion P);


/*Nuevo Hijo Derecho(New Right Son):recibe<-árbol(*A), posición (P), elemento E; 
NewRightSon(*A,P,E)
Efecto: Recibe un árbol binario *A, una posición P y un elemento E, se añade un nodo que contenga E como hijo derecho del nodo con posición P.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si el árbol *A es vacío se agrega a un nodo raíz con E. si P ya tiene un hijo derecho, se cancela la operación.
*/
void NewRightSon(arbol *A,posicion P,elemento E);



/*Nuevo Hijo Izquierdo(New Left Son):recibe<-árbol(*A), posición (P), elemento E; 
NewLeftSon(*A,P,E)
Efecto: Recibe un árbol binario *A, una posición P y un elemento E, se añade un nodo que contenga E como hijo izquierdo del nodo con posición P.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. Si el árbol *A es vacío se agrega a un nodo raíz con E; si P ya tiene un hijo Izquierdo, se cancela la operación.
*/
void NewLeftSon(arbol *A,posicion P,elemento E);


/*Eliminar Hijo Derecho (Delete Right Son):recibe<-árbol(*A), posición (P);
DeleteRightSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición se elimina al hijo derecho y todos sus descendientes del nodo con posición P.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida y tiene un hijo derecho.
*/
void DeleteRightSon(arbol *A,posicion P);


/*Eliminar Hijo Izquierdo(Delete Left Son):recibe<-árbol(*A), posición (P);
DeleteLeftSon(*A,P)
Efecto: Recibe un árbol binario *A y una posición se elimina al hijo izquierdo y todos sus descendientes del nodo con posición P.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida y tiene un hijo izquierdo.
*/
void DeleteLeftSon(arbol *A,posicion P);


/*Eliminar Nodo(Delete Node):recibe<-árbol(*A), posición (P);
DeleteNode(*A,P)
Efecto: Recibe un árbol binario *A y una posición P, se elimina al nodo con posición  P  y todos sus descendientes.
Requerimientos: El árbol *A es no vacío y la posición P es una posición valida. 
*/
void DeleteNode(arbol *A,posicion P);

/*
Remplazar Nodo(Replace Node):recibe<-árbol(*A), posición (P), elemento (E);
ReplaceNode(*A,P)
Efecto: Recibe un árbol binario *A, una posición P y un elemento E, se remplaza a E del nodo con posición P en *A.
Requerimientos: El árbol binario *A es no vacío y la posición P es una posición valida. */
void ReplaceNode(arbol *A,posicion P, elemento E);

#endif