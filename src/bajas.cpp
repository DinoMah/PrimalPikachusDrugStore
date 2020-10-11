#include "../include/bajas.hpp"
#include "../include/validacion.hpp"
#include "../include/typeOfValidations.hpp"
#include <fstream>
#include <iostream>
#include <ctime>
#include <limits>

void bajas(objeto &b)
{
    system("clear");

    std::fstream archive("base.dat", std::ios::binary|std::ios::out|std::ios::in);
    
    if (!archive.is_open())
    {
        std::cout << "Base de datos no disponible, abortando..." << std::endl;
        return;
    }

    char option = ' ';

    do
    {
        // Obtener la clave del producto a dar de baja
        int claveProducto = obtenerClaveProducto();

        // Reads product data for displaying
        archive.seekg((claveProducto - 1)*sizeof(objeto), std::ios::beg);
        archive.read( reinterpret_cast<char*>(&b), sizeof(objeto) );
        
        displayProductInfo(b);
        
        std::string confirmacion = "";
        std::cout<<"Seguro dar de baja este producto? (s/n):";
        std::cin >> confirmacion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        char op1 = confirmacion[0];
        tolower( op1 );

        if( op1 == 's' )
        {            
            b.vigente = false;
            archive.seekg((b.clave-1)*sizeof(b), std::ios::beg);
            archive.write((char*)&b,sizeof(objeto));
        }
        else
        {
            std::cout << "Articulo no dado de baja, presione una tecla para continuar\n" << std::endl;
            std::cin.get();
        }

        std::cout << "\nQuieres dar de baja otro articulo?: ";
        fgets(&option, 2, stdin);
        tolower(option);
    }while( option == 's' );
    
    archive.close();
    std::cin.get();
}

int obtenerClaveProducto()
{
    std::string claveProducto = "";

    while (true)
    {
        std::cout << "Dame la clave del producto a dar de baja: ";
        std::cin >> claveProducto;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (isInputValid(claveProducto, CLAVE)) break;
        else 
        {
            std::cout << "Clave no valida, intentelo de nuevo." << std::endl;
            claveProducto.clear();
        }
    }

    int clave = std::atoi(claveProducto.c_str());

    return clave;
}

void displayProductInfo(objeto b)
{
    std::cout << "\tARTICULO A DAR DE BAJA\n\n";
    std::cout << "Nombre del articulo: " << b.nombre << std::endl;
    std::cout << "Descripcion generica: " << b.descripcion << std::endl;
}