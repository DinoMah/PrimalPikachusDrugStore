#include "./objeto.cpp"

void consultaclave( objeto &b ){
  /*  system( "cls" );
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
    system( "pause" );*/
}
void consultageneral( objeto &b ){ //ERROR
 /*   system( "cls" );
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
    system( "pause" );*/
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