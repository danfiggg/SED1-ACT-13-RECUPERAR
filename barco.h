#ifndef BARCO_H
#define BARCO_H

#include "pila_guerreros.h"

struct barco {
	int id;
	float combustible;
	float velocidad;
	float armadura;
	PilaGuerreros *guerreros;
};
typedef struct barco Barco;

Barco *Barco_init(int id, float combustible, float velocidad, float armadura){
    Barco *barco = (Barco*)malloc(sizeof(Barco));
    if(barco != NULL){
        barco->guerreros = Pila_init();
        barco->id = id;
        barco->combustible = combustible;
        barco->velocidad = velocidad;
        barco->armadura = armadura;
    }
    return barco;
}

Barco *Barco_free(Barco *barco){
    if(barco==NULL){
        puts("EL BARCO NO TIENE MEMORIA");
        return barco;
    }
    barco->guerreros = PilaGuerreros_free(barco->guerreros);
    free(barco);
    barco = NULL;
    return barco;
}

Barco *Barco_capturar(){
    int id = leerSize_t("ID: ");
	float combustible = leerFloat("Combustible (0.0 - 100.0): ");
	float velocidad = leerFloat("Velocidad (0.0 - 14.0): ");
	float armadura = leerFloat("Armadura (0.0 - 100.0): ");

    Barco *barco = Barco_init(id,combustible,velocidad,armadura);
    return barco;
}

bool Barco_mostrar(Barco *barco){
    if(barco == NULL){
        puts("BARCO NO TIENE MEMORIA");
        return false;
    }
    printf("---------------------\n\n");
    printf("Barco: %i\n", barco->id);
    printf("Combustible: %.2f\n", barco->combustible);
    printf("Velocidad: %.2f\n", barco->velocidad);
    printf("Armadura: %.2f\n", barco->armadura);
    
    if(PilaGuerreros_mostrar(barco->guerreros)){
        puts("\nGUERREROS: MOSTRO LISTA DE GUERREROS");
    }
    else{
        puts("\nGUERREROS: ERROR AL MOSTRAR LISTA");
        return false;
    }
    return true;
}

#endif