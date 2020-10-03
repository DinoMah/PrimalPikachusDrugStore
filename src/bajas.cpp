#include "../include/bajas.hpp"

void bajas(objeto &b){
   /*system( "cls" );
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
    system( "pause" );*/
}
//FIN DE **BAJAS**