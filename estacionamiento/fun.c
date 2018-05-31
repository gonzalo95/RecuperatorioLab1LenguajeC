#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fun.h"

#define ALPHA 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

int buscarEspacioPropietario(ePropietario* lista, int len)
{
    int i;
    int retorno = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void inicializarPropietario(ePropietario *lista, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        lista[i].estado = 0;
    }
}

int obtenerIdPropietario(ePropietario *lista, int len)
{
    int i, maxId = -1;
    int retorno = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].id > maxId || maxId == -1)
                maxId = lista[i].id;
        }
    }
    retorno = maxId + 1;
    return retorno;
}

void pedirNombrePropietario(ePropietario *lista, int index)
{
    char nya[TAM];
    int validacion = 0;
    while(validacion == 0)
    {
        printf("\nNombre: ");
        fflush(stdin);
        gets(nya);
        validacion = esSoloLetras(nya);
        if(validacion == 0)
            printf("\nNombre invalido\n");
    }
    strcpy(lista[index].nya, nya);
}

void pedirDireccionPropietario(ePropietario *lista, int index)
{
    char dir[TAM];
    int validacion = 0;
    while(validacion == 0)
    {
        printf("\nDireccion: ");
        fflush(stdin);
        gets(dir);
        validacion = esAlfaNumerico(dir);
        if(validacion == 0)
            printf("\nDireccion invalida\n");
    }
    strcpy(lista[index].dir, dir);
}

void pedirTarjetaPropietario(ePropietario *lista, int index)
{
    char tarjeta[TAM];
    int validacion = 0;
    while(validacion == 0)
    {
        printf("\nTarjeta: ");
        fflush(stdin);
        gets(tarjeta);
        validacion = esTarjeta(tarjeta);
        if(validacion == 0)
            printf("\nTarjeta invalida\n");
    }
    strcpy(lista[index].tarjeta, tarjeta);
}

int esSoloLetras(char cadena[])
{
   int i=0;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esAlfaNumerico(char cadena[])
{
   int i=0;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int esTarjeta(char cadena[])
{
   int i = 0;
   int contadorGuiones = 0;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9'))
           return 0;
       if(cadena[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones == 1 && i == 7) // debe tener un guion
        return 1;

    return 0;
}

int buscarIndexPropietario(ePropietario lista[], int id, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].id == id && lista[i].estado != 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void cargarRegistrosPropietarios(ePropietario *lista)
{
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int edad[] = {22, 23, 24, 25};
    int i;

    for(i = 0; i < 4; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].nya, nombre[i]);
        strcpy(lista[i].tarjeta, tarjeta[i]);
        strcpy(lista[i].dir, direccion[i]);
        lista[i].estado = 1;
        lista[i].edad =edad[i];
    }
}

void listarPropietarios(ePropietario lista[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
            printf("%d -- %s -- %s -- %s -- %d\n", lista[i].id, lista[i].nya, lista[i].tarjeta, lista[i].dir, lista[i].edad);
    }
}

void inicializarCoche(eCoche *lista, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        lista[i].estado = 0;
        lista[i].horas =-1;
    }
}

void cargarRegistrosCoches(eCoche *lista)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    int i;

    for(i = 0; i < 10; i++)
    {
        lista[i].id = id[i];
        lista[i].marca = marca[i];
        lista[i].propietario = propietario[i];
        strcpy(lista[i].patente, patente[i]);
        lista[i].estado = 1;
        lista[i].monto = 0;
        lista[i].horas = 0;
    }
}

void listarCoches(eCoche lista[], int lenCoches, ePropietario *propietarios, int lenPropietarios)
{
    int i;
    char marca[10];
    int index;
    for(i = 0; i < lenCoches; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].marca == 1)
                strcpy(marca, "ALPHA");
            if(lista[i].marca == 2)
                strcpy(marca, "FERRARI");
            if(lista[i].marca == 3)
                strcpy(marca, "AUDI");
            if(lista[i].marca == 4)
                strcpy(marca, "OTRO");

            index = buscarIndexPropietario(propietarios, lista[i].propietario, lenPropietarios);

            printf("%d -- %s -- %s -- %s\n", lista[i].id, lista[i].patente, marca, propietarios[index].nya);
        }
    }
}

int obtenerIdCoche(eCoche *lista, int len)
{
    int i, maxId = -1;
    int retorno = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].id > maxId || maxId == -1)
                maxId = lista[i].id;
        }
    }
    retorno = maxId + 1;
    return retorno;
}

void pedirPatente(eCoche *lista, int index)
{
    char patente[TAM];
    int validacion = 0;
    while(validacion == 0)
    {
        printf("\nPatente: ");
        fflush(stdin);
        gets(patente);
        validacion = esSoloLetras(patente);
        if(validacion == 0)
            printf("\nPatente invalida\n");
    }
    strcpy(lista[index].patente, patente);
}

int buscarEspacioCoche(eCoche* lista, int len)
{
    int i;
    int retorno = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int pedirMarca()
{
    int validacion = 0;
    int marca;
    while(validacion == 0)
    {
        printf("\nMarca[1)Alpha 2)Ferrari 3)Audi 4)Otro]: \n");
        scanf("%d", &marca);
        if(marca >= 1 && marca <= 4)
            validacion = 1;
        else
            printf("Marca inexistente");
    }
    return marca;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;
}

void imprimirTicket(eCoche lista[], int indexCoche, ePropietario *propietarios, int lenPropietarios, int monto)
{
    char marca[10];
    int indexPropietario;

    if(lista[indexCoche].marca == 1)
        strcpy(marca, "ALPHA");
    if(lista[indexCoche].marca == 2)
        strcpy(marca, "FERRARI");
    if(lista[indexCoche].marca == 3)
        strcpy(marca, "AUDI");
    if(lista[indexCoche].marca == 4)
        strcpy(marca, "OTRO");

    indexPropietario = buscarIndexPropietario(propietarios, lista[indexCoche].propietario, lenPropietarios);

    printf("%s -- %s -- %s -- $%d\n", propietarios[indexPropietario].nya, lista[indexCoche].patente, marca, monto);
}

int buscarIndexCoche(eCoche *lista, int id, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].id == id && lista[i].estado != 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int calcularRecaudacionTotal(eCoche* lista, int len)
{
    int total = 0;
    int i;
    for(i = 0; i < len; i++)
    {

        if(lista[i].marca == 1 && lista[i].estado == 0)
            total += lista[i].monto;

        if(lista[i].marca == 2 && lista[i].estado == 0)
            total += lista[i].monto;

        if(lista[i].marca == 3 && lista[i].estado == 0)
            total += lista[i].monto;

        if(lista[i].marca == 4 && lista[i].estado == 0)
            total += lista[i].monto;
    }
    return total;
}

int calcularRecaudacionMarca(eCoche* lista, int len, int marca)
{
    int total = 0;
    int i;
    int precioMarca;

    if(marca == ALPHA)
        precioMarca = 150;

    if(marca == FERRARI)
        precioMarca = 175;

    if(marca == AUDI)
        precioMarca = 200;

    if(marca == OTROS)
        precioMarca = 250;

    for(i = 0; i < len; i++)
    {
        if(lista[i].marca == marca && lista[i].estado == 0)
            total += lista[i].monto;
    }
    return total;
}

void listarCochesPropietario(eCoche* lista, int len , int id)
{
    char marca[10];
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].propietario == id && lista[i].estado == 1)
        {
            if(lista[i].marca == ALPHA)
                strcpy(marca, "ALPHA");
            if(lista[i].marca == FERRARI)
                strcpy(marca, "FERRARI");
            if(lista[i].marca == AUDI)
                strcpy(marca, "AUDI");
            if(lista[i].marca == OTROS)
                strcpy(marca, "OTRO");

            printf("%s -- %s\n", lista[i].patente, marca);
        }
    }
}

void listarPropietariosAudi(ePropietario* lista, int lenPropietarios, eCoche *coches, int lenCoches)
{
    int i;
    int id;
    int index;
    for(i = 0; i < lenCoches; i++)
    {
        if(coches[i].estado == 1 && coches[i].marca == AUDI)
        {
            id = coches[i].propietario;
            index = buscarIndexPropietario(lista, id, lenPropietarios);
            if(index == -1)
                continue;
            else
                printf("%d -- %s -- %s -- %s\n", lista[index].id, lista[index].nya, lista[index].tarjeta, lista[index].dir);
        }
    }
}

void ordenarCoches(eCoche* lista, int len)
{
    int i;
    int j;
    eCoche aux;
    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(strcmp(lista[i].patente, lista[j].patente) > 0)
            {
                   aux = lista[i];
                   lista[i] = lista[j];
                   lista[j] = aux;
            }
        }
    }
}
void imprimirCochesYPropietarios(eCoche *coches, int lenC, ePropietario *propietarios, int lenP)
{
    int i;
    int id;
    int index;
    char marca[10];
    for(i = 0; i < lenC; i++)
    {
        if(coches[i].estado == 1)
        {
            id = coches[i].propietario;
            index = buscarIndexPropietario(propietarios, id, lenP);
            if(index == -1)
                continue;
            else
                if(coches[i].marca == 1)
                    strcpy(marca, "ALPHA");
                if(coches[i].marca == 2)
                    strcpy(marca, "FERRARI");
                if(coches[i].marca == 3)
                    strcpy(marca, "AUDI");
                if(coches[i].marca == 4)
                    strcpy(marca, "OTRO");

                printf("%d -- %s -- %s ", coches[i].id, coches[i].patente, marca);
                printf("%d -- %s -- %s -- %s\n", propietarios[index].id, propietarios[index].nya, propietarios[index].tarjeta, propietarios[index].dir);
        }
    }
}

//-----------

void ordenarPropietario(ePropietario* lista, int len, int opcion)
{
    int i;
    int j;
    ePropietario aux;

    if(opcion == 1)
    {
        for(i = 0; i < len - 1; i++)
        {
            for(j = i + 1; j < len; j++)
            {
                if(strcmp(lista[i].nya, lista[j].nya) > 0)
                {
                       aux = lista[i];
                       lista[i] = lista[j];
                       lista[j] = aux;
                }
            }
        }
    }

    if(opcion == 2)
    {
        for(i = 0; i < len - 1; i++)
        {
            for(j = i + 1; j < len; j++)
            {
                if(strcmp(lista[i].nya, lista[j].nya) < 0)
                {
                       aux = lista[i];
                       lista[i] = lista[j];
                       lista[j] = aux;
                }
            }
        }
    }

}

void listarPropietariosEdad(ePropietario lista[], int len, int edad)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1 && lista[i].edad > edad)
            printf("%d -- %s -- %s -- %s -- %d\n", lista[i].id, lista[i].nya, lista[i].tarjeta, lista[i].dir, lista[i].edad);
    }
}


void pedirEdadPropietario(ePropietario *lista, int index)
{
    char edad[TAM];
    int validacion = 0;
    while(validacion == 0)
    {
        printf("\nEdad: ");
        fflush(stdin);
        gets(edad);
        validacion = esSoloNumeros(edad);
        if(validacion == 0)
            printf("\nEdad invalida\n");
    }
    lista[index].edad = atoi(edad);
}

int esSoloNumeros(char cadena[])
{
   int i=0;
   while(cadena[i] != '\0')
   {
       if(!isdigit(cadena[i]))
           return 0;
       i++;
   }
   if(atoi(cadena) > 100 || atoi(cadena) < 1)
    return 0;

   return 1;
}

void listarMayorTicket(eCoche *coches, int lenC, ePropietario *propietarios, int lenP)
{
    int mayor =0;
    int idC;
    int idP;
    char marca[30];
    int indexC;
    int indexP;
    int i;
    for(i = 0; i < lenC; i++)
    {
        if(coches[i].estado == 0 && coches[i].horas != -1)
        {
            if(coches[i].monto > mayor)
            {
                mayor = coches[i].monto;
                idC = coches[i].id;
                idP = coches[i].propietario;
            }
        }
    }
    if(mayor == 0)
        printf("\nNo se facturaron tickets\n");
    else
    {
        indexP = buscarIndexPropietario(propietarios, idP, lenP);
        indexC = buscarIndexCocheBaja(coches, idC, lenC);
        if(coches[indexC].marca == 1)
            strcpy(marca, "ALPHA");
        if(coches[indexC].marca == 2)
            strcpy(marca, "FERRARI");
        if(coches[indexC].marca == 3)
            strcpy(marca, "AUDI");
        if(coches[indexC].marca == 4)
            strcpy(marca, "OTRO");
        printf("\nMayor monto: $%d\n", mayor);
        printf("%d -- %s -- %s -- %s -- %d\n", propietarios[indexP].id, propietarios[indexP].nya, propietarios[indexP].tarjeta, propietarios[indexP].dir, propietarios[indexP].edad);
        printf("%d -- %s -- %s -- HORAS: %d\n", coches[indexC].id, coches[indexC].patente, marca, coches[indexC].horas);
    }
}

int buscarIndexCocheBaja(eCoche *lista, int id, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}
