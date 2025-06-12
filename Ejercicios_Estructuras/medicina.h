
struct Medicina
{
    char nombre[100];
    float precio;
    int stock;
    char id[10];  // Identificador único del medicamento
};

struct Consulta
{
    char nombrePaciente[100];
    char cedula[11];
    char diagnostico[100];
    struct Medicina medicamentos[10];
    float costoTotal;
    char fecha[11];  // Formato: YYYY-MM-DD
};

void leerCadena(char *cadena, int num);
void crearMedicamentos(struct Medicina medicamentos[], int *contador);
void listarMedicamentos(struct Medicina medicamentos[], int *contador);
void registrarConsulta(struct Consulta *consulta, struct Medicina medicamentos[], int contadorMedicamentos);
void listarConsultas(struct Consulta consultas[], int contador, char fecha[]);
struct Consulta *buscarConsultaPorPaciente(struct Consulta consultas[], int contador, char nombrePaciente[]);
void imprimirsolouno (struct Consulta *consulta);
void agregarStockMedicamento(struct Medicina medicamentos[], int contadorMedicamentos, char id[]);