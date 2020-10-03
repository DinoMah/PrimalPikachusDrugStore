#include "../include/cascaron.hpp"
#include <fstream>
#include <iostream>

int cascaron(objeto &b)
{
    system("clear");
    std::ofstream archive("base.dat", std::ios::binary|std::ios::out|std::ios::app);

    if(!archive.is_open())
    {
        std::cout << "Base de datos no disponible" << std::endl;
        return 0;
    }
    
    archive.write((char*)&b, sizeof(b));
    archive.close();
    return 1;
}