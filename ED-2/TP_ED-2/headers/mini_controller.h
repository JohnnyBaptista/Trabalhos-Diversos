//
// Created by ratob on 09/11/2019.
//

#ifndef NOVO_TPED2_MINI_CONTROLLER_H
#define NOVO_TPED2_MINI_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

//void __registrar_log__(int __execution_number__,int tipo[50], int cicle, int counter, char __function_flow__[50], char log_name[80]);
void __registrar_log__(char __function_flow__[50],char log_name[50]);
char *replaceWord(const char *s, const char *oldW, const char *newW);

#endif //NOVO_TPED2_MINI_CONTROLLER_H
