#ifndef ALDEANOSLISTA_H
#define ALDEANOSLISTA_H

#include <stdio.h>
#include <stdlib.h>
#define CAPACIDAD 3

#include "aldeano.h"

struct aldeanos_lista
{
    Aldeano **aldeanos; 
    size_t cantidad;     
    size_t capacidad;    
};

typedef struct aldeanos_lista AldeanosLista; 

AldeanosLista *AldeanosLista_init() 
{                                  
    AldeanosLista *aldeanosLista; 
    aldeanosLista = (AldeanosLista *)malloc(sizeof(AldeanosLista)); 

    if (aldeanosLista != NULL) 
    {
        aldeanosLista->aldeanos = (Aldeano **)malloc(sizeof(Aldeano *) * CAPACIDAD); 
        if (aldeanosLista->aldeanos == NULL) 
        {
            puts("Error al crear el arreglo");
            exit(1);
        }
        aldeanosLista->cantidad = 0; 
        aldeanosLista->capacidad = CAPACIDAD;
    }
    return aldeanosLista; 
}

AldeanosLista *aldeanosLista_Free(AldeanosLista *aldeanosLista) 
{
    if (aldeanosLista != NULL) 
    { 
        if (aldeanosLista->aldeanos != NULL) 
        {
            for (size_t i = 0; i < aldeanosLista->cantidad; i++) 
            {
                free(aldeanosLista->aldeanos[i]); 
                aldeanosLista->aldeanos[i] = NULL; 
            }

            free(aldeanosLista->aldeanos); 
            aldeanosLista->aldeanos = NULL; 
        }
        free(aldeanosLista); 
        aldeanosLista = NULL;
    }

    return aldeanosLista; 
}

bool AldeanosLista_Llena(AldeanosLista *aldeanosLista)
{
    if (aldeanosLista == NULL) 
    {
        puts("No tiene memoria para jugadores");
        exit(1);
    }

    return aldeanosLista->cantidad == aldeanosLista->capacidad; 
}

bool AldeanosLista_Expandir(AldeanosLista *aldeanosLista) 
{
    bool NO_ERROR = false; 
    if (aldeanosLista != NULL) 
    {                                                                                              
        size_t nuevaCapacidad = aldeanosLista->capacidad + CAPACIDAD; 
        Aldeano **temp_p = (Aldeano **)realloc(aldeanosLista->aldeanos, sizeof(Aldeano *) * nuevaCapacidad); 
        if (temp_p != NULL) 
        {
            puts("Se expandio JugadoresLista correctamente");
            aldeanosLista->aldeanos = temp_p;         
            aldeanosLista->capacidad = nuevaCapacidad; 
            NO_ERROR = true;                            
        }
        else
        {
            puts("No fue posible expandirse el la lista");
        }
    }
    return NO_ERROR; 
}

bool AldeanosLista_Agregar_final(AldeanosLista *aldeanosLista, Aldeano *aldeano)
{
    bool NO_ERROR = false;

    if (aldeanosLista != NULL) 
    {
        if (AldeanosLista_Llena(aldeanosLista)) 
        {
            AldeanosLista_Expandir(aldeanosLista); 
        }
        
        aldeanosLista->aldeanos[aldeanosLista->cantidad] = aldeano; 
        aldeanosLista->cantidad++;
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_Mostrar(AldeanosLista *aldeanosLista) 
{
    bool NO_ERROR = false;

    if (aldeanosLista != NULL) {
        printf("Cantidad: %zu, capacidad: %zu\n", aldeanosLista->cantidad, aldeanosLista->capacidad);  
     for (size_t i = 0; i < aldeanosLista->cantidad; i++) 
        {
            Aldeano_mostrar(aldeanosLista->aldeanos[i]); 
        }
        NO_ERROR = true;
    }

    return NO_ERROR;
}

bool AldeanosLista_vacia(AldeanosLista *aldeanosLista) 
{
    if (aldeanosLista == NULL) 
    {
        puts("No tiene memoria para jugadores");
        exit(1);
    }

    return aldeanosLista->cantidad == 0; 
}


bool AldeanosLista_eliminar_final(AldeanosLista *aldeanosLista) 
{
    bool NO_ERROR = false;

    if (aldeanosLista != NULL) 
    {
        if (!AldeanosLista_vacia(aldeanosLista)) 
        {
            size_t ultimaPosicion = aldeanosLista->cantidad - 1;
            Aldeano_Free(aldeanosLista->aldeanos[ultimaPosicion]); 

            aldeanosLista->aldeanos[ultimaPosicion] = NULL;

            aldeanosLista->cantidad--;

            NO_ERROR = true;
        }
    }
    return NO_ERROR;
}

bool AldeanosLista_agregar_inicio(AldeanosLista *aldeanosLista, Aldeano *aldeano)
{
    bool NO_ERROR = false;

    if (aldeanosLista != NULL) 
    {
        if (AldeanosLista_Llena(aldeanosLista))
        {
            AldeanosLista_Expandir(aldeanosLista); 
        }

        for (size_t i = aldeanosLista->cantidad; i > 0; i--) 
        {
            aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i - 1]; 
        }
        aldeanosLista->aldeanos[0] = aldeano; 
        aldeanosLista->cantidad++; 
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_insertar(AldeanosLista *aldeanosLista, Aldeano *aldeano, size_t posicion)
{
    bool NO_ERROR = false;

    if (aldeanosLista != NULL) 
    {
        if (AldeanosLista_Llena(aldeanosLista)) 
        {
            AldeanosLista_Expandir(aldeanosLista); 
        }

        for (size_t i = aldeanosLista->cantidad; i > posicion; i--) 
        {
            aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i - 1]; 
        }
        aldeanosLista->aldeanos[posicion] = aldeano; 
        aldeanosLista->cantidad++; 
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_eliminar_inicio(AldeanosLista *aldeanosLista)
{
        bool NO_ERROR = false;

        if (aldeanosLista != NULL)
        {
            if (!AldeanosLista_vacia(aldeanosLista))
            { 
                Aldeano_Free(aldeanosLista->aldeanos[0]);
                aldeanosLista->aldeanos[0] = NULL;
                for (size_t i = 0; i < aldeanosLista->cantidad; i++)
                {
                    aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i + 1];
                }
                aldeanosLista->cantidad--;

                NO_ERROR = true;
            }
        }
        return NO_ERROR;
}

bool AldeanosLista_eliminar(AldeanosLista *aldeanosLista, size_t posicion)
{
    bool NO_ERROR = false;

    if (aldeanosLista != NULL) 
    {
        if (!AldeanosLista_vacia(aldeanosLista))
        {
            Aldeano_Free(aldeanosLista->aldeanos[posicion]); 
            aldeanosLista->aldeanos[posicion] = NULL;
            aldeanosLista->cantidad--;

            NO_ERROR = true;
        }
    }
    return NO_ERROR;
}

bool AldeanosLista_mostrar_tabla(AldeanosLista *aldeanosLista){

	bool NO_ERROR = false;

	if (aldeanosLista != NULL) 
    {
       
		printf("%-10s %-5s %-6s\n","Nombre", "Salud", "Edad");

			for (size_t i = 0; i < aldeanosLista->cantidad; i++)
			{
                fflush(stdin);
			    Aldeano_mostrar_fila(aldeanosLista->aldeanos[i]);
			}

            //printf("Cantidad: %zu, capacidad: %zu\n", aldeanosLista->cantidad, aldeanosLista->capacidad);  

		NO_ERROR= true;

	}

	return NO_ERROR;	

}

#endif
