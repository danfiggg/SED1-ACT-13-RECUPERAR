#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <stdio.h>
#include <stdlib.h>

#include "lista_aldeanos.h"
#include "puerto.h"
#include "batalla.h"

struct civilizacion
{
    char *nombre;
    AldeanosLista *aldeanosLista;
    Puerto *puerto;
    ColaBarco *batalla;
};

typedef struct civilizacion Civilizacion;

Civilizacion *Civilizacion_init(char *nombre){
    Civilizacion *civilizacion = (Civilizacion*)malloc(sizeof(Civilizacion));
    if(civilizacion == NULL){
        puts("ERRROR AL RESERVAR MEMORIA");
        return civilizacion;
    }
    civilizacion->batalla = ColaBarco_init();
    civilizacion->puerto = Puerto_init();
    civilizacion->nombre = strdup(nombre);
    civilizacion->aldeanosLista = AldeanosLista_init();
    if(civilizacion->aldeanosLista == NULL){
        puts("ERROR AL CREAR LISTA ALDEANOS");
    }
    return civilizacion;
}

Civilizacion *Civilizacion_free(Civilizacion *civilizacion){
    if(civilizacion == NULL){
        puts("LA CIVILIZACION NO TIENE MEMORIA");
        return civilizacion;
    }
    free(civilizacion->nombre);
    civilizacion->puerto = Puerto_free(civilizacion->puerto);
    civilizacion->batalla = ColaBarco_free(civilizacion->batalla);
    civilizacion->aldeanosLista = AldeanosLista_free(civilizacion->aldeanosLista);
    civilizacion = NULL;
    return civilizacion;
}

Civilizacion *Civilizacion_capturar(){
    char *nombre = leerCadena("Nombre civilizacion: ");
    
    Civilizacion *civilizacion = Civilizacion_init(nombre);
    
    return civilizacion;
}

bool Civilizacion_mostrar(Civilizacion *civilizacion){
    if(civilizacion == NULL){
        puts("NO TIENE MEMORIA");
        return false;
    }
    printf("----------------------------------------\n");
    printf("Civilizacion: %s\n\n", civilizacion->nombre);
    
    if(AldeanosLista_mostrar_lista(civilizacion->aldeanosLista)){
        puts("\nALDEANOSLISTA: MOSTRO LISTA DE ALDEANOS");
    } else{
        puts("\nALDEANOSLISTA: ERROR AL MOSTRAR LISTA DE ALDEANOS");
        return false;
    }
    
    return true;
}

bool Civilizacion_respaldar(Civilizacion *civilizacion, FILE *archivo){
    if(civilizacion==NULL){
        puts("CIVILIZACION: NO TIENE MEMORIA");
        return false;
    }
    if(archivo==NULL){
        puts("CIVILIZACION: ARCHIVO NULO");
        return false;
    }
    fprintf(archivo, "%s\n", civilizacion->nombre);

    char nombre_civilizacion[100];
    strcpy(nombre_civilizacion, civilizacion->nombre);
    strcat(nombre_civilizacion, ".txt");

    AldeanosLista_respaldar(civilizacion->aldeanosLista, nombre_civilizacion);

    return true;
}

Civilizacion *Civilizacion_recuperar(FILE *archivo){
    if(archivo==NULL){
        puts("CIVILIZACION: ARCHIVO NULO");
        return NULL;
    }
    char buffer[100];
    fgets(buffer,100,archivo);
    if(feof(archivo))return NULL;
    buffer[strlen(buffer)-1] = '\0';
    
    Civilizacion *civilizacion = Civilizacion_init(buffer);

    char nombre_civilizacion[100];
    strcpy(nombre_civilizacion, civilizacion->nombre);
    strcat(nombre_civilizacion, ".txt");
    AldeanosLista_recuperar(civilizacion->aldeanosLista,nombre_civilizacion);
    return civilizacion;
    }

#endif