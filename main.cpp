#include "Item.h"

//Posibilidad de añadir la opción tirar (el item) e implementar un algortimo de búsqueda para eliminar el objeto
//Añadir una introducción tipo videojuego, ej. bienvenido, hoy haremos tu inventario.... (debe ir más allá en cuanto a funcionalidad)
int main() {
    std::string name;
    int cant, type;
    int o1;
    int opcion=1;
    ItemList<int> Inventory;
    Inventory.addFirst("Brujula", 1,0);

    /*-------Menú-------*/
    
    while (opcion!=0){
        std::cout<<"\nInventario: "<<std::endl;
        std::cout<<"\t 0. Cerrar\n\t 1. Mostrar Inventario completo\n\t 2. Agregar Item\n\t 3. Ordenar"<<std::endl;
        std::cin>>opcion;
        if (opcion==1)
        {
            Inventory.print();
        }
        else if (opcion==2)
        {
            std::cout<<"¿Que item desea agregar? (Nombre): "<<std::endl;
            std::cin>>name;
            std::cout<<"¿Cuantos desea agregar?: "<<std::endl;
            std::cin>>cant;
            std::cout<<"¿De que tipo es?\n\t1. Herramienta\n\t2. Utilidad (Arrojadizo)\n\t3. Comida "<<std::endl;
            std::cin>>type;
            Inventory.add(name,cant,type);
            std::cout<<"Listo!! Item '"<<name<<"' ha sido agregado\n";
        }
        else if (opcion ==3)
        {
            Inventory.Insertionsort();

        }
        else if (opcion>3||opcion<0)
        {
            std::cout<<"Opcion no valida, favor de escoger otra"<<std::endl;
        }
    }
    return 0;
}
