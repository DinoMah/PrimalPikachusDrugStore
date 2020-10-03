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
            return false;
        default:
            std::cout << "Tipo de validacion no valida" << std::endl;
    }
    return false;
}

bool isInputChar(std::string input)
{
    return true;
}

bool isInputNumber(std::string input)
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