//
// Created by ratob on 09/11/2019.
//

#ifndef NOVO_TPED2_HELPER_H
#define NOVO_TPED2_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pause(){
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("read -p 'Press Enter to continue...' var");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#endif


}

/*void clrscr() {
    system("@cls||clear");
    fflush(stdin);
}*/

void clrscr(){
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

#endif //NOVO_TPED2_HELPER_H
