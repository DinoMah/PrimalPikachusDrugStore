#include "../include/altas.hpp"
#include "../include/cascaron.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <string.h>

void altas(objeto &b)
{
    std::ofstream archive("base.dat", std::ios::binary|std::ios::out|std::ios::ate);

    if(!archive.is_open())
    {
        std::cout << "Base de datos no disponible\n";
        return;
    }

    char option = 'y';
        
    do{
        if (!cascaron(b))
        {
            std::cout << "No se pudo crear el registro para almacenar informacion." << std::endl;
            return;
        }

        b.clave = capturarClave();

        archive.seekp((b.clave - 1)* sizeof(objeto), std::ios::beg);

        std::cout << archive.tellp() << std::endl;

        strcpy(b.nombre, capturarNombreProducto());

        strcpy(b.descripcion, capturarDescripcion());

        b.precio = capturarPrecioProducto();

        b.cantmin = capturarExistenciasMin();

        b.cantmax = capturarExistenciasMax();

        strcpy(b.fechaCaducidad, capturarFechaCaducidad());
        b.vigente = true;

        archive.write((char*)&b,sizeof(objeto));

        std::cout << "Quieres registrar otro articulo? (y/n): ";
        fgets(&option, 2, stdin);
    } while ( option != 'n');
    
    archive.close();
    std::cin.get();
}

std::string * capturarDato(const char* productoACapturar, const char *invalidInputMessage, validationType typeOfValidation)
{
    std::string *datoIngresado = new std::string;
    bool *terminated = new bool;

    *terminated = false;

    do{
        std::cout << productoACapturar;
        std::cin >> *datoIngresado;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (isInputValid(*datoIngresado, typeOfValidation))
            *terminated = true;
        else
        {
            std::cout << invalidInputMessage << std::endl;
            datoIngresado->clear();
        }

    }while(!*terminated);

    delete terminated;
    terminated = NULL;

    return datoIngresado;
}

int capturarClave()
{
    std::string *input = capturarDato("Dame una clave numerica: ", "Clave invalida, intentelo de nuevo.", CLAVE);
    int clave = std::atoi(input->c_str());
    
    delete input; input = NULL;

    return clave;
}

char * capturarNombreProducto()
{
    std::string *input = capturarDato(
        "Dame el nombre del producto: ", 
        "El nombre no debe contener carac. especiales", 
        ALNUM
    );
    char *nombreProducto = new char[input->length() + 1];
    strcpy(nombreProducto, input->c_str());

    delete input; input = NULL;

    return nombreProducto;
}

char * capturarDescripcion()
{
    std::string *input = capturarDato(
        "Dame una descripcion del producto: ",
        "La descripcion solo puede contener letras, numeros, puntos y comas.",
        DESC
    );
    char *descripcionProducto = new char[input->length() + 1];
    strcpy(descripcionProducto, input->c_str());

    delete input; input = NULL;

    return descripcionProducto;
}

double capturarPrecioProducto()
{
    std::string *input = capturarDato(
        "Dame el precio del producto: ",
        "El precio del producto no es valido. Intentelo de nuevo",
        PROD
    );
    double precioProducto = std::atof(input->c_str());

    delete input; input = NULL;

    return precioProducto;
}

int capturarExistenciasMin()
{
    std::string *input = capturarDato(
        "Numero de existencias minimas?: ",
        "Cantidad no valida, intentelo de nuevo.",
        INTNUM
    );
    int canMin = std::atoi(input->c_str());

    delete input; input = NULL;

    return canMin;
}

int capturarExistenciasMax()
{
    std::string *input = capturarDato(
        "Numero de existencias maximas?: ",
        "Cantidad no valida, intentelo de nuevo.",
        INTNUM
    );
    int canMax = std::atoi(input->c_str());

    delete input; input = NULL;

    return canMax;
}

char * capturarFechaCaducidad()
{
    std::string *input = capturarDato(
        "Dame la fecha de caducidad (ddmmaaaa): ",
        "Fecha no valida, intentelo de nuevo.",
        VALIDDATE
    );

    char *fechaCaducidad = new char[input->length() + 1];

    strcpy(fechaCaducidad, input->c_str());

    delete input; input = NULL;

    return fechaCaducidad;
}