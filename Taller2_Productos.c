#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char id[5][10];
    char nombre[5][30];
    int stock[5];
    float precio[5];
    int cont = 0, opci, len;
    float total_ganancias = 0, venta = 0;

    do
    {
        printf("\n Seleccione una opcion \n");
        printf("1. Registrar producto \n");
        printf("2. Vender producto \n");
        printf("3. Reabastecer stock \n");
        printf("4. Ver detalles producto \n");
        printf("5. Ver total de ganancias \n");
        printf("6. Salir \n");
        printf(">> ");
        scanf("%d", &opci);

        switch (opci)
        {
        case 1:

            if (cont < 5)
            {
                printf("Ingrese el Id del producto %d: ", cont);
                scanf("%s", &id[cont]);

                printf("Ingrese el nombre del producto %d: ", cont);
                fflush(stdin);
                fgets(nombre[cont], 30, stdin);

                len = strlen(nombre[cont]) - 1;
                nombre[cont][len] = '\0';
                // '\0'  es el caracter nulo
                // reemplaza el salto de linea por eñl caracter nulo

                printf("Ingrese el stock del producto %d: ", cont);
                scanf("%d", &stock[cont]);

                printf("Ingrese el precio del producto %d: ", cont);
                scanf("%f", &precio[cont]);
                cont++;
            }
            else
            {
                printf("No se puede ingresar mas productos \n");
            }
            break;

        case 2:
            int aux, cantidad;
            printf("Seleccione el producto a vender \n");
            printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\t\t\n", i, id[i], nombre[i], stock[i], precio[i]);
            }

            printf(">> ");
            scanf("%d", &aux);
            printf("Ingrese la cantidad del prodcuto con ID: %s a vender ", id[aux]);
            scanf("%d", &cantidad);

            if (cantidad <= stock[aux])
            {
                venta = cantidad * precio[aux];
                printf("El valor de la venta es: %.2f \n", venta);
                stock[aux] -= cantidad;
                if (cantidad > 20)
                {
                    venta *= 0.9;
                    printf("Se aplica descuenta del 10 por ciento, por venta superior a 20 unidades \n");
                    printf("El valor de la venta con descuento es: %.2f \n", venta);
                }
                total_ganancias += venta;
            }
            else
            {
                printf("No existe stock suficiente a vender \n");
            }
            break;

        case 3:
            printf("Seleccione el producto a reabastecer \n");
            printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\t\t\n", i, id[i], nombre[i], stock[i], precio[i]);
            }

            printf(">> ");
            scanf("%d", &aux);
            printf("Ingrese la cantidad del prodcuto con ID: %s a reabastecer ", id[aux]);
            scanf("%d", &cantidad);

            if (cantidad > 0)
            {
                stock[aux] += cantidad;
                printf("El nuevo stock del producto es %d \n", stock[aux]);
            }
            break;

        case 4:
            char nombuscar[30];
            int f=0;

            printf("Ingrese el nombre del producto a ver el detalle: ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < cont; i++)
            {
                if(strcmp(nombre[i], nombuscar) == 0){
                    printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n");
                    printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\t\t\n", i, id[i], nombre[i], stock[i], precio[i]);  
                    f=1;
                }
            }
            
            if (f==0)
            {
                printf("No existe ningun producto con el nombre ingresado \n");
            }
            break;

        case 5:
            printf("El total de las ganacias es de:  %.2f",&total_ganancias);
            break;
            
        default:
            break;
        }

    } while (opci != 6);

    return 0;
}
