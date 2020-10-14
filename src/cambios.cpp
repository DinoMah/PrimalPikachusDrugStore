#include "../include/cambios.hpp"
#include "../include/validacion.hpp"
#include <iostream>
#include <limits>
#include <fstream>
#include <string.h>

void cambios(objeto &b)
{
    int option;

    showChangeOptions();
    option = getChangeOption();
    
    switch(option)
    {
        case 1: 
            cambiarNombre(b);
            break;
        case 2: 
            cambiarDescripcion(b);
            break;
        case 3: 
            cambiarExistenciasMin(b);
            break;
        case 4: 
            cambiarExistenciasMax(b);
            break;
        case 5: 
            cambiarPrecio(b);
            break;
        case 6:
            std::cout << "Saliendo... Presione una tecla para continuar." << std::endl;
            std::cin.get();
            break;
    }
}

void showChangeOptions()
{
    std::cout << "QUE DESEA CAMBIAR: \n"
              << "1 -> Nombre del Articulo\n"
              << "2 -> Descripcion generica\n"
              << "3 -> Cantidad minima en stock\n"
              << "4 -> Cantidad maxima en stock\n"
              << "5 -> Precio\n"
              << "6 -> Cancelar\n";
}

int getChangeOption()
{
    std::string option = "";
    while (true)
    {
        std::cout <<"Dame una opcion: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (isChangeOptionValid(option))
            return std::atoi(option.c_str());
        else
        {
            std::cout << "Opcion invalida, intentelo de nuevo" << std::endl;
            option.clear();
        }
    }
}

bool isChangeOptionValid(std::string input)
{
    if (input.length() != 1)
        return false;

    if (!isdigit(input[0]))
        return false;
    
    int option = std::atoi(input.c_str());
    if (option < 1 || option > 6)
        return false;
    
    return true;
}

int getClave()
{
    std::string clave = "";
    while (true)
    {
        std::cout << "Dame la clave del producto: ";
        std::cin >> clave;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (isInputValid(clave, CLAVE))
        {
            int productKey = std::atoi(clave.c_str());
            return productKey;
        }
        else
        {
            std::cout << "Clave no valida, intentelo de nuevo." << std::endl;
            clave.clear();
        }
    }
}

objeto getItem(int clave)
{

    std::fstream archive("base.dat", std::ios::binary|std::ios::in|std::ios::out);

    if (!archive.is_open())
    {
        objeto b;
        std::cout << "Base de datos no disponible" << std::endl;
        return b;
    }

    objeto obj;
    archive.seekg((clave - 1)*sizeof(obj), std::ios::beg);
    archive.read((char *)&obj, sizeof(objeto));
    archive.close();
    return obj;
}

std::string getNewData(const char *message, const char *wrongDataMessage, validationType typeOfValidation)
{
    std::string newData = "";
    while (true)
    {
        std::cout << message << std::endl;
        std::cin >> newData;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (isInputValid(newData, typeOfValidation))
            return newData;
        else
        {
            std::cout << wrongDataMessage << std::endl;
            newData.clear();
        }
    }
}

bool writeNewData(objeto b)
{
    std::ofstream archive("base.dat", std::ios::binary|std::ios::out);

    if (!archive.is_open())
    {
        std::cout << "Base de datos no disponible.\n";
        return false;
    }

    archive.seekp((b.clave - 1) * sizeof(b), std::ios::beg);
    archive.write((char *)&b, sizeof(objeto));
    return true;
}

void cambiarNombre(objeto &b)
{
    int clave = getClave();
    b = getItem(clave);

    std::string newName = getNewData(
        "Dame el nuevo nombre: ",
        "Nombre no valido, intentelo de nuevo.",
        ALNUM
    );

    strcpy(b.nombre, newName.c_str());
    
    if (writeNewData(b))
        std::cout << "Cambio realizado con exito.\n";
    else
        std::cout << "Error: No se cambio el campo.\n";
}

void cambiarDescripcion(objeto &b)
{
    int clave = getClave();
    b = getItem(clave);

    std::string newDesc = getNewData(
        "Dame la nueva descripcion: ",
        "Descripcion no valida, intentelo de nuevo.",
        DESC
    );

    strcpy(b.descripcion, newDesc.c_str());
    
    if (writeNewData(b))
        std::cout << "Cambio realizado con exito.\n";
    else
        std::cout << "Error: No se cambio el campo.\n";
}

void cambiarExistenciasMin(objeto &b)
{
    int clave = getClave();
    b = getItem(clave);

    std::string newMin = getNewData(
        "Dame la nueva cantidad minima: ",
        "Cantidad no valida, intentelo de nuevo.",
        INTNUM
    );

    b.cantmin = std::atoi(newMin.c_str());
    
    if (writeNewData(b))
        std::cout << "Cambio realizado con exito.\n";
    else
        std::cout << "Error: No se cambio el campo.\n";
}

void cambiarExistenciasMax(objeto &b)
{
    int clave = getClave();
    b = getItem(clave);

    std::string newMax = getNewData(
        "Dame la nueva cantidad maxima: ",
        "Cantidad no valida, intentelo de nuevo.",
        INTNUM
    );

    b.cantmax = std::atoi(newMax.c_str());
    
    if (writeNewData(b))
        std::cout << "Cambio realizado con exito.\n";
    else
        std::cout << "Error: No se cambio el campo.\n";
}

void cambiarPrecio(objeto &b)
{
    int clave = getClave();
    b = getItem(clave);

    std::string newPrice = getNewData(
        "Dame el nuevo precio: ",
        "Cantidad no valida, intentelo de nuevo.",
        PROD
    );

    b.precio = std::atof(newPrice.c_str());
    
    if (writeNewData(b))
        std::cout << "Cambio realizado con exito.\n";
    else
        std::cout << "Error: No se cambio el campo.\n";
}