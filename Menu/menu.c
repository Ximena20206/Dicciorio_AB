#include <stdio.h>
#include "menu.h"
#include "Formato\Formato.h"


void MostrarMenu(int *op){
    int opcion;
    printf("\nMenu:\n");
    printf("1. Cargar un archivo de definiciones\n");
    printf("2. Agregar una palabra y su definicion\n");
    printf("3. Modificar su defincion\n");
    printf("4. Eliminar una palabra\n");
    printf("5. Buscar una palabra\n");
    printf("6. Recorrido PreOrden\n");
    printf("7. Recorrido InOrden\n");
    printf("8. Recorrido PosOrden\n");
    printf("9. Recorrido PreOrden\n");
    printf("10. Salir\n");
    printf("Ingrese el numero de la opcion que desea ejecutar: ");
    scanf("%d", op);
    return op; 
}

int Menu(){
    int opcion = MostrarMenu(&opcion);
    switch (opcion) {
        case 1:// Cargar un archivo
            printf("Ingrese el nombre del archivo a cargar (debe estar en el mismo directorio): ");
            fgets(nombre_archivo, sizeof(nombre_archivo), stdin);
            nombre_archivo[strcspn(nombre_archivo, "\n")] = 0; // Eliminar el salto de línea al final
            cargar_archivo(&tabla, nombre_archivo, hashAutilizar);
            break;
        case 2:// Gregar una palabra y su definicion 
            printf("Ingrese la palabra que desea agregar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            printf("Ingrese la definicion de '%s': ", palabra);
            fgets(definicion, sizeof(definicion), stdin);
            definicion[strcspn(definicion, "\n")] = 0; // Eliminar el salto de línea al final

            insertar(&tabla, palabra, definicion, hashAutilizar);
            break;
        case 3:// Modificar definicion
            printf("Ingrese la palabra cuya definicion desea modificar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            printf("Ingrese la nueva definicion de '%s': ", palabra);
            fgets(definicion, sizeof(definicion), stdin);
            definicion[strcspn(definicion, "\n")] = 0; // Eliminar el salto de línea al final

            modificar(&tabla, palabra, definicion, hashAutilizar);
            break;
        case 4:// Eliminar palabra
            printf("Ingrese la palabra que desea eliminar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            eliminar(&tabla, palabra, hashAutilizar);
            break;
        case 5:// Buscar palabra
            printf("Ingrese la palabra que desea buscar: ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = 0; // Eliminar el salto de línea al final

            char *definicion_encontrada = buscar(&tabla, palabra, hashAutilizar);
            if (definicion_encontrada != NULL) {
                printf("Definicion de '%s': %s\n", palabra, definicion_encontrada);
                free(definicion_encontrada); // Liberar la memoria asignada por strdup en buscar
            }
            break;
        case 6://Recorriodo Preorden

            break;
        case 7://Recorriodo Inorden

            break;
        case 8://Recorriodo Posorden

            break;
        case 9:
            consultar_estadisticas(&tabla);
            break;
        case 10:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida. Por favor, ingrese una opción valida.\n");
            break;
    }

    portableSleep(3);
    clearScreen();
    return opcion;
}