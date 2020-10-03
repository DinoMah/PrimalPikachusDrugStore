#include "./objeto.cpp"

void entradas( objeto &b ){
/*        fstream archivo;
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

        system("pause");*/
}