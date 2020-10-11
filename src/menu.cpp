#include "../include/menu.hpp"
#include "../include/validacion.hpp"
#include "../include/typeOfValidations.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

int menu()
{
    showOptions();
    
    return getOption();
}

void showOptions()
{
    system("clear");
    
    std::cout << "\t\t\t\tMENU\n\n"
        << " 1 --> Altas\n"
        << " 2 --> Bajas\n"
        << " 3 --> Cambios\n"
        << " 4 --> Consultas\n"
        << " 5 --> Entradas de mercancia\n"
        << " 6 --> Salidas de mercancia\n"
        << " 7 --> Salir\n";
}

int getOption()
{
    std::string option = "";

    do
    {
        std::cout << "Opcion: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (isInputValid(option, NUMBER))
            return std::atoi(option.c_str());
        else
            markOptionAsInvalid(option);
    } while(true);
}

void markOptionAsInvalid(std::string &option)
{
    std::cout << "Opcion invalida, intentelo de nuevo." << std::endl;
    option.clear();
}