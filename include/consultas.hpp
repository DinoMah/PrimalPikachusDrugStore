#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "../src/objeto.cpp"

void showConsultOptions();

void consultas(objeto &);

bool isInputValid(std::string);

void showDetails(objeto);

void consultaclave(objeto &);

void consultageneral(objeto &);

void consultavigente( objeto & );

#endif // CONSULTAS_H