#include "./objeto.cpp"

void salidas( objeto &b ){
/*
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
*/
}