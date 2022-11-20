#ifndef LISTA_ALDEANOS_H
#define LISTA_ALDEANOS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "aldeano.h"

#define CAP 3

struct lista_aldeanos
{
    Aldeano **aldeanos; 
    size_t cant;
    size_t cap;
};

typedef struct lista_aldeanos AldeanosLista;

AldeanosLista *AldeanosLista_init(){
    AldeanosLista *aldeanosLista = (AldeanosLista*)malloc(sizeof(AldeanosLista));
        if(aldeanosLista != NULL){
            aldeanosLista->aldeanos = (Aldeano**)malloc(sizeof(Aldeano*)*CAP);
            if(aldeanosLista->aldeanos ==NULL){
                puts("ERROR AL RESERVAR ARREGLO");
                exit(1);
            }
            aldeanosLista->cant = 0;
            aldeanosLista->cap = CAP;
        }
        return aldeanosLista;
}

AldeanosLista *AldeanosLista_free(AldeanosLista *aldeanosLista){
    if(aldeanosLista != NULL){
        if(aldeanosLista->aldeanos != NULL){
            for(size_t i=0; i < aldeanosLista->cant; i++){
                free(aldeanosLista->aldeanos[i]);
            }
            free(aldeanosLista->aldeanos);
            aldeanosLista->aldeanos = NULL;
            free(aldeanosLista);
            aldeanosLista = NULL;
        }
    }
    return aldeanosLista;
}

bool AldeanosLista_mostrar(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;

    if(aldeanosLista != NULL){
        printf("\nCANTIDAD DE ALDEANOS: %zu CAPACIDAD DE ALDEANOS: %zu\n", aldeanosLista->cant, aldeanosLista->cap);
        for(size_t i = 0; i < aldeanosLista->cant; i++){
            Aldeano_mostrar(aldeanosLista->aldeanos[i]);
        }
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_mostrar_lista(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    const char nom[] = "Nombre:";
    const char sal[] = "Salud:";
    const char eda[] = "Edad:";

    if(aldeanosLista != NULL){
        printf("%12s %8s %8s\n\n", nom, eda, sal);
        for(size_t i = 0; i < aldeanosLista->cant; i++){
            Aldeano_mostrar_lista(aldeanosLista->aldeanos[i]);
        }
        printf("\n\nCANTIDAD: %zu, CAPACIDAD: %zu\n", aldeanosLista->cant,aldeanosLista->cap);
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_llena(AldeanosLista *aldeanosLista){
    if(aldeanosLista == NULL){
        puts("NO EXISTE LISTA DE ALDEANOS");
        exit(1);
    }
    return aldeanosLista->cant == aldeanosLista->cap;
}

bool AldeanosLista_expandir(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;

    if(aldeanosLista != NULL){
        size_t nuevaCap = aldeanosLista->cant + CAP;
        AldeanosLista *temp_p = (Aldeano**)realloc(aldeanosLista->aldeanos,sizeof(Aldeano*)*nuevaCap);
            if(temp_p != NULL){
                puts("EXPANDIENDO CAPACIDAD DE ALDEANOS");
                aldeanosLista->aldeanos = temp_p;
                aldeanosLista->cap = nuevaCap;
                NO_ERROR = true;
            }
            else{
                puts("ERROR AL EXPANDIR CAPACIDAD DE ALDEANOS");
            }
    }
    return NO_ERROR;
}

bool AldeanosLista_vacia(AldeanosLista *aldeanosLista){
    if(aldeanosLista == NULL){
        puts("NO EXISTEN ALDEANOS REGISTRADOS");
        exit(1);
    }
    return aldeanosLista->cant == 0;
}

bool AldeanosLista_agregar_inicio(AldeanosLista *aldeanosLista, Aldeano *aldeano){
    bool NO_ERROR = false;

    if(aldeanosLista != NULL){
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        for(size_t i = aldeanosLista->cant; i > 0; i--){
            aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
        }
        aldeanosLista->aldeanos[0] = aldeano;
        aldeanosLista->cant++;
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_agregar_final(AldeanosLista *aldeanosLista, Aldeano *aldeano){
    bool NO_ERROR = false; 

    if(aldeanosLista != NULL){
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        aldeanosLista->aldeanos[aldeanosLista->cant] = aldeano;
        aldeanosLista->cant++;
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_insertar(AldeanosLista *aldeanosLista, size_t pos, Aldeano *aldeano){
    bool NO_ERROR = false;

    if(aldeanosLista != NULL){
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        for(size_t i= aldeanosLista->cant; i>pos; i--){
        aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
        }
        aldeanosLista->aldeanos[pos] = aldeano;
        aldeanosLista->cant++;
        NO_ERROR = true;
        
    }
    return NO_ERROR;
}

bool AldeanosLista_eliminar_inicio(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;

    if(aldeanosLista != NULL){
        if(!AldeanosLista_vacia(aldeanosLista)){
            aldeanosLista->aldeanos[0] = Aldeano_free(aldeanosLista->aldeanos[0]);
            if(aldeanosLista->aldeanos[0] == NULL){
                puts("\nSE LIBERO ALDEANO");
            }
            else{
                puts("ERROR AL LIBERAR ALDEANO");
            }
            for(size_t i = 0; i < aldeanosLista->cant-1; i++){
                aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
            }
            aldeanosLista->cant--;
            NO_ERROR = true;
        }
    }
    return NO_ERROR;
}

bool AldeanosLista_eliminar_final(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false; 

    if(aldeanosLista != NULL){
        if(!AldeanosLista_vacia(aldeanosLista)){
            aldeanosLista->aldeanos[aldeanosLista->cant-1] = Aldeano_free(aldeanosLista->aldeanos[aldeanosLista->cant-1]);
            if(aldeanosLista->aldeanos[aldeanosLista->cant-1] == NULL){
                puts("\nSE LIBERO ALDEANO");
                aldeanosLista->cant--;
                NO_ERROR = true;
            }
            else{
                puts("ERROR AL LIBERAR ALDEANO");
            }
        }
    }
    return NO_ERROR;
}

bool AldeanosLista_eliminar(AldeanosLista *aldeanosLista, size_t pos){
    bool NO_ERROR = false; 
    
    if(aldeanosLista != NULL){
        if(!AldeanosLista_vacia(aldeanosLista)){
            aldeanosLista->aldeanos[pos] = Aldeano_free(aldeanosLista->aldeanos[pos]);
            if(aldeanosLista->aldeanos[pos] == NULL){
                puts("\nSE LIBERO ALDEANO");
            }
            else{
                puts("ERROR AL LIBERAR ALDEANO");
            }
            for(size_t i = pos; i < aldeanosLista->cant-1; i++){
                aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
            }
            aldeanosLista->cant--;
            NO_ERROR = true;
        }
    }
    return NO_ERROR;
}

bool AldeanosLista_respaldar(AldeanosLista *aldeanosLista, char *nombre_civilizacion){
    if(aldeanosLista==NULL){
        puts("ALDEANOSLISTA: NO TIENE MEMORIA");
        return false;
    }
    FILE *archivo = fopen(nombre_civilizacion, "w");
    if(archivo==NULL){
        puts("ALDEANOSLISTA: ERROR AL CREAR ARCHIVO");
        return false;
    }
    for(size_t i = 0; i < aldeanosLista->cant; i++){
        Aldeano_respaldar(aldeanosLista->aldeanos[i], archivo);
    }
    fclose(archivo);
}

bool AldeanosLista_recuperar(AldeanosLista *aldeanosLista, char *nombre_civilizacion){
    if(aldeanosLista==NULL){
        puts("ALDEANOSLISTA: NO TIENE MEMORIA");
        return false;
    }
    FILE *archivo = fopen(nombre_civilizacion, "r");
    if(archivo==NULL){
        puts("ALDEANOSLISTA: ERROR AL ABRIR ARCHIVO");
        return false;
    }
    while(true){
        Aldeano *aldeano = Aldeano_recuperar(archivo);
        if(aldeano==NULL) break;
        AldeanosLista_agregar_final(aldeanosLista, aldeano);
    }
    fclose(archivo);
    return true;
}

#endif