/*

    AUTORES:
        - Rocha Arellano Ximena Yulian
        - Bautista Romero Demian

    (C) Junio 2024
    VERSIÓN: 1.0

    DESCRIPCIÓN:
        Este archivo implementa funciones necesarias para implementar un diccionario
        utilizando arboles binarios 

*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DiccionarioAB.h"
#include "..\TAD_AB\TADArbolBin.h"
//#include "..\Recorridos\Recorridos.h"

/*CargarArchivo: recibe<-árbol(*A), const char* nombre_archivo; 
CargarArchivo(*A, nombre_archivo)
Efecto: Recibe un árbol binario *A y un nombre de archivo. Abre el archivo y carga las palabras y definiciones en el árbol. Cada línea del archivo debe tener el formato "palabra: definición".*/
void CargarArchivo(arbol *A, const char *nombre_archivo) {
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
        while (isspace((unsigned char)*token_palabra))
            token_palabra++;
        size_t len = strlen(token_palabra);
        while (len > 0 && isspace((unsigned char)token_palabra[len - 1]))
            len--;
        token_palabra[len] = '\0'; // Terminación de la cadena

        // Ahora token_palabra contiene la palabra o palabras antes del ':'
        
        
        // Buscar definición después del ':'
        char *definicion = strtok(NULL, "."); //Así lo detenenmos
        if (definicion) {
            // Trim de la definición para quitar espacios al inicio y final
            while (isspace((unsigned char)*definicion))
                definicion++;
            len = strlen(definicion);
            while (len > 0 && isspace((unsigned char)definicion[len - 1]))
                len--;
            definicion[len] = '\0'; // Terminación de la cadena

            //Insertar en el arbol
            AgregarPalabra(A, token_palabra, definicion);
        }
    }

    fclose(archivo);
}

/*AgregarPalabra: recibe<-árbol(*A), const char* palabra, const char* definicion; 
AgregarPalabra(*A, palabra, definicion)
Efecto: Recibe un árbol binario *A, una palabra y una definición. Inserta la palabra y su definición en el árbol en la posición correspondiente.*/
void AgregarPalabra(arbol *A, const char *palabra, const char *definicion) {

    elemento e;
    posicion p;

    //llenamos los datos de la nueva palbra
    strncpy(e.palabra, palabra, sizeof(e.palabra) - 1);
    e.palabra[sizeof(e.palabra) - 1] = '\0'; // Asegurarse de que la palabra está terminada en NULL
    strncpy(e.definicion, definicion, sizeof(e.definicion) - 1);
    e.definicion[sizeof(e.definicion) - 1] = '\0'; // Asegurarse de que la definición está terminada en NULL


    if(Empty(A))//Si no hay palabras, insertar la primera palabra en la raiz
        NewRightSon(A, Root(A), e);  
    else{
        
        p=Root(A);
        
        while(1){//buscar el lugar de las palabras correspondientes
            
            if(strcasecmp(e.palabra, p->e.palabra) == 0){//si la palabra ya se encuentra en el diccionario
                printf("\nLa palabra %s ya existe", e.palabra);
                return;
            }
            else{ 
                if(strcmp(e.palabra, p->e.palabra) < 0){//la nueva palabra es menor que la actual
                    if(LeftSon(A, p)==NULL){// si no tiene hijo izquierdo, se coloca en ese espacio
                        NewLeftSon(A, p, e);
                        break;
                    }//Si tiene hijo izquierdo, vamos a el para evaluar los tamanos de las palabras registradas con la nueva
                    else
                        p=LeftSon(A, p);
                }
                else{
                    if(RightSon(A, p)==NULL){
                        NewRightSon(A, p, e);
                        break;
                    }
                    else
                        p=RightSon(A, p);
                }
            }
        }
        

    }
}

/*ModificarDefinicion: recibe<-árbol(*A), const char* palabra, const char* nueva_definicion; 
ModificarDefinicion(*A, palabra, nueva_definicion)
Efecto: Recibe un árbol binario *A, una palabra y una nueva definición. Modifica la definición de la palabra especificada en el árbol.*/
void ModificarDefinicion(arbol *A, const char *palabra, const char *nueva_definicion) {

    int saltos = 0; // Contador de saltos realizados
    int  comp_tam_cad;
    char defaux[251];
    posicion p= Root(A);
    while (p != NULL) {
        comp_tam_cad= strcasecmp(palabra, p->e.palabra);
        if (comp_tam_cad == 0 ) {            
            strncpy(p->e.definicion, nueva_definicion, 251);
            printf("\nSaltos realizados: %d", saltos);
            return;
        }
        if (comp_tam_cad < 0) {
            p = LeftSon(A, p);
        } else {
            p = RightSon(A, p);
        }
        saltos++;
    }
    printf("\nModificar: Palabra '%s' no encontrada, Saltos: %d", palabra, saltos);
}

/*EliminarPalabra: recibe<-árbol(*A), const char* palabra; 
EliminarPalabra(*A, palabra)
Efecto: Recibe un árbol binario *A y una palabra. Elimina la palabra especificada del árbol, ajustando los nodos según sea necesario.*/
void EliminarPalabra(arbol *A, const char *palabra) {
    int saltos = 0; // Contador de saltos realizados
    int comp_tam_cad;
    posicion p= Root(A);
    posicion aux;
    posicion padre, padreaux;
    while (p != NULL) {
        comp_tam_cad= strcasecmp(palabra, p->e.palabra);
        if (comp_tam_cad == 0 ) {
            padre=Parent(A, p);

            if(padre!=NULL){//Si la palabra se encontro en un nodo distinto a la raiz
                
                if(p->der== NULL && p->izq==NULL){//si el nodo a eliminar es una hoja
                    (p == padre->der)? (padre->der = NULL): (padre->izq = NULL);//se actualiza el apuntador del padre a nulo
                }
                else if(p->der!=NULL && p->izq!= NULL){//si el nodo a eliminar tiene dos hijos aplicamos el mas a la izquierda del de la derecha
                    aux=p->der;//vamos a la derecha de p
                    while(aux->izq != NULL){//a continuacion, vamos al hijo mas a la izquierda de aux
                        aux=LeftSon(A, aux);    
                    }
                    aux->izq=p->izq;// lo que estaba a la izquierda de p lo ponemos a la izquierda de aux
                    (p==padre->der)? (padre->der = aux) : (padre->izq = aux);// enlazamos aux con padre de p 
                    padreaux = Parent(A, aux);//necesitamos actualizar al padre de aux 

                    //como estamos seguros que viajamos lo mas izquierda posible, solo queda saber si la derecha de aux
                    // tiene algo, si es así, se lo ponemos al padre. De lo contrario, lo puntamos a Nulo
                    (aux->der!=NULL)? (padreaux->der = aux->der): (padreaux->izq = NULL);
                    //desenlazamos p
                    p->izq=NULL;
                    p->der=NULL;
                }
                else{//si el nodo a eliminar tiene un solo hijo
                    aux= (p->der!=NULL)? p->der: p->izq;//ver cual de los dos hijos de p es el no vacio
                    (p==padre->der)? (padre->der = aux) : (padre->izq = aux);// enlazamos el hijo de p con su padre
                }
            }
            free(p);
            printf("\nPalabra ""%s"" eliminada con exito. Saltos: %d", palabra, saltos);
            return;
        }
        if (comp_tam_cad < 0) {
            p = LeftSon(A, p);
        } else {
            p = RightSon(A, p);
        }
        saltos++;
    }

    printf("\nEliminar: Palabra '%s' no encontrada, Saltos: %d", palabra, saltos);
}

/*BuscarPalabra: recibe<-árbol(*A), const char* palabra; 
BuscarPalabra(*A, palabra)
Efecto: Recibe un árbol binario *A y una palabra. Busca la palabra en el árbol y devuelve su definición. Si la palabra no se encuentra, devuelve NULL.*/
char* BuscarPalabra(arbol *A, const char *palabra) {
    
    int saltos = 0; // Contador de saltos realizados
    int comp_tam_cad;
    posicion p= Root(A);
    while (p != NULL) {
        comp_tam_cad= strcasecmp(palabra, p->e.palabra);
        if (comp_tam_cad == 0 ) {
            char *definicion_copia = strdup(p->e.definicion);
            printf("\nSaltos realizados: %d\n", saltos);
            return definicion_copia;
        }
        if (comp_tam_cad < 0) {
            p = LeftSon(A, p);
        } else {
            p = RightSon(A, p);
        }
        saltos++;
    }

    printf("\nBuscar: Palabra '%s' no encontrada, Saltos: %d", palabra, saltos);
    return NULL;
    
}

/*ConsultarEstadisticas: recibe<-árbol(*A); 
ConsultarEstadisticas(*A)
Efecto: Recibe un árbol binario *A y consulta estadísticas del árbol, como el número total de palabras, la altura del árbol y la palabra más profunda.*/
void ConsultarEstadisticas(arbol *A) {
    int num_palabras = ContarNodos(A, Root(A));
    int altura = Altura(A, Root(A));
    char *palabra= EncontrarPalabraMasProfunda(A);
    // Imprimir estadísticas finales
    printf("\n***************************************************\n");
    printf("Estadisticas:\n");
    printf("Numero total de palabras: %d\n", num_palabras);
    printf("Tamano del arbol: %d\n", altura);
    printf("Palabra profunda: %s\n", palabra);
    printf("\n***************************************************\n");
}

//es auxiliar
static void EncontrarPalabraMasProfundaAux(posicion p, int nivel_actual, int *nivel_maximo, char *palabra_mas_profunda) {
    if (p != NULL) {
        // Procesar el nodo actual
        if (nivel_actual > *nivel_maximo) {
            *nivel_maximo = nivel_actual;
            strncpy(palabra_mas_profunda, p->e.palabra, sizeof(p->e.palabra));
            palabra_mas_profunda[sizeof(p->e.palabra) - 1] = '\0'; // Terminar la cadena
        }

        // Llamadas recursivas a los hijos izquierdo y derecho
        EncontrarPalabraMasProfundaAux(p->izq, nivel_actual + 1, nivel_maximo, palabra_mas_profunda);
        EncontrarPalabraMasProfundaAux(p->der, nivel_actual + 1, nivel_maximo, palabra_mas_profunda);
    }
}

/*EncontrarPalabraMasProfunda: recibe<-árbol(*A); 
EncontrarPalabraMasProfunda(*A)
Efecto: Recibe un árbol binario *A y encuentra la palabra más profunda en el árbol. Devuelve una copia dinámica de la palabra más profunda.*/
char* EncontrarPalabraMasProfunda(arbol *A) {
    if (A == NULL || *A == NULL)
        return NULL;

    int nivel_maximo = -1;
    char palabra_mas_profunda[sizeof((*A)->e.palabra)] = ""; // Inicializa la palabra más profunda

    // Llamar a la función auxiliar recursiva
    EncontrarPalabraMasProfundaAux(*A, 0, &nivel_maximo, palabra_mas_profunda);

    return strdup(palabra_mas_profunda); // Devuelve una copia dinámica de la palabra encontrada
}