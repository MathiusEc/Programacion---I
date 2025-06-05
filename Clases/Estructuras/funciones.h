struct Materia
{
    char codigo[10];
    char nombre[20];
    float notas[3];
    float prom;
};

struct Estudiante
{
    char codigo[10];
    char nombre[30];
    int edad;
    int numM;
    struct Materia materias[3]; 
};



void leerCadena(char *cadena, int num);
void crearMat(struct Materia materias[3], int cont);
void crearEstu(struct Estudiante estudiante[3], int cont);
void imprimirMat(struct Materia materias[3], int cont);
void imprimirEstu(struct Materia materias[3], struct Estudiante estudiante[3], int cont);