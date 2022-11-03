#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Utilidades.h"
#include "aldeanosLista.h"

struct civilizacion
{
    char *nombre;
    AldeanosLista *aldeanosLista; 
};

typedef struct civilizacion Civilizacion;

Civilizacion *Civilizacion_init(char *nombre)
{
    Civilizacion *civilizacion = (Civilizacion *)malloc(sizeof(Civilizacion));  

    if (civilizacion != NULL) 
    {                                     
        civilizacion->nombre = strdup(nombre); 
    }

    return civilizacion;
}

    Civilizacion *Civilizacion_Free(Civilizacion *civilizacion)
{
    if (civilizacion != NULL)
    {
        free(civilizacion->nombre);
        civilizacion->nombre = NULL;
        free(civilizacion);
        civilizacion = NULL;
    }
    return civilizacion;
}
#endif