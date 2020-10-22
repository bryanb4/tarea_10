#ifndef LABORATORIO_H
#define LABORATORIO_H
#include "computadora.cpp"
#include <fstream>

class laboratorio:public computadora{
    private:
        computadora Lab[5];
        size_t ultimo;
    public:
    laboratorio();
    void agregarCP(const computadora &cp);
    void mostrar();
    friend laboratorio& operator<<(laboratorio &lab, const computadora &pc){
        lab.agregarCP(pc);
        return lab;
    }
    void respaldar_tabla();
    void respaldar();
    void recuperar();
};

#endif