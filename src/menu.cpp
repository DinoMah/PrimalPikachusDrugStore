#include "../include/menu.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

int menu()
{
    showOptions();
    
    return getOption();
}

void showOptions()
{
    system("clear");// system( "cls" );
    
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
        
        if (isInputValid(option) )
            return std::atoi(option.c_str());
        else
            markOptionAsInvalid(option);
    } while(true);
}

bool isInputValid(std::string option)
{
    if (option.length() != 1)
        return false;
    else if (isalnum(option[0]))
        if (isalpha(option[0]))
            return false;
        else 
            if (std::atoi(option.c_str()) < 1 || std::atoi(option.c_str()) > 7)
                return false;
            else
                return true;
    else
        return false;
}

void markOptionAsInvalid(std::string &option)
{
    std::cout << "Opcion invalida, intentelo de nuevo." << std::endl;
    option.clear();
}