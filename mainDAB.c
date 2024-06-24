/*

    AUTORES:
    - Rocha Arellano Ximena Yulian
    - Bautista Romero Demian

    (C) Junio 2024
    VERSIÓN: 1.0
*/
#include <stdio.h>
#include "TAD_AB\TADArbolBin.h"
#include "Menu\menu.h"

int main(){
    int ans;
    arbol A;
    
    Initialize(&A);

    while(ans!=10)
        ans = Menu(&A);

    Destroy(&A);

    return 0;
}