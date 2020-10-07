#ifndef VALIDACION_H
#define VALIDACION_H

#include <string>
#include "./typeOfValidations.hpp"
#include <functional>

bool isInputChar(std::string input);

bool isInputNumber(std::string input);

bool isInputValid(std::string input, validationType typeOfValidation);

bool verificarContenido(std::string input, std::function<int(int)> function);

bool isInputAlphanumeric(std::string input);

bool isClaveValid(std::string input);

bool isDescriptionValid(std::string input);

bool checkDescription(char);

bool isProductPriceValid(std::string);

bool isInputDouble(char);

bool isQuantityValid(std::string);

bool isInputInt(char c);

bool isDateValid(std::string);

bool checkDate(std::string);

#endif // VALIDACION_H