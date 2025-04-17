
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char alumnos[5][30];
    char materia[5][30];
    float calificaciones[5][3];
    float calificacion_alta[5][3]; // llenar en 11
    float calificacion_baja[5][3]; // llenar en -1
    int cant_aprobados[3] = {0, 0, 0};
    int cant_reprobados[3] = {0, 0, 0};
    float promedios_asignatura[3] = {0, 0, 0};
    float promedios_estudiante[5] = {0, 0, 0, 0, 0};
    int val, opcin, len, cont = 0, mat = -1, duplicado;
    char nombuscar[30];
    
    /*Con el fin de evitar que datos residuales de la memoria
    dedicada a este arreglo interfiera con el resultado del programa*/

    do
    {
        printf("==================================================\n");
        printf("      SISTEMA DE GESTION DE CALIFICACIONES        \n");
        printf("==================================================\n");
        printf("\n");
        printf("1. Ingresar alumnos y notas\n"); // RESUELTOO!!!!1
        printf("2. Calcular el promedio de calificaciones para cada estudiante\n");
        printf("3. Calcular el promedio por asignatura\n");
        printf("4. Encontrar la calificacion mas alta y baja por estudiante\n");
        printf("5. Encontrar la calificacion mas alta y baja por asignatura\n");
        printf("6. Determinar cuantos estudiantes aprobaron o reprobaron cada asignatura\n");
        printf("7. Salir\n");
        printf("\n");
        printf("Ingrese una opcion:\n");
        printf(">> ");
        
        do
        {
            fflush(stdin);
            val = scanf("%d", &opcin);
            if (val != 1)
            {
                printf("Por favor, ingrese un valor correcto..\n");
            }
        } while (val != 1);

        switch (opcin)
        {
        case 1:
            char continuar;
            cont = 0;
            mat = 0;


            do
            {
                printf("Ingrese el numeros de materias, recuerde que el maximo es de 3\n");
                printf(">> ");
                fflush(stdin);
                val = scanf("%d", &mat);
                if (val != 1)
                {
                    printf("Por favor, ingrese un valor correcto..\n");
                }
                else if (mat < 1 || mat > 3)
                {
                    printf("Las calificaciones no pueden ser negativas / cero o mayores a 3.\n");
                }
            } while (val != 1 || mat < 1 || mat > 3);

            for (int i = 0; i < mat; i++)
            {
                duplicado = 0;
                do
                {
                    printf("Ingrese el nombre de la materia %d:\n>> ", i);
                    fflush(stdin);
                    fgets(materia[i], 30, stdin);

                    len = strlen(materia[i]) - 1;
                    materia[i][len] = '\0';

                    if(strlen(materia[i]) == 0)
                    {
                        printf("El nombre de la materia no puede estar vacio\n");
                    }
                    else
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if (strcmp(materia[i], materia[j]) == 0)
                            {
                                duplicado = 1;
                                printf("Ya existe una materia con ese nombre, por favor ingrese otro.\n");
                            }
                            else
                            {
                                duplicado = 0;
                            }
                        }

                    }
                } while (duplicado == 1 || strlen(materia[i]) == 0);
            }

            do
            {
                do
                {
                    // Pedir el nombre del alumno
                    printf("Ingrese el nombre del alumno %d: ", cont);
                    fflush(stdin);
                    fgets(alumnos[cont], 30, stdin);

                    len = strlen(alumnos[cont]) - 1;
                    alumnos[cont][len] = '\0';

                    if(strlen(alumnos[cont]) == 0)
                    {
                        printf("El nombre del alumno no puede estar vacio\n");
                    }else
                    {
                        for (int j = 0; j < cont; j++)
                        {
                            duplicado = 0;
                            if (strcmp(alumnos[cont], alumnos[j]) == 0)
                            {
                                duplicado = 1;
                                printf("Ya existe un alumno con ese nombre, por favor ingrese otro.\n");
                            }
                            else
                            {
                                duplicado = 0;
                            }
                        }

                    }
                } while (strlen(alumnos[cont]) == 0 || duplicado == 1);
                
                // Pedir las calificaciones
                printf("Ingrese las calificaciones del estudiante %s:\n", alumnos[cont]);
                for (int j = 0; j < mat; j++)
                {

                    do
                    {
                        printf("Ingrese la calificación para %s: ", materia[j]);
                        fflush(stdin);
                        val = scanf("%f", &calificaciones[cont][j]);
                        if (val != 1)
                        {
                            printf("Por favor, ingrese un valor correcto..\n");
                        }
                        else if (calificaciones[cont][j] < 0 || calificaciones[cont][j] > 10)
                        {
                            printf("Las calificaciones no pueden ser negativas o mayores a 10.\n");
                        }
                    } while (val != 1 || calificaciones[cont][j] < 0 || calificaciones[cont][j] > 10);
                }
                cont++;

                // Incrementar el índice del estudiante
                // ver cuantos estudiantes se ingresaron

                // Preguntar si desea continuar con otro estudiante
                printf("¿Desea ingresar otro estudiante? (s/n): ");
                fflush(stdin);
                scanf("%c", &continuar);
                if (cont > 4)
                {
                    printf("No se pueden ingresar mas de 5 estudiantes\n");
                    continuar = 'N';
                }
                else
                {
                    while (continuar != 'N' && continuar != 'n' && continuar != 'S' && continuar != 's')
                    {
                        printf("Ingrese una opcion valida\n");
                        fflush(stdin);
                        scanf("%c", &continuar);

                        if (continuar != 'N' && continuar != 'n' && continuar != 'S' && continuar != 's')
                        {
                            printf("Ingrese los valores correctos\n");
                        }
                    }
                }

            } while (continuar == 's' || continuar == 'S');

            break;

        case 2:
            if(mat == -1)
            {
                printf("No se han ingresado materias, por favor ingrese primero los datos de los estudiantes\n");
                break;
            }
            // Calcular el promedio de calificaciones para cada estudiante
            int f = 0;

            printf("Ingrese el nombre del estudiante que desea obtener el promedio de notas...\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < cont; i++)
            {
                if (strcmp(alumnos[i], nombuscar) == 0)
                {
                    printf("Promedio del estudiante %s\n", alumnos[i]);
                    len = strlen(alumnos[i]) - 1;
                    if (alumnos[i][len] == '\n')
                    {
                        alumnos[i][len] = '\0';
                    }
                    f = 1;
                    promedios_estudiante[i] = 0;

                    for (int j = 0; j < mat; j++)
                    {
                        promedios_estudiante[i] += calificaciones[i][j] / mat;
                    }
                    printf("\n");
                    printf("El promedio es: %.2f\n", promedios_estudiante[i]);
                }
            }
            if (f == 0)
            {
                printf("No existe ningun estudiante llamado asi\n");
            }
            break;
        case 3:
            if (mat == -1)
            {
                printf("No se han ingresado materias, por favor ingrese primero los datos de los estudiantes\n");
                break;
            }
            f = 0;

            printf("Ingrese el nombre de la materia que desea obtener el promedio de notas...\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < mat; i++)
            {
                if (strcmp(materia[i], nombuscar) == 0)
                {
                    printf("Promedio de la materia: %s\n", materia[i]);
                    len = strlen(materia[i]) - 1;
                    if (materia[i][len] == '\n')
                    {
                        materia[i][len] = '\0';
                    }
                    f = 1;
                    promedios_asignatura[i] = 0;

                    // recordar que 'cont' es la cantidad de estudiantes que se ingresaron
                    for (int j = 0; j < cont; j++)

                    {
                        promedios_asignatura[i] += calificaciones[j][i] / cont;
                        /*La variable cont se usa para hacer
                        la operación de promedio en función a los
                        alumnos que se haya ingresado.*/
                    }
                    printf("\n");
                    printf("El promedio es: %.2f\n", promedios_asignatura[i]);
                }
            }
            if (f == 0)
            {
                printf("No existe la materia buscada dentro del registro..\n");
            }

            break;
        case 4:
            if (mat == -1)
            {
                printf("No se han ingresado materias, por favor ingrese primero los datos de los estudiantes\n");
                break;
            }

            // Hallar la calificación más alta y baja por estudiante
            float max = -1, min = 11;
            f = 0;
            printf("Ingrese el nombre del estudiante que desea obtener la calificacion mas alta y baja...\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < cont; i++)
            {
                if (strcmp(alumnos[i], nombuscar) == 0)
                {
                    printf("Estudiante %s\n", alumnos[i]);
                    len = strlen(alumnos[i]) - 1;
                    if (alumnos[i][len] == '\n')
                    {
                        alumnos[i][len] = '\0';
                    }
                    f = 1;

                    for (int j = 0; j < mat; j++)
                    {
                        if (calificaciones[i][j] > max)
                        {
                            max = calificaciones[i][j];
                        }
                        if (calificaciones[i][j] < min)
                        {
                            min = calificaciones[i][j];
                        }
                    }
                    calificacion_alta[i][0] = max;
                    calificacion_baja[i][0] = min;

                    printf("Calificacion mas alta: %.2f\n", calificacion_alta[i][0]);
                    printf("Calificacion mas baja: %.2f\n", calificacion_baja[i][0]);
                }
            }
            if (f == 0)
            {
                printf("No existe ningun estudiante llamado asi\n");
            }

            break;

        case 5:
            if (mat == -1)
            {
                printf("No se han ingresado materias, por favor ingrese primero los datos de los estudiantes\n");
                break;
            }

            // Hallar la calificación más alta y baja por materia
            max = -1, min = 11;
            f = 0;
            printf("Ingrese el nombre de la materia para la cual desea obtener sus maximas y minimas notas.\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < mat; i++)
            {
                if (strcmp(materia[i], nombuscar) == 0)
                {
                    printf("Asignatura %s\n", materia[i]);
                    len = strlen(materia[i]) - 1;
                    if (materia[i][len] == '\n')
                    {
                        materia[i][len] = '\0';
                    }
                    f = 1;

                    for (int j = 0; j < cont; j++)
                    {
                        if (calificaciones[j][i] > max)
                        {
                            max = calificaciones[j][i];
                        }
                        if (calificaciones[j][i] < min)
                        {
                            min = calificaciones[j][i];
                        }
                    }
                    calificacion_alta[0][i] = max;
                    calificacion_baja[0][i] = min;

                    printf("Calificacion mas alta: %.2f\n", calificacion_alta[0][i]);
                    printf("Calificacion mas baja: %.2f\n", calificacion_baja[0][i]);
                }
            }
            if (f == 0)
            {
                printf("No existe ninguna materia en la base con ese nombre\n");
            }

            break;
        
        case 6:
            if (mat == -1)
            {
                printf("No se han ingresado materias, por favor ingrese primero los datos de los estudiantes\n");
                break;
            }

            // Determinar cuantos estudiantes aprobaron o reprobaron cada asignatura
            for (int i = 0; i < mat; i++)
            {
                cant_aprobados[i] = 0;
                cant_reprobados[i] = 0;
                for (int j = 0; j < cont; j++)
                {
                    if(calificaciones[j][i] >= 6)
                    {
                        cant_aprobados[i]++;
                    }
                    else
                    {
                        cant_reprobados[i]++;
                    }
                }
                printf("Materia: %s\n", materia[i]);
                printf("Aprobados: %d\n", cant_aprobados[i]);
                printf("Reprobados: %d\n", cant_reprobados[i]);
            }
           

            break;

        default:
            break;
        }

    } while (opcin != 7);

    return 0;
}
