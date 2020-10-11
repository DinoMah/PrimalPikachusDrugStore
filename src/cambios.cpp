#include "../include/cambios.hpp"
#include <iostream>
#include <limits>
#include <fstream>

void cambios(objeto &b)
{
    int option;

    showChangeOptions();
    option = getChangeOption();
    
    switch(option)
    {
        case 1: 
            cambiarnom(b);
            break;
        case 2: 
            cambiardesc(b);
            break;
        case 3: 
            cambiarexis(b);
            break;
        case 4: 
            cambiarfecha(b);
            break;
        case 5: 
            cambiarvigen(b);
            break;
        case 6: 
            cambiarprecio(b);
            break;
        case 7:
            std::cout << "Saliendo... Presione una tecla para continuar." << std::endl;
            std::cin.get();
            break;
    }
}

void showChangeOptions()
{
    std::cout << "QUE DESEA CAMBIAR: \n"
              <<"1 -> Nombre del Articulo\n"
              <<"2 -> Descripcion generica\n"
              <<"3 -> Stock\n"
              <<"4 -> Fecha de Caducidad\n"
              <<"5 -> vigencia\n"
              <<"6 -> Precio\n"
              <<"7 -> Cancelar\n";
}

int getChangeOption()
{
    std::string option = "";
    while (true)
    {
        std::cout <<"Dame una opcion: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (isChangeOptionValid(option))
            return std::atoi(option.c_str());
        else
        {
            std::cout << "Opcion invalida, intentelo de nuevo" << std::endl;
            option.clear();
        }
    }
}

bool isChangeOptionValid(std::string input)
{
    if (input.length() != 1)
        return false;

    if (!isdigit(input[0]))
        return false;
    
    int option = std::atoi(input.c_str());
    if (option < 1 || option > 7)
        return false;
    
    return true;
}

void cambiarNombre(objeto &b)
{
    std::fstream archive("base.dat", std::ios::binary|std::ios::in|std::ios::out);
    // Get item
    // Get change
    // Write change
    // Exit
}

void cambiarDescripcion(objeto &b){}

void cambiarExistenciasMin(objeto &b){}

void cambiarExistenciasMax(objeto &b){}

void cambiarExistencias(objeto &b){}

void cambiarFechaCaducidad(objeto &b){}

void cambiarPrecio(objeto &b){}

void cambiarnom( objeto &b ){
/*
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
    system("pause");*/
}

void cambiardesc( objeto &b ){
   /*   fstream archivo;
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
*/
}

void cambiarexis( objeto &b ){
 /*   fstream archivo;
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
*/
}

void cambiarfecha( objeto &b ){
/*        fstream archivo;

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
*/
}

void cambiarprecio( objeto &b ){
 /*           fstream archivo;
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
*/
}

void cambiarvigen( objeto &b ){
 /*   fstream archivo;
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
*/

}