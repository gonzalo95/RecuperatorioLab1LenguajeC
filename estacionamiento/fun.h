#define TAM 50

typedef struct propietario
{
    int id;
    char nya[TAM];
    char dir[TAM];
    char tarjeta[TAM];
    int estado;
    int edad;
}ePropietario;

typedef struct coche
{
    int id;
    char patente[TAM];
    int marca;
    int propietario;
    int estado;
    int monto;
    int horas;
}eCoche;


int buscarEspacioPropietario(ePropietario* , int );

void inicializarPropietario(ePropietario *, int );

int obtenerIdPropietario(ePropietario *lista, int len);

void pedirNombrePropietario(ePropietario*, int);

void pedirDireccionPropietario(ePropietario*, int);

void pedirTarjetaPropietario(ePropietario*, int);

int esSoloLetras(char cadena[]);

int esAlfaNumerico(char cadena[]);

int esTarjeta(char cadena[]);

int buscarIndexPropietario(ePropietario *, int , int );

void cargarRegistrosPropietarios(ePropietario *);

void listarPropietarios(ePropietario lista[], int len);

void inicializarCoche(eCoche*, int);

void cargarRegistrosCoches(eCoche*);

void listarCoches(eCoche*, int, ePropietario*, int);

int obtenerIdCoche(eCoche *lista, int len);

void pedirPatente(eCoche *lista, int index);

int buscarEspacioCoche(eCoche* lista, int len);

int pedirMarca();

int devolverHorasEstadia();

void imprimirTicket(eCoche lista[], int indexCoche, ePropietario *propietarios, int lenPropietarios, int monto);

int buscarIndexCoche(eCoche *, int, int);

int calcularRecaudacionTotal(eCoche*, int);

int calcularRecaudacionMarca(eCoche*, int, int);

void listarCochesPropietario(eCoche*, int , int);

void listarPropietariosAudi(ePropietario* , int, eCoche*, int);

void ordenarCoches(eCoche*, int);

void imprimirCochesYPropietarios(eCoche *coches, int lenC, ePropietario *propietarios, int lenP);

void ordenarPropietario(ePropietario* lista, int len, int opcion);

void listarPropietariosEdad(ePropietario lista[], int len, int edad);

int esSoloNumeros(char cadena[]);

void listarMayorTicket(eCoche *coches, int lenC, ePropietario *propietarios, int lenP);

int buscarIndexCocheBaja(eCoche *lista, int id, int len);
