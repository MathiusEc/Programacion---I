/* Programa donde se usen funciones y arreglos, donde el usuario ingresa el nombre, fecha de nacimiento y edad, las veces que
usuario quiera, mediante la consukta de si quiere agregar más.

de ahi debe preguntarle al mismo usario que ingrese el nombre para ver si existe dentro del arreglo, en caso de que existiera
se debe imprimir el nombre, la fecha de nacimiento y la edad, en caso de que no exista se debe imprimir un mensaje que diga
que no existe el nombre.
*/

#include <stdio.h>
int menu();

int main(int argc, char const *argv[])
{
    int opc;
    opc = menu();
    return 0;
}

int menu()
{
    int op;
    int val;
    do
    {
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
            }
        } while (val != 1);
    } while (op != 3);
    return op;
}