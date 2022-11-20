#ifndef MENU_ALDEANO_H
#define MENU_ALDEANO_H

#include <stdio.h>
#include <stdlib.h>
#define clear system("clear")
#define pause system( "read -n 1 -s -p \"Presione cualquier tecla para continuar...\"" );

#include "lista_aldeanos.h"
#include "menu_civilizaciones.h"
#include "menu_barco.h"
#include "batalla.h"

typedef enum{
    SALIR = 0,
    AGREGAR_INICIO,
    AGREGAR_FINAL,
    INSERTAR,
    MOSTRAR,
    MOSTRAR_LISTA,
    ELIMINAR_INICIO,
    ELIMINAR_FINAL,
    ELIMINAR,
    AGREGAR_BARCO,
    MOSTRAR_BARCO,
    BUSCAR_BARCO,
    ELIMINAR_BARCO_INICIO,
    ELIMINAR_BARCO_FINAL,
    AGREGAR_BATALLA,
    SACAR_BATALLA,
    MOSTRAR_BATALLA
}MENU_ALDEANO;

void menu_aldeano(Civilizacion *civilizacion){
    int opc;
    Aldeano *aldeano;
    Barco *barco;
    NodoDoble1 *dato;
    size_t pos;

    do{
        printf("\t\t| MENU DE CIVILIZACION: %s |\n\n", civilizacion->nombre);
        puts("LISTA DE ALDEANOS\n");
        puts("[1] AGREGAR INICIO");
        puts("[2] AGREGAR FINAL");
        puts("[3] INSERTAR");
        puts("[4] MOSTRAR");
        puts("[5] MOSTRAR LISTA");
        puts("[6] ELIMINAR INICIO");
        puts("[7] ELIMINAR FINAL");
        puts("[8] ELIMINAR\n");
        puts("BARCOS\n");
        puts("[9] AGREGAR BARCO");
        puts("[10] MOSTRAR BARCO");
        puts("[11] BUSCAR BARCO");
        puts("[12] ELIMINAR BARCO AL INICIO");
        puts("[13] ELIMINAR BARCO AL FINAL\n");
        puts("BATALLA\n");
        puts("[14] AGREGAR BARCO A BATALLA");
        puts("[15] SACAR BARCO DE BATALLA");
        puts("[16] MOSTRAR BARCOS DE BATALLA");
        puts("[0] SALIR");
        printf("\nIngresa una opcion: ");
        scanf("%i", &opc);
        while (getchar() != '\n');

        switch (opc)
        {
        case AGREGAR_INICIO:
            clear; 
            aldeano = Aldeano_capturar();
                if(aldeano == NULL){
                    puts("\nERROR AL CAPTURAR ALDEANO");
                continue;
                }
                else puts("\nSE CAPTURO ALDEANO");
                if(AldeanosLista_agregar_inicio(civilizacion->aldeanosLista, aldeano)){
                    puts("SE AGREGO ALDEANO AL INICIO");
                    }
                else puts("ERROR AL AGREGAR ALDEANO AL INICIO");
                
                pause; clear;
            break;
        
        case AGREGAR_FINAL:
            clear; 
            aldeano = Aldeano_capturar();
                if(aldeano == NULL){
                    puts("\nERROR AL CAPTURAR ALDEANO");
                continue;
                }
                else puts("\nSE CAPTURO ALDEANO");
                if(AldeanosLista_agregar_final(civilizacion->aldeanosLista, aldeano)){
                    puts("SE AGREGO ALDEANO AL FINAL");
                    }
                else puts("ERROR AL AGREGAR ALDEANO AL FINAL");
                
                pause; clear;
            break;

        case INSERTAR: 
            clear; 
            aldeano = Aldeano_capturar();
            pos = leerSize_t("Posicion a insertar: ");
                if(aldeano == NULL){
                    puts("\nERROR AL CAPTURAR ALDEANO");
                continue;
                }
                else puts("\nSE CAPTURO ALDEANO");
                if(AldeanosLista_insertar(civilizacion->aldeanosLista, pos, aldeano)){
                    puts("SE INSERTO ALDEANO");
                }
                else puts("ERROR AL INSERTAR ALDEANO");
                pause; clear;
            break;

        case MOSTRAR:
            clear;
            if(AldeanosLista_mostrar(civilizacion->aldeanosLista)) puts("\nSE MOSTRARON ALDEANOS");
            else puts("\nERROR AL MOSTRAR ALDEANOS"); 
            pause; clear;
            break;

        case MOSTRAR_LISTA:
            clear;
            if(AldeanosLista_mostrar_lista(civilizacion->aldeanosLista)) puts("\nSE MOSTRARON ALDEANOS");
            else puts("\nERROR AL MOSTRAR ALDEANOS"); 
            pause; clear;
            break;

        case ELIMINAR_INICIO:
            if(AldeanosLista_eliminar_inicio(civilizacion->aldeanosLista)){
                puts("\nSE ELIMINO ALDEANO INICIO");
                }
            else puts("\nERROR AL ELIMINAR ALDEANO INICIO");
            pause; clear;
            break;

        case ELIMINAR_FINAL: 
            if(AldeanosLista_eliminar_final(civilizacion->aldeanosLista)){
                puts("SE ELIMINO ALDEANO FINAL");
                }
            else puts("ERROR AL ELIMINAR ALDEANO FINAL");
            pause; clear;
            break;

        case ELIMINAR:
            pos = leerSize_t("\nPosicion a eliminar: ");
            if(AldeanosLista_eliminar(civilizacion->aldeanosLista, pos)){
                puts("\nSE ELIMINO ALDEANO");
                }
            else puts("\nERROR AL ELIMINAR ALDEANO");
            pause; clear;
            break;
        case AGREGAR_BARCO:
            clear;
            barco = Barco_capturar();
            if(barco==NULL){
                puts("BARCO NO TIENE MEMORIA");
                continue;
            }
            if(Puerto_insertar_inicio(civilizacion->puerto, barco)){
                puts("PUERTO: SE INSERTO AL INICIO BARCO");
            }else{
                puts("PUERTO: ERROR AL INSERTAR AL INICIO BARCO");
            }
            pause; clear;
            break;
        case MOSTRAR_BARCO:
            clear;
            if(Puerto_mostrar(civilizacion->puerto)){
                puts("PUERTO: SE MOSTRARON BARCOS");
            } else{
                puts("PUERTO: ERROR AL MOSTRAR BARCOS");
            }
            pause; clear;
            break;
        case BUSCAR_BARCO:
            clear;
            puts("\t\t| BUSCADOR DE BARCO |\n");
            int *id = leerSize_t("ID del barco: ");

            barco = Puerto_buscar(civilizacion->puerto, id);

            if(barco==NULL){
                printf("PUERTO: NO SE ENCONTRO EL BARCO\n");
                pause; clear;
                continue;
            }
            printf("\nSE ENCONTRO EL BARCO\n\n");
            pause; clear;
            menu_barco(barco);
            pause; clear;
            break;
        case ELIMINAR_BARCO_INICIO:
            clear;
            if(Puerto_eliminar_inicio(civilizacion->puerto)){
                puts("PUERTO: SE ELIMINO AL INICIO BARCO");
            }else{
                puts("PUERTO: ERROR AL ELIMINAR AL INICIO BARCO");
            }
            pause; clear;
            break;
        case ELIMINAR_BARCO_FINAL:
            clear;
            if(Puerto_eliminar_final(civilizacion->puerto)){
                puts("PUERTO: SE ELIMINO AL FINAL BARCO");
            }else{
                puts("PUERTO: ERROR AL ELIMINAR AL FINAL BARCO");
            }
            pause; clear;
            break;
        case AGREGAR_BATALLA:
            clear;
            puts("\t\t| AGREGAR BARCO A BATALLA |\n");
            int op;
            printf("[1] BARCO AL INICIO DEL PUERTO\n");
            printf("[2] BARCO AL FINAL DEL PUERTO\n\n");
            printf("INGRESA LA OPCION: ");
            scanf("%i",&op);

            switch(op){
                case 1:
                    dato = Puerto_desligar_inicio(civilizacion->puerto);
                        if(dato->dato->combustible > 0.0){
                            dato->dato->velocidad = leerFloat("Modificar velocidad del barco (0.0 - 14.0): ");
                                if(ColaBarco_encolar(civilizacion->batalla, dato)){
                                    puts("COLABARCO: SE INSERTO BARCO A BATALLA");
                                }else{
                                puts("COLABARCO: ERROR AL INSERTAR BARCO A BATALLA");
                                }
                        }else{
                            puts("COMBUSTIBLE < 0, NO SE PUEDE AGREGAR EL BARCO");
                            Puerto_regresar_inicio(civilizacion->puerto, dato);
                        }
                    break;
                case 2:
                    dato = Puerto_desligar_final(civilizacion->puerto);
                        if(dato->dato->combustible > 0.0){
                            dato->dato->velocidad = leerFloat("Modificar velocidad del barco (0.0 - 14.0): ");
                                if(ColaBarco_encolar(civilizacion->batalla, dato)){
                                    puts("COLABARCO: SE INSERTO BARCO A BATALLA");
                                }else{
                                puts("COLABARCO: ERROR AL INSERTAR BARCO A BATALLA");
                                }
                        }else{
                            puts("COMBUSTIBLE < 0, NO SE PUEDE AGREGAR EL BARCO");
                            Puerto_regresar_final(civilizacion->puerto, dato);
                        }
                    break;
                default:
                    puts("!! INGRESA UNA OPCION CORRECTA");
                    break;
            }

            if(barco==NULL){
                puts("BARCO NO TIENE MEMORIA");
                pause; clear;
                continue;
            }
            
            pause; clear;
            break;
        case SACAR_BATALLA:
            clear;
            dato = ColaBarco_desligar(civilizacion->batalla);
                if(dato!=NULL){
                dato->dato->velocidad = 0.0;
                dato->dato->combustible = leerFloat("Modificar combustible del barco (0.0 - 100.0): ");
                dato->dato->armadura = leerFloat("Modificar armadura del barco (0.0 - 100.0): ");
                if(dato->dato->armadura == 0.0){
                    puts("EL BARCO NO REGRESA A PUERTO");
                    dato = NodoDoble1_free(dato);
                }else{
                    int opc;
                    printf("\n\n[1] AGREGAR BARCO AL INICIO\n");
                    printf("[2] AGREGAR BARCO AL FINAL\n\n");
                    printf("INGRESA LA OPCION: ");
                    scanf("%i", &opc);
                        switch (opc)
                        {
                        case 1:
                            if(Puerto_regresar_inicio(civilizacion->puerto, dato)){
                            puts("PUERTO: SE INSERTO AL INICIO BARCO");
                            }else{
                            puts("PUERTO: ERROR AL INSERTAR AL INICIO BARCO");
                            }
                            break;
                        case 2: 
                            if(Puerto_regresar_final(civilizacion->puerto, dato)){
                            puts("PUERTO: SE INSERTO AL FINAL BARCO");
                            }else{
                            puts("PUERTO: ERROR AL INSERTAR AL FINAL BARCO");
                            }
                        default:
                            printf("!! INGRESA UNA OPCION CORRECTA !!");
                            break;
                        }
                    }
            }else{
            puts("COLABARCO: ERROR AL ELIMINAR BARCO A BATALLA");
            }
            pause; clear;
            break;
        case MOSTRAR_BATALLA:
            clear;
            if(ColaBarco_mostrar(civilizacion->batalla)){
                puts("COLABARCO: SE MOSTRARON BARCOS EN BATALLA");
            } else{
                puts("COLABARCO: ERROR AL MOSTRAR BARCOS EN BATALLA");
            }
            pause; clear;
            break;
        case SALIR:
            puts("\nREGRESANDO AL MENU DE CIVILIZACIONES...");
            break;
        default:
        puts("\n!! INGRESA UNA OPCION VALIDA !!");
            break;
        }
    }while(opc != SALIR);
}

#endif