#ifndef VALIDACION_H
#define VALIDACION_H

#include <string>
#include "./typeOfValidations.hpp"

bool isInputChar(std::string input);

bool isInputNumber(std::string input);

bool isInputValid(std::string input, validationType typeOfValidation);

#endif // VALIDACION_H