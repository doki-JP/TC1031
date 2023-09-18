#include "Item.h"
#include "inventario.h"

//Posibilidad de añadir la opción tirar (el item) e implementar un algortimo de búsqueda para eliminar el objeto

int main() {
    Inventario inventario;
    std::string name;
    int cant, type;
    int o1;
    int opcion=1;
    Item* item =new Item("Brujula", 1,0);
    inventario.AgregarItem(item);
    /*-------Menú-------*/
    while (opcion!=0){
        std::cout<<"Inventario: "<<std::endl;
        std::cout<<"\t 0. Cerrar\n\t 1. Mostrar Inventario completo\n\t 2. Agregar Item\n\t 3. Ordenar"<<std::endl;
        std::cin>>opcion;
        if (opcion==1)
        {
            inventario.MostrarInventario();
        }
        else if (opcion==2)
        {
            std::cout<<"¿Que item desea agregar? (Nombre): "<<std::endl;
            std::cin>>name;
            std::cout<<"¿Cuantos desea agregar?: "<<std::endl;
            std::cin>>cant;
            std::cout<<"¿De que tipo es?\n\t1. Herramienta\n\t2. Utilidad (Arrojadizo)\n\t3. Comida "<<std::endl;
            std::cin>>type;
            Item* item = new Item(name,cant,type);
            inventario.AgregarItem(item);
            std::cout<<"Listo!! Item agregado"<<std::endl;
        }
        else if (opcion ==3)
        {
            inventario.SortTipo();
            inventario.MostrarInventario();

        }
        else if (opcion>3)
        {
            std::cout<<"Opcion inválida, favor de escoger otra"<<std::endl;
        }
        else if (opcion<0)
        {
            std::cout<<"Opcion inválida, favor de escoger otra"<<std::endl;
        }
        
    }
    delete item;

    return 0;
}