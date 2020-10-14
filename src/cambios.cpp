#include "../include/cambios.hpp"
#include "../include/validacion.hpp"
#include <iostream>
#include <limits>
#include <fstream>
#include <string.h>

void cambios(objeto &b)
{
    int option;

    showChangeOptions();
    option = getChangeOption();
    
    switch(option)
    {
        case 1: 
            cambiarNombre(b);
            break;
        case 2: 
            cambiarDescripcion(b);
            break;
        case 3: 
            cambiarExistencias(b);
            break;
        case 4: 
            cambiarFechaCaducidad(b);
            break;
        case 5: 
            //cambiar(b);
            break;
        case 6: 
            cambiarPrecio(b);
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

int getClave()
{
    std::string clave = "";
    while (true)
    {
        std::cout << "Dame la clave del producto: ";
        std::cin >> clave;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (isInputValid(clave, CLAVE))
        {
            int productKey = std::atoi(clave.c_str());
            return productKey;
        }
        else
        {
            std::cout << "Clave no valida, intentelo de nuevo." << std::endl;
            clave.clear();
        }
    }
}

objeto getItem(int clave)
{

    std::fstream archive("base.dat", std::ios::binary|std::ios::in|std::ios::out);

    if (!archive.is_open())
    {
        objeto b;
        std::cout << "Base de datos no disponible" << std::endl;
        return b;
    }

    objeto obj;
    archive.seekg((clave - 1)*sizeof(obj), std::ios::beg);
    archive.read((char *)&obj, sizeof(objeto));
    archive.close();
    return obj;
}

std::string getNewData(const char *message, const char *wrongDataMessage, validationType typeOfValidation)
{
    std::string newData = "";
    while (true)
    {
        std::cout << message << std::endl;
        std::cin >> newData;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (isInputValid(newData, typeOfValidation))
            return newData;
        else
        {
            std::cout << wrongDataMessage << std::endl;
            newData.clear();
        }
    }
}

bool writeNewData(objeto b)
{
    std::ofstream archive("base.dat", std::ios::binary|std::ios::out);

    if (!archive.is_open())
    {
        std::cout << "Base de datos no disponible.\n";
        return false;
    }

    archive.seekp((b.clave - 1) * sizeof(b), std::ios::beg);
    archive.write((char *)&b, sizeof(objeto));
    return true;
}

void cambiarNombre(objeto &b)
{
    int clave = getClave();
    b = getItem(clave);

    std::string newName = getNewData(
        "Dame el nuevo nombre: ",
        "Nombre no valido, intentelo de nuevo.",
        ALNUM
    );

    strcpy(b.nombre, newName.c_str());
    
    if (writeNewData(b))
        std::cout << "Cambio realizado con exito.\n";
    else
        std::cout << "Error: No se cambio el campo.\n";
}

void cambiarDescripcion(objeto &b){}

void cambiarExistenciasMin(objeto &b){}

void cambiarExistenciasMax(objeto &b){}

void cambiarExistencias(objeto &b){}

void cambiarFechaCaducidad(objeto &b){}

void cambiarPrecio(objeto &b){}

/*void cambiarnom( objeto &b ){
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
    system("pause");
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


}*/