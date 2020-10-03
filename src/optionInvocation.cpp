#include "../include/optionInvocation.hpp"
#include <iostream>
#include "../include/cascaron.hpp"

void invokeOption(int option, std::function<void(objeto &)> (options[]))
{
    objeto b;
    switch(option)
    {
        case 1:
            cascaron(b);
            options[0](b);
            break;
        /*case 2:
            pbajas(b);
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
            
            break;*/
        case 7:
            std::cout << "\nSaliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
    }
}