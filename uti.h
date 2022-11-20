#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[100];
char *leerCadena(char *mensaje){
    char *cadena;

    printf("%s", mensaje);
    fflush(stdin);
    cadena = fgets(buffer, sizeof(buffer), stdin);
    if(cadena != NULL){
        buffer[strlen(buffer)-1] = '\0'; // SUSTITUYE LA \n
        cadena = buffer; 
    }
    return cadena;
}

int leerSize_t(char *mensaje){
    size_t st; 

    printf("%s", mensaje);
    scanf("%zi", &st);

    return st;
}

float leerFloat(char *mensaje){
    float st; 

    printf("%s", mensaje);
    scanf("%f", &st);

    return st;
}

#endif