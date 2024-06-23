#include <stdio.h>
#include "TAD_AB\TADArbolBin.h"
#include "Menu\menu.h"
int main(){
    int ans=1;
    arbol A;
    
    Initialize(&A);

    while(ans!=10)
        ans=Menu(&A);

    Destroy(&A);

    return 0;
}