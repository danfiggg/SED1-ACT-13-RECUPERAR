#ifndef ALDEANO_H
#define ALDEANO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "uti.h"

struct aldeano
{
    char *nombre;
    int edad;
    int salud;
};

typedef struct aldeano Aldeano;

Aldeano *Aldeano_init(char *nombre,int edad, int salud){
    Aldeano *aldeano = (Aldeano*)malloc(sizeof(Aldeano));
        if(aldeano != NULL){
            aldeano->nombre = strdup(nombre);
            aldeano->edad = edad;
            aldeano->salud = salud;
            
        }
        return aldeano;
}

Aldeano *Aldeano_free(Aldeano *aldeano){
    if(aldeano != NULL){
        free(aldeano->nombre);
        aldeano->nombre = NULL;
        free(aldeano);
        aldeano = NULL;
    }
    return aldeano;
}

Aldeano *Aldeano_capturar(){
    char *nombre = leerCadena("Nombre: ");
    int edad = leerSize_t("Edad: ");
    int salud = leerSize_t("Salud: ");
    

    Aldeano *aldeano = Aldeano_init(nombre, edad, salud);
    return aldeano;
}

bool Aldeano_mostrar(Aldeano *aldeano){
    bool NO_ERROR = false;

    if(aldeano != NULL){
        printf("\nNombre: %s\n", aldeano->nombre);
        printf("Edad: %i\n", aldeano->edad);
        printf("Salud: %i\n", aldeano->salud);
        
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool Aldeano_mostrar_lista(Aldeano *aldeano){
    bool NO_ERROR = false;
    if(aldeano != NULL){
        printf("%12s %8i %8i\n", aldeano->nombre,aldeano->edad, aldeano->salud);
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool Aldeano_respaldar(Aldeano *aldeano, FILE *archivo){
    if(aldeano==NULL){
        puts("ALDEANO: NO TIENE MEMORIA");
        return false;
    }
    if(archivo==NULL){
        puts("ALDEANO: ARCHIVO NULO");
        return false;
    }
    fprintf(archivo, "%s\n", aldeano->nombre);
    fprintf(archivo, "%i\n", aldeano->edad);
    fprintf(archivo, "%i\n", aldeano->salud);

    return true;
}

Aldeano *Aldeano_recuperar(FILE *archivo){
    if(archivo==NULL){
        puts("ALDEANO: ARCHIVO NULO");
        return false;
    }
    char nombre[100];
    int edad[100];
    int salud[100];

    fscanf(archivo, "%s", nombre);
    //nombre[strlen(buffer)-1] = '\0';
    fscanf(archivo, "%i", &edad);
    if(feof(archivo)) return NULL;
    fscanf(archivo, "%i", &salud);

    Aldeano *aldeano = Aldeano_init(nombre, edad, salud);

    return aldeano;
}

#endif