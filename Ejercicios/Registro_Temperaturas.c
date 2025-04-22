
/*Escribe un programa que almacene las temperaturas diarias de una semana en un *arreglo unidimensional*. Luego, el programa debe:
- Calcular la *temperatura promedio*.
- Determinar la *temperatura más alta y más baja*.

*Pistas*:
- Usa un float temperaturas[7] para guardar los datos.
- Un bucle for puede recorrer el arreglo y hacer los cálculos.*/

#include <stdio.h>
#include <string.h>

int menu();
void ingresarTemperaturas(float temperaturas[7]);
void temperaturaPromedio(float temperaturas[7]);
void temperaturaMaxima(float temperaturas[7]);
void temperaturaMinima(float temperaturas[7]);

int main(int argc, char const *argv[])
{
    float temp[7];
    float suma = 0, promedio, maximo, minimo;
    int opc, val, vali = -1;

    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            printf("Bienvenido al sistema de registro de temperaturas en Celsius\n");
            ingresarTemperaturas(temp);
            vali = 1;
            printf("\n");
            break;

        case 2:
            if (vali == -1)
            {
                printf("Primero ingrese las temperaturas \n");
                printf("\n");
            }
            else
            {
                temperaturaPromedio(temp);
                temperaturaMaxima(temp);
                temperaturaMinima(temp);
                printf("\n");
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
    printf("1. Ingresar temperaturas \n");
    printf("2. Mostrar temperaturas \n");
    printf("3. Salir \n");
    printf("============================= \n");
    do
    {
        printf("Ingrese una opcion: ");
        val = scanf("%d", &op);
        if (val != 1)
        {
            printf("Por favor, ingrese un valor numérico válido.\n");
            fflush(stdin);
        } 
    } while (val != 1);
    return op;
}

void ingresarTemperaturas(float temperaturas[7])
{
    int val;
    for (int i = 0; i < 7; i++)
    {
        do
        {
            printf("Ingrese la temperatura en Celsius del dia %d: ", i);
            val = scanf("%f", &temperaturas[i]);
            if (val != 1)
            {
                printf("Por favor, ingrese un valor numérico válido.\n");
                fflush(stdin);
            }
            else if(temperaturas[i] < -273.15)
            {
                printf("La temperatura minima en grados Celsius es de -273,15 \n");
            }
        } while (val != 1 || temperaturas[i] < -273.15);
    }
}

void temperaturaPromedio(float temperaturas[7])
{
    float suma = 0, promedio, maximo, minimo;
    for (int i = 0; i < 7; i++)
    {
        suma += temperaturas[i];
    }
    promedio = suma / 7;
    printf("La temperatura promedio es: %.2f \n", promedio);
}

void temperaturaMaxima(float temperaturas[7])
{
    float maximo = temperaturas[0];
    for (int i = 1; i < 7; i++)
    {
        if (temperaturas[i] > maximo)
        {
            maximo = temperaturas[i];
        }
    }
    printf("La temperatura maxima es: %.2f \n", maximo);
}

void temperaturaMinima(float temperaturas[7])
{
    float minimo = temperaturas[0];
    for (int i = 1; i < 7; i++)
    {
        if (temperaturas[i] < minimo)
        {
            minimo = temperaturas[i];
        }
    }
    printf("La temperatura minima es: %.2f \n", minimo);
}