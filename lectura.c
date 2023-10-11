#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celda.h"

// Entrada: nombre del archivo siendo un char.
// Salida: arreglo de celdas (estructura).
// Descripción: Esta función tiene el propósito de leer el archivo de entrada
// y retornar un array de celdas.
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
    // Moverse al final del archivo
    fseek(archivo, 0, SEEK_END);

    // Obtener la posición actual (tamaño del archivo en bytes)
    long tamaño = ftell(archivo);

    if (tamaño == 0)
    {
        printf("El archivo está vacío.\n");
        exit(1);
    }

    // Volver al inicio del archivo
    fseek(archivo, 0, SEEK_SET);
    // Se lee la primera linea
    char linea[100];
    int tamaño_array = atoi(fgets(linea, 100, archivo));
    if (tamaño_array <= 0)
    {
        printf("Error: No Cumple con el Formato Pedido\n");
        exit(1);
    }
    // Se crea un array de array de caracteres con el tamaño de la primera linea
    arreglo = (Celda *)malloc(sizeof(Celda) * tamaño_array);

    // Luego se comienza a leer linea por linea separando las lineas por " " y se guarda en el array de celdas
    // Leeme el archivo linea por linea
    int i = 0;
    int primer_numero;
    int segundo_numero;
    while (fscanf(archivo, "%d %d", &primer_numero, &segundo_numero) != EOF)
    {
        if (primer_numero < 0 || segundo_numero <= 0)
        {
            printf("Error: No Cumple con el Formato Pedido\n");
            exit(1);
        }
        arreglo[i].posicion = primer_numero;
        arreglo[i].valor = segundo_numero;
        arreglo[i].largo_del_arreglo = tamaño_array;
        i++;
    }
    return arreglo;
}