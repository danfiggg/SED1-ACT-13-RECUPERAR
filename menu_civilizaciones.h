#ifndef MENU_CIVILIZACIONES_H
#define MENU_CIVILIZACIONES_H

#include "civilizaciones.h"
#include "menu_aldeano.h"
#include "puerto.h"
#include "barco.h"
#include "menu_barco.h"
#include "lista_aldeanos.h"

#define pause system( "read -n 1 -s -p \"Presione cualquier tecla para continuar...\"" );
#define clear system("clear")

void menu_civilizaciones(Civilizaciones *civilizaciones){

    typedef enum{
        SALIR = 0,
        INSERTAR_INICIO,
        INSERTAR_FINAL,
        MOSTRAR,
        ELIMINAR_INICIO,
        ELIMINAR_FINAL,
        BUSCAR,
        RESPALDAR,
        RECUPERAR
    }MENU_CIVILIZACIONES;

    int op;
    Civilizacion *civilizacion;
    

    do{
        puts("\t\t| MENU CIVILIZACIONES |\n");
        puts("[1] INSERTAR AL INICIO");
        puts("[2] INSERTAR AL FINAL");
        puts("[3] MOSTRAR");
        puts("[4] ELIMINAR AL INICIO");
        puts("[5] ELIMINAR AL FINAL");
        puts("[6] BUSCAR");
        puts("[7] RESPALDAR");
        puts("[8] RECUPERAR");
        puts("[0] SALIR\n");
        printf("INGRESA LA OPCION A EJECUTAR: ");
        scanf("%i", &op);
        while(getchar() != '\n');

        switch (op)
        {
        case INSERTAR_INICIO:
            clear;
            civilizacion = Civilizacion_capturar();
            if(civilizacion==NULL){
                puts("CIVILIZACION NO TIENE MEMORIA");
                continue;
            }
            if(Civilizaciones_insertar_inicio(civilizaciones, civilizacion)){
                puts("CIVILIZACIONES: SE INSERTO AL INICIO CIVILIZACION");
            }else{
                puts("CIVILIZACIONES: ERROR AL INSERTAR AL INICIO CIVILIZACION");
            }
            pause; clear;
            break;
        case INSERTAR_FINAL:
            clear;
            civilizacion = Civilizacion_capturar();
            if(civilizacion==NULL){
                puts("CIVILIZACION NO TIENE MEMORIA");
                continue;
            }
            if(Civilizaciones_insertar_final(civilizaciones, civilizacion)){
                puts("CIVILIZACIONES: SE INSERTO AL FINAL CIVILIZACION");
            }else{
                puts("CIVILIZACIONES: ERROR AL INSERTAR AL FINAL CIVILIZACION");
            }
            pause; clear;
            break;
        case MOSTRAR:
            clear;
            if(Civilizaciones_mostrar(civilizaciones)){
                puts("CIVILIZACIONES: SE MOSTRARON CIVILIZACIONES");
            } else{
                puts("CIVILIZACIONES: ERROR AL MOSTRAR CIVILIZACIONES");
            }
            pause; clear;
            break;
        case ELIMINAR_INICIO:
            clear;
            if(Civilizaciones_eliminar_inicio(civilizaciones)){
                puts("CIVILIZACIONES: ELIMINO AL INICIO CIVILIZACION");
            }else{
                puts("CIVILIZACIONES: ERROR AL ELIMINAR AL INICIO CIVILIZACION");
            }
            pause; clear;   
            break;
        case ELIMINAR_FINAL:
            clear;
            if(Civilizaciones_eliminar_final(civilizaciones)){
                puts("CIVILIZACIONES: ELIMINO AL FINAL CIVILIZACION");
            }else{
                puts("CIVILIZACIONES: ERROR AL ELIMINAR AL FINAL CIVILIZACION");
            }
            pause; clear;
            break;
        case BUSCAR:
            clear;
            puts("\t\t| BUSCADOR DE CIVILIZACION |\n");
            char *nombre = leerCadena("Nombre de la civilizacion: ");

            civilizacion = Civilizaciones_buscar(civilizaciones, nombre);

            if(civilizacion==NULL){
                printf("CIVILIZACIONES: NO SE ENCONTRO LA CIVILIZACION\n");
                pause; clear;
                continue;
            }
            printf("\nSE ENCONTRO LA CIVILIZACION\n\n");
            pause; clear;
            menu_aldeano(civilizacion);
            pause; clear;
            break;
        case RESPALDAR:
            clear;
            if(Civilizaciones_respaldar(civilizaciones)){
                puts("CIVILIZACIONES: RESPALDO REALIZADO");
            }else{
                puts("CIVILIZACIONES: ERROR AL CREAR RESPALDO");
            }
            pause; clear;
            break;
        case RECUPERAR:
            clear;
            if(Civilizaciones_recuperar(civilizaciones)){
                puts("CIVILIZACIONES: RECUPERAR REALIZADO");
            }else{
                puts("CIVILIZACIONES: ERROR AL RECUPERAR");
            }
            pause; clear;
            break;
        case SALIR:
            puts("\nHASTA PRONTO");
            break;
        default:
            puts("\nELIGE UNA OPCION CORRECTA");
            pause; clear;
            break;
        }

    }while(op!=SALIR);
}

#endif