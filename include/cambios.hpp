#ifndef CAMBIOS_H
#define CAMBIOS_H

#include "../src/objeto.cpp"
#include <string>

void cambios(objeto &);

void showChangeOptions();

int getChangeOption();

bool isChangeOptionValid(std::string);

void cambiarNombre(objeto &);

void cambiarDescripcion(objeto &);

void cambiarExistenciasMin(objeto &);

void cambiarExistenciasMax(objeto &);

void cambiarExistencias(objeto &);

void cambiarFechaCaducidad(objeto &);

void cambiarPrecio(objeto &);

#endif // CAMBIOS_H