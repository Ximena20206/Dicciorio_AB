/*
    LIBRERIA: Cabecera menu

    AUTORES:
        - Rocha Arellano Ximena Yulian
        - Bautista Romero Demian

    (C) Junio 2024
    VERSIÓN: 1.0

*/
#ifndef _menu_h
#define _menu_h
#include "../TAD_AB/TADArbolBin.h"

/*MostrarMenu: recibe<-puntero a entero(*op); 
MostrarMenu(*op)
Efecto: Muestra un menú con diferentes opciones para el usuario y lee la opción seleccionada, almacenándola en la variable apuntada por *op.*/
void MostrarMenu(int *op);

/*Menu (Menu): recibe<-árbol(*A); 
Menu(*A)
Efecto: Muestra el menú de opciones al usuario y ejecuta la función correspondiente según la opción seleccionada. Las opciones incluyen cargar un archivo, agregar una palabra, modificar una definición, eliminar una palabra, buscar una palabra, realizar recorridos del árbol (PreOrden, InOrden, PosOrden), consultar estadísticas del árbol y salir del programa.*/
int Menu(arbol *A);

#endif//_menu_h