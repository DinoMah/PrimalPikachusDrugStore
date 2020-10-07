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
    return checkDate(input);
}

bool checkDate(std::string input) // Cuidao, la validacion esta truqueada a modo, por cuestiones de simpleza
{ // Solo hay 30 dias en cada mes y el año debe ser mayor o igual a 2020
    if (input.length() != 8)
        return false;

    std::string day = "", month = "", year = "";
    day = input.substr(0, 2); // From position 0 take 2 chars.
    month = input.substr(2, 2);
    year = input.substr(4, 4);

    if (!verificarContenido(day, isdigit))
        return false;

    if (!verificarContenido(month, isdigit))
        return false;

    if (!verificarContenido(year, isdigit))
        return false;

    int intday = std::atoi(day.c_str());
    int intmonth = std::atoi(month.c_str());
    int intyear = std::atoi(year.c_str());

    if (intday < 1 || intday > 30)
        return false;

    if (intmonth < 1 || intmonth > 12)
        return false;

    if (intyear < 2020)
        return false;

    return true;
}