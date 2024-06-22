#include <stdio.h>
#include "Formato.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void portableSleep(int seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000);
    #else
        sleep(seconds);
    #endif
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}