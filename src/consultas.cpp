#include "../include/consultas.hpp"
#include "../include/validacion.hpp"
#include "../include/typeOfValidations.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <limits>

void showConsultOptions()
{
    system("clear");
    std::cout << "1 -- Consultar por clave\n"
              << "2 -- Consultar todos\n"
              << "3 -- Consultar articulos vigentes\n"
              << "4 -- Regresar\n"
              << "Opcion: ";
}

void consultas(objeto &b)
{
    std::string aux;
    bool ban = false;
    int op;

    do{
        showConsultOptions();
        std::cin >> aux;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ban = isInputValid(aux);
    }while( !ban );

    op = std::atoi(aux.c_str());

    switch( op ){
        case 1: consultaclave( b );
            break;
        case 2: consultageneral( b );
            break;
        case 3:  consultavigente( b );
            break;
        case 4:
            std::cout << "Operacion terminada\n";
            break;
        default: std::cout<<"opcion invalida";
    }
}

bool isInputValid(std::string input)
{
    if (input.length() > 2 || input.length() < 1)
        return false;

    for (int i = 0; i < input.length(); i++)
        if( !isdigit(input[i]) )
        {
            std::cout << "Opcion invalida\n";
            return false;
        }
    
    int option = std::atoi(input.c_str());

    if (option < 1 || option > 13)
        return false;

    return true;
}

void showDetails(objeto b)
{
    std::cout << "ID: " << b.clave << std::endl
              << "Nombre del articulo: " << b.nombre << std::endl
              << "Descripcion: " << b.descripcion << std::endl
              << "Cant. min.: " << b.cantmin << std::endl
              << "Cant. max.: " << b.cantmax << std::endl
              << "Cant. existente: " << b.cantex << std::endl
              << "Fecha de caducidad (ddmmaa): " << b.fechaCaducidad << std::endl
              << "Vigente: " << ( ( b.vigente == true) ? "Vigente\n":"No vigente\n" ) << std::endl;
}

void consultaclave(objeto &b)
{
    system( "clear" );
    std::ifstream archive("base.dat", std::ios::binary|std::ios::in);

    if (!archive.is_open())
    {
        std::cout << "Base de datos no disponible" << std::endl;
        return;
    }

    std::string clave;
    bool valid = false;

    do
    {
        std::cout << "Clave del articulo: ";
        std::cin >> clave;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (isInputValid(clave, CLAVE))
            valid = true;
        else
            std::cout << "Clave invalida, intentelo de nuevo." << std::endl;
        
    } while (!valid);

    archive.seekg( (std::atoi(clave.c_str()) - 1)*sizeof(b), std::ios::beg );

    archive.read( (char*)&b, sizeof(b) );

    std::cout << "\nRegistro consultado\n";
    showDetails(b);
    
    archive.close();

    std::cin.get();
}

void consultageneral(objeto &b)
{
    system("clear");
    std::ifstream archive("base.dat", std::ios::binary|std::ios::in);

    if( !archive.is_open() )
    {
        std::cout << "Base de datos no disponible" << std::endl;
        return;
    }

    archive.seekg(0, std::ios::beg);

    archive.read((char*)&b, sizeof(b));

    std::cout << "\tTODOS LOS REGISTROS\n\n";

    while(!archive.eof())
    {
        if (b.vigente)
            showDetails(b);
        archive.read((char*)&b, sizeof(b));
        std::cout << std::endl;
    }

    archive.close();

    std::cin.get();
}

void consultavigente(objeto &b)
{
    system("clear");

    std::ifstream archive("base.dat", std::ios::binary|std::ios::in);

    if(!archive.is_open())
    {
        std::cout << "Base de datos no disponible." << std::endl;
        return;
    }
    
    archive.seekg( 0, std::ios::beg );
    archive.read( (char*)&b, sizeof(b) );

    std::cout << "\tREGISTROS VIGENTES\n";
    while(!archive.eof())
    {
        if(b.vigente == true) showDetails(b);
        archive.read( (char*)&b, sizeof(b) );
        std::cout << std::endl;
    }

    archive.close();
    
    std::cin.get();
}