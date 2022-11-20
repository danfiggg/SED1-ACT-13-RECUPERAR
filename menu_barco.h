#ifndef MENU_BARCO_H
#define MENU_BARCO_H

#include <stdio.h>
#include <stdlib.h>
#define clear system("clear")
#define pause system( "read -n 1 -s -p \"Presione cualquier tecla para continuar...\"" );

#include "pila_guerreros.h"
#include "guerrero.h"
#include "puerto.h"

typedef enum{
    SALIIR = 0,
    AGREGAR_GUERRERO,
    ELIMINAR_GUERRERO,
    MOSTRAR_ULTIMO,
    MOSTRARR
}MENU_BARCO;

void menu_barco(Barco *barco){
    int opc;
    Guerrero *guerrero;

    do{

        printf("\t\t| MENU DE BARCO: %i |\n\n", barco->id);
        puts("[1] AGREGAR GUERRERO");
        puts("[2] ELIMINAR GUERRERO");
        puts("[3] MOSTRAR ULTIMO GUERRERO");
        puts("[4] MOSTRAR TODOS LOS GUERREROS");
        puts("[0] SALIR\n");
        printf("INGRESA UNA OPCION: ");
        scanf("%i", &opc);
        while (getchar() != '\n');

        switch (opc)
        {
        case AGREGAR_GUERRERO:
            clear;
            guerrero = Guerrero_capturar();
            if(guerrero==NULL){
                puts("CIVILIZACION NO TIENE MEMORIA");
                continue;
            }
            if(PilaGuerreros_apilar(barco->guerreros, guerrero)){
                puts("PILAGUERREROS: SE INSERTO AL INICIO GUERRERO");
            }else{
                puts("PILAGUERREROS: ERROR AL INSERTAR AL INICIO GUERRERO");
            }
            pause; clear;
            break;
        case ELIMINAR_GUERRERO:
            clear;
            if(PilaGuerreros_vacia(barco->guerreros)){
                puts("LA PILA ESTA VACIA");
                continue;
            }else{
                PilaGuerreros_desapilar(barco->guerreros);
                printf("\nSE ELIMINO GUERRERO\n");
            }
            pause; clear;
            break;
        case MOSTRAR_ULTIMO:
            clear;
            Guerrero_mostrar(PilaGuerreros_tope(barco->guerreros));
            pause; clear;
            break;
        case MOSTRARR:
            clear;
            PilaGuerreros_mostrar(barco->guerreros);
            pause; clear;
            break;
        case SALIIR:
            puts("\nREGRESANDO AL MENU DE CIVILIZACION...");
            break;
        default:
            puts("\n!! INGRESA UNA OPCION VALIDA !!");
            break;
        }
    }while(opc!=SALIIR);
}


#endif
