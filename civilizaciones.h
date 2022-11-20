#ifndef CIVILIZACIONES_H
#define CIVILIZACIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "civilizacion.h"

struct nodo_doble2
{
    Civilizacion *dato;
    struct nodo_doble2 *siguiente;
    struct nodo_doble2 *anterior;
};
typedef struct nodo_doble2 NodoDoble2;

NodoDoble2 *NodoDoble2_init(Civilizacion *dato){
    NodoDoble2 *nodo = (NodoDoble2*)malloc(sizeof(NodoDoble2));

    if(nodo == NULL){
        puts("ERROR AL RESERVAR MEMORIA");
        return NULL;
    }
    nodo->dato = dato;
    nodo->siguiente = NULL;
    nodo->anterior = NULL;
    return nodo;
}

struct listaligadadoble
{
    NodoDoble2 *inicio;
    NodoDoble2 *final;
    size_t cantidad;
};
typedef struct listaligadadoble ListaLigadaDoble;

ListaLigadaDoble *ListaLigadaDoble_init(){
    ListaLigadaDoble *listaLigadaDoble = (ListaLigadaDoble*)malloc(sizeof(ListaLigadaDoble));
    if(listaLigadaDoble == NULL){
        puts("LISTA LIGADA DOBLE: ERROR AL RESERVAR MEMORIA");
        return NULL;
    }
    listaLigadaDoble->inicio = NULL;
    listaLigadaDoble->final = NULL;
    listaLigadaDoble->cantidad = 0;

    return listaLigadaDoble;
}

bool ListaLigadaDoble_vacia(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA");
        exit(1);
    }
    return listaLigadaDoble->cantidad == 0;
}

bool ListaLigadaDoble_insertar_inicio(ListaLigadaDoble *listaLigadaDoble, Civilizacion *dato){
    if(listaLigadaDoble == NULL){
        puts("LISTA LIGADA DOBLE NO TIENE MEMORIA");
        return false;
    }
    NodoDoble2 *nuevo = NodoDoble2_init(dato);
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = nuevo;
        listaLigadaDoble->final = nuevo;
        listaLigadaDoble->cantidad++;
        return true;
    }
    nuevo->siguiente = listaLigadaDoble->inicio;
    listaLigadaDoble->inicio->anterior = nuevo;
    listaLigadaDoble->inicio = nuevo;
    listaLigadaDoble->cantidad++;

    return true;
}

bool ListaLigadaDoble_insertar_final(ListaLigadaDoble *listaLigadaDoble, Civilizacion *dato){
    if(listaLigadaDoble == NULL){
        puts("LISTA LIGADA DOBLE NO TIENE MEMORIA");

        return false;
    }
    NodoDoble2 *nuevo = NodoDoble2_init(dato);
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = nuevo;
        listaLigadaDoble->final = nuevo;
        listaLigadaDoble->cantidad++;

        return true;
    }
    nuevo->anterior = listaLigadaDoble->final;
    listaLigadaDoble->final->siguiente = nuevo;
    listaLigadaDoble->final = nuevo;

    listaLigadaDoble->cantidad++;

    return true;
}

bool ListaLigadaDoble_mostrar(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("LISTA LIGADA DOBLE: NO TIENE MEMORIA");
        return false;
    }

    printf("CANTIDAD DE CIVILIZACIONES: %zu\n\n", listaLigadaDoble->cantidad);
    
    NodoDoble2 *temp = listaLigadaDoble->inicio;
    
    while(temp != NULL){
        if(Civilizacion_mostrar(temp->dato)){
            puts("CIVILIZACION: SE MOSTRO CIVILIZACION\n");
        }else{
            puts("CIVILIZACION: ERROR AL MOSTRAR CIVILIZACION\n");
        }
        temp = temp->siguiente; // ++
    }

    return true;
}

bool ListaLigadaDoble_eliminar_inicio(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA");
        return false;
    }
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        puts("LISTA LIGADA DOBLE: VACIA");
        return false;
    }
    NodoDoble2 *temp = listaLigadaDoble->inicio;
    listaLigadaDoble->inicio = temp->siguiente;
    listaLigadaDoble->cantidad--;
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->final = NULL;
    } else{
        listaLigadaDoble->inicio->anterior = NULL;
    }
    Civilizacion_free(temp->dato);
    free(temp);
    temp = NULL;

    return true;
}

bool ListaLigadaDoble_eliminar_final(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("LISTA LIGADA NO TIENE MEMORIA");
        return false;
    }
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        puts("LISTA LIGADA DOBLE: VACIA");
        return false;
    }
    NodoDoble2 *temp = listaLigadaDoble->final;

    if(temp->anterior!=NULL){
        temp->anterior->siguiente = NULL;
        listaLigadaDoble->final=temp->anterior;
    }

    //listaLigadaDoble->final = temp->anterior;
    //listaLigadaDoble->final->siguiente = NULL;
    listaLigadaDoble->cantidad--;
    Civilizacion_free(temp->dato);
    free(temp);
    temp = NULL;
    
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->final = NULL;
        listaLigadaDoble->inicio = NULL;
    }

    return true;
}



ListaLigadaDoble *ListaLigadaDoble_free(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("NO TIENE MEMORIA");
        return NULL;
    }
    while(!ListaLigadaDoble_vacia(listaLigadaDoble)){
        ListaLigadaDoble_eliminar_inicio(listaLigadaDoble);
    }

    free(listaLigadaDoble);
    listaLigadaDoble = NULL;

    return NULL;
}



typedef ListaLigadaDoble Civilizaciones;
#define Civilizaciones_init ListaLigadaDoble_init
#define Civilizaciones_free ListaLigadaDoble_free
#define Civilizaciones_insertar_inicio ListaLigadaDoble_insertar_inicio
#define Civilizaciones_insertar_final ListaLigadaDoble_insertar_final
#define Civilizaciones_mostrar ListaLigadaDoble_mostrar
#define Civilizaciones_eliminar_inicio ListaLigadaDoble_eliminar_inicio
#define Civilizaciones_eliminar_final ListaLigadaDoble_eliminar_final

Civilizaciones *Civilizaciones_buscar(Civilizaciones *civilizaciones, char *nombre){
    if(civilizaciones == NULL){
        puts("CIVILIZACIONES: NO TIENE MEMORIA");
        return NULL;
    }
    NodoDoble2 *temp = civilizaciones->inicio;
    
    while(temp != NULL){
        if(strcmp(nombre, temp->dato->nombre)==0){
            return temp->dato;
        }
        temp = temp->siguiente; // ++
    }
    return NULL;
}

bool Civilizaciones_respaldar(Civilizaciones *civilizaciones){
    if(civilizaciones == NULL){
        puts("CIVILIZACIONES: NO TIENE MEMORIA");
        return false;
    }
    if(civilizaciones->cantidad == 0){
        puts("SELECCIONES: NO HAY SELECCIONES");
        return false;
    }
    FILE *archivo = fopen("civilizaciones.txt", "w");
    if(archivo == NULL){
        puts("CIVILIZACIONES: ERROR AL CREAR ARCHIVO");
        return false;
    }
    NodoDoble2 *temp = civilizaciones->inicio;
    while(temp != NULL){
        Civilizacion_respaldar(temp->dato, archivo);
        temp = temp->siguiente;
    }
    fclose(archivo);
    return true;
}

bool Civilizaciones_recuperar(Civilizaciones *civilizaciones){
    if(civilizaciones==NULL){
        puts("CIVILIZACIONES: NO TIENE MEMORIA");
        return false;
    }
    FILE *archivo = fopen("civilizaciones.txt", "r");

    if(archivo == NULL){
        puts("CIVILIZACIONES: ERROR AL ABRIR ARCHIVO");
        return false;
    }
    while(true){
        Civilizacion *civilizacion = Civilizacion_recuperar(archivo);
        if(civilizacion==NULL){
            break;
        }
        Civilizaciones_insertar_final(civilizaciones, civilizacion);
    }
    fclose(archivo);
    return true;
}

#endif