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
#ifndef TABLA_HASH_H
#define TABLA_HASH_H
#include "TADListaDL.h"
//Constante global con la que controlamos el tamaño de la tabla hash
#define TAMANO_TABLA_HASH 1499

// Estructura para la tabla hash
typedef struct {
    lista arreglo[TAMANO_TABLA_HASH]; // Arreglo de listas enlazadas
    int tamano;           // Tamaño del arreglo (número de listas)
} TablaHash;

// Funciones para manejar la tabla hash

/*
Función para crear una tabla hash con un número especificado de listas.
Recibe: TablaHash *tabla (Referencia a la tabla hash que se creará)
No devuelve nada. Inicializa la tabla hash con el tamaño especificado.
*/
void crear_tabla(TablaHash *tabla);

/*
Función de hash 1 utilizando la razón áurea.
Recibe: int clave (Valor entero para calcular el hash)
Devuelve: int (Valor hash resultante)
*/
int funcion_hash1(int clave);


/*
Función de hash 2 utilizando el número Euler.
Recibe: int clave (Valor entero para calcular el hash)
Devuelve: int (Valor hash resultante)
*/
int funcion_hash2(int clave);

/*
Función para convertir texto a entero usando valores ASCII.
Recibe: const char *clave (Cadena de caracteres para convertir)
Devuelve: int (Valor entero resultante)
*/
int textoAint(const char *clave);

/*
Inserta un par palabra-definición en la tabla hash.
Recibe: TablaHash *tabla (Referencia a la tabla hash donde se insertará),
        const char *palabra (Palabra a insertar),
        const char *definicion (Definición asociada a la palabra),
        int hashAutilizar (Número de función de hash a utilizar)
No devuelve nada. Inserta el par en la tabla hash usando la función de hash especificada.
*/
void insertar(TablaHash *tabla, const char *palabra, const char *definicion, int hashAutilizar);

/*
Inserta un par palabra-definición en la tabla hash desde un archivo.
Recibe: TablaHash *tabla (Referencia a la tabla hash donde se cargarán las definiciones),
        const char *nombre_archivo (Nombre del archivo de definiciones a cargar),
        int hashAutilizar (Número de función de hash a utilizar)
No devuelve nada. Carga las definiciones desde el archivo en la tabla hash.
*/
void insertarArchivo(TablaHash *tabla, const char *palabra, const char *definicion, int hashAutilizar);

/*
Busca una definición en la tabla hash dada una palabra.
Recibe: TablaHash *tabla (Referencia a la tabla hash donde se buscará la palabra),
        const char *palabra (Palabra a buscar),
        int hashAutilizar (Número de función de hash a utilizar)
Devuelve: char* (Copia de la definición encontrada de la palabra buscada)
Observaciones: Si la palabra no se encuentra, muestra un mensaje de error y devuelve NULL.
*/
char* buscar(TablaHash *tabla, const char *palabra, int hashAutilizar);

/*
Elimina un par palabra-definición de la tabla hash dada una palabra.
Recibe: TablaHash *tabla (Referencia a la tabla hash de donde se eliminará la palabra),
        const char *palabra (Palabra a eliminar),
        int hashAutilizar (Número de función de hash a utilizar)
No devuelve nada. Elimina la palabra y su definición asociada de la tabla hash.
*/
void eliminar(TablaHash *tabla, const char *palabra, int hashAutilizar);

/*
Libera toda la memoria utilizada por la tabla hash.
Recibe: TablaHash *tabla (Referencia a la tabla hash que se desea liberar)
No devuelve nada. Libera la memoria asignada a la tabla hash y sus elementos.
*/
void liberar_tabla(TablaHash *tabla);

/*
Carga un archivo de definiciones en la tabla hash.
Recibe: TablaHash *tabla (Referencia a la tabla hash donde se cargarán las definiciones),
        const char *nombre_archivo (Nombre del archivo de definiciones a cargar),
        int hashAutilizar (Número de función de hash a utilizar)
No devuelve nada. Carga las definiciones desde el archivo en la tabla hash.
*/
void cargar_archivo(TablaHash *tabla, const char *nombre_archivo, int hashAutilizar);

/*
Consulta un resumen estadístico de la distribución de palabras, colisiones y eficiencia de la tabla hash.
Recibe: TablaHash *tabla (Referencia a la tabla hash de la cual se obtendrán las estadísticas)
No devuelve nada. Imprime por consola las estadísticas obtenidas de la tabla hash.
*/
void consultar_estadisticas(TablaHash *tabla);

/*
Modifica la definición de una palabra en la tabla hash.
Recibe: TablaHash *tabla (Referencia a la tabla hash donde se modificará la definición),
        const char *palabra (Palabra cuya definición se modificará),
        const char *nueva_definicion (Nueva definición para la palabra),
        int hashAutilizar (Número de función de hash a utilizar)
No devuelve nada. Modifica la definición de la palabra especificada en la tabla hash.
*/
void modificar(TablaHash *tabla, const char *palabra, const char *nueva_definicion, int hashAutilizar);

/*
Función para mostrar el menú de opciones en el programa principal.
No recibe parámetros.
No devuelve nada. Imprime por consola el menú de opciones disponibles.
*/
void mostrar_menu();

/*
Función para seleccionar una función de hash entre dos opciones disponibles.
No recibe parámetros.
Devuelve: int (Número de la función de hash seleccionada: 1 o 2)
*/
int seleccionar_funcion_hash();


#endif // TABLA_HASH_H


