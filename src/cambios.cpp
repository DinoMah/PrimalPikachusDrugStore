#include "./objeto.cpp"

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