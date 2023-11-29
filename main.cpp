#include "Item.h"
#include <fstream>

//Posibilidad de añadir la opción tirar (el item) e implementar un algortimo de búsqueda para eliminar el objeto
//Añadir una introducción tipo videojuego, ej. bienvenido, hoy haremos tu inventario.... (debe ir más allá en cuanto a funcionalidad)
int main() {
    std::string name;
    int cant, type, orden, menu;
    int opcion=1;
    ItemList<int> Inventory;
    std::ifstream File("Archivo.txt");

    /*-------Menú-------*/
    while (opcion!=0){
        std::cout<<"Extrayendo...\n";
        while (File>>name>>cant>>type){
            Inventory.add(name,cant,type);
        };
        std::cout<<"Terminado\n";
        std::cout<<"\nInventario: "<<std::endl;
        std::cout<<"\t 0. Cerrar\n\t 1. Mostrar Inventario completo\n\t 2. Agregar Item\n\t 3. Ordenar"<<std::endl;
        std::cin>>opcion;
        if (opcion==1)
        {
            std::cout<<"\t1. Imprimir al derecho\n\t2. Imprimir al reves\n";
            std::cin>>menu;
            if (menu==1){
                Inventory.print();    
            }
            else if(menu==2){
                Inventory.printContrario();
            }
            else{
                std::cout<<"Opcion no valida, regresando al menu...";
            }
            
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
            std::cout<<"A partir de que atributo lo quieres ordenar?\n\t1.Nombre (Alfabéticamente)\n\t2. Cantidad\n\t3. Tipo\n Selecccion: ";
            std::cin>>orden;
            Inventory.Sort();

        }
        else if (opcion>3||opcion<0)
        {
            std::cout<<"Opcion no valida, favor de escoger otra"<<std::endl;
        }
    }
    return 0;
}
