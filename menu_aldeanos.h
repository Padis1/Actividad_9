#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aldeanosLista.h"
#include "aldeano.h"

void menu_aldeanos(AldeanosLista *aldeanosLista)
{   
    int pocicion;
    int opcion;
    Aldeano *aldeano;


    do{
    puts("MENU");
    puts("1. Inicializar lista");
    puts("2. Agregar aldeano al incio");
    puts("3. Agregar aldeano al final");
    puts("4. Eliminar aldeano del incio");
    puts("5. Eliminar aldeano del final");
    puts("6. Insertar en posicion deseada");
    puts("7. Eliminar en posicion deseada");
    puts("8. Mostrar lista");
    puts("9. Mostrar Tabla");
    puts("10. Salir");
    puts("10. Limpiar Pantalla");
    printf("Ingrese una opcion: ");
    scanf("%i", &opcion);
    
    
    switch (opcion)
    {
    case 1:
        AldeanosLista *aldeanosLista = AldeanosLista_init();
        break;
    case 2:   
        fflush(stdin);
        aldeano = Aldeano_capturar();
        AldeanosLista_agregar_inicio(aldeanosLista, aldeano);
        break;
    case 3:
        fflush(stdin);
        aldeano = Aldeano_capturar();
        AldeanosLista_Agregar_final(aldeanosLista, aldeano);
        break;
    case 4:
        AldeanosLista_eliminar_inicio(aldeanosLista);
        break;
    case 5:
        AldeanosLista_eliminar_final(aldeanosLista);
        break;
    case 6:
        fflush(stdin);
        aldeano = Aldeano_capturar();
        printf("Ingrese la pocicion donde desea insertar el aldeano: ");
        scanf("%d", &pocicion);
        AldeanosLista_insertar(aldeanosLista, aldeano, pocicion);
        break;
    case 7:
        printf("Ingrese la posicion donde desea eliminar el aldeano: ");
        scanf("%d", &pocicion);
        AldeanosLista_eliminar(aldeanosLista, pocicion);
        break;
    case 8:
        AldeanosLista_Mostrar(aldeanosLista);
        break;
    case 9:
        AldeanosLista_mostrar_tabla(aldeanosLista);
        break;
    case 10:
        system("cls");
        break;
    }
    }while(opcion != 11);
}