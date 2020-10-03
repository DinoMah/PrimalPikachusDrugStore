//Almacen de una farmacia PROYECTO FINAL
//fecha: 17 - Julio - 2016
//Autores:  Juan Carlos Herrera, Berenice Morones Alba

#include "./include/menu.hpp"
#include "./include/optionInvocation.hpp"
#include "./include/altas.hpp"
#include "../include/cambios.hpp"
#include "../include/bajas.hpp"
#include "../include/consultas.hpp"
#include "../include/entradas.hpp"
#include "../include/salidas.hpp"


void executeProgram(int option, void (*options[])(objeto &));

int main()
{
    int *option = new int;
    void (*options[7])(objeto &);

    options[0] = &altas;
    
    executeProgram(*option, options);
    
    delete option;
    option = NULL;

    return 0;
}

void executeProgram(int option, void (*options[])(objeto &))
{
    do
    {
        option = menu();
        invokeOption(option, options);
    } while (option != 7);
}