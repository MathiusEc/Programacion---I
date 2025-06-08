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
void imprimirEstu(struct Estudiante estudiante[3], int cont);
struct Estudiante* buscarEstu(struct Estudiante estudiante[3], char codigoBusc[], int cont);
void imprimirunSoloEstu (struct Estudiante *prtEstu);