/*
    Alumna: Rocha Arellano Ximena Yulian
    Profesor: Edgardo Franco Martinez
    Practica 5 Implementacion de Arboles Binarios
    Compilacion: gcc -o Recorridos.c -o re.o
*/
#include "Recorridos.h"
#include "TAD_AB/TADArbolBin.h"
#include <stdio.h>

// Recorrido PreOrden
void PreOrden(posicion P) {
    if (P != NULL) {
        printf("%d ", P->e.n);  // Imprimir nodo actual
        PreOrden(P->izq);       // Recorrer subárbol izquierdo
        PreOrden(P->der);       // Recorrer subárbol derecho
    }
}

// Recorrido InOrden
void InOrden(posicion P) {
    if (P != NULL) {
        InOrden(P->izq);        // Recorrer subárbol izquierdo
        printf("%d ", P->e.n);  // Imprimir nodo actual
        InOrden(P->der);        // Recorrer subárbol derecho
    }
}

// Recorrido PostOrden
void PostOrden(posicion P) {
    if (P != NULL) {
        PostOrden(P->izq);      // Recorrer subárbol izquierdo
        PostOrden(P->der);      // Recorrer subárbol derecho
        printf("%d ", P->e.n);  // Imprimir nodo actual
    }
}