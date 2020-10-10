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
              << "4 -- Consultar articulos caducados\n"
              << "5 -- Consultar articulos mayores a cierto precio\n"
              << "6 -- Consultar articulos menores a cierto precio\n"
              << "7 -- Consultar articulos mayores al minimo permitido\n"
              << "8 -- Consultar articulos menores al minimo permitido\n"
              << "9 -- Consultar articulos comprados a cierto proveedor\n"
              << "10 - Consultar relacion de articulos vendidos\n"
              << "11 - Consultar todas las facturas\n"
              << "12 - Consultar estadisticas\n"
              << "13 - Regresar\n"
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
        case 4:consultacaducados( b );
            break;
        case 5: consultamayor( b );
            break;
        case 6: consultamenor( b );
            break;
        case 7:  consultaminar( b );
            break;
        case 8:  consultaminab( b);
            break;
        case 9:   consultaporprov( b );
            break;
        case 10:  consultarelven( b );
            break;
        case 11:  consultafacven( b );
            break;
        case 12:  consultaestadistica( b );
            break;
        case 13:
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
        showDetails(b);
        archive.read((char*)&b, sizeof(b));
        std::cout << std::endl;
    }

    archive.close();

    std::cin.get();
}

void consultavigente( objeto &b ){ //ERROR
  /*  system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        archive.seekg( 0, ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\tREGISTROS VIGENTES\n";
        while( !archive.eof() ){
            if( b.vigente == true ){
                cout << "Nombre del art\241culo: " << b.nom << endl
                     << "Descripci\242n: " << b.descripcion << endl
                     << "Cant. m\241n.: " << b.cantmin << endl
                     << "Cant. m\240x.: " << b.cantmax << endl
                     << "Cant. existente: " << b.cantex << endl
                     << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
                     << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            }
            archive.read( (char*)&b, sizeof(b) );
            cout << endl;
        }
            archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );*/
}
void consultacaducados( objeto &b ){ //ERROR
    /*system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        string aux;
        do{
            cout << "Dame un fecha (ddmmaa): ";
            cin >> aux;
            for( int i = 0; i < aux.length(); i++ ){
                if( isalpha(aux[i]) ){
                    cout << "\nClave inv\240lida\n";
                    b.clave = 0;
                    break;
                }
                else{
                    if( aux.length() == 6 )
                        b.clave = atoi(aux.c_str() );
                    else{
                        cout << "Clave inv\240lida\n";
                    }
                }
            }
        }while( b.clave <= 0 );
        archive.seekg( 0, ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\tREGISTROS CADUCADOS\n";
        while( !archive.eof() ){
            if( aux.c_str() == b.fechacad ){
                cout << "Nombre del art\241culo: " << b.nom << endl
                     << "Descripci\242n: " << b.descripcion << endl
                     << "Cant. m\241n.: " << b.cantmin << endl
                     << "Cant. m\240x.: " << b.cantmax << endl
                     << "Cant. existente: " << b.cantex << endl
                     << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
                     << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            }
            archive.read( (char*)&b, sizeof(b) );
            cout << endl;
        }
            archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );*/
}
void consultamayor( objeto &b ){
   /* system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        string aux;
        int aux1;
        do{
                cout << "Dame un precio: ";
                cin >> aux;
                for( int i = 0; i < aux.length(); i++ ){
                    if( isalpha(aux[i]) ){
                        cout << "\nClave inv\240lida\n";
                        aux1 = -1;
                        break;
                    }
                    else{
                        aux1 = atoi(aux.c_str() );
                    }
                }
            }while( aux1 < 0 );
        archive.seekg( 0, ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\tREGISTROS POR ARRIBA DEL PRECIO\n";
        while( !archive.eof() ){
            if( aux1 < b.precio ){
                cout << "Nombre del art\241culo: " << b.nom << endl
                     << "Descripci\242n: " << b.descripcion << endl
                     << "Cant. m\241n.: " << b.cantmin << endl
                     << "Cant. m\240x.: " << b.cantmax << endl
                     << "Cant. existente: " << b.cantex << endl
                     << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
                     << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            }
            archive.read( (char*)&b, sizeof(b) );
            cout << endl;
        }
            archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );*/
}
void consultamenor( objeto &b ){
 /*   system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        string aux;
        int aux1;
        do{
                cout << "Dame un precio: ";
                cin >> aux;
                for( int i = 0; i < aux.length(); i++ ){
                    if( isalpha(aux[i]) ){
                        cout << "\nClave inv\240lida\n";
                        aux1 = -1;
                        break;
                    }
                    else{
                        aux1 = atoi(aux.c_str() );
                    }
                }
            }while( aux1 < 0 );
        archive.seekg( 0, ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\tREGISTROS POR ARRIBA DEL PRECIO\n";
        while( !archive.eof() ){
            if( aux1 > b.precio ){
                cout << "Nombre del art\241culo: " << b.nom << endl
                     << "Descripci\242n: " << b.descripcion << endl
                     << "Cant. m\241n.: " << b.cantmin << endl
                     << "Cant. m\240x.: " << b.cantmax << endl
                     << "Cant. existente: " << b.cantex << endl
                     << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
                     << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            }
            archive.read( (char*)&b, sizeof(b) );
            cout << endl;
        }
            archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );*/
}
void consultaminar( objeto &b ){
 /*   system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        string aux;
        int aux1;
        do{
                cout << "Dame un cantidad m\241nima: ";
                cin >> aux;
                for( int i = 0; i < aux.length(); i++ ){
                    if( isalpha(aux[i]) ){
                        cout << "\nClave inv\240lida\n";
                        aux1 = -1;
                        break;
                    }
                    else{
                        aux1 = atoi(aux.c_str() );
                    }
                }
            }while( b.clave < 0 );
        archive.seekg( 0, ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\tREGISTROS POR ARRIBA DEL PRECIO\n";
        while( !archive.eof() ){
            if( aux1 > b.cantmin ){
                cout << "Nombre del art\241culo: " << b.nom << endl
                     << "Descripci\242n: " << b.descripcion << endl
                     << "Cant. m\241n.: " << b.cantmin << endl
                     << "Cant. m\240x.: " << b.cantmax << endl
                     << "Cant. existente: " << b.cantex << endl
                     << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
                     << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            }
            archive.read( (char*)&b, sizeof(b) );
            cout << endl;
        }
            archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );*/
}
void consultaminab( objeto &b ){
 /*   system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        string aux;
        int aux1;
        do{
                cout << "Dame una cantidad: ";
                cin >> aux;
                for( int i = 0; i < aux.length(); i++ ){
                    if( isalpha(aux[i]) ){
                        cout << "\nClave inv\240lida\n";
                        aux1 = -1;
                        break;
                    }
                    else{
                        aux1 = atoi(aux.c_str() );
                    }
                }
            }while( aux1 < 0 );
        archive.seekg( 0, ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\tREGISTROS POR ARRIBA DEL PRECIO\n";
        while( !archive.eof() ){
            if( aux1 < b.cantmin ){
                cout << "Nombre del art\241culo: " << b.nom << endl
                     << "Descripci\242n: " << b.descripcion << endl
                     << "Cant. m\241n.: " << b.cantmin << endl
                     << "Cant. m\240x.: " << b.cantmax << endl
                     << "Cant. existente: " << b.cantex << endl
                     << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
                     << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            }
            archive.read( (char*)&b, sizeof(b) );
            cout << endl;
        }
            archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );*/
}
void consultaporprov( objeto &b ){
 /*   system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        string aux;
        do{
                cout << "Dame una clave: ";
                cin >> aux;
                for( int i = 0; i < aux.length(); i++ ){
                    if( isalpha(aux[i]) ){
                        cout << "\nClave inv\240lida\n";
                        b.clave = 0;
                        break;
                    }
                    else{
                        b.clave = atoi(aux.c_str() );
                    }
                }
            }while( b.clave <= 0 );
        archive.seekg( (b.clave - 1)*sizeof(b), ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\nRegistro consultado\n"
             << "Nombre del art\241culo: " << b.nom << endl
             << "Descripci\242n: " << b.descripcion << endl
             << "Cant. m\241n.: " << b.cantmin << endl
             << "Cant. m\240x.: " << b.cantmax << endl
             << "Cant. existente: " << b.cantex << endl
             << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
             << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl
             << "Proveedor: " << b.prov << endl;
        archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );*/
}
void consultarelven( objeto &b ){ //relaci�n de art�culos vendidos
}
void consultafacven( objeto &b ){
}
void consultaestadistica( objeto &b ){
}