#include "../include/validacion.hpp"
#include <iostream>

bool isInputValid(std::string input, validationType typeOfValidation)
{
    switch(typeOfValidation)
    {
        case NUMBER:
            return isInputNumber(input);
        case ALPHA:
            return isInputChar(input);
        case ALNUM:
            return isInputAlphanumeric(input);
        case CLAVE:
            return isClaveValid(input);
        case DESC:
            return isDescriptionValid(input);
        case PROD:
            return isProductPriceValid(input);
        case INTNUM:
            return isQuantityValid(input);
        case VALIDDATE:
            return isDateValid(input);
        default:
            std::cout << "Tipo de validacion no valida" << std::endl;
    }
    return false;
}

bool isInputChar(std::string input) // Para los menus: altas, bajas, cambios, consultas, entradas y salidas
{
    if (input.length() != 1)
        return false;
    else if (isdigit(input[0]))
        return false;
    else if (!isalpha(input[0]))
        return false;

    return true;
}

bool isInputNumber(std::string input) // Para el menu principal
{
    if (input.length() != 1)
        return false;
    else if (isalnum(input[0]))
        if (isalpha(input[0]))
            return false;
        else 
            if (std::atoi(input.c_str()) < 1 || std::atoi(input.c_str()) > 7)
                return false;
            else
                return true;
    else
        return false;
}

bool verificarContenido(std::string input, std::function<int(int)> function)
{
    for (int i = 0; i < input.length(); i++)
        if (!function(input[i]))
            return false;
    
    return true;
}

bool isInputAlphanumeric(std::string input)
{
    return verificarContenido(input, isalnum);
}

bool isClaveValid(std::string input)
{
    return verificarContenido(input, isdigit);
}

bool isDescriptionValid(std::string input)
{
    return verificarContenido(input, checkDescription);
}

bool checkDescription(char carac)
{
    if (isalnum(carac) || carac == '.' || carac == ',')
        return true;
    else
        return false;
}

bool isProductPriceValid(std::string input)
{
    return verificarContenido(input, isInputDouble);
}

bool isInputDouble(char c)
{
    if (isdigit(c) || c == '.' )
        return true;
    return false;
}

bool isQuantityValid(std::string input)
{
    return verificarContenido(input, isInputInt);
}

bool isInputInt(char c)
{
    if (isdigit(c))
        return true;
    return false;
}

bool isDateValid(std::string input)
{
    return false;
}