/*

AUTORES:
    - Rocha Arellano Ximena Yulian
    - Bautista Romero Demian

(C) Junio 2024
VERSIÓN: 1.0

DESCRIPCIÓN:
    Este archivo implementa funciones necesarias para recorrer de una forma especifica
    los arboles binarios 

*/

#include <stdio.h>
#include "Recorridos.h"
#include "../TAD_AB/TADArbolBin.h"


// Recorrido PreOrden
void PreOrden(posicion P) {
    if (P != NULL) {
        printf("%s ", P->e.palabra);  // Imprimir nodo actual
        PreOrden(P->izq);       // Recorrer subárbol izquierdo
        PreOrden(P->der);       // Recorrer subárbol derecho
    }
}

// Recorrido InOrden
void InOrden(posicion P) {
    if (P != NULL) {
        InOrden(P->izq);        // Recorrer subárbol izquierdo
        printf("%s ", P->e.palabra);  // Imprimir nodo actual
        InOrden(P->der);        // Recorrer subárbol derecho
    }
}

// Recorrido PostOrden
void PostOrden(posicion P) {
    if (P != NULL) {
        PostOrden(P->izq);      // Recorrer subárbol izquierdo
        PostOrden(P->der);      // Recorrer subárbol derecho
        printf("%s ", P->e.palabra);  // Imprimir nodo actual
    }
}