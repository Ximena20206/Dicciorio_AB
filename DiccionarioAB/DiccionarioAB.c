

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DiccionarioAB.h"
#include "..\TAD_AB\TADArbolBin.h"
#include "..\Recorridos\Recorridos.h"

void CargarArchivo(arbol A, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        fprintf(stderr, "Error al abrir el archivo.\n");
        return;
    }

    char linea[512]; // Asumimos que ninguna línea del archivo superará los 512 caracteres

    while (fgets(linea, sizeof(linea), archivo)) {
        // Buscar el primer ':' que separa las palabras de la definición
        char *token_palabra = strtok(linea, ":");
        if (!token_palabra) continue; // Si no hay ':' en la línea, saltar a la siguiente

        // Con isspace quitamos los espacios si llegaran a haber del inicio y el final del token para quitar espacios al inicio y final
        while (isspace((unsigned char)*token_palabra)) token_palabra++;
        size_t len = strlen(token_palabra);
        while (len > 0 && isspace((unsigned char)token_palabra[len - 1])) len--;
        token_palabra[len] = '\0'; // Terminación de la cadena

        // Ahora token_palabra contiene la palabra o palabras antes del ':'
        // Buscar definición después del ':'
        char *definicion = strtok(NULL, "."); //Así lo detenenmos
        if (definicion) {
            // Trim de la definición para quitar espacios al inicio y final
            while (isspace((unsigned char)*definicion)) definicion++;
            len = strlen(definicion);
            while (len > 0 && isspace((unsigned char)definicion[len - 1])) len--;
            definicion[len] = '\0'; // Terminación de la cadena

            // Insertar en la tabla hash
            insertarArchivo(tabla, token_palabra, definicion, hashAutilizar);
        }
    }

    fclose(archivo);
}

void AgregarPalabra(/*TablaHash *tabla, const char *palabra, const char *definicion, int hashAutilizar) {
    int clave = textoAint(palabra);
    int hash;

    // Seleccionar la función de hash a utilizar
    if (hashAutilizar == 1) {
        hash = funcion_hash1(clave);
    } else if (hashAutilizar == 2) {
        hash = funcion_hash2(clave);
    } else {
        printf("\nError: Función de hash no válida.\n");
        return;
    }

    int indice = hash % tabla->tamano;
    int colisiones = 0;

    // Verificar si la palabra ya existe en la lista
    posicion pos = First(&tabla->arreglo[indice]);
    while (ValidatePosition(&tabla->arreglo[indice], pos)) {
        elemento e = Position(&tabla->arreglo[indice], pos);
        if (strcmp(e.palabra, palabra) == 0) {
            // Ya existe la misma palabra en la tabla
            if (strcmp(e.definicion, definicion) == 0) {
                printf("La definición para la palabra '%s' ya existe en la tabla.\n", palabra);
            } else {
                printf("La palabra '%s' ya existe en la tabla con una definición diferente.\n", palabra);
            }
            return;
        }
        colisiones++;
        pos = Following(&tabla->arreglo[indice], pos);
    }

    // Insertar en la lista en el índice correspondiente
    elemento e;
    strncpy(e.palabra, palabra, sizeof(e.palabra) - 1);
    e.palabra[sizeof(e.palabra) - 1] = '\0'; // Asegurarse de que la palabra está terminada en NULL
    strncpy(e.definicion, definicion, sizeof(e.definicion) - 1);
    e.definicion[sizeof(e.definicion) - 1] = '\0'; // Asegurarse de que la definición está terminada en NULL
    Add(&tabla->arreglo[indice], e);

    // Mostrar estadísticas
    printf("Insertar: Palabra '%s', Hash: %d, Colisiones: %d\n", palabra, hash, colisiones);
}*/)

void ModificarDefinicion(/*TablaHash *tabla, const char *palabra, const char *nueva_definicion, int hashAutilizar) {
    int clave = textoAint(palabra);
    int hash;

    // Seleccionar la función de hash a utilizar
    if (hashAutilizar == 1) {
        hash = funcion_hash1(clave);
    } else if (hashAutilizar == 2) {
        hash = funcion_hash2(clave);
    } else {
        printf("Error: Función de hash no válida.\n");
        return;
    }

    int indice = hash % tabla->tamano;
    int colisiones = 0;
    int saltos = 0; // Contador de saltos realizados

    while (!Empty(&tabla->arreglo[indice])) {
        elemento e;
        posicion pos = First(&tabla->arreglo[indice]);
        while (ValidatePosition(&tabla->arreglo[indice], pos)) {
            e = Position(&tabla->arreglo[indice], pos);
            if (strcmp(e.palabra, palabra) == 0) {
                // Encontrado: modificar la definición
                strncpy(e.definicion, nueva_definicion, 500);
                Replace(&tabla->arreglo[indice], pos, e); // Actualizar el elemento modificado

                // Mostrar estadísticas de la modificación
                    printf("Modificar: Palabra '%s' modificada, Hash: %d, Colisiones: %d, Saltos: %d\n", palabra, indice, colisiones, saltos);
                return;
            }
            saltos++;
            pos = Following(&tabla->arreglo[indice], pos);
        }
        colisiones++;
        saltos++;
        indice = (indice + 1) % tabla->tamano; // Linear probing para manejar colisiones
    }

    // Mostrar estadísticas (no encontrada)
    printf("Modificar: Palabra '%s' no encontrada, Hash: %d, Colisiones: %d, Saltos: %d\n", palabra, indice, colisiones, saltos);
}*/)

void EliminarPalabra(/*TablaHash *tabla, const char *palabra, int hashAutilizar) {
    int clave = textoAint(palabra);
    int hash;

    // Seleccionar la función de hash a utilizar
    if (hashAutilizar == 1) {
        hash = funcion_hash1(clave);
    } else if (hashAutilizar == 2) {
        hash = funcion_hash2(clave);
    } else {
        printf("\nError: Función de hash no válida.\n");
        return;
    }

    int indice = hash % tabla->tamano;
    int colisiones = 0;
    int saltos = 0; // Contador de saltos realizados

    while (!Empty(&tabla->arreglo[indice])) {
        posicion pos = First(&tabla->arreglo[indice]);
        while (ValidatePosition(&tabla->arreglo[indice], pos)) {
            elemento e = Position(&tabla->arreglo[indice], pos);
            if (strcmp(e.palabra, palabra) == 0) {
                Remove(&tabla->arreglo[indice], pos);
                // Mostrar estadísticas
                    printf("\nEliminar: Palabra '%s' eliminada, Hash: %d, Colisiones: %d, Saltos: %d\n", palabra, indice, colisiones, saltos);
                return;
            }
            saltos++;
            pos = Following(&tabla->arreglo[indice], pos);
        }
        colisiones++;
        saltos++;
        indice = (indice + 1) % tabla->tamano; // Linear probing para manejar colisiones
    }

    // Mostrar estadísticas (no encontrada)
    printf("\nEliminar: Palabra '%s' no encontrada, Hash: %d, Colisiones: %d, Saltos: %d\n", palabra, indice, colisiones, saltos);
}*/)

char* BuscarPalabra(/*TablaHash *tabla, const char *palabra, int hashAutilizar) {
    int clave = textoAint(palabra);
    int hash;
    int colisiones = 0;
    // Seleccionar la función de hash a utilizar
    if (hashAutilizar == 1) {
        hash = funcion_hash1(clave);
    } else if (hashAutilizar == 2) {
        hash = funcion_hash2(clave);
    } else {
        printf("\nError: Función de hash no válida.\n");
        return NULL;
    }

    int indice = hash % tabla->tamano;
    int saltos = 0; // Contador de saltos realizados (En que lugar se encuentra de la lista)

    while (!Empty(&tabla->arreglo[indice])) {
        elemento e;
        posicion pos = First(&tabla->arreglo[indice]);
        while (ValidatePosition(&tabla->arreglo[indice], pos)) {
            e = Position(&tabla->arreglo[indice], pos);
            if (strcmp(e.palabra, palabra) == 0) {
                // Mostrar estadísticas
                    printf("\nBuscar: Palabra '%s' encontrada, Hash: %d, Colisiones: %d, Saltos: %d\n", palabra, indice, colisiones, saltos);
                // Devolver una copia de definicion
                char *definicion_copia = strdup(e.definicion); //strdup copia el contenido de la cadena original en la nueva área de memoria asignada
                return definicion_copia;
            }
            saltos++;
            pos = Following(&tabla->arreglo[indice], pos);
        }
        saltos++;
        indice = (indice + 1) % tabla->tamano; // Linear probing para encontrar la siguiente posición
    }

    // Mostrar estadísticas (no encontrada)
    printf("Buscar: Palabra '%s' no encontrada, Hash: %d, Saltos: %d\n", palabra, indice, colisiones, saltos);
    return NULL;
}*/)

void ConsultarEstadisticas(/*TablaHash *tabla) {
    int num_palabras = 0;
    int num_colisiones = 0;
    int num_listas_vacias = 0;
    int tamano_max_lista = 0;
    int orden_max_busqueda = 0;

    // Recorre cada índice de la tabla hash
    for (int i = 0; i < tabla->tamano; ++i) {
        // Obtener el tamaño de la lista actual
        int tamano_lista = Size(&tabla->arreglo[i]);

        // Contabilizar el número total de palabras
        num_palabras += tamano_lista;

        // Actualizar el tamaño máximo de lista
        if (tamano_lista > tamano_max_lista) {
            tamano_max_lista = tamano_lista;
        }

        // Contabilizar listas vacías
        if (tamano_lista == 0) {
            num_listas_vacias++;
        }

        // Calcular colisiones
        if (tamano_lista > 1) {
            num_colisiones += (tamano_lista - 1);
        }

        // Calcular el orden máximo de búsqueda en cada lista no vacía
        int pasos_max = 0;
        if (tamano_lista > 0) {
            posicion pos = First(&tabla->arreglo[i]);

            // Iterar a través de la lista
            while (ValidatePosition(&tabla->arreglo[i], pos)) {
                pasos_max++;
                pos = Following(&tabla->arreglo[i], pos);
            }
        }
        
        // Actualizar el orden máximo de búsqueda
        if (pasos_max > orden_max_busqueda) {
            orden_max_busqueda = pasos_max;
        }
    }

    // Imprimir estadísticas finales
    printf("\n***************************************************\n");
    printf("Estadisticas:\n");
    printf("Numero total de palabras: %d\n", num_palabras);
    printf("Numero total de colisiones: %d\n", num_colisiones);
    printf("Numero de listas vacias: %d\n", num_listas_vacias);
    printf("Tamano maximo de una lista: %d\n", tamano_max_lista);
    printf("Orden maximo de busqueda: %d\n", orden_max_busqueda);
    printf("Tamano de la tabla hash: O(n)");
    printf("\n***************************************************\n");
}*/)




void insertarArchivo(/*TablaHash *tabla, const char *palabra, const char *definicion, int hashAutilizar) {
    int clave = textoAint(palabra);
    int hash = 0;

    // Seleccionar la función de hash a utilizar
    if (hashAutilizar == 1) {
        hash = funcion_hash1(clave);
    } else if (hashAutilizar == 2) {
        hash = funcion_hash2(clave);
    } else {
        printf("\nError: Función de hash no válida.\n");
        return;
    }

    int indice = hash % tabla->tamano;
    int colisiones = 0;

    // Insertar en la tabla hash sin resolver colisiones
    elemento e;
    strncpy(e.palabra, palabra, sizeof(e.palabra) - 1);
    e.palabra[sizeof(e.palabra) - 1] = '\0'; // Asegurarse de que la palabra está terminada en NULL
    strncpy(e.definicion, definicion, sizeof(e.definicion) - 1);
    e.definicion[sizeof(e.definicion) - 1] = '\0'; // Asegurarse de que la definición está terminada en NULL

    // Insertar el elemento en el índice calculado
    Add(&tabla->arreglo[indice], e);

    // Contar las colisiones sin resolverlas
    while (!Empty(&tabla->arreglo[indice])) {
        colisiones++;
        indice = (indice + 1) % tabla->tamano; // Avanzar al siguiente índice sin resolver colisiones
    }


    // Incrementar el contador de colisiones
    colisiones++;
}*/)

