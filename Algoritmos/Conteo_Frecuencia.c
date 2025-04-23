/*conteo de frecuencia es el proceso de determinar cuántas veces aparece cada elemento distinto en un conjunto de datos. 
Este conjunto de datos puede ser una lista de números, una cadena de caracteres, un arreglo, o cualquier otra colección de elementos.*/

#include <stdio.h>
#define TAM 10

int contarFrecuencia(int arr[], int n, int clave) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == clave) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int ventas[TAM] = {101, 202, 303, 101, 404, 202, 101, 303, 404, 101};
    int producto;

    printf("Ingrese el código del producto a contar: ");
    scanf("%d", &producto);

    int frecuencia = contarFrecuencia(ventas, TAM, producto);
    printf("El producto %d se vendió %d veces.\n", producto, frecuencia);

    return 0;
}