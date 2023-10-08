#include "lectura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Esta función tiene el propósito de leer el archivo de entrada y retornar un array de celdas
Celda *leer_archivo(char *nombre_archivo)
{
    // Se inicializan las variables
    Celda *arreglo;
    // Se lee la primera linea del archivo de entrada y se crea un array de array de celdas
    // con el tamaño de la primera linea.
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        printf("Error: Archivo no encontrado\n");
        exit(1);
    }
    // Se lee la primera linea
    char linea[100];
    int tamaño_array = atoi(fgets(linea, 100, archivo));
    if (tamaño_array == 0)
    {
        printf("Error: Archivo vacío\n");
        exit(1);
    }
    // Se crea un array de array de caracteres con el tamaño de la primera linea
    arreglo = (Celda *)malloc(sizeof(Celda) * tamaño_array);

    // Luego se comienza a leer linea por linea separando las lineas por " " y se guarda en el array de celdas
    // Leeme el archivo linea por linea
    int i = 0;
    while (fscanf(archivo, "%c %c", linea) != EOF)
    {
        // Ahora se separa linea por " " y lo guarda en el array de celdas
        char *token = strtok(linea, " ");
        arreglo[i].posicion = atoi(token);
        arreglo[i].valor = atoi(strtok(NULL, " "));
        i++;
    }
    return arreglo;
}