#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cadena[100];
int numero;
char *temp;
void *leerCadena(char *mensaje)
{
    printf("%s", mensaje);
    temp = fgets(cadena, sizeof(cadena), stdin); 

    if (temp != NULL)
    {
        cadena[strlen(cadena) - 1] = '\0';  
    }

    return cadena;
}

int leerEntero(char *mensaje)
{
    printf("%s: ", mensaje);
    scanf("%i", &numero);
    fflush(stdin);

    return numero;
}
#endif