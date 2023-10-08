#ifndef LECTURA_H
#define LECTURA_H
typedef struct
{
    int posicion;
    int valor;
    int largo_del_arreglo;
} Celda;

Celda *leer_archivo(char *nombre_archivo);

#endif