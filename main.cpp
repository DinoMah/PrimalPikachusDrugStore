//Almacen de una farmacia PROYECTO FINAL
//fecha: 17 - Julio - 2016
//Autores:  Juan Carlos Herrera, Berenice Morones Alba

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <iomanip>

#include "./src/objeto.cpp"
#include "./include/menu.hpp"

int cascaron( objeto & );
void altas( objeto & ,int&,int&,int&);
void bajas( objeto & ,int&,int&,int&);
void cambios( objeto & );
void consultas(objeto & );

void entradas( objeto & );
void salidas( objeto & );

void cambiarnom( objeto & );
void cambiardesc( objeto & );
void cambiarexis( objeto & );
void cambiarfecha( objeto & );
void cambiarprecio( objeto & );
void cambiarvigen( objeto & );

void consultaclave( objeto & );
void consultageneral( objeto & );
void consultavigente( objeto & );
void consultacaducados( objeto & );
void consultamayor( objeto & );
void consultamenor( objeto & );
void consultaminar( objeto & );
void consultaminab( objeto & );
void consultaporprov( objeto & );
void consultarelven( objeto & );
void consultafacven( objeto & );
void consultaestadistica( objeto & );


int main()
{
    int option = menu();
    std::cout << "Selected option: " << option << std::endl;
    /*int op;
    int (*pmenu)();
    void (*paltas)(objeto &,int&,int&,int&);
    void (*pbajas)(objeto &,int&,int&,int&);
    void (*pcambios)(objeto &);
    void (*pconsultas)(objeto &);
    void (*pentradas)(objeto &);
    void (*psalidas)(objeto &);
    objeto b;
    int sdia,smes,sanyo;
    pmenu = &menu;


    pcambios = &cambios;
    pconsultas = &consultas;
    pentradas = &entradas;
    psalidas = &salidas;

    do{
        op = pmenu();
        switch( op ){
            case 1:
                cascaron( b );
                paltas = &altas;
                paltas( b,sdia,smes,sanyo );
                break;
            case 2:
                pbajas = &bajas;
                pbajas( b,sdia,smes,sanyo);
                break;
            case 3:
                pcambios( b );
                break;
            case 4:
                pconsultas( b );
                break;
            case 5:
                pentradas( b );
                break;
            case 6:
                psalidas( b );
                break;
            case 7:
                cout << "\nOperaci\242n terminada con \202xito\n";
                break;
            default:
                cout << "Opci\242n inv\240lida";
        }
    }while( op != 7 );
    system( "pause" );*/
    return 0;
}

/*int cascaron(objeto &b)
{
    system("cls");
    fstream archive("base.dat", ios::binary|ios::out|ios::app);
    if(!archive.is_open())
    {
        cout << "Base de datos no disponible\n";
        return 1;
    }
    archive.write((char*)&b, sizeof(b));
    archive.close();
    return 0;
}

void altas( objeto &b ,int &sdia,int &smes,int &sanyo){
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        char op;
        string aux, op1;
        int lon = 0;
        bool ban = true;
        string dia,mes,anyo;
        do{
            do{
                cout << "Clave del art\241culo: ";
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
           }while( b.clave <= 0 ); //fin de clave del art�culo
            aux.clear();
            do{
                cout << "Nombre del art\241culo: ";
                cin.ignore();
                getline( cin, aux );
                for( int i = 0; i < aux.length(); i++ ){
                    if( isdigit(aux[i]) ){
                        cout << "Nombre inv\240lido\n";
                        aux.clear();
                        ban = false;
                        break;
                    }
                    else{
                        strcpy(b.nom, aux.c_str() );
                        ban = true;
                    }
                }
            }while( !(ban) ); //fin de do nombre
            aux.clear();
            do{
                cout << "Descripci\242n del art\241culo: ";
                cin.ignore();
                getline( cin, aux );
                for( int i = 0; i < aux.length(); i++ ){
                    if( isdigit(aux[i]) ){
                        cout << "Descripci\242n inv\240lido\n";
                        aux.clear();
                        ban = false;
                        break;
                    }
                    else{
                        strcpy(b.descripcion, aux.c_str() );
                        ban = true;
                    }
                }
            }while( !(ban) ); //fin de do descripcion
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
                            sdia=atoi(dia.c_str());
                            smes=atoi(mes.c_str());
                            sanyo=atoi(anyo.c_str());
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
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );
}
void bajas( objeto &b, int &sdia, int &smes, int &sanyo  ){
   system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        int sdiah,smesh,sanyoh;
        int sdia, smes, sanyo;
        string dia,mes,anyo;
        string aux;
        bool ban = true;
        char op;
        do{
            do{
                cout << "Dame la fecha del dia de hoy: (ddmmaa): ";
                cin >> aux;
                for(int i = 0; i < aux.length(); i++){
                    if( aux[i] < char(48) || aux[i] > char(58) ){
                        cout<<"\nFecha invalida\n";
                        aux.clear();
                        ban = false;
                        break;
                    }
                    else{
                        if( aux.length() == 6 ){
                            dia = aux.substr(0,2);
                            mes = aux.substr(2,2);
                            anyo = aux.substr(4,2);
                            sdiah = atoi( dia.c_str() );
                            smesh = atoi( mes.c_str() );
                            sanyoh = atoi( anyo.c_str() );
                            ban = true;
                        }
                        else{
                            cout << "\nFecha inv\240lida\n";
                            ban = false;
                        }
                    }
                }
            }while( !ban );
            //FIN DE CAPTURA *FECHA*
            aux.clear();
            do{
                cout << "Clave del art\241culo a dar de baja: ";
                cin >> aux;
                 for( int i = 0; i < aux.length(); i++ ){
                        if( isalpha(aux[i]) ){
                            cout << "\nClave inv\240lida\n";
                            b.clave = 0;
                            break;
                        }
                        else{
                            b.clave = atoi( aux.c_str() );
                        }
                 }
            }while( b.clave <= 0 );
            //FIN DE CAPTURA *CLAVE*
            aux.clear();
            archive.seekg( (b.clave - 1)*sizeof(objeto), ios::beg );
            archive.read( reinterpret_cast<char*>(&b), sizeof(objeto) );
            cout<<"\tART\241CULO A DAR DE BAJA\n\n";
            cout<<"Nombre del articulo: " << b.nom <<endl;
            cout<<"Descripcion generica: " << b.descripcion << endl;
            do{
                cout<<"Seguro dar de baja? (s/n):";
                cin >> aux;
                char op1;
                op1 = aux[0];
                tolower( op1 );
                if( op1 == 's' ){
                    if( (sdiah < sdia || smesh < smes || sanyoh < sanyo) || b.cantex < 1 ){
                        b.vigente=0;
                        archive.seekg((b.clave-1)*sizeof(b),ios::beg);
                        archive.write((char*)&b,sizeof(objeto));
                        ban = true;
                        //break;
                    }
                    else{
                        cout << "El art\241culo est\240 vigente o queda en existencia\n";
                    }
                }
                else{
                    cout << "Art\241culo no dado de baja\n" << endl;
                }
            }while( !ban );
            //FIN DE *BAJA*
            aux.clear();
            do{
                cout << "\nQuieres dar de baja otro art\241culo?: ";
                cin.ignore();
                getline( cin, aux );
                for( int i = 0; i < aux.length(); i++ ){
                    if( isdigit(aux[i]) ){
                        cout << "Opci\242n inv\240lida\n";
                        aux.clear();
                        ban = false;
                        break;
                    }
                    else{
                        op = aux[0];
                        ban = true;
                    }
                }
            }while( !(ban) );
            //FIN DE *VALIDACION OP*
            tolower( op );
        }while( op == 's' );
        //FIN DE DO *BAJA*
        archive.close();
    }
    //FIN DE *IF*
    else{
        cout << "Archivo no disponible\n";
    }
    //FIN DE *ELSE*
    system( "pause" );
}
//FIN DE **BAJAS**

void cambios( objeto &b ){
     string op;
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


}
void consultas( objeto &b ){
    string aux;
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
    }
}
void consultaclave( objeto &b ){
    system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        string clave;
        do{
            cout << "Clave del art\241culo: ";
            cin >> clave;
            for( int i = 0; i < clave.length(); i++ ){
                if( isalpha(clave[i]) ){
                    cout << "\nClave inv\240lida\n";
                    b.clave = 0;
                    break;
                }
                else{
                    b.clave = atoi(clave.c_str() );
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
                 << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );
}
void consultageneral( objeto &b ){ //ERROR
    system( "cls" );
    fstream archive( "base.dat", ios::binary | ios::out | ios::in );
    if( archive.is_open() ){
        archive.seekg( 0, ios::beg );
        archive.read( (char*)&b, sizeof(b) );
        cout << "\tTODOS LOS REGISTROS\n\n";
        while( !archive.eof() ){
            cout << "Nombre del art\241culo: " << b.nom << endl
                 << "Descripci\242n: " << b.descripcion << endl
                 << "Cant. m\241n.: " << b.cantmin << endl
                 << "Cant. m\240x.: " << b.cantmax << endl
                 << "Cant. existente: " << b.cantex << endl
                 << "Fecha de caducidad (ddmmaa): " << b.fechacad << endl
                 << "Vigente: " << ( ( b.vigente == true) ? "Disponible\n":"No disponible\n" ) << endl;
            archive.read( (char*)&b, sizeof(b) );
            cout << endl;
        }
        archive.close();
    }
    else{
        cout << "Archivo no disponible\n";
    }
    system( "pause" );
}
void consultavigente( objeto &b ){ //ERROR
    system( "cls" );
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
    system( "pause" );
}
void consultacaducados( objeto &b ){ //ERROR
    system( "cls" );
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
    system( "pause" );
}
void consultamayor( objeto &b ){
    system( "cls" );
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
    system( "pause" );
}
void consultamenor( objeto &b ){
    system( "cls" );
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
    system( "pause" );
}
void consultaminar( objeto &b ){
    system( "cls" );
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
    system( "pause" );
}
void consultaminab( objeto &b ){
    system( "cls" );
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
    system( "pause" );
}
void consultaporprov( objeto &b ){
    system( "cls" );
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
    system( "pause" );
}
void consultarelven( objeto &b ){ //relaci�n de art�culos vendidos
}
void consultafacven( objeto &b ){
}
void consultaestadistica( objeto &b ){
}
void cambiarnom( objeto &b ){

    fstream archivo;
    archivo.open("base.dat",ios::out|ios::in|ios::binary);
    if(archivo.is_open()){
        string nom;
        cout<<"Dame el id a cambiar: ";
        cin>>b.clave;
    // validazion
        archivo.seekg((b.clave-1)*sizeof(b),ios::beg);
        archivo.read((char*)&b,sizeof(objeto));
        cout<<"Dame el nombre nuevo";
        cin.ignore();
        getline(cin,nom);
    //validazion
        strcpy(b.nom,nom.c_str());
        archivo.write((char*)&b,sizeof(objeto));
        archivo.close();


    }else {cout<<"error al abrir el archivo"<<endl;}
    system("pause");
}

void cambiardesc( objeto &b ){
      fstream archivo;
    archivo.open("base.dat",ios::out|ios::in|ios::binary);
    if(archivo.is_open()){
        string descam;
        cout<<"Dame el id a cambiar: ";
        cin>>b.clave;
    // validazion
        archivo.seekg((b.clave-1)*sizeof(b),ios::beg);
        archivo.read((char*)&b,sizeof(objeto));
        cout<<"Dame la descrpcion generica nueva";
        cin.ignore();
        getline(cin,descam);
            //validazion
        strcpy(b.descripcion,descam.c_str());
        archivo.write((char*)&b,sizeof(objeto));
        archivo.close();
    }else {cout<<"error al abrir el archivo"<<endl;}
    system("pause");

}

void cambiarexis( objeto &b ){
    fstream archivo;
    archivo.open("base.dat",ios::out|ios::in|ios::binary);
    if(archivo.is_open()){
        string descam;
        cout<<"Dame el id a cambiar: ";
        cin>>b.clave;
    // validazion
        archivo.seekg((b.clave-1)*sizeof(b),ios::beg);
        archivo.read((char*)&b,sizeof(objeto));
        cout<<"Dame la descrpcion generica nueva";
        cin.ignore();
        getline(cin,descam);
            //validazion
        strcpy(b.descripcion,descam.c_str());
        archivo.write((char*)&b,sizeof(objeto));
        archivo.close();
    }else {cout<<"error al abrir el archivo"<<endl;}
    system("pause");

}

void cambiarfecha( objeto &b ){
        fstream archivo;

    archivo.open("base.dat",ios::out|ios::in|ios::binary);
    if(archivo.is_open()){
        string fechacam;
        char f[50];
        cout<<"Dame el id a cambiar: ";
        cin>>b.clave;
    // validazion
        archivo.seekg((b.clave-1)*sizeof(b),ios::beg);
        archivo.read((char*)&b,sizeof(objeto));
        cout<<"Dame la fecha nueva";
        cin.ignore();
        getline(cin,fechacam);
            //validazion
        strcpy(b.fechacad,fechacam.c_str());

        archivo.write((char*)&b,sizeof(objeto));
        archivo.close();
    }else {cout<<"error al abrir el archivo"<<endl;}
    system("pause");

}

void cambiarprecio( objeto &b ){
            fstream archivo;
    archivo.open("base.dat",ios::out|ios::in|ios::binary);
    if(archivo.is_open()){
        string preciocam;
        cout<<"Dame el id a cambiar: ";
        cin>>b.clave;
    // validazion
        archivo.seekg((b.clave-1)*sizeof(b),ios::beg);
        archivo.read((char*)&b,sizeof(objeto));
        cout<<"Dame el precio nuevo";
        cin.ignore();
        getline(cin,preciocam);
            //validazion
        b.precio=atoi(preciocam.c_str());
        archivo.write((char*)&b,sizeof(objeto));
        archivo.close();
    }else {cout<<"error al abrir el archivo"<<endl;}
    system("pause");

}

void cambiarvigen( objeto &b ){
    fstream archivo;
    archivo.open("base.dat",ios::out|ios::in|ios::binary);
    if(archivo.is_open()){
        char v[2];
        string vigencam;
        cout<<"Dame el id a cambiar: ";
        cin>>b.clave;
    // validazion
        archivo.seekg((b.clave-1)*sizeof(b),ios::beg);
        archivo.read((char*)&b,sizeof(objeto));
        cout<<"Dame la vigencia nueva: ";
        cin.ignore();
        getline(cin,vigencam);
            //validazion
        strcpy(v,vigencam.c_str());
    b.vigente=bool(v);
        archivo.write((char*)&b,sizeof(objeto));
        archivo.close();
    }else {cout<<"error al abrir el archivo"<<endl;}
    system("pause");


}


void entradas( objeto &b ){
        fstream archivo;
        archivo.open("base.dat",ios::out|ios::in|ios::binary);
        if(archivo.is_open()){
            string compra,id="1";
            string cant;
            string proveedor;
            int ecant;
            cout<<"Que articulo  fue comprado: ";
            cin>>compra;
            strcpy(b.nom,compra.c_str());
            cout<<"Cual es el id de este articulo: ";
            cin>>id;
            b.clave=atoi(id.c_str());
            archivo.seekp((b.clave-1)*sizeof(b),ios::beg);
            cout<<"Cuanta cantidad desea comprar: ";
            cin>>cant;
            cout<<"Quien fue el proveedor de la compra: ";
            cin>>proveedor;
            ecant=atoi(cant.c_str());
            b.cantex+=ecant;
            cout<<"compra hecha exitosamente"<<endl<<endl;
            cout<<"Compra: "<<endl;
            cout<<"Articulo: "<<b.nom<<endl;
            cout<<"Provedor: "<<proveedor<<endl;
            cout<<"Cantidad existente: "<<b.cantex<<endl;
            archivo.write((char*)&b,sizeof(objeto));

            archivo.close();
        }else {cout<<"nose pudo abrir el archivo"; }

        system("pause");
}

void salidas( objeto &b ){

     fstream archivo("base.dat",ios::out|ios::in|ios::binary);
        if(archivo.is_open()){
            bool ban=1;
            int sub=0;
            string venta;
            string cant;
            int ecant;
            ofstream archive("Facturas.txt",ios::out|ios::app);
            archive<<"\tFarmacia Pikachu :3"<<endl;
            archive<<"Can.\t\tDescripcion\t\tP/unit\t\timporte"<<endl;
            do {
            cout<<"Precio: ";
            cin>>b.precio;
            cout<<"Que articulo  se vendio: ";
            cin>>venta;
            strcpy(b.nom,venta.c_str());
            archivo.seekp((b.clave-1)*sizeof(b),ios::beg);
            cout<<"Cuanta cantidad fue vendida: ";
            cin>>cant;
            ecant=atoi(cant.c_str());
            b.cantex-=ecant;
            cout<<"venta hecha exitosamente"<<endl<<endl;
            cout<<"\tFarmacia Pikachu :3"<<endl;
            cout<<"Can.\t\tDescripcion\t\tP/unit\t\timporte"<<endl;
            int n =b.precio;
           int pretot= (n*ecant);
            cout<<cant.c_str()<<"\t\t"<<b.nom<<"\t\t"<<b.precio<<"\t\t"<<pretot<<endl;
            archive<<cant.c_str()<<"\t\t"<<b.nom<<"\t\t"<<b.precio<<"\t\t"<<pretot<<endl;

            sub=sub+pretot;

            char resp;
            cout<<"Quiere grabar otra venta: (s/n)";
            cin>>resp;
            if(tolower(resp)=='s')ban=1;
                else if(tolower(resp)=='n')ban=0;
            }while(ban);

            float tot=float(sub*1.16);
            cout<<"\t\t\t\t\t\tSubTotal: "<<sub<<endl
                   <<"\t\t\t\t\t\tIVA: "<<fixed<<setprecision(2)<<sub*.16<<endl
                   <<"\t\t\t\t\t\tTotal: "<<fixed<<setprecision(2)<<tot<<endl;
            archive<<"\t\t\t\t\t\tSubTotal: "<<sub<<endl
                   <<"\t\t\t\t\t\tIVA: "<<fixed<<setprecision(2)<<sub*.16<<endl
                   <<"\t\t\t\t\t\tTotal: "<<fixed<<setprecision(2)<<tot<<endl;
            archivo.close();
        }else {cout<<"nose pudo abrir el archivo"; }

        system("pause");

}
*/