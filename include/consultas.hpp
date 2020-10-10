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
void consultacaducados( objeto & );
void consultamayor( objeto & );
void consultamenor( objeto & );
void consultaminar( objeto & );
void consultaminab( objeto & );
void consultaporprov( objeto & );
void consultarelven( objeto & );
void consultafacven( objeto & );
void consultaestadistica( objeto & );

#endif // CONSULTAS_H