/* Ejercicio 5: Encontrar números repetidos*  
Escribe un programa que detecte y muestre los números repetidos en un *arreglo de 10 elementos*.  

Ejemplo:
*Entrada:* {5, 3, 8, 5, 1, 3, 7, 8, 2, 4}  
*Salida:* Los números repetidos son: 5, 3, 8  

*Pistas*:
- Usa un bucle doble (for) para comparar cada elemento con los demás.*/

#include <stdio.h>

void ingresarNumeros (int numeros[10]);
void numerosRepetidos (int numeros[10], int repetidos[10]); 
void imprimirRepetidos (int repetidos[10]);

int main(int argc, char const *argv[])
{
    int numeros[10];
    int repetidos[10] = {0};
    ingresarNumeros(numeros);
    printf("\n");
    numerosRepetidos(numeros, repetidos);  
    printf("\n");
    imprimirRepetidos(repetidos);
    printf("\n");
    return 0;
}

void ingresarNumeros (int numeros[10])
{
    int val;
    for (int i = 0; i < 10; i++)
    {
        do
        {
            printf("Ingrese el numero %d: ", i);
            fflush(stdin);
            val = scanf("%d", &numeros[i]);
            if (val != 1)
            {
                printf("Error, el numero no es valido\n");
            }
        } while (val != 1);
        
        
    }
}

void numerosRepetidos(int numeros[10], int repetidos[10])
{
    int guardarRepetidos[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (numeros[i] == numeros[j] && !guardarRepetidos[i])
            {
                repetidos[i] = numeros[i];
                guardarRepetidos[i] = 1;
                break; 
            }
        }
    }
}

void imprimirRepetidos (int repetidos[10])
{
    int f = 0;

    printf("Los numeros repetidos son: ");
    for (int i = 0; i < 10; i++)
    {
        if (repetidos[i] != 0)
        {
            if(f != 0)
            {
                printf(", ");
            }
            printf("%d ", repetidos[i]);
            f = 1;
            
        }
    }

    if (f == 0)
    {
        printf("No hay numeros repetidos\n");
    }
   
}