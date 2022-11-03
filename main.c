#include <stdio.h>
#include <stdlib.h>
#include "civilizacion.h"
#include "menu_aldeanos.h"
int main()
{

    Civilizacion *civilizacion = Civilizacion_init("Padis_Farm");
    
    menu_aldeanos(civilizacion->aldeanosLista);

    civilizacion = Civilizacion_Free(civilizacion);
    
    return 0;
}