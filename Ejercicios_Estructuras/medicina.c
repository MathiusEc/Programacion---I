/* Se desea desarrollar un sistema de gestión médica que permita administrar consultas y medicamentos. Las funcionalidades incluyen
visualizar medicamentos en stock, registrar una consulta médica con medicamentos, listar todas las consultas realizadas en un día,
buscar consultas por paciente y actualizar el stock de medicamentos.

Los atributos de la consulta son los siguientes: nombre del paciente, cédula, diagnóstico, medicamentos recetados, costo total de
los medicamentos y fecha de la consulta.

Los atributos del medicamento son los siguientes: nombre del medicamento, precio unitario y stock disponible. */

#include <stdio.h>
#include <string.h>
#include "medicina.h"

int main(int argc, char *argv[])
{

    struct Medicina medicamentos[100];
    struct Consulta consultas[100];
    int contadorMedicamentos = 0;
    int contadorConsultas = 0;
    int opcion;

    do
    {
        printf("\n=== MENÚ DE GESTIÓN MÉDICA ===\n");
        printf("1. Crear Medicamento\n");
        printf("2. Listar Medicamentos\n");
        printf("3. Registrar Consulta Médica\n");
        printf("4. Listar Consultas por Fecha\n");
        printf("5. Buscar Consulta por Paciente\n");
        printf("6. Actualizar Stock\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion)
        {
        case 1:
            crearMedicamentos(medicamentos, &contadorMedicamentos);
            break;

        case 2:
            if (contadorMedicamentos == 0)
            {
                printf("No hay medicamentos registrados.\n");
                break;
            }
            listarMedicamentos(medicamentos, &contadorMedicamentos);
            break;

        case 3:
            if (contadorMedicamentos == 0)
            {
                printf("No hay medicamentos registrados.\n");
                break;
            }
            registrarConsulta(&consultas[contadorConsultas], medicamentos, contadorMedicamentos);
            contadorConsultas++;
            break;

        case 4:
            if (contadorConsultas == 0)
            {
                printf("No hay consultas registradas.\n");
                break;
            }
            char fecha[11];
            printf("Ingrese la fecha (YYYY-MM-DD): ");
            leerCadena(fecha, 11);
            listarConsultas(consultas, contadorConsultas, fecha);
            break;

        case 5:
            if (contadorConsultas == 0)
            {
                printf("No hay consultas registradas.\n");
                break;
            }
            char nombrePaciente[100];
            printf("Ingrese el nombre del paciente: ");
            leerCadena(nombrePaciente, 100);
            struct Consulta *consulta = buscarConsultaPorPaciente(consultas, contadorConsultas, nombrePaciente);
            imprimirsolouno(consulta);
            break;

        case 6:
            if (contadorMedicamentos == 0)
            {
                printf("No hay medicamentos registrados.\n");
                break;
            }
            char idMedicamento[10];
            printf("Ingrese el ID del medicamento a actualizar: ");
            leerCadena(idMedicamento, 10);
            agregarStockMedicamento(medicamentos, contadorMedicamentos, idMedicamento);
            break;

        default:
            break;
        }
    } while (opcion != 7);

    return 0;
}