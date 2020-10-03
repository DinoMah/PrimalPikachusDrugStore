#ifndef OBJETO_H
#define OBJETO_H

#include <string>

typedef struct
{
    int clave;
    char nombre[50], descripcion[256];
    int cantmin, cantmax, cantex;
    char fechaCaducidad[7];
    char proveedor[8] = "Agapito";
    bool vigente;
    double precio;
} objeto;

#endif /* OBJETO_H */