#include <stdio.h>

float rest; // Variable global

/*Las variabls cambian durante el tiempo de ejecución*/
int menu();
float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float mdivision(float a, float b);


int main(int argc, char const *argv[])
{
    int op;
    float x, y, resu;

    op = menu();

    switch (op)
    {
    case 1:
        printf("Ingrese el primer numero \n");
        scanf("%f",&x);
        printf("Ingrese el segundo numero \n");
        scanf("%f",&y);

        resu = suma(x,y);
        printf("La suma de  %f es de: ",resu);
        break;

    case 2:
        printf("Ingrese el primer numero \n");
        scanf("%f", &x);
        printf("Ingrese el segundo numero \n");
        scanf("%f", &y);

        resu = resta(x, y);
        printf("La resta de  %f es de: ", resu);
        break;

    case 3:
        printf("Ingrese el primer numero \n");
        scanf("%f", &x);
        printf("Ingrese el segundo numero \n");
        scanf("%f", &y);

        resu = multiplicacion(x, y);
        printf("La multiplicacion de  %f es de: ", resu);
        break;

    case 4:
        printf("Ingrese el primer numero \n");
        scanf("%f", &x);
        printf("Ingrese el segundo numero \n");
        scanf("%f", &y);

        resu = mdivision(x, y);
        printf("La division de %f es de: ", resu);
        break;
    default:
        break;
    }


    return 0;
}


int menu(){
    int opc;
    printf("Seleccione una opcion \n");
    printf("1. Suma \n");
    printf("2. Resta \n");
    printf("3. Multiplicacion \n");
    printf("4. Division \n");
    printf(">> ");
    scanf("%d",&opc);
    return opc;
}

float suma(float a, float b){
    float r; //Variable Local
    r = a + b;
    return r;
}

float resta(float a, float b){
    float r; 
    r = a - b;
    return r;
}

float multiplicacion(float a, float b){
    float r; 
    r = a * b;
    return r;
}


float mdivision(float a, float b /* Parametros posicionales */){
    float r;
    if (b != 0)
    {
        r = a / b;
    }else{
        printf("No se puede dividir para cero \n");
    }
    return r;
}

