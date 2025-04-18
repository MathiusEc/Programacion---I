/* Programa donde se usen funciones y arreglos, donde el usuario ingresa el nombre, fecha de nacimiento y edad, las veces que
usuario quiera, mediante la consukta de si quiere agregar más. (Puede hacer hasta un máximo de 5 registros).

de ahi debe preguntarle al mismo usario que ingrese el nombre para ver si existe dentro del arreglo, en caso de que existiera
se debe imprimir el nombre, la fecha de nacimiento y la edad, en caso de que no exista se debe imprimir un mensaje que diga
que no existe el nombre.
*/

/// Nota!!!!
/// El ejercicio es solo para validar el uso de matrices y cadenas en funciones y transportar a main
/// No se verifica que ingrese una fecha valida o calcular la edad correspondiente a la misma


#include <stdio.h>
#include <string.h>

int menu();
void solicitarNombre(char nombres[5][30], int cont);
void solicitarFecha(char fecha[5][12], int cont, char nombres[5][30]);
void solicitarEdad(int edad[5], int cont, char nombres[5][30]);
char preguntarContinuar(int cont);
void agregarPersona(char nombres[5][30], char fecha[5][12], int edad[5]);
int buscarNombre(char nombres[5][30], char nombuscar[30], int totalRegistros);
void indentificarPersona(char nombres[5][30], char fecha[5][12], int edad[5], int totalRegistros);

int main(int argc, char const *argv[])
{
    int opc,vali = 0;
    char nombres[5][30];
    char fecha[5][12];
    int edad[5];
do
{
    opc = menu();
    switch (opc)
    {
    case 1:
        printf("Bienvenido al sistema de registro de personas\n");
        agregarPersona(nombres, fecha, edad);
        vali = 1;
        break;

    case 2:
        if (vali == 0)
        {
            printf("Primero ingrese un nombre \n");
        }
        else
        {
            indentificarPersona(nombres, fecha, edad, 5);
        }
        break;

    default:
        break;
    }

} while (opc != 3);
    return 0;
}

int menu()
{
    int op;
    int val;
        printf("============================= \n");
        printf("1. Registrar Persona \n");
        printf("2. Identificar Persona\n");
        printf("3. Salir \n");
        printf("============================= \n");
        printf(">> ");

        do
        {
            fflush(stdin);
            val = scanf("%d", &op);
            if (val != 1)
            {
                printf("Por favor, ingrese un valor correcto..\n");
            }else{


            }

        } while (val != 1);
    return op;
}

void solicitarNombre(char nombres[5][30], int cont)
{
    int duplicado;
    do
    {
        printf("Ingrese el nombre de la persona %d: ", cont);
        fflush(stdin);
        fgets(nombres[cont], 30, stdin);

        // Eliminar el salto de línea al final del nombre
        int len = strlen(nombres[cont]) - 1;
        if (nombres[cont][len] == '\n')
        {
            nombres[cont][len] = '\0';
        }

        if (strlen(nombres[cont]) == 0)
        {
            printf("El nombre no puede estar vacío.\n");
        }
        else
        {
            // Verificar si el nombre ya existe en el arreglo
            duplicado = 0;
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(nombres[cont], nombres[i]) == 0)
                {
                    duplicado = 1;
                    printf("Ya existe una persona con ese nombre, por favor ingrese otro.\n");
                    break;
                }
            }
        }
    } while (strlen(nombres[cont]) == 0 || duplicado == 1);
}

void solicitarFecha(char fecha[5][12], int cont,  char nombres[5][30])
{
    do
    {
        printf("Ingrese la fecha de nacimiento de %s: ", nombres[cont]);
        fflush(stdin);
        fgets(fecha[cont], 12, stdin);

        // Eliminar el salto de línea al final de la cadena
        int len = strlen(fecha[cont]) - 1;
        if (fecha[cont][len] == '\n')
        {
            fecha[cont][len] = '\0';
        }

        if (strlen(fecha[cont]) == 0)
        {
            printf("La fecha no puede estar vacía.\n");
        }
    } while (strlen(fecha[cont]) == 0);
}

void solicitarEdad(int edad[5], int cont, char nombres[5][30])
{
    int val;
    do
    {
        printf("Ingrese la edad de %s: ", nombres[cont]);
        fflush(stdin);
        val = scanf("%d", &edad[cont]);
        if (val != 1)
        {
            printf("Por favor, ingrese un valor numérico válido.\n");
            fflush(stdin);
        }
        else if (edad[cont] < 0 || edad[cont] > 125)
        {
            printf("La edad debe estar en un rango razonable (0-125).\n");
        }
    } while (val != 1 || edad[cont] < 0 || edad[cont] > 125);
}

char preguntarContinuar(int cont)
{
    char continuar;
    if (cont > 4)
    {
        printf("No se pueden ingresar más de 5 personas.\n");
        return 'N';
    }

    do
    {
        printf("¿Desea ingresar otra persona? (s/n): ");
        fflush(stdin);
        scanf(" %c", &continuar);

        if (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n')
        {
            printf("Ingrese una opción válida (s/n).\n");
        }
    } while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');

    return continuar;
}

void agregarPersona(char nombres[5][30], char fecha[5][12], int edad[5])
{
    char continuar;
    int cont = 0;

    do
    {
        solicitarNombre(nombres, cont);
        printf("\n");
        solicitarFecha(fecha, cont, nombres);
        printf("\n");
        solicitarEdad(edad, cont, nombres);
        printf("\n");

        cont++;
        continuar = preguntarContinuar(cont);
    } while (continuar == 'S' || continuar == 's');
}

int buscarNombre(char nombres[5][30], char nombuscar[30], int totalRegistros)
{
    for (int i = 0; i < totalRegistros; i++)
    {
        if (strcmp(nombres[i], nombuscar) == 0)
        {
            return i; // Retorna el índice si encuentra el nombre
        }
    }
    return -1; // Retorna -1 si no encuentra el nombre
}

void indentificarPersona(char nombres[5][30], char fecha[5][12], int edad[5], int totalRegistros)
{
    char nombuscar[30];
    int len;

    printf("Ingrese el nombre de la persona que desea identificar: ");
    printf("\n>> ");
    fflush(stdin);
    fgets(nombuscar, 30, stdin);
    // Eliminar el salto de línea al final del nombre
    len = strlen(nombuscar) - 1;
    if (nombuscar[len] == '\n')
    {
        nombuscar[len] = '\0';
    }

    // Llamar a la función buscarNombre
    int indice = buscarNombre(nombres, nombuscar, totalRegistros);

    if (indice != -1)
    {
        // Si el nombre existe, mostrar los datos
        printf("Nombre \t\t Fecha de Nacimiento \t\t Edad\n");
        printf("%s \t\t %s \t\t\t %d\n", nombres[indice], fecha[indice], edad[indice]);
        printf("\n");
    }
    else
    {
        // Si el nombre no existe, mostrar un mensaje
        printf("No se encontró a la persona con el nombre ingresado.\n");
    }
}