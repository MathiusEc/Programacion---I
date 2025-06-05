#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);

    int len = strlen(cadena)-1;
    cadena[len] = '\0';
}

void crearMat(struct Materia materias[3], int cont)
{
    for (int i = 0; i < cont; i++)
    {
        printf("Ingrese el codig de la materia: %d\n",i+1);
        leerCadena(materias[i].codigo,10);

        printf("Ingrese el nombre de la materia: %d\n",i+1);
        leerCadena(materias[i].nombre,20);

        printf("Ingrese las notas de la materia:  %d\n",i+1);

        printf("Nota 1: ");
        scanf("%f",&materias[i].notas[0]);
        
        printf("Nota 2: ");
        scanf("%f",&materias[i].notas[1]);
        
        printf("Nota 2: ");
        scanf("%f",&materias[i].notas[2]);

        materias[i].prom  = (materias[i].notas[0] + materias[i].notas[1] + materias[i].notas[2])/3;
    }
    
}

void crearEstu(struct Estudiante estudiante[3], int cont)
{
    int contM = 0;
    printf("Ingrese el codigo del estudiante: %d\n", cont +1);
    leerCadena(estudiante[30].codigo,10);
   
    printf("Ingrese el nombre de los estudiantes: %d\n", cont +1);
    leerCadena(estudiante[cont].nombre, 30);

    printf("Ingrese la edad del estudiante %d\n", cont +1);
    scanf("%d", &estudiante[cont].edad);

    printf("Ingrese el numero de materias a asignar\n");
    scanf("%d", &estudiante[cont].numM);

    crearMat(estudiante[cont].materias, estudiante[cont].numM);
}

void imprimirMat(struct Materia materias[3], int cont)
{
    printf("1. Codigo \t, 2. Nombre \t, 3. Nota 1 \t, Nota 2 \t, Nota 3 \t, 4. Promedio \t\n");
    for (int i = 0; i < cont; i++)
    {
        printf("%s\t, %s\t, %f\t, %f\t,  %f \t %f\t\n", materias[i].codigo, materias[i].nombre, materias[i].notas[0], 
                                                                                                    materias[i].notas[1], materias[i].notas[2], materias[i].prom );
    }
    
}

void imprimirEstu(struct Estudiante estudiante[3], int cont)
{
    for (int i = 0; i < cont; i++)
    {
        printf("1. Codigo %s, \t 2. Nombre %s\t , 3. Edad %f\n", estudiante[i].codigo, estudiante[i].materias, estudiante[i].edad);
        imprimirMat(estudiante[i].materias, estudiantes[i].NumM);
    }
    
}