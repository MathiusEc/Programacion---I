// Sistema de Notas

#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    int opc;
    int cont = 0;
    int contE=0;
    struct Estudiante estudiantes[3];
    


    do
    {
        printf("Menu\n");
        printf("1. Ingresar Alumnos\n");
        printf("2. Imprimir Alumnos\n");
        printf("3. salir");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            crearEstu(estudiantes, contE);
            contE++;
            break;

        case 2:
            imprimirEstu(estudiantes, contE);
            break;

        default:
            break;
        }
    } while (opc != 3);

    return 0;
}