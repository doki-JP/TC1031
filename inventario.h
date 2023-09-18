#ifndef INVENTARIO_H
#define INVENTARIO_H
//#include <herramienta.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


class Inventario{
    private:
    std::vector<Item*> items; //vector que almacena los apuntadores a los objetos del inventario

    public:
    void AgregarItem(Item* item);
    void MostrarInventario();
    void SortTipo();

};
void Inventario::AgregarItem(Item* item){
    items.push_back(item); //el apuntador item se pondrá al final del vector items
}

void Inventario::MostrarInventario() {
    std::cout<<"Tu inventario tiene: "<<std::endl;
    for (Item* item :items){
        item-> Mostrar();
    }
}
void Inventario::SortTipo(){
    std::sort(items.begin(),items.end(),[](Item* a, Item* b){return a->getTipo()<b->getTipo();
    });
}
#endif