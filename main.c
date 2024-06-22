/*
    Alumna: Rocha Arellano Ximena Yulian
    Profesor: Edgardo Franco Martinez
    Practica 5 Implementacion de Arboles Binarios
    Compilacion: gcc programa main.c Recorridos.c TAD_AB\TADArbolBin.c -o recorridos
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "TAD_AB\TADArbolBin.h"
#include "Recorridos.h"

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    arbol A;
    elemento e1 = {1};  
    elemento e2 = {2};
    elemento e3 = {3};
    elemento e4 = {4};
    elemento e5 = {5};

    // Inicializar árbol
    Initialize(&A);

    // Insertar nodos
    NewRightSon(&A, Root(&A), e2);          // Añadir nodo derecho a la raíz// pero como es el primero, se va a quedar en la raiz
    NewLeftSon(&A, Root(&A), e1);           // Añadir nodo izquierdo a la raíz
    posicion p2 = RightSon(&A, Root(&A));
    NewRightSon(&A, p2, e4);                // Añadir nodo derecho al hijo derecho de la raíz
    posicion p3 = LeftSon(&A, Root(&A));
    NewRightSon(&A, p3, e3);                // Añadir nodo derecho al hijo izquierdo de la raíz
    NewLeftSon(&A, p3, e5);                 // Añadir nodo izquierdo al hijo izquierdo de la raíz

    // Mostrar recorridos
    printf("Recorrido PreOrden: ");
    PreOrden(Root(&A));                                       
    printf("\n");

    printf("Recorrido InOrden: ");
    InOrden(Root(&A));
    printf("\n");

    printf("Recorrido PostOrden: ");
    PostOrden(Root(&A));
    printf("\n");

    // Liberar memoria del árbol al finalizar
    Destroy(&A);

    return 0;
}