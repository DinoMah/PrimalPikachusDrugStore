#include "../include/optionInvocation.hpp"
#include <iostream>

void invokeOption(int option, std::function<void(objeto &)> (options[]))
{
    objeto b;
    switch(option)
    {
        case 1:
            options[0](b);
            break;
        case 2:
            options[1](b);
            break;
        case 3:
            options[2](b);
            break;
        case 4:
            options[3](b);
            break;
        case 5:
            options[4](b);
            break;
        case 6:
            options[5](b);
            break;
        case 7:
            std::cout << "\nSaliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
    }
}