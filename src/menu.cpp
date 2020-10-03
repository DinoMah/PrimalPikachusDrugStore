#include "../include/menu.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

int menu()
{
    showOptions();
    
    return getOption();
}

void showOptions()
{
    //system("clear");// system( "cls" );
    
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
        
        if (isInputValid(option) )
            return std::atoi(option.c_str());
        else
            markOptionAsInvalid(option);
    } while(true);
}

bool isInputValid(std::string option)
{
    if (option.length() != 1)
        return false;
    else if (isalnum(option[0]))
        if (isalpha(option[0]))
            return false;
        else 
            if (std::atoi(option.c_str()) < 1 || std::atoi(option.c_str()) > 7)
                return false;
            else
                return true;
    else
        return false;
}

void markOptionAsInvalid(std::string &option)
{
    std::cout << "Opcion invalida, intentelo de nuevo." << std::endl;
    option.clear();
}

void cambios( objeto &b ){
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

void consultas( objeto &b ){
    /*string aux;
    bool ban = true;
    int op;
    do{
        system( "cls" );
        cout << "1 -- Consultar por clave\n"
             << "2 -- Consultar todos\n"
             << "3 -- Consultar art\241culos vigentes\n"
             << "4 -- Consultar art\241culos caducados\n"
             << "5 -- Consultar art\241culos mayores a cierto precio\n"
             << "6 -- Consultar art\241culos menores a cierto precio\n"
             << "7 -- Consultar art\241culos mayores al m\241nimo permitido\n"
             << "8 -- Consultar art\241culos menores al m\241nimo permitido\n"
             << "9 -- Consultar art\241culos comprados a cierto proveedor\n"
             << "10 - Consultar relaci\242n de art\241culos vendidos\n"
             << "11 - Consultar todas las facturas\n"
             << "12 - Consultar estad\241sticas\n"
             << "Opci\242n: ";
        cin >> aux;
        for( int i = 0; i < aux.length(); i++ ){
            if( isalpha(aux[i]) ){
                cout << "Opci\242n inv\240lida\n";
                op = 0;
                ban = false;
                break;
            }
            //FIN DE IF
            else{
                op = atoi( aux.c_str() );
                ban = true;
            }
            //FIN DE ELSE
        }
        //FIN DE FOR
    }while( !ban );
    //FIN DE WHILE
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
            cout << "Operaci\242n terminada\n";
            break;
        default: cout<<"opcion invalida";
    }*/
}