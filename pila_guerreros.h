#ifndef PILA_GUERREROS_H
#define PILA_GUERREROS_H

#include "guerrero.h"


struct nodo
{
    Guerrero *dato;
    struct nodo *siguiente;
};
typedef struct nodo Nodo;

Nodo *Nodo_init(Guerrero *dato){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));

    if(nodo == NULL){
        puts("ERROR AL RESERVAR MEMORIA");
        return NULL;
    }
    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;
}

struct pila
{
    Nodo *raiz;
    size_t cantidad;
};
typedef struct pila Pila;

Pila *Pila_init(){
    Pila *pila = (Pila*)malloc(sizeof(Pila));
    if(pila == NULL){
        puts("PILA DE GUERREROS: ERROR AL RESERVAR MEMORIA");
        return NULL;
    }
    pila->raiz = NULL;
    pila->cantidad = 0;

    return pila;
}

bool Pila_apilar(Pila *pila, Guerrero *dato){
    if(pila == NULL){
        puts("PILA DE GUERREROS NO TIENE MEMORIA");
        return false;
    }
    Nodo *nuevo = Nodo_init(dato);
    nuevo->siguiente = pila->raiz;
    pila->raiz = nuevo;
    pila->cantidad++;

    return true;
}


bool Pila_mostrar(Pila *pila){
    if(pila == NULL){
        puts("\nPILA DE GUERREROS: NO TIENE MEMORIA");
        return false;
    }
    printf("\nCANTIDAD DE GUERREROS: %zu\n\n", pila->cantidad);
    Nodo *temp = pila->raiz;

    while(temp != NULL){
        Guerrero_mostrar(temp->dato);
        temp = temp->siguiente; // ++
    }
    return true;
}

bool Pila_vacia(Pila *pila){
    if(pila == NULL){
        puts("PILA DE GURERREROS NO TIENE MEMORIA");
        exit(1);
    }
    return pila->cantidad == 0;
}

bool Pila_desapilar(Pila *pila){
    if(pila == NULL){
        puts("PILA DE GUERREROS NO TIENE MEMORIA");
        return false;
    }
    if(Pila_vacia(pila)){
        puts("PILA DE GUERREROS: VACIA");
        return false;
    }
    Nodo *temp = pila->raiz;
    pila->raiz = temp->siguiente;
    free(temp);
    temp = NULL;
    pila->cantidad--;
    return true;
}

Pila *Pila_free(Pila *pila){
    Pila_desapilar(pila);

    free(pila);
    pila = NULL;
    return pila;
}

Guerrero *Pila_tope(Pila *pila){
    if(pila==NULL){
        puts("PILA DE GUERREROS NO TIENE MEMORIA");
        return NULL;
    }
    if(Pila_vacia(pila)){
        puts("PILA DE GUERREROS VACIA");
        return NULL;
    }
    return pila->raiz->dato;
}

typedef Pila PilaGuerreros;
#define PilaGuerreros_init Pila_init
#define PilaGuerreros_free Pila_free
#define PilaGuerreros_apilar Pila_apilar
#define PilaGuerreros_desapilar Pila_desapilar
#define PilaGuerreros_mostrar Pila_mostrar
#define PilaGuerreros_vacia Pila_vacia
#define PilaGuerreros_tope Pila_tope


#endif