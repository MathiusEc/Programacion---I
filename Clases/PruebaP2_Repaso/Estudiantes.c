/* *Sistema de registro de estudiantes en una academia*
*Objetivo:* Desarrollar una plataforma que maneje la inscripción de estudiantes y cursos.  
*Requerimientos:*
- Registrar un estudiante con: nombre, número de identificación, curso, estado (pendiente/matriculado).
- No permitir números de identificación repetidos.
- Permitir la matriculación de un estudiante, cambiando su estado a "matriculado".
- Buscar estudiantes por número de identificación.
- Mostrar un listado de estudiantes aún no matriculados.
*/


#include <stdio.h>
#include <string.h>

void registrarAlumno(char estudiantes[5][30], char identificaciones[5][15], char cursos[5][30], char estados[5][15], int *ubicacion) {
    int duplicado, len;

    if (*ubicacion >= 5) {
        printf("No se pueden registrar más de 5 estudiantes.\n");
        return;
    }

    do {
        printf("Ingrese el nombre del estudiante: ");
        fflush(stdin);
        fgets(estudiantes[*ubicacion], 30, stdin);
        len = strlen(estudiantes[*ubicacion]) - 1;
        if (len >= 0 && estudiantes[*ubicacion][len] == '\n') {
            estudiantes[*ubicacion][len] = '\0'; // Eliminar el salto de línea
        }

        printf("Ingrese el número de identificación: ");
        fflush(stdin);
        fgets(identificaciones[*ubicacion], 15, stdin);
        len = strlen(identificaciones[*ubicacion]) - 1;
        if (len >= 0 && identificaciones[*ubicacion][len] == '\n') {
            identificaciones[*ubicacion][len] = '\0'; // Eliminar el salto de línea
        }

        duplicado = 0;
        for (int i = 0; i < *ubicacion; i++) {
            if (strcmp(identificaciones[i], identificaciones[*ubicacion]) == 0) {
                duplicado = 1;
                printf("Este número de identificación ya está registrado. Por favor, ingrese otro.\n");
            }
        }
    } while (duplicado == 1);

    printf("Ingrese el curso del estudiante: ");
    fflush(stdin);
    fgets(cursos[*ubicacion], 30, stdin);
    len = strlen(cursos[*ubicacion]) - 1;
    if (len >= 0 && cursos[*ubicacion][len] == '\n') {
        cursos[*ubicacion][len] = '\0'; // Eliminar el salto de línea
    }

    strcpy(estados[*ubicacion], "pendiente");
    (*ubicacion)++;
}

void matricularAlumno(char identificaciones[5][15], char estados[5][15], int ubicacion) {
    char idBuscar[15];
    int encontrado = 0;

    printf("Ingrese el número de identificación del estudiante a matricular: ");
    fflush(stdin);
    fgets(idBuscar, 15, stdin);
    int len = strlen(idBuscar) - 1;
    if (len >= 0 && idBuscar[len] == '\n') {
        idBuscar[len] = '\0'; // Eliminar el salto de línea
    }

    for (int i = 0; i < ubicacion; i++) {
        if (strcmp(identificaciones[i], idBuscar) == 0) {
            strcpy(estados[i], "matriculado");
            printf("Estudiante %s matriculado exitosamente.\n", identificaciones[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("No se encontró un estudiante con el número de identificación %s.\n", idBuscar);
    }
}

void buscarEstudiante(char identificaciones[5][15], char estudiantes[5][30], int ubicacion, char cursos[5][30], char estados[5][15]) 
{
    char idBuscar[15];
    int encontrado = 0;

    printf("Ingrese el número de identificación del estudiante a buscar: ");
    fflush(stdin);
    fgets(idBuscar, 15, stdin);
    int len = strlen(idBuscar) - 1;
    if (len >= 0 && idBuscar[len] == '\n') {
        idBuscar[len] = '\0'; // Eliminar el salto de línea
    }

    for (int i = 0; i < ubicacion; i++) {
        if (strcmp(identificaciones[i], idBuscar) == 0) {
            printf("Estudiante encontrado: %s, ID: %s, Curso: %s, Estado: %s\n", estudiantes[i], identificaciones[i], cursos[i], estados[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("No se encontró un estudiante con el número de identificación %s.\n", idBuscar);
    }
}
void listarEstudiantesPendientes(char estudiantes[5][30], char identificaciones[5][15], char cursos[5][30], char estados[5][15], int ubicacion) {
    printf("Listado de estudiantes pendientes:\n");
    for (int i = 0; i < ubicacion; i++) {
        if (strcmp(estados[i], "pendiente") == 0) {
            printf("Nombre: %s, ID: %s, Curso: %s\n", estudiantes[i], identificaciones[i], cursos[i]);
        }
    }
}

int main (int argc, char *argv[]) {

    char estudiantes[5][30];
    char identificaciones[5][15];
    char cursos[5][30];
    char estados[5][15];
    int ubicacion = 0, opc, val, len;

    do
    {
        printf("Seleccione una opción:\n");
        printf("1. Registrar estudiante\n");
        printf("2. Matricular estudiante\n");
        printf("3. Buscar estudiante por ID\n");
        printf("4. Listar estudiantes pendientes\n");
        printf("5. Salir\n");
        printf(">> ");
        val = scanf("%d", &opc);
        if (val != 1) {
            printf("Entrada inválida. Por favor, ingrese un número.\n");
            fflush(stdin); 
        }

        switch (opc)
        {
        case 1:
            registrarAlumno(estudiantes, identificaciones, cursos, estados, &ubicacion);
            break;
        case 2:
            if (ubicacion == 0) {
                printf("No hay estudiantes registrados para matricular.\n");
            } else {
                matricularAlumno(identificaciones, estados, ubicacion);
            }
            break;
        case 3:
            if (ubicacion == 0) {
                printf("No hay estudiantes registrados.\n");
            } else {
                buscarEstudiante(identificaciones, estudiantes, ubicacion, cursos, estados);
            }
            break;

        case 4:
            if (ubicacion == 0) {
                printf("No hay estudiantes registrados.\n");
            } else {
                listarEstudiantesPendientes(estudiantes, identificaciones, cursos, estados, ubicacion);
            }
            break;

        default:
            break;
        }
    } while (opc != 5  || val != 1);
    
    return 0;
}