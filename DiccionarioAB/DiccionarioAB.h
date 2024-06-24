/*
LIBRERIA: Cabecera de Diccionario con Tabla Hash Abierta

AUTORES:
    - Rocha Arellano Ximena Yulian
    - Bautista Romero Demian

(C) Junio 2024
VERSIÓN: 1.0

DESCRIPCIÓN:
    Este archivo define las estructuras y funciones necesarias para implementar un diccionario
    utilizando una tabla hash abierta. Se utiliza un arreglo de listas enlazadas para manejar
    colisiones y se incluyen dos funciones de hash distintas para distribuir las palabras en la tabla.

OBSERVACIONES:
    - La lista utilizada para manejar las colisiones es simplemente ligada.
    - Se define el tamaño de la tabla hash mediante la constante global TAMANO_TABLA_HASH.
    - Se proporcionan funciones para crear la tabla, insertar palabras y definiciones, buscar y eliminar,
      así como funciones para cargar un archivo de definiciones y consultar estadísticas de la tabla.

*/
//Librerias a utilizar:
#ifndef DiccionarioAB_H
#define DiccionarioAB_H
#include "..\TAD_AB\TADArbolBin.h"
// Funciones para manejar el diccionario de acuerdo con la estructura del arbol binario

void CargarArchivo(arbol *A, const char *nombre_archivo);// falta poner la altura final despues de la carga

void AgregarPalabra(arbol *A, const char *palabra, const char *definicion);

void ModificarDefinicion(arbol *A, const char *palabra, const char *nueva_definicion);

void EliminarPalabra(arbol *A, const char *palabra);

char* BuscarPalabra(arbol *A, const char *palabra);

void ConsultarEstadisticas(arbol *A);

char* EncontrarPalabraMasProfunda(arbol *A);

#endif // DiccionarioAB_H