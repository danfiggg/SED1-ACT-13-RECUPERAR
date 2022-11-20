#ifndef PUERTO_H
#define PUERTO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pila_guerreros.h"
#include "barco.h"

struct nodo_doble1
{
    Barco *dato;
    struct nodo_doble1 *siguiente;
    struct nodo_doble1 *anterior;
};
typedef struct nodo_doble1 NodoDoble1;

NodoDoble1 *NodoDoble_init1(Barco *dato){
    NodoDoble1 *nodo = (NodoDoble1*)malloc(sizeof(NodoDoble1));

    if(nodo == NULL){
        puts("ERROR AL RESERVAR MEMORIA");
        return NULL;
    }
    nodo->dato = dato;
    nodo->siguiente = NULL;
    nodo->anterior = NULL;
    return nodo;
}

NodoDoble1 *NodoDoble1_free(NodoDoble1 *nodo_doble1){
    if(nodo_doble1!=NULL){
        Barco_free(nodo_doble1->dato);
        nodo_doble1->dato = NULL;
        free(nodo_doble1);
        nodo_doble1=NULL;
    }
    return nodo_doble1;
}

struct listaligadadoble1
{
    NodoDoble1 *inicio;
    NodoDoble1 *final;
    size_t cantidad;
};
typedef struct listaligadadoble1 ListaLigadaDoble1;

ListaLigadaDoble1 *ListaLigadaDoble_init1(){
    ListaLigadaDoble1 *listaLigadaDoble1 = (ListaLigadaDoble1*)malloc(sizeof(ListaLigadaDoble1));
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA DOBLE: ERROR AL RESERVAR MEMORIA");
        return NULL;
    }
    listaLigadaDoble1->inicio = NULL;
    listaLigadaDoble1->final = NULL;
    listaLigadaDoble1->cantidad = 0;

    return listaLigadaDoble1;
}

bool ListaLigadaDoble_vacia1(ListaLigadaDoble1 *listaLigadaDoble1){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA");
        exit(1);
    }
    return listaLigadaDoble1->cantidad == 0;
}

bool ListaLigadaDoble_insertar_inicio1(ListaLigadaDoble1 *listaLigadaDoble1, Barco *dato){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA DOBLE NO TIENE MEMORIA");
        return false;
    }
    NodoDoble1 *nuevo = NodoDoble_init1(dato);
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->inicio = nuevo;
        listaLigadaDoble1->final = nuevo;
        listaLigadaDoble1->cantidad++;
        return true;
    }
    nuevo->siguiente = listaLigadaDoble1->inicio;
    listaLigadaDoble1->inicio->anterior = nuevo;
    listaLigadaDoble1->inicio = nuevo;
    listaLigadaDoble1->cantidad++;

    return true;
}

bool ListaLigadaDoble_regresar_inicio(ListaLigadaDoble1 *listaLigadaDoble1, NodoDoble1 *nuevo){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA DOBLE NO TIENE MEMORIA");
        return false;
    }
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->inicio = nuevo;
        listaLigadaDoble1->final = nuevo;
        listaLigadaDoble1->cantidad++;
        return true;
    }
    nuevo->siguiente = listaLigadaDoble1->inicio;
    listaLigadaDoble1->inicio->anterior = nuevo;
    listaLigadaDoble1->inicio = nuevo;
    listaLigadaDoble1->cantidad++;

    return true;
}

bool ListaLigadaDoble_insertar_final1(ListaLigadaDoble1 *listaLigadaDoble1, Barco *dato){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA DOBLE NO TIENE MEMORIA");

        return false;
    }
    NodoDoble1 *nuevo = NodoDoble_init1(dato);
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->inicio = nuevo;
        listaLigadaDoble1->final = nuevo;
        listaLigadaDoble1->cantidad++;

        return true;
    }
    nuevo->anterior = listaLigadaDoble1->final;
    listaLigadaDoble1->final->siguiente = nuevo;
    listaLigadaDoble1->final = nuevo;

    listaLigadaDoble1->cantidad++;

    return true;
}

bool ListaLigadaDoble_regresar_final(ListaLigadaDoble1 *listaLigadaDoble1, NodoDoble1 *nuevo){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA DOBLE NO TIENE MEMORIA");

        return false;
    }
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->inicio = nuevo;
        listaLigadaDoble1->final = nuevo;
        listaLigadaDoble1->cantidad++;

        return true;
    }
    nuevo->anterior = listaLigadaDoble1->final;
    listaLigadaDoble1->final->siguiente = nuevo;
    listaLigadaDoble1->final = nuevo;

    listaLigadaDoble1->cantidad++;

    return true;
}

bool ListaLigadaDoble_mostrar1(ListaLigadaDoble1 *listaLigadaDoble1){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA DOBLE: NO TIENE MEMORIA");
        return false;
    }

    printf("CANTIDAD DE BARCOS: %zu\n\n", listaLigadaDoble1->cantidad);
    NodoDoble1 *temp = listaLigadaDoble1->inicio;
    
    while(temp != NULL){
        if(Barco_mostrar(temp->dato)){
            puts("BARCO: SE MOSTRO BARCO\n");
        }else{
            puts("BARCO: ERROR AL MOSTRAR BARCO\n");
        }
        temp = temp->siguiente; // ++
    }

    return true;
}

bool ListaLigadaDoble_eliminar_inicio1(ListaLigadaDoble1 *listaLigadaDoble1){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA");
        return false;
    }
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        puts("LISTA LIGADA DOBLE: VACIA");
        return false;
    }
    NodoDoble1 *temp = listaLigadaDoble1->inicio;
    listaLigadaDoble1->inicio = temp->siguiente;
    listaLigadaDoble1->cantidad--;
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->final = NULL;
    } else{
        listaLigadaDoble1->inicio->anterior = NULL;
    }
    Barco_free(temp->dato);
    free(temp);
    temp = NULL;
    
    return true;
}

NodoDoble1 *Puerto_desligar_inicio(ListaLigadaDoble1 *listaLigadaDoble1){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA"); 
        return NULL;
    }
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        puts("LISTA LIGADA DOBLE: VACIA");
        return NULL;
    }
    NodoDoble1 *temp = listaLigadaDoble1->inicio;
    listaLigadaDoble1->inicio = temp->siguiente;
    listaLigadaDoble1->cantidad--;
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->final = NULL;
    } else{
        listaLigadaDoble1->inicio->anterior = NULL;
    }
    //Barco_free(temp->dato);
    //free(temp);
    temp->siguiente = NULL;
    temp->anterior = NULL;
    
    return temp;
}

bool ListaLigadaDoble_eliminar_final1(ListaLigadaDoble1 *listaLigadaDoble1){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA");
        return false;
    }
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        puts("LISTA LIGADA DOBLE: VACIA");
        return false;
    }
    NodoDoble1 *temp = listaLigadaDoble1->final;

    if(temp->anterior!=NULL){
        temp->anterior->siguiente = NULL;
        listaLigadaDoble1->final=temp->anterior;
    }

    listaLigadaDoble1->cantidad--;
    Barco_free(temp->dato);
    free(temp);
    temp = NULL;
    
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->final = NULL;
        listaLigadaDoble1->inicio = NULL;
    }

    return true;
}

NodoDoble1 *Puerto_desligar_final(ListaLigadaDoble1 *listaLigadaDoble1){
    if(listaLigadaDoble1 == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA");
        return false;
    }
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        puts("LISTA LIGADA DOBLE: VACIA");
        return false;
    }
    NodoDoble1 *temp = listaLigadaDoble1->final;

    if(temp->anterior!=NULL){
        temp->anterior->siguiente = NULL;
        listaLigadaDoble1->final=temp->anterior;
    }

    listaLigadaDoble1->cantidad--;
    //Barco_free(temp->dato);
    //free(temp);
    //temp = NULL;
    
    if(ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        listaLigadaDoble1->final = NULL;
        listaLigadaDoble1->inicio = NULL;
    }
    temp->siguiente = NULL;
    temp->anterior = NULL;

    return temp;
}


ListaLigadaDoble1 *ListaLigadaDoble_free1(ListaLigadaDoble1 *listaLigadaDoble1){
    if(listaLigadaDoble1 == NULL){
        puts("NO TIENE MEMORIA");
        return NULL;
    }
    while(!ListaLigadaDoble_vacia1(listaLigadaDoble1)){
        ListaLigadaDoble_eliminar_inicio1(listaLigadaDoble1);
    }

    free(listaLigadaDoble1);
    listaLigadaDoble1 = NULL;

    return NULL;
}



typedef ListaLigadaDoble1 Puerto;
#define Puerto_init ListaLigadaDoble_init1
#define Puerto_free ListaLigadaDoble_free1
#define Puerto_insertar_inicio ListaLigadaDoble_insertar_inicio1
#define Puerto_insertar_final ListaLigadaDoble_insertar_final1
#define Puerto_mostrar ListaLigadaDoble_mostrar1
#define Puerto_eliminar_inicio ListaLigadaDoble_eliminar_inicio1
#define Puerto_eliminar_final ListaLigadaDoble_eliminar_final1
#define Puerto_regresar_inicio ListaLigadaDoble_regresar_inicio
#define Puerto_regresar_final ListaLigadaDoble_regresar_final


Puerto *Puerto_buscar(Puerto *puerto, int *id){
    if(puerto == NULL){
        puts("BARCOS: NO TIENE MEMORIA");
        return NULL;
    }
    NodoDoble1 *temp = puerto->inicio;
    

    while(temp != NULL){
        if(id == temp->dato->id){
            return temp->dato;
        }
        temp = temp->siguiente;
    }
    return NULL;
}



#endif