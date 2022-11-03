#ifndef ALDEANO_H
#define ALDEANO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Utilidades.h"

struct aldeano
{
    char *nombre;
    int edad;
    int salud;
};

typedef struct aldeano Aldeano;

Aldeano *aldeano_init(char *nombre, int edad, int salud)
{
    Aldeano *aldeano = (Aldeano *)malloc(sizeof(Aldeano));  

    if (aldeano != NULL) 
    {                                    
        aldeano->nombre = strdup(nombre); 
        aldeano->edad = edad;
        aldeano->salud = salud;
    }

    return aldeano;
}

Aldeano *Aldeano_Free(Aldeano *aldeano)     
{ 
    if (aldeano != NULL)
    {
        free(aldeano->nombre);                       
        aldeano->nombre = NULL; 
        free(aldeano);
        aldeano = NULL;
    }

    return aldeano; 
}

bool Aldeano_mostrar(Aldeano *aldeano)
{
    bool NO_ERROR = false;

    if (aldeano != NULL)
    {
        printf("\nNombre: %s", aldeano->nombre);
        printf("\nEdad: %d", aldeano->edad);
        printf("\nSalud: %d", aldeano->salud);
        printf("\n");
        NO_ERROR = true;
    }

    return NO_ERROR;
}

Aldeano *Aldeano_capturar()
{
    char *nombre;
    int edad;
    int salud;

    nombre = leerCadena("Nombre: ");
    edad = leerEntero("Edad: ");
    salud = leerEntero("Salud: ");

    Aldeano *aldeano = aldeano_init(nombre, edad, salud);

    return aldeano;
}

bool Aldeano_mostrar_fila(Aldeano *aldeano)
{
	bool NO_ERROR = false;
	
	if (aldeano != NULL)
	{
        
		printf("%-10s %-5s %-6s\n",
        aldeano->nombre,aldeano->salud,aldeano->edad);

		NO_ERROR = true;
	}
	
    return NO_ERROR;
}

#endif