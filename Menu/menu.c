/*
    AUTORES:
        - Rocha Arellano Ximena Yulian
        - Bautista Romero Demian

    (C) Junio 2024
    VERSIÓN: 1.0

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "menu.h"
#include "../TAD_AB/TADArbolBin.h"
#include "..\DiccionarioAB\DiccionarioAB.h"
#include "..\Recorridos\Recorridos.h"

/*MostrarMenu: recibe<-puntero a entero(*op); 
MostrarMenu(*op)
Efecto: Muestra un menú con diferentes opciones para el usuario y lee la opción seleccionada, almacenándola en la variable apuntada por *op.*/
void MostrarMenu(int *op){
    printf("\nMenu:\n");
    printf("1. Cargar un archivo de definiciones\n");
    printf("2. Agregar una palabra y su definicion\n");
    printf("3. Modificar su defincion\n");
    printf("4. Eliminar una palabra\n");
    printf("5. Buscar una palabra\n");
    printf("6. Recorrido PreOrden\n");
    printf("7. Recorrido InOrden\n");
    printf("8. Recorrido PosOrden\n");
    printf("9. Consultar Estadisticas\n");
    printf("10. Salir\n");
    printf("Ingrese el numero de la opcion que desea ejecutar: ");
    scanf("%d", op);
    while (getchar() != '\n');  // Consumir cualquier carácter residual en el buffer de entrada
}

/*Menu (Menu): recibe<-árbol(*A); 
Menu(*A)
Efecto: Muestra el menú de opciones al usuario y ejecuta la función correspondiente según la opción seleccionada. Las opciones incluyen cargar un archivo, agregar una palabra, modificar una definición, eliminar una palabra, buscar una palabra, realizar recorridos del árbol (PreOrden, InOrden, PosOrden), consultar estadísticas del árbol y salir del programa.*/
int Menu(arbol *A){
    int opcion;
    MostrarMenu(&opcion);
    char nombre_archivo[500], palabra[101], definicion[251];
    switch (opcion) {
        case 1://   Cargar un archivo
            printf("Ingrese el nombre del archivo a cargar (debe estar en el mismo directorio): ");
            fgets(nombre_archivo, sizeof(nombre_archivo), stdin);
            nombre_archivo[strcspn(nombre_archivo, "\n")] = 0; // Eliminar el salto de línea al final
            CargarArchivo(A, nombre_archivo);
            //TAMAÑO FINAL DEL ARBOL
            printf("\nLa altura del arbol despues de la operacion es de: %d", Altura(A, Root(A)));
            break;
        case 2://   Agregar una palabra y su definicion 
            printf("Ingrese la palabra que desea agregar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            printf("Ingrese la definicion de '%s': ", palabra);
            fgets(definicion, sizeof(definicion), stdin);
            definicion[strcspn(definicion, "\n")] = 0; // Eliminar el salto de línea al final

            AgregarPalabra(A, palabra, definicion);
            //TAMAÑO FINAL DEL ARBOL
            printf("\nLa altura del arbol despues de la operacion es de: %d", Altura(A, Root(A)));
            break;
        case 3://   Modificar definicion
            printf("Ingrese la palabra cuya definicion desea modificar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            printf("Ingrese la nueva definicion de '%s': ", palabra);
            fgets(definicion, sizeof(definicion), stdin);
            definicion[strcspn(definicion, "\n")] = 0; // Eliminar el salto de línea al final

            ModificarDefinicion(A, palabra, definicion);
            break;
        case 4://   Eliminar palabra
            printf("Ingrese la palabra que desea eliminar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            EliminarPalabra(A, palabra);
            break;
        case 5://   Buscar palabra
            printf("Ingrese la palabra que desea buscar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            char *definicion_encontrada = BuscarPalabra(A, palabra);
            if (definicion_encontrada != NULL) {
                printf("Definicion de '%s': %s\n", palabra, definicion_encontrada);
                free(definicion_encontrada); // Liberar la memoria asignada por strdup en buscar
            }
            break;
        case 6://   Recorriodo Preorden
            PreOrden(Root(A));
            break;
        case 7://   Recorriodo Inorden
            InOrden(Root(A));
            break;
        case 8://   Recorriodo Posorden
            PostOrden(Root(A));
            break;
        case 9://   Consultar Estadisticas
            ConsultarEstadisticas(A);
            break;
        case 10:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida. Por favor, ingrese una opción valida.\n");
            break;
    }
    printf("\n\nPresiona enter para continuar...");
    char algo;
    scanf("%c", &algo);
    Sleep(3);
    system("cls");
    return opcion;
}