#ifndef MENU_H
#define MENU_H

#include <string>
#include "../src/objeto.cpp"

int menu();

void showOptions();

int getOption();

void markOptionAsInvalid(std::string &option);

void cambios( objeto & );

#endif // MENU_H