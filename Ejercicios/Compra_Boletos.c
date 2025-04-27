
/*Crear un programa que permita simular la compra de n boletos para el cine para n clientes, por
cada cliente debe ingresar el nombre, numero de boletos, el nombre de la película, precio y sala.
Debe realizar usando un menú repetitivo, almacenando los datos en una matriz.
Las funciones son: Ingreso datos, Compra Boletos*/

// Descuento si son mas de 5

#include <stdio.h>
#include <string.h>

int menu();
void ingresoDatos(char nombres[][30], int boletos[], char pelicula[][30], int sala[], int cantCliente, int cantboleto);
int encontrarCliente(char nombres[][30], char temp[30], int n);
void compraBoletos(char nombres[][30], int boletos[], char pelicula[][30], int sala[], int cantCliente);

int main(int argc, char const *argv[])
{
    int val, opc, n, vali = -1;
    char nombres[n][30], pelicula[n][30];
    float precio;
    int boletos[n], sala[n];
    int cantboleto, cantCliente;

    do
    {
        opc = menu();
        printf("\n");
        switch (opc)
        {
        case 1:
            ingresoDatos(nombres, boletos, pelicula, sala, cantCliente, cantboleto);
            vali = 1;
            break;

        case 2:
            if (vali == -1)
            {
                printf("Primero ingrese un nombre \n");
            }
            else
            {
                compraBoletos(nombres, boletos, pelicula, sala, n);
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
    int op, val;

    do
    {
        printf("1. Ingreso de datos\n");
        printf("2. Compra de boletos\n");
        printf("3. Salir\n");
        printf(">> ");

        fflush(stdin);
        val = scanf("%d", &op);
        if (val != 1)
        {
            printf("Error: Ingrese un valor numérico válido.\n\n");
        }
    } while (val != 1);

    return op;
}

void ingresoDatos(char nombres[][30], int boletos[], char pelicula[][30], int sala[], int cantCliente, int cantboleto)
{
    int val, len;

    printf("Ingrese la cantidad de clientes\n");
    printf(">> ");

    do
    {
        fflush(stdin);
        val = scanf("%d", &cantCliente);
        if (val != 1 || cantCliente < 0)
        {
            printf("Error: Ingrese un valor numérico válido. (Mayor a 0)\n");
        }
    } while (val != 1 || cantCliente < 0);

    for (int i = 0; i < cantCliente; i++)
    {
        do
        {
            printf("Ingrese el nombre del cliente %d: ", i);
            fflush(stdin);
            fgets(nombres[i], 30, stdin);
            len = strlen(nombres[i]) - 1;
            nombres[i][len] = '\0';

            if (strlen(nombres[i]) == 0)
            {
                printf("Error: Nombre de equipo no puede estar vacío. Inténtelo de nuevo.\n");
            }
        } while (strlen(nombres[i]) == 0);

        printf("Ingrese la cantidad de boletos que desea comprar\n");
        printf(">> ");

        do
        {
            fflush(stdin);
            val = scanf("%d", &cantboleto);
            if (val != 1 || cantboleto < 0)
            {
                printf("Error: Ingrese un valor numérico válido. (Mayor a 0)\n");
            }
        } while (val != 1 || cantboleto < 0);

        boletos[i] = cantboleto;

        printf("Ingrese el nombre de la película\n");
        fflush(stdin);
        fgets(pelicula[i], 30, stdin);
        len = strlen(pelicula[i]) - 1;
        pelicula[i][len] = '\0';

        if (strlen(pelicula[i]) == 0)
        {
            printf("Error: Nombre de equipo no puede estar vacío. Inténtelo de nuevo.\n");
            i--;
        }

        printf("Escoja la sala\n");
        printf("1. Sala 403\n");
        printf("2. Sala 404\n");
        printf("3. Sala 405\n");
        printf(">> ");

        do
        {
            fflush(stdin);
            val = scanf("%d", &sala[i]);
            if (val != 1 || sala[i] < 1 || sala[i] > 3)
            {
                printf("Error: Ingrese un valor numérico válido. (1-3)\n");
            }
        } while (val != 1 || sala[i] < 1 || sala[i] > 3);
    }
}

void compraBoletos(char nombres[][30], int boletos[], char pelicula[][30], int sala[], int cantCliente)
{
    float precio = 2.50;
    float total, iva, descuento;
    int len, cliente;
    char nombuscar[30];

    printf("El precio de cada boleto es de $2.50\n");
    printf("Escriba el cliente que desea comprar los boletos\n");
    printf(">> ");
    fflush(stdin);
    fgets(nombuscar, 30, stdin);
    len = strlen(nombuscar) - 1;
    nombuscar[len] = '\0';

    if (strlen(nombuscar) == 0)
    {
        printf("Error: Nombre de equipo no puede estar vacío. Inténtelo de nuevo.\n");
    }
    else
    {
        cliente = encontrarCliente(nombres, nombuscar,cantCliente);
        if (cliente == -1)
        {
            printf("El cliente no existe\n");
        }
        else
        {
            printf("Factura de %s\n", nombres[cliente]);
            printf("Pelicula \t Sala \t Cantidad \t Precio \n");
            for (int i = 0; i < boletos[cliente]; i++)
            {
                printf("%s \t\t %d \t\t 1 \t %.2f \n", pelicula[cliente], sala[cliente], precio);
            }
            printf("\t \t \t Subototal: %.2f\n", precio * boletos[cliente]);
            iva = (precio * boletos[cliente]) * 0.16;
            printf("\t \t \t IVA: %.2f\n", iva);
            if (boletos[cliente] > 5)
            {
                descuento = (precio * boletos[cliente]) * 0.10;
                printf("\t \t \t Descuento: %.2f\n", descuento);
            }
            else
            {
                descuento = 0;
                printf("\t \t \t Descuento: %.2f\n", descuento);
            }
            printf("\t \t \t Total: %.2f\n", precio * boletos[cliente] - descuento + iva);
        }
    }
}

int encontrarCliente(char nombres[][30], char temp[30], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nombres[i], temp) == 0)
        {
            return i;
        }
    }
    return -1;
}