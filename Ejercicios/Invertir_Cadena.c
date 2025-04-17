/* Enunciado: Crea un programa que invierta el orden de una cadena de texto sin usar funciones 
   propias del lenguaje que lo hagan de forma automática.

 * - Si le pasamos "Hola mundo" nos retornaría "odnum aloH" */

#include <stdio.h>
void invertirCadena(char cadena[]);


int main(int argc, char const *argv[])
{
    printf("Ingrese una cadena de texto: ");
    char cadena[100];
    fflush(stdin); 
    fgets(cadena, sizeof(cadena), stdin);
    invertirCadena(cadena);
    printf("La cadena invertida es: %s", cadena);
    return 0;
}

void invertirCadena(char cadena[]) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    
    for (int i = 0; i <longitud/2; i++){
        char cadenatemp = cadena[i];
        cadena[i] = cadena[longitud - i - 1];
        cadena[longitud - i - 1] = cadenatemp;
    }
}