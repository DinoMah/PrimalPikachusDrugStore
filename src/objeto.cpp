#ifndef OBJETO_H
#define OBJETO_H

#include <string>

typedef struct
{
    int clave;
    std::string nombre, descripcion;
    int cantmin, cantmax, cantex;
    std::string fechaCaducidad;
    std::string proveedor = "Agapito";
    bool vigente;
    double precio;
} objeto;

#endif /* OBJETO_H */