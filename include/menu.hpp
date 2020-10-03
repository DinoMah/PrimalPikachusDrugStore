#ifndef MENU_H
#define MENU_H

#include <string>
#include "../src/objeto.cpp"

int menu();

void showOptions();

int getOption();

bool isInputValid(std::string option);

void markOptionAsInvalid(std::string &option);

void cambios( objeto & );

void consultas(objeto & );

#endif // MENU_H