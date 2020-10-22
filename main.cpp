#include "laboratorio.cpp"
main(){
    laboratorio Lab2;
    Lab2.recuperar();
    Lab2.mostrar();

    computadora cp1;
    std::string aux;
    aux= "Windowos 10";
    cp1.setSO(aux);
    aux = "oregel'PC";
    cp1.setNombre(aux);
    aux = "Intel i9 10900k";
    cp1.setCPU(aux);
    cp1.setRAM(128);

    computadora cp2("Uwuntu", "bryan", 64, "Ryzen 4");

    computadora pc3;
    std::cin >> pc3;
    std::cout << std::endl;
    std::cout << pc3 << std::endl;
    std::cout << std::endl;

    laboratorio l1;

    l1.agregarCP(cp2);
    l1.agregarCP(cp1);

    l1 << pc3 << cp2 << cp1;

    l1.mostrar();
    l1.respaldar_tabla();
    std::cout << cp2;
    l1.respaldar();
    l1.mostrar();

    return 0;

}
