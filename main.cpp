//Almacen de una farmacia PROYECTO FINAL
//fecha: 17 - Julio - 2016 a Octubre de 2020
//Autores:  Juan Carlos Herrera, Berenice Morones Alba

#include "./include/menu.hpp"
#include "./include/optionInvocation.hpp"
#include "./include/altas.hpp"
#include "./include/cambios.hpp"
#include "./include/bajas.hpp"
#include "./include/consultas.hpp"
#include "./include/entradas.hpp"
#include "./include/salidas.hpp"
#include <functional>


void executeProgram(int option, std::function<void(objeto &)> (options[]));

int main()
{
    int *option = new int;
    std::function<void(objeto &)> options[6];

    options[0] = &altas;
    options[1] = &bajas;
    options[2] = &cambios;
    options[3] = &consultas;
    options[4] = &entradas;
    options[5] = &salidas;
    
    executeProgram(*option, options);
    
    delete option;
    option = NULL;

    return 0;
}

void executeProgram(int option, std::function<void(objeto &)> (options[]))
{
    do
    {
        option = menu();
        invokeOption(option, options);
    } while (option != 7);
}