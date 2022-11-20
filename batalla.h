#ifndef BATALLA_H
#define BATALLA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "puerto.h"

struct colabarco
{
    NodoDoble1 *inicio; // HEAD
    NodoDoble1 *final; // FINAL
    size_t cantidad;
};
typedef struct colabarco ColaBarco;

ColaBarco *ColaBarco_init(){
    ColaBarco *colabarco = (ColaBarco*)malloc(sizeof(ColaBarco));
    if(colabarco == NULL){
        puts("COLABARCO: ERROR AL RESERVAR MEMORIA");
        return NULL;
    }
    colabarco->inicio = NULL;
    colabarco->final = NULL;
    colabarco->cantidad = 0;

    return colabarco;
}

bool ColaBarco_vacia(ColaBarco *colabarco){
    if(colabarco == NULL){
        puts("COLABARCO: NO TIENE MEMORIA");
        exit(1);
    }
    return colabarco->cantidad == 0;
}


bool ColaBarco_encolar(ColaBarco *colabarco, NodoDoble1 *nuevo){
    if(colabarco == NULL){
        puts("COLABARCO: NO TIENE MEMORIA");

        return false;
    }
    if(ColaBarco_vacia(colabarco)){
        colabarco->inicio = nuevo;
        colabarco->final = nuevo;
        colabarco->cantidad++;

        return true;
    }
    nuevo->anterior = colabarco->final;
    colabarco->final->siguiente = nuevo;
    colabarco->final = nuevo;

    colabarco->cantidad++;

    return true;
}

NodoDoble1 *ColaBarco_desligar(ColaBarco *colabarco){
    if(colabarco == NULL){
        puts("COLABARCO: NO TIENE MEMORIA");
        return false;
    }
    if(ColaBarco_vacia(colabarco)){
        puts("COLABARCO: VACIA");
        return false;
    }
    NodoDoble1 *temp = colabarco->inicio;
    colabarco->inicio = temp->siguiente;
    colabarco->cantidad--;
    if(ColaBarco_vacia(colabarco)){
        colabarco->final = NULL;
    } else{
        colabarco->inicio->anterior = NULL;
    }
    temp->siguiente = NULL;
    temp->anterior = NULL;

    return temp;
}

bool ColaBarco_mostrar(ColaBarco *colabarco){
    if(colabarco == NULL){
        puts("COLABARCO: NO TIENE MEMORIA");
        return false;
    }
    printf("\t\t| BARCOS EN BATALLA |\n\n");
    printf("CANTIDAD BARCOS EN BATALLA: %zu\n\n", colabarco->cantidad);
    NodoDoble1 *temp = colabarco->inicio;
    
    while(temp != NULL){
        if(Barco_mostrar(temp->dato)){
            puts("BARCO: SE MOSTRARON BARCOS EN BATALLA\n");
        }else{
            puts("BARCO: ERROR AL MOSTRAR BARCOS EN BATALLA\n");
        }
        temp = temp->siguiente; // ++
    }
    puts("NULL\n\n");

    return true;
}

bool ColaBarco_desencolar(ColaBarco *colabarco){
    if(colabarco == NULL){
        puts("COLABARCO: NO TIENE MEMORIA");
        return false;
    }
    if(ColaBarco_vacia(colabarco)){
        puts("COLABARCO: VACIA");
        return false;
    }
    NodoDoble1 *temp = colabarco->inicio;
    colabarco->inicio = temp->siguiente;
    colabarco->cantidad--;
    if(ColaBarco_vacia(colabarco)){
        colabarco->final = NULL;
    } else{
        colabarco->inicio->anterior = NULL;
    }

    free(temp);
    temp = NULL;

    return true;
}

ColaBarco *ColaBarco_free(ColaBarco *colabarco){
    if(colabarco == NULL){
        puts("COLABARCO: NO TIENE MEMORIA");
        return NULL;
    }
    while(!ColaBarco_vacia(colabarco)){
        ColaBarco_desencolar(colabarco);
    }

    free(colabarco);
    colabarco = NULL;

    return NULL;
}

Barco *ColaBarco_tomar(ColaBarco *colabarco){
    if(colabarco == NULL){
        puts("COLABARCO: NO TIENE MEMORIA");
        return NULL;
    }
    if(ColaBarco_vacia(colabarco)){
        puts("COLABARCO: VACIA");
        return NULL;
    }
    return colabarco->inicio->dato;

}


#endif