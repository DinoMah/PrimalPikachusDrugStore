#include "../include/altas.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <string.h>

void altas(objeto &b)
{
    b.clave = capturarClave();
    std::cout << "Clave del producto: " << b.clave << std::endl;

    strcpy(b.nombre, capturarNombreProducto());
    std::cout << "Nombre producto: " << b.nombre << std::endl;

    strcpy(b.descripcion, capturarDescripcion());
    std::cout << "Descripcion: " << b.descripcion << std::endl;
    
    /*std::ofstream archive("base.dat", std::ios::binary|std::ios::out|std::ios::in);

    if(!archive.is_open())
    {
        std::cout << "Base de datos no disponible\n";
        return;
    }
        
    char op;
    string aux, op1;
    int lon = 0;
    bool ban = true;
    string dia,mes,anyo;
    do{
        
        aux.clear();
        aux.clear();
        aux.clear(); //limpia aux
        do{
            b.cantmin = 1;
            cout << "Cu\240l es la cantidad m\241nima en stock?: ";
            cin >> aux;
            b.cantmin = atoi(aux.c_str() );
            for( int i = 0; i < aux.length(); i++ ){
                if( isalpha(aux[i]) || b.cantmin <= 0 ){
                    cout << "Cantidad m\241nima inv\240lida\n";
                    b.cantmin = 0;
                    break;
                }
            }
        }while( b.cantmin <= 0 ); //fin de cantidad m�nima
        aux.clear();
        do{
            b.cantmax= 1;
            cout << "Cantidad m\240xima de art\241culo?: ";
            cin >> aux;
            b.cantmax = atoi(aux.c_str() );
            for( int i = 0; i < aux.length(); i++ ){
                if( isalpha(aux[i]) || b.cantmax <= 0  ){
                    cout << "\nCantidad m\240xima inv\240lida\n";
                    b.cantmax = 0;
                    break;
                }
            }
        }while( b.cantmax <= 0 ); //fin de cantidad m�xima
        aux.clear();
        do{
            b.cantex= 0;
            cout << "Cantidad existente del art\241culo?: ";
            cin >> aux;
            b.cantex = atoi(aux.c_str() );
            for( int i = 0; i < aux.length(); i++ ){
                if( isalpha(aux[i]) || b.cantex < 0  ){
                    cout << "\nCantidad existente inv\240lida\n";
                    b.cantex = 0;
                    ban=false;
                    break;
                }else ban=true;
            }
        }while( b.cantex < 0 || !ban ); //fin de cantidad existente
        aux.clear();
        do{
            cout<< "Dame la fecha de caducidad del articulo (ddmmaa): ";
            cin>> b.fechacad;
            for(int i=0; i < 6; i++){
                if( b.fechacad[i] < char(48) || b.fechacad[i] > char(58) ){
                    cout<<"Fecha de Caducidad inv\240lida\n";
                    string str(b.fechacad);
                    str="";
                    ban = false;
                    break;
                }
                else{
                        string str(b.fechacad);
                        dia=str.substr(0,2);
                        mes=str.substr(2,2);
                        anyo=str.substr(5,2);
                        //sdia=atoi(dia.c_str());
                        //smes=atoi(mes.c_str());
                        //sanyo=atoi(anyo.c_str());
                        ban = true;
                }
            }
        }while( !ban );
        b.vigente = true;
        aux.clear();
        do{
            cout << "Quieres agregar otro art\241culo?: ";
            cin.ignore();
            getline( cin, op1 );
            for( int i = 0; i < op1.length(); i++ ){
                if( isdigit(op1[i]) ){
                    cout << "Nombre inv\240lido\n";
                    op1.clear();
                    ban = false;
                    break;
                }
                else{
                    op = op1[0];
                    ban = true;
                }
            }
        }while( !ban );

    }while( op != 'n');
    
    archive.write((char*)&b,sizeof(objeto));
    
    archive.close();
    */std::cin.get();
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
    delete input;
    input = NULL;
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
    return descripcionProducto;
}