/* Se desea desarrollar un sistema de gestión médica que permita administrar consultas y medicamentos. Las funcionalidades incluyen
visualizar medicamentos en stock, registrar una consulta médica con medicamentos, listar todas las consultas realizadas en un día,
buscar consultas por paciente y actualizar el stock de medicamentos.

Los atributos de la consulta son los siguientes: nombre del paciente, cédula, diagnóstico, medicamentos recetados, costo total de
los medicamentos y fecha de la consulta.

Los atributos del medicamento son los siguientes: nombre del medicamento, precio unitario y stock disponible.*/

#include <stdio.h>
#include <string.h>
#include "medicina.h"

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);

    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void crearMedicamentos(struct Medicina medicamentos[], int *contador)
{
    int f = 0;
    do
    {
        printf("Ingrese el código del medicamento: %d\n", *contador + 1);
        leerCadena(medicamentos[*contador].id, 10);

        for (int i = 0; i < *contador; i++)
        {
            if (strcmp(medicamentos[i].id, medicamentos[*contador].id) == 0)
            {
                printf("El código ya existe. Por favor, ingrese un código diferente.\n");
                f = 1; // Marcar que el código ya existe
                break; // Salir del bucle para volver a pedir el código
            }  
        }

    } while (f == 1); // Repetir hasta que se ingrese un código único

    printf("Ingrese el nombre del medicamento: ");
    leerCadena(medicamentos[*contador].nombre, 100);

    printf("Ingrese el precio del medicamento: ");
    scanf("%f", &medicamentos[*contador].precio);

    printf("Ingrese el stock del medicamento: ");
    scanf("%d", &medicamentos[*contador].stock);

    (*contador)++;
}

void listarMedicamentos(struct Medicina medicamentos[], int *contador)
{
    printf("\nID\tMedicamento\tPrecio\tStock\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < *contador; i++)
    {
        printf("%s\t%s\t%.2f\t%d\n",
               medicamentos[i].id, medicamentos[i].nombre, medicamentos[i].precio, medicamentos[i].stock);
    }
}

void registrarConsulta(struct Consulta *consulta, struct Medicina medicamentos[], int contadorMedicamentos)
{
    printf("Ingrese el nombre del paciente: ");
    leerCadena(consulta->nombrePaciente, 100);

    printf("Ingrese la cédula del paciente: ");
    leerCadena(consulta->cedula, 11);

    printf("Ingrese el diagnóstico: ");
    leerCadena(consulta->diagnostico, 100);

    printf("Ingrese la fecha de la consulta (YYYY-MM-DD): ");
    leerCadena(consulta->fecha, 11);

    consulta->costoTotal = 0.0;
    int continuar = 1; // Variable para controlar si se agrega otro medicamento
    int numMedicamentosRecetados = 0; // Contador de medicamentos recetados
    int cantidadesRecetadas[10]; // Arreglo para almacenar las cantidades recetadas

    do
    {
        listarMedicamentos(medicamentos, &contadorMedicamentos);
        printf("Ingrese el índice del medicamento: ");
        char index[11];
        leerCadena(index, 11);

        int encontrado = 0; // Bandera para verificar si el medicamento fue encontrado
        for (int i = 0; i < contadorMedicamentos; i++)
        {
            if (strcmp(medicamentos[i].id, index) == 0)
            {
                consulta->medicamentos[numMedicamentosRecetados] = medicamentos[i];
                consulta->costoTotal += medicamentos[i].precio;

                printf("¿Cuántos medicamentos se recetaron? ");
                int cantidad;
                scanf("%d", &cantidad);
                fflush(stdin);

                if (cantidad > medicamentos[i].stock)
                {
                    printf("No hay suficiente stock. Se recetará el máximo disponible: %d\n", medicamentos[i].stock);
                    cantidad = medicamentos[i].stock;
                }

                cantidadesRecetadas[numMedicamentosRecetados] = cantidad; // Guardar la cantidad en el arreglo paralelo
                medicamentos[i].stock -= cantidad;
                numMedicamentosRecetados++;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Medicamento no encontrado. Por favor, intente de nuevo.\n");
        }

        printf("¿Desea agregar otro medicamento? (1: Sí, 0: No): ");
        scanf("%d", &continuar);
        fflush(stdin);

    } while (continuar == 1);

    printf("Consulta registrada exitosamente. Costo total: %.2f\n", consulta->costoTotal);

    // Mostrar los medicamentos recetados con sus cantidades
    printf("\nMedicamentos recetados:\n");
    for (int i = 0; i < numMedicamentosRecetados; i++)
    {
        printf("- %s: %d unidades\n", consulta->medicamentos[i].nombre, cantidadesRecetadas[i]);
    }
}

void listarConsultas(struct Consulta consultas[], int contador, char fecha[])
{
    int found = 0; // Variable para verificar si se encontraron consultas en la fecha especificada
    for (int i = 0; i < contador; i++)
    {
        if (strcmp(consultas[i].fecha, fecha) == 0)
        {
            found = 1; // Se encontró al menos una consulta
            printf("Consulta %d:\n", i + 1);
            printf("Nombre del paciente: %s\n", consultas[i].nombrePaciente);
            printf("Cédula: %s\n", consultas[i].cedula);
            printf("Diagnóstico: %s\n", consultas[i].diagnostico);
            printf("Medicamentos recetados:\n");

            for (int j = 0; j < 10 && consultas[i].medicamentos[j].precio > 0; j++)
            {
                printf("- %s (Precio: %.2f, Stock restante: %d)\n",
                       consultas[i].medicamentos[j].nombre,
                       consultas[i].medicamentos[j].precio,
                       consultas[i].medicamentos[j].stock);
            }
            printf("Costo total de la consulta: %.2f\n", consultas[i].costoTotal);
            printf("----------------------------------------\n");
        }
    }

    if (!found)
    {
        printf("No se encontraron consultas en la fecha %s.\n", fecha);
    }
}

struct Consulta *buscarConsultaPorPaciente(struct Consulta consultas[], int contador, char nombrePaciente[])
{
    for (int i = 0; i < contador; i++)
    {
        if (strcmp(consultas[i].nombrePaciente, nombrePaciente) == 0)
        {
            return &consultas[i]; // Retorna un puntero a la consulta encontrada
        }
    }
    return 0; // Si no se encuentra la consulta
}

void imprimirsolouno (struct Consulta *consulta)
{
    if (consulta == NULL)
    {
        printf("Consulta no encontrada.\n");
        return;
    }

    printf("\n=== DETALLES DE LA CONSULTA ===\n");
    printf("Nombre del paciente: %s\n", consulta->nombrePaciente);
    printf("Cédula: %s\n", consulta->cedula);
    printf("Diagnóstico: %s\n", consulta->diagnostico);
    printf("Fecha de la consulta: %s\n", consulta->fecha);
    printf("Costo total de la consulta: %.2f\n", consulta->costoTotal);
    printf("Medicamentos recetados:\n");

    for (int i = 0; i < 10 && consulta->medicamentos[i].precio > 0; i++)
    {
        printf("- %s (Precio: %.2f, Stock restante: %d)\n",
               consulta->medicamentos[i].nombre,
               consulta->medicamentos[i].precio,
               consulta->medicamentos[i].stock);
    }
}


void agregarStockMedicamento(struct Medicina medicamentos[], int contadorMedicamentos, char id[])
{
    for (int i = 0; i < contadorMedicamentos; i++)
    {
        if (strcmp(medicamentos[i].id, id) == 0)
        {
            int cantidad;
            printf("Ingrese la cantidad a agregar al stock de %s: ", medicamentos[i].nombre);
            scanf("%d", &cantidad);
            fflush(stdin);
            medicamentos[i].stock += cantidad;
            printf("Stock actualizado. Nuevo stock de %s: %d\n", medicamentos[i].nombre, medicamentos[i].stock);
            return;
        }
    }
    printf("Medicamento con ID %s no encontrado.\n", id);
}