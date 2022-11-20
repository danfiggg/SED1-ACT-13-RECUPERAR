#ifndef GUERRERO_H
#define GUERRERO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "menu_civilizaciones.h"

const char *tipo[5]={"Ejército", "Caballero" ,"Soldado", "Mercenario", "Militar"};

enum{
    EJERCITO,
    CABALLERO,
    SOLDADO,
    MERCENARIO,
    MILITAR
}MENU_TIPO;

struct guerrero
{
    int id;
    int salud;
    float fuerza;
    float escudo;
    int tipo;
};

typedef struct guerrero Guerrero;

Guerrero *Guerrero_init(int id, int salud, float fuerza, float escudo, int tipo){
    Guerrero *guerrero = (Guerrero*)malloc(sizeof(Guerrero));
    if(guerrero!=NULL){
        guerrero->id = id;
        guerrero->salud = salud;
        guerrero->fuerza = fuerza;
        guerrero->escudo = escudo;
        guerrero->tipo = tipo;
    }
    return guerrero;
}

Guerrero *Guerrero_free(Guerrero *guerrero){
    if(guerrero!=NULL){
        free(guerrero->id);
        guerrero->id = NULL;
        free(guerrero);
        guerrero = NULL;
    }
    return guerrero;
}

Guerrero *Guerrero_capturar(){
    int id = leerSize_t("ID: ");
    int salud = leerSize_t("Salud (0-100): ");
    float fuerza = leerFloat("Fuerza (0.0 - 60.0): ");
    float escudo = leerFloat("Escudo (0.0 - 0.30): ");
    printf("\n[%i] %s\n", EJERCITO, tipo[EJERCITO]);
    printf("[%i] %s\n", CABALLERO, tipo[CABALLERO]);
    printf("[%i] %s\n", SOLDADO, tipo[SOLDADO]);
    printf("[%i] %s\n", MERCENARIO, tipo[MERCENARIO]);
    printf("[%i] %s\n\n", MILITAR, tipo[MILITAR]);
    int tipo = leerSize_t("Tipo de guerrero: ");

    Guerrero *guerrero = Guerrero_init(id,salud,fuerza,escudo,tipo);
    return guerrero;
}

bool Guerrero_mostrar(Guerrero *guerrero){
    bool NO_ERROR = false;

    if(guerrero != NULL){
        
        printf("ID: %i\n", guerrero->id);
        printf("Salud: %i\n", guerrero->salud);
        printf("Fuerza: %.2f\n", guerrero->fuerza);
        printf("Escudo: %.2f\n", guerrero->escudo);
        printf("Tipo: %s\n\n", tipo[guerrero->tipo]);
        

        NO_ERROR = true;
    }
    return NO_ERROR;
}


#endif