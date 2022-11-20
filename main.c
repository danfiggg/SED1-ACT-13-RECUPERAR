
#include <stdlib.h>
#include <stdio.h>

#include "menu_civilizaciones.h"


int main(){
   
    clear;
    Civilizaciones *civilizaciones = Civilizaciones_init();
    menu_civilizaciones(civilizaciones);
    civilizaciones = Civilizaciones_free(civilizaciones);

    return 0;
}