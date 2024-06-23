
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

