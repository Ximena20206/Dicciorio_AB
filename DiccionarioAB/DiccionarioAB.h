/*
    LIBRERIA: Cabecera de Diccionario con Arbol Binario

    AUTORES:
        - Rocha Arellano Ximena Yulian
        - Bautista Romero Demian

    (C) Junio 2024
    VERSIÓN: 1.0

    DESCRIPCIÓN:
        Este archivo define las estructuras y funciones necesarias para implementar un diccionario
        utilizando un arbol binario. 

*/
//Librerias a utilizar:
#ifndef DiccionarioAB_H
#define DiccionarioAB_H
#include "..\TAD_AB\TADArbolBin.h"

// Funciones para manejar el diccionario de acuerdo con la estructura del arbol binario


/*CargarArchivo: recibe<-árbol(*A), const char* nombre_archivo; 
CargarArchivo(*A, nombre_archivo)
Efecto: Recibe un árbol binario *A y un nombre de archivo. Abre el archivo y carga las palabras y definiciones en el árbol. Cada línea del archivo debe tener el formato "palabra: definición".*/
void CargarArchivo(arbol *A, const char *nombre_archivo);// falta poner la altura final despues de la carga

/*AgregarPalabra: recibe<-árbol(*A), const char* palabra, const char* definicion; 
AgregarPalabra(*A, palabra, definicion)
Efecto: Recibe un árbol binario *A, una palabra y una definición. Inserta la palabra y su definición en el árbol en la posición correspondiente.*/
void AgregarPalabra(arbol *A, const char *palabra, const char *definicion);

/*ModificarDefinicion: recibe<-árbol(*A), const char* palabra, const char* nueva_definicion; 
ModificarDefinicion(*A, palabra, nueva_definicion)
Efecto: Recibe un árbol binario *A, una palabra y una nueva definición. Modifica la definición de la palabra especificada en el árbol.*/
void ModificarDefinicion(arbol *A, const char *palabra, const char *nueva_definicion);

/*EliminarPalabra: recibe<-árbol(*A), const char* palabra; 
EliminarPalabra(*A, palabra)
Efecto: Recibe un árbol binario *A y una palabra. Elimina la palabra especificada del árbol, ajustando los nodos según sea necesario.*/
void EliminarPalabra(arbol *A, const char *palabra);

/*BuscarPalabra: recibe<-árbol(*A), const char* palabra; 
BuscarPalabra(*A, palabra)
Efecto: Recibe un árbol binario *A y una palabra. Busca la palabra en el árbol y devuelve su definición. Si la palabra no se encuentra, devuelve NULL.*/
char* BuscarPalabra(arbol *A, const char *palabra);

/*ConsultarEstadisticas: recibe<-árbol(*A); 
ConsultarEstadisticas(*A)
Efecto: Recibe un árbol binario *A y consulta estadísticas del árbol, como el número total de palabras, la altura del árbol y la palabra más profunda.*/
void ConsultarEstadisticas(arbol *A);

/*EncontrarPalabraMasProfunda: recibe<-árbol(*A); 
EncontrarPalabraMasProfunda(*A)
Efecto: Recibe un árbol binario *A y encuentra la palabra más profunda en el árbol. Devuelve una copia dinámica de la palabra más profunda.*/
char* EncontrarPalabraMasProfunda(arbol *A);

#endif // DiccionarioAB_H