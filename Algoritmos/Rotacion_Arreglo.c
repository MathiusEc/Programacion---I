/*La rotación de un arreglo es una operación que desplaza los elementos de un arreglo hacia la izquierda o hacia la derecha por un
 número específico de posiciones. Los elementos que se desplazan fuera de un extremo del arreglo vuelven a entrar por el otro extremo.

Hay dos tipos principales de rotación de arreglos:

    Rotación a la izquierda: Los elementos se mueven hacia el inicio del arreglo.
    Rotación a la derecha: Los elementos se mueven hacia el final del arreglo.*/

    #include <stdio.h>
    #define TAM 5
    
    void rotarDerecha(int arr[], int n) {
        int ultimo = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = ultimo;
    }
    
    void rotarIzquierda(int arr[], int n) {
        if (n <= 1) {
            return; // No hay necesidad de rotar un arreglo de 0 o 1 elemento
        }
        int primero = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = primero;
    }   

    int main() {
        int tareas[TAM] = {1, 2, 3, 4, 5};
        int tareas2[TAM] = {6, 7, 8, 9, 10};
    
        printf("Tareas pendientes: ");
        for (int i = 0; i < TAM; i++) {
            printf("%d ", tareas[i]);
        }
    
        rotarDerecha(tareas, TAM);
    
        printf("\nTareas después de la rotación a la derecha: ");
        for (int i = 0; i < TAM; i++) {
            printf("%d ", tareas[i]);
        }
    
        rotarIzquierda(tareas2, TAM);

        printf("\nTareas después de la rotación a la izquierda: ");
        for (int i = 0; i < TAM; i++)
        {
            printf("%d ", tareas2[i]);
        }
        
        return 0;
    }