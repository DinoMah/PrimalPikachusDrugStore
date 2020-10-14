#ifndef CAMBIOS_H
#define CAMBIOS_H

#include "../src/objeto.cpp"
#include "../include/typeOfValidations.hpp"
#include <string>

void cambios(objeto &);

void showChangeOptions();

int getChangeOption();

bool isChangeOptionValid(std::string);

int getClave();

objeto getItem(int);

std::string getNewData(const char *, const char *, validationType);

bool writeNewData(objeto);

void cambiarNombre(objeto &);

void cambiarDescripcion(objeto &);

void cambiarExistenciasMin(objeto &);

void cambiarExistenciasMax(objeto &);

void cambiarPrecio(objeto &);

#endif // CAMBIOS_H