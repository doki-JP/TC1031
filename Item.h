#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item{
    private:
    std::string nombre;
    int cantidad;
    int tipo;
    public:
    Item(std::string name, int cant, int tip): nombre(name), cantidad(cant),tipo(tip){}
    void Mostrar();
    int getTipo();
};
void Item::Mostrar(){
    std::cout<<"Nombre: "<< nombre<< "\n Cantidad: "<<cantidad<<"\n"<<std::endl;
}
int Item::getTipo(){
    return tipo;
}
#endif