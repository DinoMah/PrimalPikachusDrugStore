#include "../include/optionInvocation.hpp"
#include <iostream>
#include "./objeto.cpp"
#include "../include/cascaron.hpp"

void invokeOption(int option, void (*options[])(objeto &))
{

    objeto b;
    switch(option)
    {
        case 1:
            cascaron(b);
            options[0](b);
            break;
        /*case 2:
            pbajas( b,sdia,smes,sanyo);
            break;
        case 3:
            pcambios( b );
            break;
        case 4:
            pconsultas( b );
            break;
        case 5:
            pentradas( b );
            break;
        case 6:
            psalidas( b );
            break;
        */
        case 7:
            std::cout << "\nSaliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
    }
}