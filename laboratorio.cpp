#include "laboratorio.h"
laboratorio::laboratorio(){
    ultimo = 0;
}
void laboratorio::agregarCP(const computadora &cp){
    if (ultimo < 5)
    {
        Lab[ultimo] = cp;
        ultimo ++;
    } 
    else
    {
        std::cout << "El arreglo esta lleno" << std::endl; 
    }
    
}
    
void laboratorio::mostrar(){
    std::cout << std::left;
    std::cout << std::setw(19) << "Sistema Operativo";
    std::cout << std::setw(16) << "Nombre Equipo";
    std::cout << std::setw(6) << "RAM";
    std::cout << std::setw(15) << "CPU";
    std::cout << std::endl;
    for (int  i = 0; i < ultimo; i++)
    {
        computadora &pc = Lab[i];
        std::cout << pc;
        /* std::cout << "     Computadora " << i+1 << std::endl;
        std::cout << "Sistema Operativo: " << Lab[i].getSO() << std::endl;
        std::cout << "Nombre Equipo: " << Lab[i].getNombre() << std::endl;
        std::cout << "RAM:  " << Lab[i].getRAM() << std::endl;
        std::cout << "CPU:  " << Lab[i].getCPU() << std::endl; */
        std::cout << std::endl;
    }
}
void laboratorio::respaldar_tabla(){
    std::ofstream archivo("Respaldo_PC");
    if (archivo.is_open())
    {
        archivo << std::left;
        archivo << std::setw(19) << "Sistema Operativo";
        archivo << std::setw(16) << "Nombre Equipo";
        archivo << std::setw(6) << "RAM";
        archivo << std::setw(15) << "CPU";
        archivo << std::endl;
        for (int  i = 0; i < ultimo; i++)
        {
            computadora &pc = Lab[i];
            archivo << pc;
        }
    }
    archivo.close();    
}
void laboratorio::respaldar(){
    std::ofstream archivo("Backup_PC");
    if (archivo.is_open())
    {
        for (int i = 0; i < ultimo; i++)
        {
            computadora &pc = Lab[i];
            archivo << pc.getSO() << std::endl;
            archivo << pc.getNombre() << std::endl;
            archivo << pc.getRAM() << std::endl;
            archivo << pc.getCPU() << std::endl;
        }
        
    }
    archivo.close();
}
void laboratorio::recuperar(){
    std::ifstream archivo("Backup_PC");
    if (archivo.is_open())
    {
        std::string temp;
        int ramus;
        computadora pc;
        while (!archivo.eof())
        {
            std::getline(archivo, temp);
            if (archivo.eof())
            {
                break;
            }
            
            pc.setSO(temp);

            std::getline(archivo, temp);
            pc.setNombre(temp);

            std::getline(archivo, temp);
            ramus = std::stoi(temp);
            pc.setRAM(ramus);
            
            std::getline(archivo, temp);
            pc.setCPU(temp);
            agregarCP(pc);
        }
        
    }
    archivo.close();
}