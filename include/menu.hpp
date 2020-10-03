#ifndef MENU_H
#define MENU_H

#include <string>

int menu();

void showOptions();

int getOption();

bool isInputValid(std::string option);

void markOptionAsInvalid(std::string &option);

#endif // MENU_H