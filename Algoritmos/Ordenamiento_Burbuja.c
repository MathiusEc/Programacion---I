/*Se usa para ordenar los elementos de un arreglo comparando pares adyacentes y realizando intercambios.
  Puede ser ascendente o descendente*/

/*Ordena los tiempos de entrega de 5 pedidos (en minutos) ingresados por el usuario.*/

#include <stdio.h>
#define TAM 5

void ordenarBurbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { //cambiar el simbolo si quieres ascendente o descendente
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int tiempos[TAM];
    printf("Ingrese los tiempos de entrega de 5 pedidos (en minutos):\n");
    for (int i = 0; i < TAM; i++) {
        scanf("%d", &tiempos[i]);
    }

    ordenarBurbuja(tiempos, TAM);

    printf("Tiempos ordenados: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", tiempos[i]);
    }
    return 0;
}