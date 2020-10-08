#include "../include/menu.hpp"
#include "../include/validacion.hpp"
#include "../include/typeOfValidations.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

int menu()
{
    showOptions();
    
    return getOption();
}

void showOptions()
{
    system("clear");
    
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (isInputValid(option, NUMBER))
            return std::atoi(option.c_str());
        else
            markOptionAsInvalid(option);
    } while(true);
}

void markOptionAsInvalid(std::string &option)
{
    std::cout << "Opcion invalida, intentelo de nuevo." << std::endl;
    option.clear();
}

void cambios(objeto &b)
{
    /* string op;
     int opc;
    cout<<"QUE DESEA CAMBIAR"<<endl
           <<"1-> Nombre del Articulo\n"
           <<"2-> Descripcion generica\n"
           <<"3-> Stock\n"
           <<"4-> Fecha de Caducidad\n"
           <<"5-> vigencia\n"
           <<"6->Precio\n"
           <<"7->Cancelar\n"
           <<"Dame una opcion: ";
    cin>>op;
    //validacion
    opc=atoi(op.c_str());
    switch(opc){
        case 1: cambiarnom(b);
            break;
        case 2: cambiardesc(b);
            break;
        case 3: cambiarexis(b);
            break;
        case 4: cambiarfecha( b );
            break;
        case 5: cambiarvigen( b );
            break;
        case 6: cambiarprecio( b );
            break;
        case 7:
            break;
        default: cout<<"opcion invalida";


    }

*/
}