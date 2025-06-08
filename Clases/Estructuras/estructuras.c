// Sistema de Notas

#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    int opc;
    int contE=0;
    struct Estudiante estudiantes[3];
    struct Estudiante *prtEstu;
    

    do
    {
        printf("Menu\n");
        printf("1. Ingresar Alumnos\n");
        printf("2. Imprimir Alumnos\n");
        printf("3. Buscar Alumno\n");
        printf("4. salir\n");
        printf(">> ");
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

        case 3:
            char codigoBusc[10];
            printf("Ingrese el codigo del estudiante a buscar: ");
            leerCadena(codigoBusc, 10);
            prtEstu = buscarEstu(estudiantes, codigoBusc, contE);
            if (prtEstu != 0)
            {
                printf("Estudiante encontrado:\n");
                imprimirunSoloEstu(prtEstu);
            }
            else
            {
                printf("Estudiante no encontrado.\n");
            }
            break;

        default:
            break;
        }
    } while (opc != 3);

    return 0;
}