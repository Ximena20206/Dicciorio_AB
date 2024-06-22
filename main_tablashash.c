/*
PROGRAMA: Diccionario con Tabla Hash Abierta

AUTORES:
    - Rocha Arellano Ximena Yulian
    - Bautista Romero Demian

(C) Junio 2024
VERSIÓN: 1.0

DESCRIPCIÓN:
    Este programa interactivo permite gestionar un diccionario utilizando una tabla hash abierta.
    Permite cargar definiciones desde un archivo, agregar nuevas palabras, modificar definiciones,
    eliminar palabras, buscar definiciones, mostrar estadísticas y salir del programa.

OBSERVACIONES:
    - La tabla hash utiliza dos funciones de hash diferentes para generar índices únicos para
      las palabras almacenadas.
    - Utiliza el TAD de lista doblemente enlazada definido en TADListaDL.c para gestionar las colisiones.
    - El programa se ejecuta en un bucle interactivo hasta que el usuario decide salir.

COMPILACIÓN:
    gcc main_tablashash.c tablashash.c TADListaDL.c -o nombre_ejecutable
*/

//Librerias a utilizar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablashash.h"  
#include <math.h>


int main( ){
    TablaHash tabla;
    crear_tabla(&tabla);

    liberar_tabla(&tabla);

    return 0;
}

