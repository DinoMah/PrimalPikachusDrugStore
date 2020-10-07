#ifndef ALTAS_H
#define ALTAS_H

#include "../src/objeto.cpp"
#include "./typeOfValidations.hpp"
#include "./validacion.hpp"

void altas(objeto &);

int capturarClave();

char * capturarNombreProducto();

char * capturarDescripcion();

double capturarPrecioProducto();

int capturarExistenciasMin();

int capturarExistenciasMax();

char * capturarFechaCaducidad();

#endif // ALTAS_H